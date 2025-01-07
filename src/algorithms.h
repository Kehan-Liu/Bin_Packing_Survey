#ifndef ALGORITHMS_H
#define ALGORITHMS_H
#include <vector>
#include "datastructures.h"

int next_fit(const std::vector<int>& L, int B);

int first_fit(int n,const std::vector<int>& L, int B);

int best_fit(const std::vector<int>& L, int B);

int harmonic_6(const std::vector<int>& L, int B);

int harmonic_12(const std::vector<int>& L, int B);

int refined_harmonic(const std::vector<int>& L, int B);

#endif