#include "hache.hpp"
#include <functional>
#include <numeric>

const std::vector<Insect> insect_values = {
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

const std::vector<int> expected_insect_counts = {
    75, 50, 100, 20, 400, 150, 60, 10, 40, 90, 5
};

size_t folding_string_hash(const std::string& s, size_t max) {
    size_t hash = 0;
    for (char c : s) {
        hash += static_cast<size_t>(c);
    }
    return hash % max;
}

size_t folding_string_ordered_hash(const std::string& s, size_t max) {
    size_t hash = 0;
    for (size_t i = 0; i < s.size(); ++i) {
        hash += static_cast<size_t>(s[i]) * (i + 1);
    }
    return hash % max;
}

size_t polynomial_rolling_hash(const std::string& s, size_t p, size_t m) {
    size_t hash = 0;
    size_t power = 1;
    for (char c : s) {
        hash = (hash + (static_cast<size_t>(c) * power) % m) % m;
        power = (power * p) % m;
    }
    return hash;
}

std::vector<float> probabilities_from_count(const std::vector<int>& counts) {
    std::vector<float> probabilities;
    int total_count = std::accumulate(counts.begin(), counts.end(), 0);

    for (int count : counts) {
        probabilities.push_back(static_cast<float>(count) / total_count);
    }

    return probabilities;
}

std::vector<Card> get_cards(size_t size) {
    std::vector<Card> cards;
    cards.reserve(size);
    for (size_t i = 0; i < size; ++i) {
        cards.push_back({static_cast<CardKind>(rand() % 4), static_cast<CardValue>(rand() % 13)});
    }
    return cards;
}

std::string card_name(const Card& card) {
    std::string name;

    unsigned int card_value = (static_cast<unsigned int>(card.value) + 2) % 14;

    if (card_value < 10) {
        name += std::to_string(card_value);
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

size_t Card::hash() const {
    // Combine the kind and value into a unique hash
    return static_cast<size_t>(kind) * 13 + static_cast<size_t>(value);
}