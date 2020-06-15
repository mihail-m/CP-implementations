#include <bits/stdc++.h>
using namespace std;

static const int MAX_SIZE = 1 << 18;

struct Edge {
    int to = -1;
    int cost = INT_MAX;

    bool operator <(const Edge& rhs) const {
        return make_pair(cost, to) < make_pair(rhs.cost, rhs.to);
    }
};

int n, m; // nodes and edges
vector<Edge> graph[MAX_SIZE];
vector<Edge> mst[MAX_SIZE];

int prim() {
    int total_weight = 0;

    vector<Edge> min_edge(n);
    min_edge[0].cost = 0;

    set<Edge> s;
    s.insert({0, 0});

    vector<bool> used(n, false);

    for (int i = 0; i < n; i++) {
        if (s.size() == 0) {
            cerr << "Graph is disjoined.\n";
            return -1;
        }

        int u = s.begin()->to;
        used[u] = true;

        total_weight += s.begin()->cost;
        s.erase(s.begin());

        if (min_edge[u].to != -1) {
            mst[u].push_back({min_edge[u].to, min_edge[u].cost});
            mst[min_edge[u].to].push_back({u, min_edge[u].cost});
        }

        for (Edge e : graph[u]) {
            if (!used[e.to] && e.cost < min_edge[e.to].cost) {
                s.erase({e.to, min_edge[e.to].cost});
                min_edge[e.to] = {u, e.cost};
                s.insert({e.to, e.cost});
            }
        }
    }

    return total_weight;
}

void test() {
    cerr << prim() << "\n";

    for (int u = 0; u < n; u++) {
        cerr << u << ": ";
        for (Edge e : mst[u]) {
            cerr << "(" << e.to << ", " << e.cost << "), ";
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

        graph[u].push_back({v, cost});
        graph[v].push_back({u, cost});
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