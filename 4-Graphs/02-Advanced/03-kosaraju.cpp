#include <bits/stdc++.h>
using namespace std;

static const int MAX_SIZE = 1 << 18;

int n, m; // nodes and edges
vector<int> graph[MAX_SIZE];
vector<int> rev_graph[MAX_SIZE];

vector<int> condensed_grah[MAX_SIZE];

vector<int> top_sort;
bool visited[MAX_SIZE];

int component[MAX_SIZE];

void dfs_rev(int u, int num) {
    visited[u] = true;
    component[u] = num;

    for (int v : rev_graph[u]) {
        if (!visited[v]) {
            dfs_rev(v, num);
        }
    }
}

void dfs(int u) {
    visited[u] = true;

    for (int v : graph[u]) {
        if (!visited[v]) {
            dfs(v);
        }
    }
    top_sort.push_back(u);
}

int kosaraju() {
    for (int u = 0; u < n; u++) {
        if (!visited[u]) {
            dfs(u);
        }
    }

    reverse(top_sort.begin(), top_sort.end());
    fill(visited, visited + n, false);

    int num = 0;
    for (int u : top_sort) {
        if (!visited[u]) {
            dfs_rev(u, num);
            num++;
        }
    }

    for (int u = 0; u < n; u++) {
        cerr << component[u] << " ";
    }
    cerr << "\n";

    return num;
}

void build_condensed_grah() {
    for (int u = 0; u < n; u++) {
        for (int v : graph[u]) {
            if (component[u] != component[v]) {
                condensed_grah[component[u]].push_back(component[v]);
            }
        }
    }
}

void solve() {
    int condensed_n = kosaraju();

    build_condensed_grah();

    for (int u = 0; u < condensed_n; u++) {
        cerr << u << ": ";
        for (int v : condensed_grah[u]) {
            cerr << v << " ";
        }
        cerr << "\n";
    }
}

void input() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;

        graph[u].push_back(v);
        rev_graph[v].push_back(u);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    input();
    solve();

    return 0;
}