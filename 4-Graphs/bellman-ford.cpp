#include <bits/stdc++.h>
using namespace std;

static const int MAX_SIZE = 1 << 18;

int n, m; // nodes and edges
vector<pair<pair<int, int>, int>> edges;

int dist[MAX_SIZE];

void bellman_ford(int start) {
	fill(dist, dist + n, INT_MAX);
	dist[start] = 0;

	bool relaxed = true;
	while (relaxed) {
		relaxed = false;

		for (auto e : edges) {
			int u = e.first.first;
			int v = e.first.second;
			int cost = e.second;

			if (dist[u] != INT_MAX) {
				if (dist[v] > dist[u] + cost) {
					dist[v] = dist[u] + cost;
					relaxed = true;
				}
			} 
		}
	}
}

void solve() {
	bellman_ford(0);

	for (int u = 0; u < n; u++) {
		cerr << dist[u] << " ";
	}
	cerr << "\n";
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
	cout.tie(nullptr);

	freopen("test.in", "r", stdin);

	input();
	solve();

	return 0;
}