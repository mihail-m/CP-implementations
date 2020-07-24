#include <bits/stdc++.h>
using namespace std;

static const int MAX_SIZE = 1 << 18;

int n, m; // nodes and edges
vector<int> graph[MAX_SIZE];

bool visited[MAX_SIZE];
int dist[MAX_SIZE];

void bfs(int start) {
    visited[start] = true;
    dist[start] = 0;

    queue<int> q;
    q.push(start);

    while (q.size() > 0) {
        int u = q.front();
        q.pop();

        for (int v : graph[u]) {
            if (!visited[v]) {
                q.push(v);
                dist[v] = dist[u] + 1;
                visited[v] = true;
            }
        }
    }
}

void input() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;

        graph[u].push_back(v);
        graph[v].push_back(u);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    return 0;
}