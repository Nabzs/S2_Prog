#include "tri.hpp"
#include <algorithm>
#include <iostream>
#include <vector>

// Bubble Sort
void bubble_sort(std::vector<int> &vec) {
    bool swapped;
    int iterations = 0;
    for (size_t i = 0; i < vec.size() - 1; ++i) {
        swapped = false;
        for (size_t j = 0; j < vec.size() - i - 1; ++j) {
            ++iterations;
            if (vec[j] > vec[j + 1]) {
                std::swap(vec[j], vec[j + 1]);
                swapped = true;
            }
        }
        if (!swapped) {
            break;
        }
    }
    std::cout << "Nb iterations tri a bulle : " << iterations << std::endl;
}

// Selection Sort
void selection_sort(std::vector<int> &vec) {
    int iterations = 0;
    for (size_t i = 0; i < vec.size() - 1; ++i) {
        size_t min_index = i;
        for (size_t j = i + 1; j < vec.size(); ++j) {
            ++iterations;
            if (vec[j] < vec[min_index]) {
                min_index = j;
            }
        }
        if (min_index != i) {
            std::swap(vec[i], vec[min_index]);
        }
    }
    std::cout << "Nb iterations tri par selection : " << iterations << std::endl;
}

// Quick Sort Partition
size_t quick_sort_partition(std::vector<float> &vec, size_t left, size_t right, size_t const pivot, int &iterations) {
    float pivot_value = vec[pivot];
    std::swap(vec[pivot], vec[right]);
    size_t store_index = left;
    for (size_t i = left; i < right; ++i) {
        ++iterations;
        if (vec[i] < pivot_value) {
            std::swap(vec[i], vec[store_index]);
            ++store_index;
        }
    }
    std::swap(vec[store_index], vec[right]);
    return store_index;
}

// Quick Sort
void quick_sort(std::vector<float> &vec, size_t const left, size_t const right, int &iterations) {
    if (left < right) {
        size_t pivot = left + (right - left) / 2;
        size_t new_pivot = quick_sort_partition(vec, left, right, pivot, iterations);
        if (new_pivot > 0) {
            quick_sort(vec, left, new_pivot - 1, iterations);
        }
        quick_sort(vec, new_pivot + 1, right, iterations);
    }
}

void quick_sort(std::vector<float> &vec) {
    int iterations = 0;
    if (!vec.empty()) {
        quick_sort(vec, 0, vec.size() - 1, iterations);
    }
    std::cout << "Nb iterations Tri rapide : " << iterations << std::endl;
}

// Merge Sort Merge
void merge_sort_merge(std::vector<float> &vec, size_t const left, size_t const middle, size_t const right, int &iterations) {
    std::vector<float> left_vec(vec.begin() + left, vec.begin() + middle + 1);
    std::vector<float> right_vec(vec.begin() + middle + 1, vec.begin() + right + 1);

    size_t left_index = 0, right_index = 0, merge_index = left;
    while (left_index < left_vec.size() && right_index < right_vec.size()) {
        ++iterations;
        if (left_vec[left_index] <= right_vec[right_index]) {
            vec[merge_index++] = left_vec[left_index++];
        } else {
            vec[merge_index++] = right_vec[right_index++];
        }
    }

    while (left_index < left_vec.size()) {
        vec[merge_index++] = left_vec[left_index++];
    }

    while (right_index < right_vec.size()) {
        vec[merge_index++] = right_vec[right_index++];
    }
}

// Merge Sort
void merge_sort(std::vector<float> &vec, size_t const left, size_t const right, int &iterations) {
    if (left < right) {
        size_t middle = left + (right - left) / 2;
        merge_sort(vec, left, middle, iterations);
        merge_sort(vec, middle + 1, right, iterations);
        merge_sort_merge(vec, left, middle, right, iterations);
    }
}

void merge_sort(std::vector<float> &vec) {
    int iterations = 0;
    if (!vec.empty()) {
        merge_sort(vec, 0, vec.size() - 1, iterations);
    }
    std::cout << "Nb iterations Tri fusion : " << iterations << std::endl;
}

// Binary Search (Dichotomie)
int search(const std::vector<int> &vec, int value) {
    size_t left = 0;
    size_t right = vec.size() - 1;

    while (left <= right) {
        size_t middle = left + (right - left) / 2;

        if (vec[middle] == value) {
            return middle; // Value found
        } else if (vec[middle] < value) {
            left = middle + 1; // Search in the right half
        } else {
            right = middle - 1; // Search in the left half
        }
    }

    return -1; // Value not found
}