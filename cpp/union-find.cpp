#include "./template.cpp"

// Union-Find =====================
struct UnionFind {

    int n;
    vi root;

    UnionFind(int n) : n(n), root(vi(n, -1)) {}

    int find(int x) {
        if (root[x] < 0) return x;
        return root[x] = find(root[x]);
    }

    void unite(int x, int y) {
        x = find(x), y = find(y);
        if (x == y) return;
        if (-root[x] > -root[y]) swap(x, y);
        root[y] += root[x];
        root[x] = y;
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
