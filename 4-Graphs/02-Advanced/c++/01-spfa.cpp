#include <bits/stdc++.h>
using namespace std;

static const int MAX_SIZE = 1 << 18;

int n, m; // nodes and edges
vector<pair<pair<int, int>, int>> edges;

int dist[MAX_SIZE];

bool spfa(int start) {
    fill(dist, dist + n, INT_MAX);
    dist[start] = 0;

    vector<int> updated(n, 0);
    vector<bool> queued(n, false);

    queue<int> q;
    q.push(start);
    queued[start] = true;

    while (q.size() > 0) {
        int u = q.front();
        q.pop();

        queued[u] = false;

        for (auto e : edges) {
            int u = e.first.first;
            int v = e.first.second;
            int cost = e.second;

            if (dist[v] > dist[u] + cost) {
                dist[v] = dist[u] + cost;
                
                if (!queued[v]) {
                    q.push(v);
                    queued[v] = true;
                    updated[v]++;

                    if (updated[v] > n) {
                        return true; // has negative cycle
                    }
                }
            }
        }
    }

    return false; // no negative cycle
}

void solve() {
    int neg_cycle = spfa(0);

    if (!neg_cycle) {
        for (int u = 0; u < n; u++) {
            cerr << dist[u] << " ";
        }
        cerr << "\n";
    } else {
        cerr << "Negative cycle found\n";
    }
}

void input() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v, cost;
        cin >> u >> v >> cost;
        u--, v--;

        edges.push_back({{u, v}, cost});
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    input();
    solve();

    return 0;
}