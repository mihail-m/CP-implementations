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

void solve() {
    floyd();

    for (int u = 0; u < n; u++) {
        for (int v = 0; v < n; v++) {
            cerr << dist[u][v] << " ";
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

        graph[u][v] = cost;
        graph[v][u] = cost;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    input();
    solve();

    return 0;
}