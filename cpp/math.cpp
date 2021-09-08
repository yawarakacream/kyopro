#include "template.cpp"

// floor(log_e(x))
ll floorlog(ll e, ll x) {
    if (e < 2 || x == 0) return -1;
    ll ans = 0, p = e;
    while (p <= x) {
        ans++;
        p *= e;
    }
    return ans;
}

/**
 * T: 計算の型
 * M: 最大値
 */

// Combination ====================
template<typename T, int M>
struct Combination {

    array<T, M + 1> _fac;

    // O(M)
    Combination() : _fac(array<T, M + 1>()) {
        _fac[0] = _fac[1] = 1;
        rep (i, 2, M + 1) _fac[i] = _fac[i] * i;
    }

    // O(1)
    T factorial(int n) {
        return n < 0 ? 0 : _fac[n];
    }

    // O(1)
    T nPr(int n, int r) {
        return n < r ? 0 : (_fac[n] / _fac[n - r]);
    }

    // O(1)
    T nCr(int n, int r) {
        return n < r ? 0 : (_fac[n] / (_fac[n - r] * _fac[r]));
    }

};
// ================================

/**
 * M: 最大値
 */

// Sieve of Eratosthenes ==========
template<int M>
struct ESieve {

    array<bool, M + 1> _p;
    array<int, M + 1> _d;

    // O(M log log M)
    ESieve() : _p(array<bool, M + 1>()), _d(array<int, M + 1>()) {
        _p.fill(true); _p[0] = _p[1] = false;
        _d[0] = -1; _d[1] = 1;
        rep (i, 2, M + 1) {
            if (!_p[i]) continue;
            _d[i] = i;
            for (int j = i * 2; j <= M; j += i) {
                if (!_p[j]) continue;
                _p[j] = false;
                _d[j] = i;
            }
        }
    }

    bool is_prime(int n) {
        assert(n <= M);
        return _p[n];
    }

    // O(log log n)
    map<int, int> factorization(int n) {
        assert(n <= M);
        map<int, int> ret;
        while (n > 1) {
            ret[_d[n]]++;
            if (_p[n]) break;
            n /= _d[n];
        }
        return ret;
    }
    
};
// ================================
