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

void solve() {
	for (int u = 0; u < n; u++) {
		if (!visited[u]) {
			dfs(u);
		}
	}

	reverse(top_sort.begin(), top_sort.end());

	for (int u : top_sort) {
		cerr << u << " ";
	}
	cerr << "\n";
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

	freopen("test.in", "r", stdin);

	input();
	solve();

	return 0;
}