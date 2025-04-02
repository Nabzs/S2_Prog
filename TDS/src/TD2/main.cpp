#include <iostream>
#include <vector>
#include <string>
#include "npi.hpp"
#include "utils.hpp"
#include "npi_token.hpp"

int main() {
    // Saisie de l'expression en notation infixe
    std::string expression;
    std::cout << "Entrez une expression en notation infixe (ex: 3 + 4 * 2) : ";
    std::getline(std::cin, expression);

    try {
        // Conversion en NPI
        std::vector<Token> npi_tokens = infix_to_npi_tokens(expression);

        // Évaluation de l'expression en NPI
        float result = npi_evaluate(npi_tokens);

        std::cout << "Resultat : " << result << std::endl;
    } catch (const std::invalid_argument& e) {
        std::cout << "Erreur : " << e.what() << std::endl;
    }

    return 0;
}