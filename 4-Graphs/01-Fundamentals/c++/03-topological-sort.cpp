#include <bits/stdc++.h>
using namespace std;

static const int MAX_SIZE = 1 << 18;

int n, m; // nodes and edges
vector<int> graph[MAX_SIZE];

vector<int> top_sort;
bool visited[MAX_SIZE];

void dfs(int u) {
    visited[u] = true;
    for (int v : graph[u]) {
        if (!visited[v]) {
            dfs(v);
        }
    }
    top_sort.push_back(u);
}

void topological_sort() {
    fill(visited, visited + n, false);
    top_sort.clear();

    for (int u = 0; u < n; u++) {
        if (!visited[u]) {
            dfs(u);
        }
    }

    reverse(top_sort.begin(), top_sort.end());
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

    topological_sort();

    vector<int> expectedResult({5, 4, 2, 3, 1, 0});`
    assert(expectedResult == top_sort);

    for (int i = 0; i < n; i++) {
        graph[i].clear();
    }
    n = m = 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    test();

    return 0;
}