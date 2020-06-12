#include <bits/stdc++.h>
using namespace std;

static const int MAX_SIZE = 1 << 18;

int n, m; // nodes and edges
vector<int> graph[MAX_SIZE];
vector<int> rev_graph[MAX_SIZE];

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
	for (int u = 0; u < 2 * n; u++) {
		if (!visited[u]) {
			dfs(u);
		}
	}

	reverse(top_sort.begin(), top_sort.end());
	fill(visited, visited + (2 * n), false);

	int num = 0;
	for (int u : top_sort) {
		if (!visited[u]) {
			dfs_rev(u, num);
			num++;
		}
	}

	for (int u = 0; u < 2 * n; u++) {
		cerr << component[u] << " ";
	}
	cerr << "\n";

	return num;
}

bool solve() {
	kosaraju();

	for (int i = 0; i < n; i++) {
		if (component[i] == component[i + n]) {
			return false;
		}
	}

	return true;
}

void input() {
	cin >> n >> m;
	n /= 2;
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
	cout.tie(nullptr);

	input();
	cerr << solve() << "\n";

	return 0;
}