#define PROBLEM "https://judge.yosupo.jp/problem/lca"

#include "../../template/template.hpp"
//
#include "../../graph/tree/lca.cpp"

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, q;
    cin >> n >> q;
    struct edge {
        int to;
        edge(int _to) : to(_to) {}
    };
    vector<vector<edge>> G(n);
    reps(i, n - 1) {
        int p;
        cin >> p;
        G[i].emplace_back(p);
        G[p].emplace_back(i);
    }

    LCA<edge> lca(G, 0);
    rep(i, q) {
        int u, v;
        cin >> u >> v;
        cout << lca.query(u, v) << '\n';
    }
}
