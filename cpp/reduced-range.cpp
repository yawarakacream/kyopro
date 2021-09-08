#include "template.cpp"

// ReducedRange ===================
struct ReducedRange {

    int _n;
    vll _v;

    map<ll, int> _m;
    int _size;

    ReducedRange(vll& v) : _v(v) {
        sort(_v);
        _v.erase(unique(all(_v)), _v.end());
        _n = _v.size();
        rep (i, _n) _m[_v[i]] = i;
        _size = int(_m.size());
    }

    int size() {
        return _size;
    }

    int get(ll original) {
        return _m[original];
    }

    // returns i s.t. _v[i - 1] < original <= _v[i] (if i - 1 < 0 then _v[i - 1] => -inf)
    // example: v = [ 0, 2, 4, 6, 8 ], get_as_lower(5) => 3
    int get_as_lower(ll original) {
        return ll(lower_bound(all(_v), original) - _v.begin());
    }

};
// ================================
