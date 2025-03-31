#ifndef UTILS_HPP
#define UTILS_HPP

#include <vector>
#include <string>

// Exercice 1
void fillVectorWithRandomNumbers(std::vector<int>& vec, int size);
void printVector(const std::vector<int>& vec);
bool findNumberInVector(const std::vector<int>& vec, int number);
int countOccurrencesInVector(const std::vector<int>& vec, int number);
void sortVector(std::vector<int>& vec);
int sumVectorElements(const std::vector<int>& vec);
#endif