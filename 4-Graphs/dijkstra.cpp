#include <bits/stdc++.h>
using namespace std;

static const int MAX_SIZE = 1 << 18;

int n, m; // nodes and edges
vector<pair<int, int>> graph[MAX_SIZE];

int dist[MAX_SIZE];

// Usually better 
// O(n log n + m)
void dijkstra(int start) {
	fill(dist, dist + n, INT_MAX);
	dist[start] = 0;

	set<pair<int, int>> s;
	s.insert({0, start});

	while (s.size() > 0) {
		int u = (*s.begin()).second;
		s.erase(s.begin());

		for (auto v : graph[u]) {
			if (dist[v.first] > dist[u] + v.second) {
				s.erase({dist[v.first], v.first});
				dist[v.first] = dist[u] + v.second;
				s.insert({dist[v.first], v.first});
			}
		}
	}
}

// Better on dense graphs, where m -> n^2
// O(n^2 + m) < O(n log n + m) = O(n log n + n ^ 2)
void dijkstra_dense(int start) {
	fill(dist, dist + n, INT_MAX);
	dist[start] = 0;

	vector<bool> used(n, false);

	for (int i = 0; i < n; i++) {
		int u = -1;
		for (int v = 0; v < n; v++) {
			if (!used[v] && (u == -1 || dist[v] < dist[u])) {
				u = v;
			}
		}

		if (dist[u] == INT_MAX) {
			break;
		}

		used[u] = true;

		for (auto v : graph[u]) {
			if (dist[v.first] > dist[u] + v.second) {
				dist[v.first] = dist[u] + v.second;
			}
		}
	}
}

void solve() {
	dijkstra(0);

	for (int u = 0; u < n; u++) {
		cerr << dist[u] << " ";
	}
	cerr << "\n";

	dijkstra_dense(0);

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

		graph[u].push_back({v, cost});
		graph[v].push_back({u, cost});
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