#include <iostream>
#include <vector>
#include <string>
#include "npi.hpp"
#include "utils.hpp"
#include "npi_token.hpp"

int main() {
    // Saisie de l'expression en notation polonaise inversée
    std::string expression;
    std::cout << "Entrez une expression en NPI (ex 3 4 +) : ";
    std::getline(std::cin, expression);

    // Séparer l'expression en mots (tokens)
    std::vector<std::string> words = split_string(expression);

    // Transformer les mots en tokens
    std::vector<Token> tokens = tokenize(words);

    // Evaluer l'expression
    try {
        float result = npi_evaluate(tokens);
        std::cout << "Resultat : " << result << std::endl;
    } catch (const std::invalid_argument& e) {
        std::cout << "Erreur : " << e.what() << std::endl;
    }

    return 0;
}
