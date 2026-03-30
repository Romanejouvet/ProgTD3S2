#include <iostream>
#include <vector>


int search(const std::vector<int>& vec, int value) {
    int left = 0;
    int right = vec.size() - 1;

    while (left <= right) {
        int middle = (left + right) / 2;

        if (vec[middle] == value) {
            return middle;
        }
        else if (vec[middle] < value) {
            left = middle + 1;
        }
        else {
            right = middle - 1;
        }
    }

    return -1; 
}

int main() {
    std::vector<int> array1 {1, 2, 2, 3, 4, 8, 12};
    std::vector<int> array2 {1, 2, 3, 3, 6, 12, 14, 15}; 
    std::vector<int> array3 {2, 2, 3, 4, 5, 8, 12, 15, 16};
    std::vector<int> array4 {5, 6, 7, 8, 9, 10, 11, 12, 13};
    std::vector<int> array5 {1, 2, 3, 4, 5, 6, 7, 8, 9};

    std::cout << search(array1, 8) << std::endl;   
    std::cout << search(array2, 15) << std::endl;  
    std::cout << search(array3, 16) << std::endl;  
    std::cout << search(array4, 6) << std::endl;   
    std::cout << search(array5, 10) << std::endl;  

    return 0;
}
