#include <bits/stdc++.h>
using namespace std;

static const int MAX_SIZE = 1 << 10;

int n, m; // nodes and edges
int graph[MAX_SIZE][MAX_SIZE];
int dist[MAX_SIZE][MAX_SIZE];

void floyd() {
    for (int u = 0; u < n; u++) {
        for (int v = 0; v < n; v++) {
            if (graph[u][v] == 0 && u != v) {
                dist[u][v] = INT_MAX;
            } else {
                dist[u][v] = graph[u][v];
            }
        }
    }

    for (int k = 0; k < n; k++) {
        for (int u = 0; u < n; u++) {
            for (int v = 0; v < n; v++) {
                if (dist[u][k] != INT_MAX && dist[k][v] != INT_MAX) {
                    dist[u][v] = min(dist[u][v], dist[u][k] + dist[k][v]);
                }
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
        graph[p.first.first][p.first.second] = p.second;
        graph[p.first.second][p.first.first] = p.second;
    }

    int expectedResult[9][9] {
        {0, 4, 12, 19, 21, 11, 9, 8, 14},
        {4, 0, 8, 15, 22, 12, 12, 11, 10},
        {12, 8, 0, 7, 14, 4, 6, 7, 2},
        {19, 15, 7, 0, 9, 11, 13, 14, 9},
        {21, 22, 14, 9, 0, 10, 12, 13, 16},
        {11, 12, 4, 11, 10, 0, 2, 3, 6},
        {9, 12, 6, 13, 12, 2, 0, 1, 6},
        {8, 11, 7, 14, 13, 3, 1, 0, 7},
        {14, 10, 2, 9, 16, 6, 6, 7, 0}
    };

    floyd();

    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++) {
            assert(expectedResult[i][j] == dist[i][j]);
        }
    }
} 

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    test();

    return 0;
}