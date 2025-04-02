#ifndef HACHE_HPP
#define HACHE_HPP

#include <string>
#include <vector>
#include <cstddef>
#include <functional>


// Déclarations des fonctions de hachage
size_t folding_string_hash(const std::string& s, size_t max);
size_t folding_string_ordered_hash(const std::string& s, size_t max);
size_t polynomial_rolling_hash(const std::string& s, size_t p, size_t m);

// Déclaration de la fonction pour calculer les probabilités
std::vector<float> probabilities_from_count(const std::vector<int>& counts);

// Déclaration de la structure Card et des fonctions associées
enum class CardKind {
    Heart,
    Diamond,
    Club,
    Spade,
};

enum class CardValue {
    Two,
    Three,
    Four,
    Five,
    Six,
    Seven,
    Eight,
    Nine,
    Ten,
    Jack,
    Queen,
    King,
    Ace,
};

struct Card {
    CardKind kind;
    CardValue value;

    bool operator==(const Card& other) const {
        return kind == other.kind && value == other.value;
    }
};

// Specialization of std::hash for Card
namespace std {
    template <>
    struct hash<Card> {
        std::size_t operator()(const Card& card) const {
            return std::hash<int>()(static_cast<int>(card.kind)) ^ (std::hash<int>()(static_cast<int>(card.value)) << 1);
        }
    };
}

#endif // HACHE_HPP