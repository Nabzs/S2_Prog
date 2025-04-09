#include "npi_token.hpp"
#include <stdexcept>
#include <sstream>
#include <cctype>
#include <vector>
#include <stack>
#include "utils.hpp"

bool is_floating(const std::string& str) {
    std::istringstream iss(str);
    float f;
    iss >> std::noskipws >> f; 
    return iss.eof() && !iss.fail();
}

// Fonction pour créer un token à partir d'un opérande
Token make_token(float value) {
    return Token{TokenType::OPERAND, value, Operator::ADD}; 
}

// Fonction pour créer un token à partir d'un opérateur
Token make_token(Operator op) {
    return Token{TokenType::OPERATOR, 0.0f, op}; // La valeur n'est pas utilisée ici
}

// Fonction pour obtenir la priorité d'un opérateur
int operator_precedence(Operator const op) {
    switch (op) {
        case Operator::ADD:
        case Operator::SUB: return 1;
        case Operator::MUL:
        case Operator::DIV: return 2;
        case Operator::OPEN_PAREN:
        case Operator::CLOSE_PAREN: return 0;
        default: throw std::invalid_argument("Operateur invalide");
    }
}

// Fonction pour convertir une expression infixe en NPI
std::vector<Token> infix_to_npi_tokens(const std::string& expression) {
    std::vector<std::string> words = split_string(expression);
    std::vector<Token> output;
    std::stack<Token> operators;

    for (const auto& word : words) {
        if (is_floating(word)) {
            output.push_back(make_token(std::stof(word)));
        } else if (word == "(") {
            operators.push(make_token(Operator::OPEN_PAREN));
        } else if (word == ")") {
            while (!operators.empty() && operators.top().op != Operator::OPEN_PAREN) {
                output.push_back(operators.top());
                operators.pop();
            }
            if (operators.empty() || operators.top().op != Operator::OPEN_PAREN) {
                throw std::invalid_argument("Parentheses non correspondantes");
            }
            operators.pop();
        } else {
            Operator op;
            if (word == "+") op = Operator::ADD;
            else if (word == "-") op = Operator::SUB;
            else if (word == "*") op = Operator::MUL;
            else if (word == "/") op = Operator::DIV;
            else throw std::invalid_argument("Operateur invalide");

            while (!operators.empty() &&
                   operator_precedence(operators.top().op) >= operator_precedence(op)) {
                output.push_back(operators.top());
                operators.pop();
            }
            operators.push(make_token(op));
        }
    }

    while (!operators.empty()) {
        if (operators.top().op == Operator::OPEN_PAREN) {
            throw std::invalid_argument("Parentheses non correspondantes");
        }
        output.push_back(operators.top());
        operators.pop();
    }

    return output;
}