#include "npi.hpp"
#include <stdexcept>
#include <vector>
#include "npi_token.hpp"

float npi_evaluate(const std::vector<Token>& tokens) {
    std::vector<float> stack;
    for (const auto& token : tokens) {
        if (token.type == TokenType::OPERAND) {
            stack.push_back(token.value);
        } else if (token.type == TokenType::OPERATOR) {
            if (stack.size() < 2) {
                throw std::invalid_argument("Expression invalide !");
            }
            float b = stack.back(); stack.pop_back();
            float a = stack.back(); stack.pop_back();
            switch (token.op) {
                case Operator::ADD: stack.push_back(a + b); break;
                case Operator::SUB: stack.push_back(a - b); break;
                case Operator::MUL: stack.push_back(a * b); break;
                case Operator::DIV: stack.push_back(a / b); break;
                default: throw std::invalid_argument("Operateur invalide");
            }
        }
    }
    if (stack.size() != 1) {
        throw std::invalid_argument("Expression invalide !");
    }
    return stack.back();
}