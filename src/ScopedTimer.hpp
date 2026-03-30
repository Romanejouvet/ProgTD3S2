#pragma once
#include <iostream>
#include <chrono>

class ScopedTimer {
private:
    std::string name;
    std::chrono::steady_clock::time_point start;

public:
    ScopedTimer(const std::string& n) {
        name = n;
        start = std::chrono::steady_clock::now();
    }

    ~ScopedTimer() {
        auto end = std::chrono::steady_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);

        std::cout << name << " : " << duration.count() << " us" << std::endl;
    }
};






