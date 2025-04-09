#ifndef HACHE_HPP
#define HACHE_HPP

#include <string>
#include <vector>
#include <unordered_map>
#include <cstddef>

// Déclarations des fonctions de hachage
size_t folding_string_hash(const std::string& s, size_t max);
size_t folding_string_ordered_hash(const std::string& s, size_t max);
size_t polynomial_rolling_hash(const std::string& s, size_t p, size_t m);

// Déclaration de la fonction pour calculer les probabilités
std::vector<float> probabilities_from_count(const std::vector<int>& counts);

// Déclaration des insectes
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

extern const std::vector<Insect> insect_values;
extern const std::unordered_map<Insect, std::string> insect_to_string;
extern const std::vector<int> expected_insect_counts;

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

    size_t hash() const;
};

// Specialization of std::hash for Card
namespace std {
    template <>
    struct hash<Card> {
        std::size_t operator()(const Card& card) const {
            return card.hash();
        }
    };
}

// Fonction pour générer des cartes aléatoires
std::vector<Card> get_cards(size_t size);

// Fonction pour obtenir le nom d'une carte
std::string card_name(const Card& card);

#endif // HACHE_HPP