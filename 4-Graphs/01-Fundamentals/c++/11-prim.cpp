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
    n = 9;
    m = 14;

    vector<pair<pair<int, int>, int>> edges;
    edges.push_back({{0, 1}, 4});
    edges.push_back({{0, 7}, 8});
    edges.push_back({{1, 2}, 8});
    edges.push_back({{1, 7}, 11});
    edges.push_back({{2, 3}, 7});
    edges.push_back({{2, 5}, 4});
    edges.push_back({{2, 8}, 2});
    edges.push_back({{3, 4}, 9});
    edges.push_back({{3, 5}, 14});
    edges.push_back({{4, 5}, 10});
    edges.push_back({{5, 6}, 2});
    edges.push_back({{6, 7}, 1});
    edges.push_back({{6, 8}, 6});
    edges.push_back({{7, 8}, 7});

    for (auto edge : edges) {
        graph[edge.first.first].push_back({edge.first.second, edge.second});
        graph[edge.first.second].push_back({edge.first.first, edge.second});
    }

    assert(37 == prim());

    for (int i = 0; i < n; i++) {
        graph[i].clear();
        mst[i].clear();
    }
    n = m = 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    test();

    return 0;
}