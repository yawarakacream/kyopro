#include "./template.cpp"

// Union-Find =====================
struct UnionFind {

    int n;
    vi root;

    UnionFind(int n) : n(n), root(vi(n)) {
        rep (i, n) root[i] = i;
    }

    int find(int x) {
        if (root[x] == x) return x;
        return root[x] = find(root[x]);
    }

    void unite(int x, int y) {
        x = find(x), y = find(y);
        if (x == y) return;
        root[y] = x;
    }

    bool same(int x, int y) {
        return find(x) == find(y);
    }

    umap<int, vi> groups() {
        umap<int, vi> ret;
        rep (i, n) ret[find(i)].emplace_back(i);
        return ret;
    }

};
// ================================
