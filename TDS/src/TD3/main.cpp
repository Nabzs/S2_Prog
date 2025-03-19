#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include "tri.hpp"
#include "ScopedTimer.hpp"

void print_vector(const std::vector<int>& vec) {
    for (int num : vec) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}

void print_vector(const std::vector<float>& vec) {
    for (float num : vec) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}

std::vector<int> random_tabl(size_t const size, int const max = 100) {
    std::vector<int> vec(size);
    std::generate(vec.begin(), vec.end(), [&max]() { return std::rand() % max; });
    return vec;
}

int main() {
    // Ex1
    std::vector<int> vec1 = {11, 12, 22, 25, 34, 64, 90}; // déjà trié
    std::vector<int> vec2 = vec1;

    std::cout << std::endl;
    std::cout << "Exercice 1 : " << std::endl;
    std::cout << std::endl;

    std::cout << "Tableau : ";
    print_vector(vec1);
    std::cout << std::endl;

    {
        ScopedTimer timer("Tri a bulle");
        bubble_sort(vec1);
    }
    std::cout << "Tri a bulle : ";
    print_vector(vec1);
    std::cout << std::endl;

    {
        ScopedTimer timer("Tri par selection");
        selection_sort(vec2);
    }
    std::cout << "Tri par selection : ";
    print_vector(vec2);
    std::cout << std::endl;

    // Ex2
    std::cout << "Exercice 2 : " << std::endl;
    std::cout << std::endl;

    std::vector<float> vec3 = {64.0, 34.0, 25.0, 12.0, 22.0, 11.0, 90.0};
    std::vector<float> vec4 = vec3;

    std::cout << "Tableau (float) : ";
    print_vector(vec3);
    std::cout << std::endl;

    {
        ScopedTimer timer("Tri rapide");
        quick_sort(vec3);
    }
    std::cout << "Tri rapide : ";
    print_vector(vec3);
    std::cout << std::endl;

    {
        ScopedTimer timer("Tri fusion");
        merge_sort(vec4);
    }
    std::cout << "Tri fusion : ";
    print_vector(vec4);
    std::cout << std::endl;

    // Ex3
    std::cout << "Exercice 3 : " << std::endl;
    std::cout << std::endl;

    std::vector<int> random_vec = random_tabl(1000);

    std::vector<int> vec_bubble = random_vec;
    std::vector<int> vec_selection = random_vec;
    std::vector<int> vec_std_sort = random_vec;

    {
        ScopedTimer timer("Tri a bulles (tableau aleatoire)");
        bubble_sort(vec_bubble);
    }
    std::cout << std::endl;

    {
        ScopedTimer timer("Tri par selection (tableau aleatoire)");
        selection_sort(vec_selection);
    }
    std::cout << std::endl;

    {
        ScopedTimer timer("std::sort (tableau aleatoire)");
        std::sort(vec_std_sort.begin(), vec_std_sort.end());
    }
    std::cout << std::endl;

    return 0;
}