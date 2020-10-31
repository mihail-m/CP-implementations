#include <bits/stdc++.h>
using namespace std;

static const int MAX_SIZE = 1 << 18;

int n, m; // nodes and edges
vector<int> graph[MAX_SIZE];
vector<int> articulation_points;

bool visited[MAX_SIZE];
int in[MAX_SIZE];
int low[MAX_SIZE];

int timer = 0;

void dfs(int u, int par = -1) {
    visited[u] = true;
    in[u] = low[u] = timer++;

    int splits = 0;
    for (int v : graph[u]) {
        if (!visited[v]) {
            dfs(v, u);

            low[u] = min(low[u], low[v]);

            if (low[v] >= in[u] && par != -1) {
                articulation_points.push_back(u + 1);
            }

            splits++;
        } else if (v != par) {
            low[u] = min(low[u], in[v]);
        }
    }

    if (par == -1 && splits > 1) {
        articulation_points.push_back(u + 1);
    }
}

void test() {
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs(i);
        }
    }

    for (int point : articulation_points) {
        cerr << point << "\n";
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

    input();
    test();

    return 0;
}