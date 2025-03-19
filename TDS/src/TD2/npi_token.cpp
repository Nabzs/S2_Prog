#include "npi_token.hpp"
#include <stdexcept>
#include <sstream>
#include <cctype>
#include <vector>


// Fonction pour créer un token à partir d'un opérande
Token make_token(float value) {
    return Token{TokenType::OPERAND, value, Operator::ADD}; // L'opérateur par défaut n'est pas utilisé ici
}

// Fonction pour créer un token à partir d'un opérateur
Token make_token(Operator op) {
    return Token{TokenType::OPERATOR, 0.0f, op}; // La valeur n'est pas utilisée ici
}

// Fonction pour vérifier si une chaîne représente un nombre flottant
bool is_floating(const std::string& s) {
    bool dot_found = false;
    for (char ch : s) {
        if (ch == '.') {
            if (dot_found) return false;
            dot_found = true;
        } else if (!std::isdigit(ch)) {
            return false;
        }
    }
    return true;
}

std::vector<Token> tokenize(const std::vector<std::string>& words) {
    std::vector<Token> tokens;

    for (const auto& word : words) {
        if (is_floating(word)) {
            tokens.push_back(make_token(std::stof(word)));  // Convertir en float et ajouter un opérande
        } else if (word == "+") {
            tokens.push_back(make_token(Operator::ADD));  // opérateur +
        } else if (word == "-") {
            tokens.push_back(make_token(Operator::SUB));  // opérateur -
        } else if (word == "*") {
            tokens.push_back(make_token(Operator::MUL));  // opérateur *
        } else if (word == "/") {
            tokens.push_back(make_token(Operator::DIV));  // opérateur /
        } else {
            throw std::invalid_argument("Operateur ou operande invalide");
        }
    }

    return tokens;
}
