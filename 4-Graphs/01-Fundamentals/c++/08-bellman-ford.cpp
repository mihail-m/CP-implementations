#include <bits/stdc++.h>
using namespace std;

static const int MAX_SIZE = 1 << 18;

int n, m; // nodes and edges
vector<pair<pair<int, int>, int>> edges;

int dist[MAX_SIZE];

void bellman_ford(int start) {
    fill(dist, dist + n, INT_MAX);
    dist[start] = 0;

    bool relaxed = true;
    while (relaxed) {
        relaxed = false;

        for (auto e : edges) {
            int u = e.first.first;
            int v = e.first.second;
            int cost = e.second;

            if (dist[u] != INT_MAX) {
                if (dist[v] > dist[u] + cost) {
                    dist[v] = dist[u] + cost;
                    relaxed = true;
                }
            } 
        }
    }
}

void test() {
    n = 9;
    m = 28;

    edges.push_back({{0, 1}, 4}),  edges.push_back({{1, 0}, 4});
    edges.push_back({{0, 7}, 8}),  edges.push_back({{7, 0}, 8});
    edges.push_back({{1, 2}, 8}),  edges.push_back({{2, 1}, 8});
    edges.push_back({{1, 7}, 11}), edges.push_back({{7, 1}, 11});
    edges.push_back({{2, 3}, 7}),  edges.push_back({{3, 2}, 7}); 
    edges.push_back({{2, 5}, 4}),  edges.push_back({{5, 2}, 4}); 
    edges.push_back({{2, 8}, 2}),  edges.push_back({{8, 2}, 2}); 
    edges.push_back({{3, 4}, 9}),  edges.push_back({{4, 3}, 9}); 
    edges.push_back({{3, 5}, 14}), edges.push_back({{5, 3}, 14});
    edges.push_back({{4, 5}, 10}), edges.push_back({{5, 4}, 10});
    edges.push_back({{5, 6}, 2}),  edges.push_back({{6, 5}, 2});
    edges.push_back({{6, 7}, 1}),  edges.push_back({{7, 6}, 1});
    edges.push_back({{6, 8}, 6}),  edges.push_back({{8, 6}, 6});
    edges.push_back({{7, 8}, 7}),  edges.push_back({{8, 7}, 7});

    int expectedResult[] {0, 4, 12, 19, 21, 11, 9, 8, 14};

    bellman_ford(0);

    for (int i = 0; i < 9; i++) {
        assert(expectedResult[i] == dist[i]);
    }

    edges.clear();
    n = m = 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    test();

    return 0;
}