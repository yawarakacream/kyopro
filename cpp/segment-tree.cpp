#include "./template.cpp"

/*
 * (experimental)
 * 
 * 0-indexed
 */

// Segment Tree ===================
template<typename T = ll>
struct SegmentTree {

    int n;
    T e;
    function<T(T, T)> calc;
    function<void(T&, T)> assign;
    vector<T> dat;

    SegmentTree(int n_, T e, function<T(T, T)> calc, function<void(T&, T)> assign) : n(1), e(e), calc(calc), assign(assign) {
        while (n < n_) n *= 2;
        dat = vector<T>(n * 2 - 1, e);
    }

    // 初期化用；raw_update 後に必ず init を呼び初期化する
    void raw_update(int i, int x) { dat[i + n - 1] = x; }
    void init() { rrep (i, 0, n - 1) dat[i] = calc(dat[2 * i + 1], dat[2 * i + 2]); }

    // i 番目の要素を x を用いて更新
    void update(int i, int x) {
        i += n - 1;
        assign(dat[i], x);
        while (i > 0) {
            i = (i - 1) / 2;
            dat[i] = calc(dat[2 * i + 1], dat[2 * i + 2]);
        }
    }

    // 区間の calc の値を返す
    T query(int i) { return query(i, i + 1); }
    T query(int a, int b) { return query(a, b, 0, 0, n); }
    T query(int a, int b, int k, int l, int r) {
        if (r <= a || b <= l) return inf;
        if (a <= l && r <= b) return dat[k];
        return calc(query(a, b, k * 2 + 1, l, (l + r) / 2), query(a, b, k * 2 + 2, (l + r) / 2, r));
    }

    // (experimental) 値が x の index を返す．[l, r) 内に x の要素がなければならない
    int find(T x, int l, int r) {
        if (r - l <= 1) return x == query(l) ? l : -1;
        T p = query(l, (l + r) / 2), q = query((l + r) / 2, r);
        if (x == p) return find(x, l, (l + r) / 2);
        if (x == q) return find(x, (l + r) / 2, r);
        return -1;
    }

};
template<typename T> ostream& operator<<(ostream &os, SegmentTree<T> &seg) {
    assert(&os == &cerr);
    os << "ST(n=" << seg.n << ")["; rep (i, seg.n - 1) cout << seg.query(i, i + 1) << ", "; return os << seg.query(seg.n - 1, seg.n) << ']';
    // return os << "ST(n=" << seg.n << ')' << seg.dat;
}
// Range Minimum Query ll
SegmentTree<ll> rmq(int n) {
    return SegmentTree<ll>(n, inf, [](ll x1, ll x2) { return min(x1, x2); }, [](ll& d, ll x) { d = x; });
}
// ================================
