#include "template.cpp"
#include "union-find.cpp"

/**
 * 幅優先探索
 */
vll breadth_first_search(ll start, vector<vll>& es) {
    queue<ll> q;
    vll d(es.size(), -1);
    auto emp = [&](ll x, ll c) {
        if (d[x] != -1) return;
        d[x] = c;
        q.emplace(x);
    };
    emp(start, 0);
    while (!q.empty()) {
        ll& x = q.front(); q.pop();
        each (y : es[x]) emp(y, d[x] + 1);
    }
    return d;
}

/**
 * 深さ優先探索
 */
vll depth_first_search(ll start, vector<vll>& es) {
    stack<ll> q;
    vll d(es.size(), -1);
    auto emp = [&](ll x, ll c) {
        if (d[x] != -1) return;
        d[x] = c;
        q.emplace(x);
    };
    emp(start, 0);
    while (!q.empty()) {
        ll& x = q.top(); q.pop();
        each (y : es[x]) emp(y, d[x] + 1);
    }
    return d;
}

/**
 * Dijkstra 法：最短経路を求める
 * 
 * @param es 辺；es[from]: pair<to, cost>[]
 * @return 各点 v までの pair<cost, from>
 */
vector<pll> dijkstra(ll n, ll start, vector<vector<pll>>& es) {
    vector<pll> d(n, mkpair(-1, -1));
    revpque<tuple<ll, ll, ll>> q;

    auto emp = [&](ll x, ll c, ll from) {
        if (d[x].first != -1) return;
        q.emplace(make_tuple(c, x, from));
    };
    emp(start, 0, -1);
    while (!q.empty()) {
        auto [c, x, from] = q.top(); q.pop();
        if (d[x].first != -1) continue;
        d[x].first = c; d[x].second = from;
        each ([x2, c2] : es[x]) emp(x2, c + c2, x);
    }

    return d;
};

/**
 * Dijkstra 法の結果より v から result が 0 の点までの経路を求める
 */
vll dijkstra_route(ll v, vector<pll>& result, vector<vector<pll>>& es) {
    vll ans { v };
    while (1) {
        auto [x, from] = result[ans[ans.size() - 1]];
        if (from == -1) break;
        ans.emplace_back(from);
    }
    reverse(all(ans));
    return ans;
}

/**
 * Kruskal 法：最小全域木を求める
 * 
 * O(E log V)
 * @param edges edges[from]: pair<to, cost>[]
 * @return edges[from]: pair<pair<to, cost>, sum of cost>[]
 */
pair<vector<vector<pll>>, ll> kruskal(vector<vector<pll>>& edges) {
    ll n = (ll) edges.size();
    UnionFind uf(n);
    ll s = 0;
    vector<vector<pll>> ret(n);

    vector<tuple<ll, ll, ll>> v;
    rep (f, n) each ([t, c] : edges[f]) {
        v.emplace_back(make_tuple(c, f, t));
    }
    sort(v);
    
    each ([c, x, y] : v) {
        if (uf.same(x, y)) continue;
        uf.unite(x, y);
        ret[x].emplace_back(mkpair(y, c));
        s += c;
    }
    return mkpair(ret, s);
}

/**
 * Ford-Fulkerson 法：最大流を求める
 */
struct FordFulkerson {

    ll _n;
    vector<vector<tuple<ll, ll, ll>>> _es;

    ll _t;
    vector<bool> _u;

    /**
     * @param es es[from]: pair<to, capacity>[]
     */
    FordFulkerson(vector<vector<pll>>& es)
        : _n(ll(es.size())),
          _es(vector<vector<tuple<ll, ll, ll>>>(_n)),
          _u(vector<bool>(_n)) {
        rep (x, _n) each ([y, c] : es[x]) {
            _es[x].emplace_back(mktuple(y, c, _es[y].size()));
            _es[y].emplace_back(mktuple(x, 0, _es[x].size() - 1));
        }
    }

    ll _dfs(ll s, ll f) {
        if (s == _t) return f;
        _u[s] = true;
        each ([s2, c, r] : _es[s]) {
            if (_u[s2] || c <= 0) continue;
            ll p = _dfs(s2, min(f, c));
            if (p <= 0) continue;
            c -= p;
            get<1>(_es[s2][r]) += p;
            return p;
        }
        return 0;
    }

    /**
     * O(f|E|)
     * @param s source；始点
     * @param t sink；終点
     */
    ll exec(ll s, ll t) {
        _t = t;
        ll ans = 0;
        while (1) {
            fill(all(_u), false);
            ll add = _dfs(s, inf);
            if (add == 0) return ans;
            ans += add;
        }
    }

};
