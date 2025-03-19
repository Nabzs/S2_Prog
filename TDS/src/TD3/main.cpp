#include <iostream>
#include <vector>
#include "tri.hpp"

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

int main() {
     //Ex1
     std::vector<int> vec1 = {11, 12, 22, 25, 34, 64, 90}; // déjà trié (permet de voir la différence entre tri à bulle et le tri par sélection et dans quel cas l'un est plus intéressant que l'autre)
     // std::vector<int> vec2 = {64, 34, 25, 12, 22, 11, 90};   // A tester avec ce tableau pour voir la diff
     std::vector<int> vec2 = vec1;  

    std::cout << std::endl;
    std::cout << "Exercice 1 : " << std::endl;

    std::cout << std::endl;

    std::cout << "Tableau : ";
    print_vector(vec1);

    std::cout << std::endl;

    bubble_sort(vec1);
    std::cout << "Tri a bulle : ";
    print_vector(vec1);

    std::cout << std::endl;

    selection_sort(vec2);
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

    quick_sort(vec3);
    std::cout << "Tri rapide : ";
    print_vector(vec3);
    
    std::cout << std::endl;

    merge_sort(vec4);
    std::cout << "Tri fusion : ";
    print_vector(vec4);

    std::cout << std::endl;

    return 0;
}