#include <bits/stdc++.h>
using namespace std;

static const int MAX_SIZE = 1 << 18;

int n, m; // nodes and edges
vector<int> graph[MAX_SIZE];

int colour[MAX_SIZE];


bool cycle_directed(int u) {
    colour[u] = 1;

    for (int v : graph[u]) {
        if (colour[v] == 0) {
            if (cycle_directed(v)) {
                return true;
            }
        } else if (colour[v] == 1) {
            return true;
        }
    }

    colour[u] = 2;
    return false;
}

bool cycle_undirected(int u, int par) {
    colour[u] = 1;

    for (int v : graph[u]) {
        if (colour[v] == 0) {
             if (cycle_undirected(v, u)) {
                return true;
             }
        } else if (colour[v] == 1 && v != par) {
            return true;
        }
    }

    colour[u] = 2;
    return false;
}

void test() {
    bool res = false;
    for (int i = 0; i < n; i++) {
        if (colour[i] == 0) {
            res |= cycle_directed(i);
        }
    }
    cerr << res << "\n";
}

void input() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;

        graph[u].push_back(v);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    input();
    test();

    return 0;
}