#include <bits/stdc++.h>
using namespace std;

static const int MAX_SIZE = 1 << 18;

int n, m; // nodes and edges
vector<int> graph[MAX_SIZE];

bool visited[MAX_SIZE];

void dfs(int u) {
    cerr << u << " ";

    visited[u] = true;
    for (int v : graph[u]) {
        if (!visited[v]) {
            dfs(v);
        }
    }
}

void dfs_iterative(int start) {
    visited[start] = true;

    stack<int> s;
    s.push(start);

    while(s.size() > 0) {
        int u = s.top();
        s.pop();

        cerr << u << " ";

        for (int v : graph[u]) {
            if (!visited[v]) {
                s.push(v);
                visited[v] = true;
            }
        }
    }
}

void solve() {
    dfs(0);
    cerr << "\n";

    fill(visited, visited + n, false);

    dfs_iterative(0);
    cerr << "\n";
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

    input();
    solve();

    return 0;
}