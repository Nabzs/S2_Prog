#include "hache.hpp"
#include <functional>

// Implémentation de folding_string_hash
size_t folding_string_hash(const std::string& s, size_t max) {
    size_t hash = 0;
    for (char c : s) {
        hash += static_cast<size_t>(c);
    }
    return hash % max;
}

// Implémentation de folding_string_ordered_hash
size_t folding_string_ordered_hash(const std::string& s, size_t max) {
    size_t hash = 0;
    for (size_t i = 0; i < s.size(); ++i) {
        hash += static_cast<size_t>(s[i]) * (i + 1);
    }
    return hash % max;
}

// Implémentation de polynomial_rolling_hash
size_t polynomial_rolling_hash(const std::string& s, size_t p, size_t m) {
    size_t hash = 0;
    size_t power = 1; // p^0 = 1
    for (char c : s) {
        hash = (hash + (static_cast<size_t>(c) * power) % m) % m;
        power = (power * p) % m; // Compute the next power of p
    }
    return hash;
}

// Exercice 2
// Implémentation de probabilities_from_count
std::vector<float> probabilities_from_count(const std::vector<int>& counts) {
    std::vector<float> probabilities;
    int total_count = 0;

    // Calculer la somme totale des comptages
    for (int count : counts) {
        total_count += count;
    }

    // Calculer les probabilités normalisées
    for (int count : counts) {
        probabilities.push_back(static_cast<float>(count) / total_count);
    }

    return probabilities;
}

// Surcharge de std::hash pour la structure Card
namespace std {
    template<>
    struct hash<Card> {
        size_t operator()(const Card& card) const {
            return card.hash();
        }
    };
}

// Exercice 3
// Implémentation de l'opérateur ==
bool Card::operator==(const Card& other) const {
    return kind == other.kind && value == other.value;
}

// Implémentation de la fonction hash
size_t Card::hash() const {
    // Une fonction de hachage parfaite pour les cartes
    return static_cast<size_t>(kind) * 13 + static_cast<size_t>(value);
}