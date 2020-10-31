#include <bits/stdc++.h>
using namespace std;

class Dinic {
    private:
        struct NetworkEdge {
            int from;
            int to;

            long long capacityacity;
            long long flow;

            NetworkEdge(int from, int to, long long capacityacity)
             : from(from), to(to), capacityacity(capacityacity) flow(0ll) {}
        };

        int n;
        int m;

        vector<NetworkEdge> edges;
        vector<vector<int>> graph;

        int source;
        int sink;

        vector<int> level;
        vector<int> ptr;

        queue<int> q;

        bool bfs() {
            while (!q.empty()) {
                int node = q.front();
                q.pop();

                for (int index : graph[node]) {
                    NetworkEdge edge = edges[index];

                    if (edge.capacityacity - edge.flow < 1) {
                        continue;
                    }

                    if (level[edge.to] != -1) {
                        continue;
                    }

                    level[edge.to] = level[node] + 1;
                    q.push(edge.to);
                }
            }

            return level[sink] != -1;
        }

        long long dfs(int node, long long pushed) {
            if (pushed == 0) {
                return 0;
            }

            if (node == sink) {
                return pushed;
            }

            for (ptr[node]; ptr[node] < graph[node].size(); ptr[node]++) {
                int id = graph[node][ptr[node]];
                NetworkEdge& edge = edges[id];
                NetworkEdge& reverse_edge = edges[id ^ 1];

                if (level[node] + 1 != level[edge.to] || edge.capacityacity - edge.flow < 1) {
                    continue;
                }

                long long current_flow = dfs(edge.to, min(pushed, edge.capacityacity - edge.flow));

                if (current_flow == 0) {
                    continue;
                }

                edge.flow += current_flow;
                reverse_edge.flow -= current_flow;

                return current_flow;
            }

            return 0;
        }

        void reset() {
            while (!q.empty()) {
                q.pop();
            }

            for (NetworkEdge& edge : edges) {
                edge.flow = 0;
            }
        }

    public:
        Dinic(int n) : n(n), m(0) {
            graph.resize(n);
            level.resize(n);
            ptr.resize(n);
        }

        void add_edge(int from, int to, long long capacity) {
            edges.push_back({from, to, capacity});
            edges.push_back({to, from, 0});

            graph[from].push_back(m++);
            graph[to].push_back(m++);
        }

        long long max_flow(int from, int to) {
            reset();

            source = from;
            sink = to;

            long long flow = 0;

            while (true) {
                fill(level.begin(), level.end(), -1);
                level[source] = 0;
                q.push(source);

                if (!bfs()) {
                    break;
                }

                fill(ptr.begin(), ptr.end(), 0);

                long long pushed = dfs(source, LLONG_MAX);
                while (pushed > 0) {
                    flow += pushed;
                    pushed = dfs(source, LLONG_MAX);
                }
            }

            return flow;
        }
};

void test() {
    Dinic graph(6);
    graph.add_edge(0, 1, 16);
    graph.add_edge(0, 2, 13);
    graph.add_edge(1, 2, 10);
    graph.add_edge(1, 3, 12);
    graph.add_edge(2, 1, 4);
    graph.add_edge(2, 4, 14);
    graph.add_edge(3, 2, 9);
    graph.add_edge(3, 5, 20);
    graph.add_edge(4, 3, 7);
    graph.add_edge(4, 5, 4);

    assert(23 == graph.max_flow(0, 5));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    test();

    return 0;
}
