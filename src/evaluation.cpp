#include <iostream>
#include "algorithms.h"
#include <chrono>
int main() {
    int n, B, result;
    std::cin >> n >> B;
    std::vector<int> L;
    for (int i = 0; i < n; ++i) {
        int l;
        std::cin >> l;
        L.push_back(l);
    }
    //Next Fit
    auto start = std::chrono::high_resolution_clock::now();
    result = next_fit(L,B);
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    std::cout << result << " " << duration.count() << std::endl;
    //First Fit
    start = std::chrono::high_resolution_clock::now();
    result = first_fit(n,L,B);
    end = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    std::cout << result << " " << duration.count() << std::endl;
    //Best Fit
    start = std::chrono::high_resolution_clock::now();
    result = best_fit(L,B);
    end = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    std::cout << result << " " << duration.count() << std::endl;
    //Harmonic 6
    start = std::chrono::high_resolution_clock::now();
    result = harmonic_6(L,B);
    end = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    std::cout << result << " " << duration.count() << std::endl;
    //Harmonic 12
    start = std::chrono::high_resolution_clock::now();
    result = harmonic_12(L,B);
    end = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    std::cout << result << " " << duration.count() << std::endl;
    //Refined Harmonic
    start = std::chrono::high_resolution_clock::now();
    result = refined_harmonic(L,B);
    end = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    std::cout << result << " " << duration.count() << std::endl;
    return 0;
}