#include "datastructures.h"

SegTreeBin::SegTreeBin(int n) : n(n) {
    tree.resize(4 * n);
    build(0, 0, n - 1);
}

void SegTreeBin::update(int idx, int size) {
    update(0, 0, n - 1, idx, size);
}

Bin SegTreeBin::query(int bound) {
    return query(0, 0, n - 1, bound);
}

void SegTreeBin::build(int node, int start, int end) {
    if (start == end)
        tree[node] = Bin(0, start);
    else {
        int mid = (start + end) / 2;
        build(2 * node + 1, start, mid);
        build(2 * node + 2, mid + 1, end);
        tree[node] = Bin(0,-1);
    }
}

void SegTreeBin::update(int node, int start, int end, int idx, int size) {
    if (start == end)
        tree[node].level += size;
    else {
        int mid = (start + end) / 2;
        if (idx <= mid)
            update(2 * node + 1, start, mid, idx, size);
        else
            update(2 * node + 2, mid + 1, end, idx, size);
        tree[node].level = std::min(tree[2 * node + 1].level, tree[2 * node + 2].level);
    }
}

Bin SegTreeBin::query(int node, int start, int end, int bound) {
    if (start == end)
        return tree[node];
    int mid = (start + end) / 2;
    if (tree[2 * node + 1].level <= bound)
        return query(2 * node + 1, start, mid, bound);
    return query(2 * node + 2, mid + 1, end, bound);
}