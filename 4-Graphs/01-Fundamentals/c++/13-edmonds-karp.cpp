#include <bits/stdc++.h>
using namespace std;

static const int MAX_SIZE = 1 << 10;

int n, m;
vector<int> graph[MAX_SIZE];
int capacity[MAX_SIZE][MAX_SIZE];

int bfs(int from, int to, vector<int> parent) {
    fill(parent.begin(), parent.end(), -1);
    parent[from] = INT_MIN;

    queue<pair<int, int>> q;
    q.push({from, INT_MAX});

    while (!q.empty()) {
        int node = q.front().first;
        int flow = q.front().second;
        q.pop();

        for (int i : graph[node]) {
            if (parent[i] == -1 && capacity[node][i]) {
                parent[i] = node;
                int current_flow = min(flow, capacity[node][i]);

                if (i == to) {
                    return current_flow;
                }

                q.push({i, current_flow});
            }
        }
    }

    return 0;
}

int max_flow(int source, int sink) {
    int flow = 0;
    int current_flow = 0;
    vector<int> parent(n);

    while (current_flow = bfs(source, sink, parent)) {
        flow += current_flow;

        int node = sink;
        while (node != source) {
            int previous = parent[node];
            capacity[previous][node] -= current_flow;
            capacity[node][previous] += current_flow;
            node = previous;
        }
    }

    return flow;
}

void input() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int from, to, cap;
        cin >> from >> to >> cap;
        graph[from].push_back(to);
        capacity[from][to] = cap;
    }
}

void test() {
    input();

    int source, sink;
    cin >> source >> sink;
    cerr << max_flow(source, sink) << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    test();

    return 0;
}