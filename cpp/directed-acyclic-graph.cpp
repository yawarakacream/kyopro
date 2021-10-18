#include "template.cpp"

/**
 * トポロジカルソート
 * 与えられた有向グラフをもとに頂点に順序を付ける
 * 
 * 一度しか実行できず，結果は is_dag, sorted に格納される
 * DAG (有向非巡回グラフ，directed acyclic graph) のときは順序が付けられない
 * 
 * 複数回実行するには exec, exec_with_priority 内にて _deg をコピーして使えばよい
 * 
 * is_dag: DAG か否か
 * sorted: ソートの結果
 */
// TopologicalSort ================
struct TopologicalSort {
    // graph
    int _n;
    vector<vll> _es;
    vll _deg;

    // result of sort
    bool is_dag;
    vll sorted;

    TopologicalSort(ll n) : _n(n), _es(n), _deg(n) {}

    // O(1)
    void add_edge(ll from, ll to){
        _es[from].emplace_back(to);
        _deg[to]++;
    }

    /**
     * O(n)
     */
    void exec() {
        queue<ll> q;
        rep (i, _n) {
            if (_deg[i] == 0) q.emplace(i);
        }
        while (!q.empty()) {
            ll x = q.front();
            q.pop();
            sorted.emplace_back(x);
            each (y : _es[x]) {
                if (--_deg[y] == 0) q.push(y);
            }
        }
        is_dag = *max_element(_deg.begin(), _deg.end()) == 0;
    }

    /**
     * consider the vertex priority with f
     * 
     * O(n \log n * f(n))
     * @param f default: greater<ll>; lexical order, O(1)
     */
    void exec_with_priority(function<ll(ll, ll)> f = greater<ll>()) {
        priority_queue<ll, vector<ll>, decltype(f)> q(f);
        rep (i, _n) {
            if (_deg[i] == 0) q.emplace(i);
        }
        while (!q.empty()) {
            ll x = q.top();
            q.pop();
            sorted.emplace_back(x);
            each (y : _es[x]) {
                if (--_deg[y] == 0) q.push(y);
            }
        }
        is_dag = *max_element(_deg.begin(), _deg.end()) == 0;
    }
    
};
// ================================

/**
 * 強連結成分分解
 * ret: 各強連結成分毎の頂点の vector の vector
 */
// StronglyConnectedComponent =====
struct StronglyConnectedComponent {

    ll _n;
    vector<vll> _es, _res;

    vi f;
    vll po;

    vector<vll> ret;

    /**
     * O(|V| + |E|)
     * @param n |V|
     * @param es edges
     */
    StronglyConnectedComponent(ll n, vector<vll>& es)
        : _n(n), _es(es), _res(vector<vll>(n)), f(vi(n)) {
        // reversed edges
        rep (x, n) each (y : _es[x]) _res[y].emplace_back(x);
    }

    /**
     * O(|V|)
     */
    void _dfs(ll x) {
        f[x] = 1;
        each (y : _es[x]) {
            if (!f[y]) _dfs(y);
        }
        po.emplace_back(x);
    }

    /**
     * O(|V|)
     */
    void _rdfs(ll x, ll p) {
        f[x] = 0;
        ret[p].emplace_back(x);
        each (y : _res[x]) {
            if (f[y]) _rdfs(y, p);
        }
    }

    /**
     * O(|V|)
     */
    vector<vll> exec() {
        // post order
        rep (x, _n) {
            if (!f[x]) _dfs(x);
        }

        // second check
        ll p = 0;
        rrep (i, _n) {
            ll x = po[i];
            if (f[x]) {
                ret.emplace_back(vll());
                _rdfs(x, p++);
            }
        }

        return ret;
    }

};
// ================================
