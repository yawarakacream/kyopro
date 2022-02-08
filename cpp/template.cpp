#ifdef LOCAL_DEBUG
    #define _GLIBCXX_DEBUG
#endif
#define _unused __attribute__((unused))
#include <bits/stdc++.h>
using namespace std;
template<typename K, typename V> using umap = unordered_map<K, V>;
template<typename T> using pque = priority_queue<T>;
template<typename T> using revpque = priority_queue<T, vector<T>, greater<T>>;
using ll = long long;
using ld = long double;
using str = string;
using pll = pair<ll, ll>;
using pii = pair<int, int>;
using vll = vector<ll>;
using vi = vector<int>;
using vs = vector<str>;
using umapll = umap<ll, ll>;
#define _rep(i, n) _repi(i, 0, n)
#define _repi(i, l, r) for (ll i = ll(l); i < ll(r); i++)
#define _get_rep(_1, _2, _3, NAME, ...) NAME
#define rep(...) _get_rep(__VA_ARGS__, _repi, _rep) (__VA_ARGS__)
#define _rrep(i, n) _rrepi(i, 0, n)
#define _rrepi(i, l, r) for (ll i = ll(r) - 1; l <= i; i--)
#define _get_rrep(_1, _2, _3, NAME, ...) NAME
#define rrep(...) _get_rrep(__VA_ARGS__, _rrepi, _rrep) (__VA_ARGS__)
#define each(...) for (auto& __VA_ARGS__)
#define all(x) x.begin(), x.end()
#define mkpair make_pair
#define mktuple make_tuple
#define is_in(x, l, r) ((l) <= (x) && (x) < (r))
#define in(t, ...) t __VA_ARGS__; cins(__VA_ARGS__)
#define inv(t, v, n) vector<t> v(n); cins(v)
#define inv2(t, v, h, w) vector<vector<t>> v(h, vector<t>(w)); cins(v)
#define invv(t, va, vb, n) vector<t> va(n), vb(n); rep (i, n) { cins(va[i], vb[i]); }
#define invvv(t, va, vb, vc, n) vector<t> va(n), vb(n), vc(n); rep (i, n) { cins(va[i], vb[i], vc[i]); }
#define inln(s) str s; getline(cin, s)
#define print(...) osouts(cout, __VA_ARGS__)
#ifdef LOCAL_DEBUG
    #define debug(...) osouts(cerr, __VA_ARGS__)
#else
    #define debug(...)
#endif
constexpr ll inf = 1001002003004005006LL;
template<typename T> inline bool chmax(T &x, const T &y) { if (x < y) { x = y; return 1; } return 0; }
template<typename T> inline bool chmin(T &x, const T &y) { if (x > y) { x = y; return 1; } return 0; }
template<typename T> inline void sort(vector<T> &v) { sort(all(v)); }
template<typename T> inline void rsort(vector<T> &v) { sort(all(v), greater<T>()); }
template<typename T> inline void unique(vector<T> &v) { v.erase(unique(all(v)), v.end()); }
template<typename T> inline void dec(vector<T> &v) { rep (i, v.size()) v[i]--; }
template<typename T> inline bool bitif(ll bit, ll i) { return (bit >> i) & 1; }
template<typename T> istream& operator>>(istream &is, vector<T> &v) {
    rep (i, v.size()) { is >> v[i]; } return is;
}
template<typename S, typename T> ostream& operator<<(ostream &os, pair<S, T> &p) {
    if (&os == &cout) { os << p.first << ' ' << p.second; }
    if (&os == &cerr) { os << '(' << p.first << ", " << p.second << ')'; }
    return os;
}
template<typename S, typename T> ostream& operator<<(ostream &os, map<S, T> &m) {
    int i = int(m.size()); os << '{';
    each (p : m) { os << p.first << ": " << p.second; if (--i) os << ", "; }
    return os << '}';
}
template<typename S, typename T> ostream& operator<<(ostream &os, umap<S, T> &m) {
    int i = int(m.size()); os << '{';
    each (p : m) { os << p.first << ": " << p.second; if (--i) os << ", "; }
    return os << '}';
}
template<typename T> ostream& operator<<(ostream &os, vector<T> &v) {
    if (v.empty()) { if (&os == &cerr) { os << "[]"; } return os; }
    if (&os == &cout) { rep(i, v.size() - 1) { os << v[i] << ' '; } os << v[v.size() - 1]; }
    if (&os == &cerr) { os << '['; rep(i, v.size() - 1) { os << v[i] << ", "; } os << v[v.size() - 1] << ']'; }
    return os;
}
void cins() {}
template<class S, class... T> void cins(S &s, T&... t) {
    cin >> s; cins(t...);
}
void osouts(ostream& os) { if (&os == &cerr) { os << "\033[49m"; } os << '\n'; }
template<class S, class... T> void osouts(ostream &os, S s, T... t) {
    if (&os == &cerr) os << "\033[44m";
    os << s; if (sizeof...(t)) os << ' '; osouts(os, t...);
}
namespace config {
    int precision;
    void update();
}
void solve();
int main() {
    config::update();

    cin.tie(0);
    ios::sync_with_stdio(false);
    if (config::precision) {
        cout << fixed << setprecision(15);
        cerr << fixed << setprecision(15);
    }

    solve();

    #ifdef LOCAL_DEBUG
        debug("time:", 1000 * clock() / CLOCKS_PER_SEC, "[ms]");
    #endif
}
void config::update() {
    precision = 1;
}

void solve() {
}
