---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-graph/yosupo-lowest-common-ancestor-doubling.test.cpp
    title: verify/verify-yosupo-graph/yosupo-lowest-common-ancestor-doubling.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"graph/tree/lca.cpp\"\n\ntemplate <typename edge>\nstruct\
    \ LCA {\n   private:\n    const vector<vector<edge>> &G;\n    int root, logV;\n\
    \    vector<vector<int>> _parent;\n    vector<int> _depth;\n\n    void dfs() {\n\
    \        _parent.at(0).at(root) = -1;\n        _depth.at(root) = 0;\n        stack<int,\
    \ vector<int>> s;\n        s.push(root);\n        while (!s.empty()) {\n     \
    \       int cur = s.top();\n            s.pop();\n            for (const auto\
    \ &e : G.at(cur)) {\n                if (e.to != _parent.at(0).at(cur)) {\n  \
    \                  _parent.at(0).at(e.to) = cur;\n                    _depth.at(e.to)\
    \ = _depth.at(cur) + 1;\n                    s.push(e.to);\n                }\n\
    \            }\n        }\n    }\n\n   public:\n    LCA(const vector<vector<edge>>\
    \ &G, int root) : G(G), root(root) {\n        logV = 1;\n        int _v = 1;\n\
    \        while (_v < int(G.size())) {\n            _v *= 2;\n            logV++;\n\
    \        }\n        _parent = vector<vector<int>>(logV, vector<int>(G.size()));\n\
    \        _depth = vector<int>(G.size());\n        dfs();\n        for (int k =\
    \ 0; k < logV - 1; k++) {\n            for (int v = 0; v < int(G.size()); v++)\
    \ {\n                if (_parent.at(k).at(v) < 0) _parent.at(k + 1).at(v) = -1;\n\
    \                else _parent.at(k + 1).at(v) = _parent.at(k).at(_parent.at(k).at(v));\n\
    \            }\n        }\n    }\n\n    int query(int u, int v) {\n        if\
    \ (_depth.at(u) > _depth.at(v)) swap(u, v);\n        for (int k = 0; k < logV;\
    \ k++) {\n            if ((_depth.at(v) - _depth.at(u)) >> k & 1) {\n        \
    \        v = _parent.at(k).at(v);\n            }\n        }\n        if (u ==\
    \ v) return u;\n        for (int k = logV - 1; k >= 0; k--) {\n            if\
    \ (_parent.at(k).at(u) != _parent.at(k).at(v)) {\n                u = _parent.at(k).at(u);\n\
    \                v = _parent.at(k).at(v);\n            }\n        }\n        return\
    \ _parent.at(0).at(u);\n    }\n\n    const vector<vector<int>> &parent() { return\
    \ _parent; }\n    const vector<int> &depth() { return _depth; }\n};\n"
  code: "#pragma once\n\ntemplate <typename edge>\nstruct LCA {\n   private:\n   \
    \ const vector<vector<edge>> &G;\n    int root, logV;\n    vector<vector<int>>\
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
    \ _parent; }\n    const vector<int> &depth() { return _depth; }\n};"
  dependsOn: []
  isVerificationFile: false
  path: graph/tree/lca.cpp
  requiredBy: []
  timestamp: '2025-03-08 18:45:31+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/verify-yosupo-graph/yosupo-lowest-common-ancestor-doubling.test.cpp
documentation_of: graph/tree/lca.cpp
layout: document
redirect_from:
- /library/graph/tree/lca.cpp
- /library/graph/tree/lca.cpp.html
title: graph/tree/lca.cpp
---
