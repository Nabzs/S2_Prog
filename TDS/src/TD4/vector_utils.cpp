#include "vector_utils.hpp"
#include <iostream>
#include <algorithm>
#include <numeric>
#include <cstdlib>
#include <ctime>

// Exercice 1

void fillVectorWithRandomNumbers(std::vector<int>& vec, int size) {
    vec.resize(size);
    std::srand(static_cast<unsigned>(std::time(nullptr)));
    for (auto& num : vec) {
        num = std::rand() % 101; // Génère un nombre entre 0 et 100
    }
}
void printVector(const std::vector<int>& vec) {
    for (const auto& num : vec) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}

bool findNumberInVector(const std::vector<int>& vec, int number) {
    return std::find(vec.begin(), vec.end(), number) != vec.end();
}

int countOccurrencesInVector(const std::vector<int>& vec, int number) {
    return std::count(vec.begin(), vec.end(), number);
}

void sortVector(std::vector<int>& vec) {
    std::sort(vec.begin(), vec.end());
}

int sumVectorElements(const std::vector<int>& vec) {
    return std::accumulate(vec.begin(), vec.end(), 0);
}
