---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/tree/lca.cpp
    title: graph/tree/lca.cpp
  - icon: ':heavy_check_mark:'
    path: template/template.hpp
    title: template/template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/lca
    links:
    - https://judge.yosupo.jp/problem/lca
  bundledCode: "#line 1 \"verify/verify-yosupo-graph/yosupo-lowest-common-ancestor-doubling.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/lca\"\n\n#line 2 \"template/template.hpp\"\
    \n#include <bits/stdc++.h>\nusing ll = long long;\n#define rep(i, n) for (int\
    \ i = 0, i##_len = (n); i < i##_len; ++i)\n#define reps(i, n) for (int i = 1,\
    \ i##_len = (n); i <= i##_len; ++i)\n#define rrep(i, n) for (int i = ((int)(n)-1);\
    \ i >= 0; --i)\n#define rreps(i, n) for (int i = ((int)(n)); i > 0; --i)\n#define\
    \ rep2(i, s, n) for (int i = (s); i < (int)(n); i++)\n#define repc2(i, s, n) for\
    \ (int i = (s); i <= (int)(n); i++)\n#define all(v) begin(v), end(v)\n#define\
    \ rall(v) rbegin(v), rend(v)\nusing namespace std;\n#line 4 \"verify/verify-yosupo-graph/yosupo-lowest-common-ancestor-doubling.test.cpp\"\
    \n//\n#line 2 \"graph/tree/lca.cpp\"\n\ntemplate <typename edge>\nstruct LCA {\n\
    \   private:\n    const vector<vector<edge>> &G;\n    int root, logV;\n    vector<vector<int>>\
    \ _parent;\n    vector<int> _depth;\n\n    void dfs() {\n        _parent.at(0).at(root)\
    \ = -1;\n        _depth.at(root) = 0;\n        stack<int, vector<int>> s;\n  \
    \      s.push(root);\n        while (!s.empty()) {\n            int cur = s.top();\n\
    \            s.pop();\n            for (const auto &e : G.at(cur)) {\n       \
    \         if (e.to != _parent.at(0).at(cur)) {\n                    _parent.at(0).at(e.to)\
    \ = cur;\n                    _depth.at(e.to) = _depth.at(cur) + 1;\n        \
    \            s.push(e.to);\n                }\n            }\n        }\n    }\n\
    \n   public:\n    LCA(const vector<vector<edge>> &G, int root) : G(G), root(root)\
    \ {\n        logV = 1;\n        int _v = 1;\n        while (_v < int(G.size()))\
    \ {\n            _v *= 2;\n            logV++;\n        }\n        _parent = vector<vector<int>>(logV,\
    \ vector<int>(G.size()));\n        _depth = vector<int>(G.size());\n        dfs();\n\
    \        for (int k = 0; k < logV - 1; k++) {\n            for (int v = 0; v <\
    \ int(G.size()); v++) {\n                if (_parent.at(k).at(v) < 0) _parent.at(k\
    \ + 1).at(v) = -1;\n                else _parent.at(k + 1).at(v) = _parent.at(k).at(_parent.at(k).at(v));\n\
    \            }\n        }\n    }\n\n    int query(int u, int v) {\n        if\
    \ (_depth.at(u) > _depth.at(v)) swap(u, v);\n        for (int k = 0; k < logV;\
    \ k++) {\n            if ((_depth.at(v) - _depth.at(u)) >> k & 1) {\n        \
    \        v = _parent.at(k).at(v);\n            }\n        }\n        if (u ==\
    \ v) return u;\n        for (int k = logV - 1; k >= 0; k--) {\n            if\
    \ (_parent.at(k).at(u) != _parent.at(k).at(v)) {\n                u = _parent.at(k).at(u);\n\
    \                v = _parent.at(k).at(v);\n            }\n        }\n        return\
    \ _parent.at(0).at(u);\n    }\n\n    const vector<vector<int>> &parent() { return\
    \ _parent; }\n    const vector<int> &depth() { return _depth; }\n};\n#line 6 \"\
    verify/verify-yosupo-graph/yosupo-lowest-common-ancestor-doubling.test.cpp\"\n\
    \nint main() {\n    ios_base::sync_with_stdio(false);\n    cin.tie(NULL);\n  \
    \  int n, q;\n    cin >> n >> q;\n    struct edge {\n        int to;\n       \
    \ edge(int _to) : to(_to) {}\n    };\n    vector<vector<edge>> G(n);\n    reps(i,\
    \ n - 1) {\n        int p;\n        cin >> p;\n        G[i].emplace_back(p);\n\
    \        G[p].emplace_back(i);\n    }\n\n    LCA<edge> lca(G, 0);\n    rep(i,\
    \ q) {\n        int u, v;\n        cin >> u >> v;\n        cout << lca.query(u,\
    \ v) << '\\n';\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/lca\"\n\n#include \"../../template/template.hpp\"\
    \n//\n#include \"../../graph/tree/lca.cpp\"\n\nint main() {\n    ios_base::sync_with_stdio(false);\n\
    \    cin.tie(NULL);\n    int n, q;\n    cin >> n >> q;\n    struct edge {\n  \
    \      int to;\n        edge(int _to) : to(_to) {}\n    };\n    vector<vector<edge>>\
    \ G(n);\n    reps(i, n - 1) {\n        int p;\n        cin >> p;\n        G[i].emplace_back(p);\n\
    \        G[p].emplace_back(i);\n    }\n\n    LCA<edge> lca(G, 0);\n    rep(i,\
    \ q) {\n        int u, v;\n        cin >> u >> v;\n        cout << lca.query(u,\
    \ v) << '\\n';\n    }\n}\n"
  dependsOn:
  - template/template.hpp
  - graph/tree/lca.cpp
  isVerificationFile: true
  path: verify/verify-yosupo-graph/yosupo-lowest-common-ancestor-doubling.test.cpp
  requiredBy: []
  timestamp: '2025-03-08 18:45:31+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/verify-yosupo-graph/yosupo-lowest-common-ancestor-doubling.test.cpp
layout: document
redirect_from:
- /verify/verify/verify-yosupo-graph/yosupo-lowest-common-ancestor-doubling.test.cpp
- /verify/verify/verify-yosupo-graph/yosupo-lowest-common-ancestor-doubling.test.cpp.html
title: verify/verify-yosupo-graph/yosupo-lowest-common-ancestor-doubling.test.cpp
---
