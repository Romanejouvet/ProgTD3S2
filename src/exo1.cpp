#include <iostream>
#include <vector>
#include <algorithm>

bool is_sorted(std::vector<int> const& vec) {
    return std::is_sorted(vec.begin(), vec.end());
}

void selection_sort(std::vector<int> &vec) {
    size_t n = vec.size();

    for (size_t i = 0; i < n - 1; i++) {
        size_t min_index = i;

        for (size_t j = i + 1; j < n; j++) {
            if (vec[j] < vec[min_index]) {
                min_index = j;
            }
        }

        if (min_index != i) {
            std::swap(vec[i], vec[min_index]);
        }
    }
}

int main() {
    std::vector<int> array {42, 13, 14, 29, 89, 3, 25, 118, 7, 0};

    selection_sort(array);

    if (is_sorted(array)) {
        std::cout << "Le tableau est trié, youpiiii : ";
    } else {
        std::cout << "Le tableau n'est pas trié naonn : ";
    }

    for (int val : array) {
        std::cout << val << " ";
    }

    std::cout << std::endl;
    return 0;
}