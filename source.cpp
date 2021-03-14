#ifdef LOCAL_DBG
    #define _GLIBCXX_DEBUG
#endif
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
#define _rrep(i, n) for (ll i = ll(n) - 1; 0 <= i; i--)
#define _rrepi(i, l, r) for (ll i = ll(r) - 1; l <= i; i--)
#define _get_rrep(_1, _2, _3, NAME, ...) NAME
#define rrep(...) _get_rrep(__VA_ARGS__, _rrepi, _rrep) (__VA_ARGS__)
#define each(...) for (auto __VA_ARGS__)
#define all(x) x.begin(), x.end()
#define mkpair make_pair
#define is_in(x, l, r) ((l) <= (x) && (x) < (r))
#define in(t, ...) t __VA_ARGS__; isin(cin, __VA_ARGS__)
#define inv(t, v, n) vector<t> v(n); isin(cin, v)
#define inv2(t, v, h, w) vector<vector<t>> v(h, vector<t>(w)); isin(cin, v)
#define invv(t, va, vb, n) vector<t> va(n), vb(n); rep (i, n) { isin(cin, va[i], vb[i]); }
#define invvv(t, va, vb, vc, n) vector<t> va(n), vb(n), vc(n); rep (i, n) { isin(cin, va[i], vb[i], vc[i]); }
#define inln(s) str s; getline(cin, s)
#define print(...) osout(cout, __VA_ARGS__)
#ifdef LOCAL_DBG
    #define debug(...) osout(cerr, __VA_ARGS__)
#else
    #define debug(...)
#endif
constexpr ll inf = 1001002003004005006LL;
template<typename T> inline bool chmax(T &x, const T &y) { if (x < y) { x = y; return 1; } return 0; }
template<typename T> inline bool chmin(T &x, const T &y) { if (x > y) { x = y; return 1; } return 0; }
template<typename T> inline void sort(vector<T> &v) { sort(all(v)); }
template<typename T> inline void rsort(vector<T> &v) { sort(all(v), greater<T>()); }
template<typename T> inline void dec(vector<T> &v) { rep (i, v.size()) v[i]--; }
template<typename T> istream& operator>>(istream &is, vector<T> &v) {
    rep (i, v.size()) { is >> v[i]; } return is;
}
template<typename T1, typename T2> ostream& operator<<(ostream &os, pair<T1, T2> p) {
    if (&os == &cout) { os << p.first << ' ' << p.second; }
    if (&os == &cerr) { os << '(' << p.first << ", " << p.second << ')'; }
    return os;
}
template<typename T> ostream& operator<<(ostream &os, vector<T> v) {
    if (v.empty()) { os << "[]"; return os; }
    if (&os == &cout) { rep(i, v.size() - 1) { os << v[i] << ' '; } os << v[v.size() - 1]; }
    if (&os == &cerr) { os << '['; rep(i, v.size() - 1) { os << v[i] << ", "; } os << v[v.size() - 1] << ']'; }
    return os;
}
void isin(__attribute__((unused)) istream &_) {}
template<class S, class... T> void isin(istream &is, S &s, T&... t) {
    is >> s; isin(is, t...);
}
void osout(ostream& os) { os << '\n'; }
template<class S, class... T> void osout(ostream &os, S s, T... t) {
    os << s; if (sizeof...(t)) os << ' '; osout(os, t...);
}
namespace config {
    int precision;
    int infinity;
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

    #ifdef LOCAL_DBG
        debug("time:", 1000 * clock() / CLOCKS_PER_SEC, "[ms]");
    #endif
}
void config::update() {
    precision = 0;
}

void solve() {
}
