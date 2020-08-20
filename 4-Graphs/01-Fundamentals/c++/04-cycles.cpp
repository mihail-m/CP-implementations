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
    n = m = 6;

    vector<pair<int, int>> edges;
    edges.push_back({5, 2}); 
    edges.push_back({5, 0}); 
    edges.push_back({4, 0}); 
    edges.push_back({4, 1}); 
    edges.push_back({2, 3}); 
    edges.push_back({3, 1}); 
    
    for (int i = 0; i < m; i++) {
        graph[edges[i].first].push_back(edges[i].second);
    }

    assert(false == cycle_directed(0));

    for (int i = 0; i < m; i++) {
        graph[edges[i].second].push_back(edges[i].first);
    }

    fill(colour, colour + n, 0);

    assert(true == cycle_undirected(0, -1));

    fill(colour, colour + n, 0);
    for (int i = 0; i < n; i++) {
        graph[i].clear();
    }
    n = m = 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    test();

    return 0;
}