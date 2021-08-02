#include "./template.cpp"

/*
 * (experimental)
 * 
 * 0-indexed
 */

// Lazy Segment Tree ==============
template<typename T = ll>
struct LazySegmentTree {
    
    // 要素数
    int n;
    // 単位元
    T e;
    vector<T> dat, lazy;

    LazySegmentTree(int n_, T e) : e(e) {
        n = 1; while (n < n_) n *= 2;
        dat = vector<T>(n * 2 - 1, e);
        lazy = vector<T>(n * 2 - 1, e);
    }

    // [a, b) 番目の要素を x を用いて更新
    void update(int i, T x) { update(i, i + 1, x); }
    void update(int a, int b, T x) { update(a, b, x, 0, 0, n); }
    void update(int a, int b, T x, int k, int l, int r) {
        apply(k);
        if (a <= l && r <= b) {
            lazy[k] = assignLazy(lazy[k], x, l, r);
            apply(k);
        }
        else if (a < r && l < b) {
            update(a, b, x, k * 2 + 1, l, (l + r) / 2);
            update(a, b, x, k * 2 + 2, (l + r) / 2, r);
            dat[k] = calc(dat[k * 2 + 1], dat[k * 2 + 2]);
        }
    }

    // lazy を dat に適用
    void apply(int k) {
        if (lazy[k] == e) return;
        if (k < n - 1) {
            lazy[k * 2 + 1] = propagate(lazy[k], lazy[k * 2 + 1]);
            lazy[k * 2 + 2] = propagate(lazy[k], lazy[k * 2 + 2]);
        }
        dat[k] = assignDat(dat[k], lazy[k]);
        lazy[k] = e;
    }

    // 区間の calc の値を返す
    T query(int i) { return query(i, i + 1); }
    T query(int a, int b) { return query(a, b, 0, 0, n); }
    T query(int a, int b, int k, int l, int r) {
        apply(k);
        if (r <= a || b <= l) return e;
        if (a <= l && r <= b) return dat[k];
        return calc(
            query(a, b, k * 2 + 1, l, (l + r) / 2),
            query(a, b, k * 2 + 2, (l + r) / 2, r)
        );
    }

    // dat から親の値を計算する
    virtual T calc(T dat1, T dat2) = 0;

    // 親から子に伝播させる値を返す
    virtual T propagate(T parent, T child) = 0;

    // lazy に dat を割り当てたあとの dat を返す
    virtual T assignDat(T dat, T lazy) = 0;

    // lazy に x が与えられたとき，lazy に設定する値を返す
    virtual T assignLazy(T lazy, T x, int l, int r) = 0;

};
template<typename T> ostream& operator<<(ostream &os, LazySegmentTree<T> &seg) {
    assert(&os == &cerr);
    // return os << "ST(n=" << seg.n << ')' << seg.dat;
    os << "LST(n=" << seg.n << ")["; rep (i, seg.n - 1) cout << seg.query(i, i + 1) << ", ";
    return os << seg.query(seg.n - 1, seg.n) << ']';
}
// ================================

// Range Minimum Query ============
template<typename T>
struct RangeMinimumQuery : public LazySegmentTree<T> {

    RangeMinimumQuery(int n, T e) : LazySegmentTree<T>(n, e) {}

    T calc(T dat1, T dat2) override { return min(dat1, dat2); }
    T propagate(T parent, _unused T child) override { return parent; }
    T assignDat(_unused T dat, T lazy) override { return lazy; }
    T assignLazy(_unused T lazy, T x, _unused int l, _unused int r) override { return x; }

    // (experimental) 値が x の index を返す．[l, r) 内に x の要素がなければならない
    int find(T x, int l, int r) {
        if (r - l <= 1) return x == LazySegmentTree<T>::query(l) ? l : -1;
        if (x == LazySegmentTree<T>::query(l, (l + r) / 2)) return find(x, l, (l + r) / 2);
        if (x == LazySegmentTree<T>::query((l + r) / 2, r)) return find(x, (l + r) / 2, r);
        return -1;
    }
    
};
RangeMinimumQuery<ll> rmqll(int n) { return RangeMinimumQuery<ll>(n, inf); }
// ================================

// Range Add Query ================
template<typename T>
struct RangeAddQuery : public LazySegmentTree<T> {

    RangeAddQuery(int n, T e) : LazySegmentTree<T>(n, e) {}

    T calc(T dat1, T dat2) override { return dat1 + dat2; }
    T propagate(T parent, T child) override { return child + parent / 2; }
    T assignDat(T dat, T lazy) override { return dat + lazy; }
    T assignLazy(T lazy, T x, int l, int r) override { return lazy + (r - l) * x; }

};
RangeAddQuery<ll> raqll(int n) { return RangeAddQuery<ll>(n, 0LL); }
// ================================
