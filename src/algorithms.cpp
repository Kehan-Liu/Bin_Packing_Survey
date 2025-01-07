#include "algorithms.h"
#include <vector>
#include <set>
#include <iostream>
#include <functional>

int next_fit(const std::vector<int>& L, int B) {
    std::vector<Bin> bins;
    bins.push_back(Bin());
    for (auto i = L.begin(); i != L.end(); ++i) {
        if (bins.back().level + *i <= B)
            bins.back().level += *i;
        else
            bins.push_back(Bin(*i));
    }
    return bins.size();
}

int first_fit(int n,const std::vector<int>& L, int B) {
    SegTreeBin seg_tree(n);
    for (auto i = L.begin(); i != L.end(); ++i) {
        Bin first = seg_tree.query(B - *i);
        seg_tree.update(first.index, *i);
    }
    return seg_tree.query(0).index;
}

int best_fit(const std::vector<int>& L, int B) {
    std::set<Bin> bins;
    int bin_cnt = 1;
    bins.insert(Bin(0,1));
    for (auto i = L.begin(); i != L.end(); ++i) {
        auto best = bins.lower_bound(Bin(B - *i));
        if (best != bins.end() && best->level + *i <= B) {
            Bin new_bin = *best;
            bins.erase(best);
            new_bin.level += *i;
            bins.insert(new_bin);
        }
        else
            bins.insert(Bin(*i, ++bin_cnt));
    }
    return bins.size();
}

int harmonic_6(const std::vector<int>& L, int B) {
    std::vector<Bin> bins[7];
    for (int i = 1; i <= 6; ++i)
        bins[i].push_back(Bin());
    for (auto i = L.begin(); i != L.end(); ++i) {
        int k = std::min(6, B / *i);
        if (bins[k].back().level + *i <= B)
            bins[k].back().level += *i;
        else
            bins[k].push_back(Bin(*i));
    }
    int result = 0;
    for (int i = 1; i <= 6; ++i) {
        result += bins[i].size();
        if (bins[i].back().level == 0)
            result--;
    }
    return result;
}

int harmonic_12(const std::vector<int>& L, int B) {
    std::vector<Bin> bins[13];
    for (int i = 1; i <= 12; ++i)
        bins[i].push_back(Bin());
    for (auto i = L.begin(); i != L.end(); ++i) {
        int k = std::min(12, B / *i);
        if (bins[k].back().level + *i <= B)
            bins[k].back().level += *i;
        else
            bins[k].push_back(Bin(*i));
    }
    int result = 0;
    for (int i = 1; i <= 12; ++i) {
        result += bins[i].size();
        if (bins[i].back().level == 0)
            result--;
    }
    return result;
}

int refined_harmonic(const std::vector<int>& L, int B) {\
    std::vector<Bin> bins[21], bin_a, bin_b, bin_ab, bin_bb;
    int delta = B * 59 / 96, m_b_prime = 0;
    for (int i = 1; i <= 20; ++i)
        bins[i].push_back(Bin());
    for (auto i = L.begin(); i != L.end(); ++i) {
        int k = std::min(20, B / *i);
        if (k <= 3 || (k == 1 && *i > delta) || (k == 2 && *i > 1 - delta)) {
            if (bins[k].back().level + *i <= B)
                bins[k].back().level += *i;
            else
                bins[k].push_back(Bin(*i));
        }
        else if (k == 1 && *i <= delta) {
            if (bin_b.size() != 0) {
                Bin mix_bin = bin_b.back();
                bin_b.pop_back();
                mix_bin.level += *i;
                bin_ab.push_back(mix_bin);
            }
            else
                bin_a.push_back(Bin(*i));
        }
        else {
            if (m_b_prime) {
                bin_bb.back().level += *i;
                m_b_prime = 0;
            }
            else if (bin_bb.size() <=  3 * (bin_b.size() + bin_ab.size())) {
                    bin_bb.push_back(Bin(*i));
                    m_b_prime = 1;
                }
                else {
                    if (bin_a.size() != 0) {
                        Bin mix_bin = bin_a.back();
                        bin_a.pop_back();
                        mix_bin.level += *i;
                        bin_ab.push_back(mix_bin);
                    }
                    else
                        bin_b.push_back(Bin(*i));
                }
        }
    }
    int result = 0;
    for (int i = 1; i <= 20; ++i) {
        result += bins[i].size();
        if (bins[i].back().level == 0)
            result--;
    }
    result = result + bin_a.size() + bin_b.size() + bin_ab.size() + bin_bb.size();
    return result;
}