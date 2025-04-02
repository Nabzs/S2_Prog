#include <iostream>
#include <unordered_map>
#include <iomanip>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <functional>
#include "hache.hpp"

enum class Insect {
    ClassicBee,
    Ladybug,
    Butterfly,
    Dragonfly,
    Ant,
    Grasshopper,
    Beetle,
    Wasp,
    Caterpillar,
    Spider,
    GuimielBee
};

const std::vector<Insect> insect_values {
    Insect::ClassicBee,
    Insect::Ladybug,
    Insect::Butterfly,
    Insect::Dragonfly,
    Insect::Ant,
    Insect::Grasshopper,
    Insect::Beetle,
    Insect::Wasp,
    Insect::Caterpillar,
    Insect::Spider,
    Insect::GuimielBee
};

const std::unordered_map<Insect, std::string> insect_to_string = {
    {Insect::ClassicBee, "ClassicBee"},
    {Insect::Ladybug, "Ladybug"},
    {Insect::Butterfly, "Butterfly"},
    {Insect::Dragonfly, "Dragonfly"},
    {Insect::Ant, "Ant"},
    {Insect::Grasshopper, "Grasshopper"},
    {Insect::Beetle, "Beetle"},
    {Insect::Wasp, "Wasp"},
    {Insect::Caterpillar, "Caterpillar"},
    {Insect::Spider, "Spider"},
    {Insect::GuimielBee, "GuimielBee"}
};

const std::vector<int> expected_insect_counts {
    75, // ClassicBee
    50, // Ladybug
    100, // Butterfly
    20, // Dragonfly
    400, // Ant
    150, // Grasshopper
    60, // Beetle
    10, // Wasp
    40, // Caterpillar
    90, // Spider
    5   // GuimielBee
};

// Fonction pour générer une liste de cartes aléatoires
std::vector<Card> get_cards(size_t const size) {
    std::vector<Card> cards;
    cards.reserve(size);
    for (size_t i = 0; i < size; ++i) {
        cards.push_back({
            static_cast<CardKind>(rand() % 4),
            static_cast<CardValue>(rand() % 13)
        });
    }
    return cards;
}

// Fonction pour obtenir le nom d'une carte
std::string card_name(const Card& card) {
    std::string name;

    unsigned int card_value = (static_cast<unsigned int>(card.value) + 2) % 14;

    if (card_value < 10) {
        name += '0' + card_value;
    } else if (card_value == 10) {
        name += "10";
    } else if (card_value == 11) {
        name += 'J';
    } else if (card_value == 12) {
        name += 'Q';
    } else if (card_value == 13) {
        name += 'K';
    }

    name += " of ";

    if (card.kind == CardKind::Heart) {
        name += "Heart";
    } else if (card.kind == CardKind::Diamond) {
        name += "Diamond";
    } else if (card.kind == CardKind::Club) {
        name += "Club";
    } else if (card.kind == CardKind::Spade) {
        name += "Spade";
    }

    return name;
}

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