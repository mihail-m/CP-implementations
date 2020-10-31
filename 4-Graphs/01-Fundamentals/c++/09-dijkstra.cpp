#include <bits/stdc++.h>
using namespace std;

static const int MAX_SIZE = 1 << 18;

int n, m; // nodes and edges
vector<pair<int, int>> graph[MAX_SIZE];

int dist[MAX_SIZE];

// Usually better 
// O(m log n)
void dijkstra(int start) {
    fill(dist, dist + n, INT_MAX);
    dist[start] = 0;

    set<pair<int, int>> s;
    s.insert({0, start});

    while (s.size() > 0) {
        int u = (*s.begin()).second;
        s.erase(s.begin());

        for (auto v : graph[u]) {
            if (dist[v.first] > dist[u] + v.second) {
                s.erase({dist[v.first], v.first});
                dist[v.first] = dist[u] + v.second;
                s.insert({dist[v.first], v.first});
            }
        }
    }
}

// Better on dense graphs, where m -> n^2
// O(n^2 + m) = O(n ^ 2) < O(m log n) = O(n ^ 2 log n)
void dijkstra_dense(int start) {
    fill(dist, dist + n, INT_MAX);
    dist[start] = 0;

    vector<bool> used(n, false);

    for (int i = 0; i < n; i++) {
        int u = -1;
        for (int v = 0; v < n; v++) {
            if (!used[v] && (u == -1 || dist[v] < dist[u])) {
                u = v;
            }
        }

        if (dist[u] == INT_MAX) {
            break;
        }

        used[u] = true;

        for (auto v : graph[u]) {
            if (dist[v.first] > dist[u] + v.second) {
                dist[v.first] = dist[u] + v.second;
            }
        }
    }
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

    for (auto p : edges) {
        graph[p.first.first].push_back({p.first.second, p.second});
        graph[p.first.second].push_back({p.first.first, p.second});
    }

    int expectedResult[] {0, 4, 12, 19, 21, 11, 9, 8, 14};

    dijkstra(0);

    for (int i = 0; i < 9; i++) {
        assert(expectedResult[i] == dist[i]);
    }

    dijkstra_dense(0);

    for (int i = 0; i < 9; i++) {
        assert(expectedResult[i] == dist[i]);
    }

    for (int i = 0; i < n; i++) {
        graph[i].clear();
    }
    n = m = 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    test();

    return 0;
}