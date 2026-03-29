#include <iostream>
#include <vector>
#include <algorithm>

bool is_sorted(std::vector<int> const& vec) {
    return std::is_sorted(vec.begin(), vec.end());
}

void merge_sort_merge(std::vector<int>& vec, size_t left, size_t middle, size_t right) {
    
    std::vector<int> temp(vec.begin() + left, vec.begin() + right + 1);

    size_t i = 0;                        
    size_t j = middle - left + 1;        
    size_t k = left;                       

    while (i <= middle - left && j <= right - left) {
        if (temp[i] < temp[j]) {
            vec[k++] = temp[i++];
        } else {
            vec[k++] = temp[j++];
        }
    }

   
    while (i <= middle - left) {
        vec[k++] = temp[i++];
    }

    
    while (j <= right - left) {
        vec[k++] = temp[j++];
    }
}

void merge_sort(std::vector<int>& vec, size_t left, size_t right) {
    if (left >= right) return;

    size_t middle = (left + right) / 2;

    merge_sort(vec, left, middle);
    merge_sort(vec, middle + 1, right);

    merge_sort_merge(vec, left, middle, right);
}

void merge_sort(std::vector<int>& vec) {
    if (!vec.empty()) {
        merge_sort(vec, 0, vec.size() - 1);
    }
}

int main() {
    std::vector<int> array {9, 3, 7, 1, 5, 12, 13, 16, 29, 63,0};

    merge_sort(array);

    std::cout << "Tableau trié, youpi : ";
    for (int x : array) {
        std::cout << x << " ";
    }
    std::cout << std::endl;

    return 0;
}




