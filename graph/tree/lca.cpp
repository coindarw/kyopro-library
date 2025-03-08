#pragma once

template <typename edge>
struct LCA {
   private:
    const vector<vector<edge>> &G;
    int root, logV;
    vector<vector<int>> _parent;
    vector<int> _depth;

    void dfs() {
        _parent.at(0).at(root) = -1;
        _depth.at(root) = 0;
        stack<int, vector<int>> s;
        s.push(root);
        while (!s.empty()) {
            int cur = s.top();
            s.pop();
            for (const auto &e : G.at(cur)) {
                if (e.to != _parent.at(0).at(cur)) {
                    _parent.at(0).at(e.to) = cur;
                    _depth.at(e.to) = _depth.at(cur) + 1;
                    s.push(e.to);
                }
            }
        }
    }

   public:
    LCA(const vector<vector<edge>> &G, int root) : G(G), root(root) {
        logV = 1;
        int _v = 1;
        while (_v < int(G.size())) {
            _v *= 2;
            logV++;
        }
        _parent = vector<vector<int>>(logV, vector<int>(G.size()));
        _depth = vector<int>(G.size());
        dfs();
        for (int k = 0; k < logV - 1; k++) {
            for (int v = 0; v < int(G.size()); v++) {
                if (_parent.at(k).at(v) < 0) _parent.at(k + 1).at(v) = -1;
                else _parent.at(k + 1).at(v) = _parent.at(k).at(_parent.at(k).at(v));
            }
        }
    }

    int query(int u, int v) {
        if (_depth.at(u) > _depth.at(v)) swap(u, v);
        for (int k = 0; k < logV; k++) {
            if ((_depth.at(v) - _depth.at(u)) >> k & 1) {
                v = _parent.at(k).at(v);
            }
        }
        if (u == v) return u;
        for (int k = logV - 1; k >= 0; k--) {
            if (_parent.at(k).at(u) != _parent.at(k).at(v)) {
                u = _parent.at(k).at(u);
                v = _parent.at(k).at(v);
            }
        }
        return _parent.at(0).at(u);
    }

    const vector<vector<int>> &parent() { return _parent; }
    const vector<int> &depth() { return _depth; }
};