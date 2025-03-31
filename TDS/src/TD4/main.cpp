#include "vector_utils.hpp"
#include "str.hpp"

#include <iostream>

int main() {
    // Exercice 1 : Vecteurs
    std::vector<int> numbers;

    fillVectorWithRandomNumbers(numbers, 20);

    std::cout << "Contenu du vecteur : ";
    printVector(numbers);

    int searchNumber;
    std::cout << "Entrez un nombre a chercher : ";
    std::cin >> searchNumber;

    if (findNumberInVector(numbers, searchNumber)) {
        std::cout << "Le nombre " << searchNumber << " est present dans le vecteur." << std::endl;
    } else {
        std::cout << "Le nombre " << searchNumber << " n'est pas present dans le vecteur." << std::endl;
    }

    int countNumber;
    std::cout << "Entrez un nombre pour compter ses occurrences : ";
    std::cin >> countNumber;

    int count = countOccurrencesInVector(numbers, countNumber);
    std::cout << "Le nombre " << countNumber << " apparait " << count << " fois dans le vecteur." << std::endl;

    sortVector(numbers);
    std::cout << "Vecteur trie : ";
    printVector(numbers);

    int sum = sumVectorElements(numbers);
    std::cout << "La somme des elements du vecteur est : " << sum << std::endl;
    std::cout << std::endl;

    // Exercice 2 : Chaînes de caractères
    std::cout << "Exercice 2 :" << std::endl;
    std::cin.ignore();
    std::string phrase;
    std::cout << "Entrez une phrase : ";
    std::getline(std::cin, phrase);

    size_t firstWordLength = getFirstWordLength(phrase);
    std::cout << "La longueur du premier mot est : " << firstWordLength << std::endl;

    std::vector<std::string> words = splitString(phrase);
    std::cout << "Les mots de la phrase sont : ";
    for (const auto& word : words) {
        std::cout << "[" << word << "] ";
    }
    std::cout << std::endl;

    // Exercice 3 : Palindrome
    std::cout << "\nExercice 3 : Palindrome" << std::endl;
    std::cout << "Entrez une chaine de caracteres : ";
    std::string palindromeTest;
    std::getline(std::cin, palindromeTest);

    if (isPalindrome(palindromeTest)) {
        std::cout << palindromeTest << "\" est un palindrome." << std::endl;
    } else {
        std::cout << palindromeTest << "\" n'est pas un palindrome." << std::endl;
    }

    return 0;
}