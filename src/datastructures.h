#ifndef DS_H
#define DS_H

#include <vector>

class Bin {
    public:
    Bin() : level(0), index(0) {}
    Bin(const Bin& b) : level(b.level), index(b.index) {}
    Bin(int l) : level(l), index(0) {}
    Bin(int l, int i) : level(l), index(i) {}
    int index;
    int level;
    bool operator<(const Bin& other) const {
        if (level == other.level)
            return index < other.index;
        return level > other.level;
    }
};

class SegTreeBin {
    public:
    SegTreeBin(int n);
    void update(int idx, int size);
    Bin query(int bound);
    private:
    int n;
    std::vector<Bin> tree;
    void build(int node, int start, int end);
    void update(int node, int start, int end, int idx, int size);
    Bin query(int node, int start, int end, int bound);
};

#endif