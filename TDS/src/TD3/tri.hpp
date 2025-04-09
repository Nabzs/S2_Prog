#ifndef TRI_HPP
#define TRI_HPP

#include <vector>

void bubble_sort(std::vector<int> &vec);
void selection_sort(std::vector<int> &vec);

size_t quick_sort_partition(std::vector<float> &vec, size_t left, size_t right, size_t const pivot);
void quick_sort(std::vector<float> &vec, size_t const left, size_t const right);
void quick_sort(std::vector<float> &vec);

void merge_sort_merge(std::vector<float> &vec, size_t const left, size_t const middle, size_t const right);
void merge_sort(std::vector<float> &vec, size_t const left, size_t const right);
void merge_sort(std::vector<float> &vec);


int search(const std::vector<int> &vec, int value);


// Aller plsu loin
void counting_sort(std::vector<int> &vec, int const max);
#endif 