#include "str.hpp"
#include <algorithm> 

size_t getFirstWordLength(std::string const& str) {
    auto const is_space = [](char letter) { return letter == ' '; };

    auto firstNonSpace = std::find_if_not(str.begin(), str.end(), is_space);
    auto firstSpace = std::find_if(firstNonSpace, str.end(), is_space);

    return std::distance(firstNonSpace, firstSpace);
}

std::vector<std::string> splitString(std::string const& str) {
    auto const is_space = [](char letter) { return letter == ' '; };
    std::vector<std::string> words;

    auto it = str.begin();
    while (it != str.end()) {
        it = std::find_if_not(it, str.end(), is_space);
        auto wordEnd = std::find_if(it, str.end(), is_space);

        if (it != str.end()) {
            words.emplace_back(it, wordEnd);
        }

        it = wordEnd;
    }

    return words;
}

bool isPalindrome(std::string const& str) {
    // Utiliser std::equal pour comparer les itérateurs de début et de fin inversée
    return std::equal(str.begin(), str.end(), str.rbegin(), str.rend());
}