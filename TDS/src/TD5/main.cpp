#include <iostream>
#include <unordered_map>
#include <iomanip>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <functional>
#include "hache.hpp"

int main() {
    // Exercice 1
    std::cout << "Exercice 1" << std::endl;
    std::string test_string = "Bonjour";
    size_t max = 1024;

    // Test de folding_string_hash
    std::cout << "folding_string_hash: " 
              << folding_string_hash(test_string, max) << std::endl;

    // Test de folding_string_ordered_hash
    std::cout << "folding_string_ordered_hash: " 
              << folding_string_ordered_hash(test_string, max) << std::endl;

    // Test de polynomial_rolling_hash
    size_t p = 31;
    size_t m = 1000000009;
    std::cout << "polynomial_rolling_hash: " 
              << polynomial_rolling_hash(test_string, p, m) << std::endl;

    // Exercice 2
    std::cout << "\nExercice 2" << std::endl;

    // Calcul des probabilités initiales
    std::vector<float> expected_probabilities = probabilities_from_count(expected_insect_counts);

    // Générer des observations aléatoires
    size_t number_of_observations = 10000;
    std::unordered_map<Insect, int> observed_counts;

    // Simuler les observations
    for (size_t i = 0; i < number_of_observations; ++i) {
        size_t random_index = rand() % insect_values.size();
        Insect random_insect = insect_values[random_index];
        observed_counts[random_insect]++;
    }

    // Convertir les comptages observés en probabilités
    std::vector<int> observed_counts_vector;
    for (const auto& insect : insect_values) {
        observed_counts_vector.push_back(observed_counts[insect]);
    }
    std::vector<float> observed_probabilities = probabilities_from_count(observed_counts_vector);

    // Afficher les résultats
    std::cout << std::fixed << std::setprecision(3);
    std::cout << "Probabilities of observed insects vs expected probabilities" << std::endl;

    for (size_t i = 0; i < insect_values.size(); ++i) {
        const std::string& insect_name = insect_to_string.at(insect_values[i]);
        float observed = observed_probabilities[i];
        float expected = expected_probabilities[i];
        std::cout << insect_name << " : " << observed << " vs " << expected;

        if (std::abs(observed - expected) > 0.01) {
            std::cout << " BAD";
        } else {
            std::cout << " OK";
        }
        std::cout << std::endl;
    }

    // Exercice 3
    std::cout << "Exercice 3" << std::endl;

    // Générer une liste de 100 cartes aléatoires
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    std::vector<Card> cards = get_cards(100);

    // Compter les occurrences de chaque carte
    std::unordered_map<Card, int> card_counts;
    for (const auto& card : cards) {
        card_counts[card]++;
    }

    // Afficher les résultats
    for (const auto& [card, count] : card_counts) {
        std::cout << card_name(card) << " : " << count << std::endl;
    }

    return 0;
}