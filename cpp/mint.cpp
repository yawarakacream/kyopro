#include "./source.cpp"

// mint ===========================
struct mint {
    static constexpr ll mod = 1000000007; // must be prime

    ll _value;

    mint() : mint(0) {}
    mint(ll value) : _value((value % mod + mod) % mod) {}

    mint& _set(ll value) {
        if (mod <= (_value = value)) {
            if (_value < mod * 2) _value -= mod;
            else _value &= mod;
        }
        return *this;
    }

    mint& operator+=(const mint &y) {
        if (mod <= (_value += y._value)) _value -= mod;
        return *this;
    }
    mint& operator-=(const mint &y) {
        if (mod <= (_value += mod - y._value)) _value -= mod;
        return *this;
    }
    mint& operator*=(const mint &y) {
        if (mod <= (_value *= y._value)) _value %= mod;
        return *this;
    }
    mint& operator/=(const mint &y) {
        _value *= y.inverse()._value; _value %= mod;
        return *this;
    }

    mint& operator++() { _value++; if (_value == mod) { _value = 0; } return *this; }
    mint& operator--() { _value--; if (_value == -1) { _value = mod; } return *this; }

    mint operator-() const { return mint(mod - _value); }
    
    friend mint operator+(const mint &x, const mint &y) { return mint(x) += y; }
    friend mint operator-(const mint &x, const mint &y) { return mint(x) -= y; }
    friend mint operator*(const mint &x, const mint &y) { return mint(x) *= y; }
    friend mint operator/(const mint &x, const mint &y) { return mint(x) /= y; }

    bool operator==(mint &y) { return _value == y._value; }
    bool operator!=(mint &y) { return _value != y._value; }

    mint pow(ll y) const {
        mint t = *this, ret = 1;
        for (; y; y >>= 1) {
            if (y & 1) ret *= t;
            t *= t;
        }
        return ret;
    }
    mint inverse() const { return pow(mod - 2); }
};
istream& operator>>(istream &is, mint &x) { is >> x._value; return is; }
ostream& operator<<(ostream &os, mint x) { return os << x._value; }
// ================================
