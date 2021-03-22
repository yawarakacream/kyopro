#include "./template.cpp"

/*
 * 閉区間 [0, n] であるので注意
 */

// Binary Indexed Tree ============
template<typename T = ll>
struct BinaryIndexedTree {
    
    int n;
    vector<T> bit;

    BinaryIndexedTree(int n) : n(n), bit(vector<T>(n + 1)) {}

    T sum(int i) {
        T ret = 0;
        for (; 0 < i; i -= i & -i) ret += bit[i];
        return ret;
    }

    void add(int i, T t) {
        for (; i <= n; i += i & -i) bit[i] += t;
    }

};
// ================================
