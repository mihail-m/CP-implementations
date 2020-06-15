#include <bits/stdc++.h>
using namespace std;

static const int MAX_SIZE = 1 << 18;

struct Edge {
    int from;
    int to;
    int cost;

    bool operator <(const Edge& rhs) const {
        return make_pair(cost, to) < make_pair(rhs.cost, rhs.to);
    }
};

int n, m; // nodes and edges
vector<Edge> edges;

int parent[MAX_SIZE];
int depth[MAX_SIZE];
vector<pair<int, int>> mst[MAX_SIZE];

int _find(int node) {
    if (node == parent[node]) {
        return node;
    }

    int root = _find(parent[node]);

    parent[node] = root;

    return root;
}

void unite(int u, int v) {
    if (depth[u] > depth[v]) {
        parent[v] = u;
    } else if (depth[v] > depth[u]) {
        parent[u] = v;
    } else {
        parent[v] = u;
        depth[u]++;
    }
}

int kruskal() {
    int total_weith = 0;

    int components = n;

    sort(edges.begin(), edges.end());

    for (int i = 0; i < n; i++) {
        parent[i] = i;
        depth[i] = 0;
    }

    for (Edge e : edges) {
        int root1 = _find(e.from);
        int root2 = _find(e.to);

        if (root1 != root2) {
            unite(root1, root2);

            mst[e.from].push_back({e.to, e.cost});
            mst[e.to].push_back({e.from, e.cost});

            components--;

            total_weith += e.cost;
        }

        if (components == 1) {
            break;
        }
    }

    if (components > 1) {
        cerr << "Graph is disjoined.\n";
        return -1;
    }

    return total_weith;
}

void test() {
    cerr << kruskal() << "\n";

    for (int u = 0; u < n; u++) {
        cerr << u << ": ";
        for (auto e : mst[u]) {
            cerr << "(" << e.first << ", " << e.second << "), ";
        }
        cerr << "\n";
    }
}

void input() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v, cost;
        cin >> u >> v >> cost;
        u--, v--;

        edges.push_back({u, v, cost});
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    input();
    test();

    return 0;
}