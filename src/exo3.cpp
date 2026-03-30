#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include "ScopedTimer.hpp"

bool is_sorted(std::vector<int> const& vec) {
    return std::is_sorted(vec.begin(), vec.end());
}


void bubble_sort(std::vector<int>& vec) {
    for (size_t i = 0; i < vec.size(); i++) {
        for (size_t j = 0; j < vec.size() - 1; j++) {
            if (vec[j] > vec[j + 1]) {
                std::swap(vec[j], vec[j + 1]);
            }
        }
    }
}


size_t partition(std::vector<int>& vec, size_t left, size_t right) {
    int pivot = vec[right];
    size_t i = left;

    for (size_t j = left; j < right; j++) {
        if (vec[j] < pivot) {
            std::swap(vec[i], vec[j]);
            i++;
        }
    }

    std::swap(vec[i], vec[right]);
    return i;
}

void quick_sort(std::vector<int>& vec, size_t left, size_t right) {
    if (left >= right) return;

    size_t p = partition(vec, left, right);

    if (p > 0) quick_sort(vec, left, p - 1);
    quick_sort(vec, p + 1, right);
}

void quick_sort(std::vector<int>& vec) {
    if (!vec.empty()) {
        quick_sort(vec, 0, vec.size() - 1);
    }
}


std::vector<int> generate_random_vector(size_t size) {
    std::vector<int> vec(size);
    for (size_t i = 0; i < size; i++) {
        vec[i] = std::rand() % 100;
    }
    return vec;
}

int main() {
    std::vector<int> base = generate_random_vector(1000);

    
    std::vector<int> v1 = base;
    std::vector<int> v2 = base;
    std::vector<int> v3 = base;

    {
        ScopedTimer timer("bubble_sort");
        bubble_sort(v1);
    }

    {
        ScopedTimer timer("quick_sort");
        quick_sort(v2);
    }

    {
        ScopedTimer timer("std::sort");
        std::sort(v3.begin(), v3.end());
    }

    return 0;
}