#include <bits/stdc++.h>
using namespace std;

class MPM {
    private:
        struct NetworkEdge {
            int from;
            int to;

            long long capacity;
            long long flow;

            NetworkEdge() { }

            NetworkEdge(int from, int to, long long capacity)
                : from(from), to(to), capacity(capacity), flow(0ll) { }

            NetworkEdge(int from, int to, long long capacity, long long flow)
                : from(from), to(to), capacity(capacity), flow(flow) { }
        };

        int n;
        int m = 0;

        vector<vector<int>> graph;
        vector<NetworkEdge> edges;

        vector<list<int>> in;
        vector<list<int>> out;
        
        vector<long long> potentialential_in;
        vector<long long> potentialential_out;
        
        vector<char> alive;
        vector<long long> ex;
        
        vector<int> level;
        vector<int> q;

        int source, sink;
        int q_head, q_tail;

        void resize (int vetrices) {
            n = vetrices;

            graph.resize(n);

            in.resize(n);
            out.resize(n);

            potentialential_in.resize(n);
            potentialential_out.resize(n);

            ex.resize(n);

            q.resize(n);
            level.resize(n);
        }

        void reset() {
            for (NetworkEdge& edge : edges) {
                edge.flow = 0;
            }
        }

        long long potential (int node) {
            return min(potentialential_in[node], potentialential_out[node]);
        }

        void remove_node (int node) {
            for (int i : in[node]) {
                int u = edges[i].from;
                auto it = find(out[u].begin(), out[u].end(), i);
                out[u].erase(it);
                potentialential_out[u] -= edges[i].capacity - edges[i].flow;
            }

            for (int i : out[node]) {
                int u = edges[i].to;
                auto it = find(in[u].begin(), in[u].end(), i);
                in[u].erase(it);
                potentialential_in[u] -= edges[i].capacity - edges[i].flow;
            }
        }

        void push(int from, int to, long long f, bool forward) {
            q_head = q_tail = 0;
            ex.assign(n, 0);
            ex[from] = f;
            q[q_tail++] = from;

            while (q_head < q_tail) {
                int node = q[q_head++];

                if(node == to) {
                    break;
                }

                long long must = ex[node];
                auto it = forward ? out[node].begin() : in[node].begin();

                while (true) {
                    int next_node = forward ? edges[*it].to : edges[*it].from;
                    long long pushed = min(must, edges[*it].capacity - edges[*it].flow);

                    if (pushed == 0) {
                        break;
                    }

                    if (forward) {
                        potentialential_out[node] -= pushed;
                        potentialential_in[next_node] -= pushed;
                    } else {
                        potentialential_in[node] -= pushed;
                        potentialential_out[next_node] -= pushed;
                    }

                    if (ex[next_node] == 0) {
                        q[q_tail++] = next_node;
                    }

                    ex[next_node] += pushed;
                    edges[*it].flow += pushed;
                    edges[(*it)^1].flow -= pushed;
                    must -= pushed;

                    if (edges[*it].capacity - edges[*it].flow == 0) {
                        auto temp_it = it;
                        ++temp_it;

                        if (forward) {
                            in[next_node].erase(find(in[next_node].begin(), in[next_node].end(), *it));
                            out[node].erase(it);
                        } else {
                            out[next_node].erase(find(out[next_node].begin(), out[next_node].end(), *it));
                            in[node].erase(it);
                        }

                        it = temp_it;
                    }  else {
                        break;
                    }

                    if (!must) {
                        break;
                    }
                }
            }
        }

        bool bfs() {
            while (q_head < q_tail) {
                int node = q[q_head++];

                for (int id : graph[node]) {
                    NetworkEdge edge = edges[id];
                    if(edge.capacity - edge.flow < 1) {
                        continue;
                    }

                    if (level[edge.to] != -1) {
                        continue;
                    }

                    level[edge.to] = level[node] + 1;
                    q[q_tail++] = edge.to;
                }
            }

            return level[sink] != -1;
        }

    public:
        MPM() { }

        MPM(int vetrices) {
            resize(vetrices);
        }

        void add_edge(int from, int to, long long capacity) {
            edges.push_back(NetworkEdge(from, to, capacity));
            edges.push_back(NetworkEdge(to, from, 0));

            graph[from].push_back(m);
            graph[to].push_back(m + 1);
            m += 2;
        }

        long long max_flow(int from, int to) {
            reset();

            source = from;
            sink = to;

            long long ans = 0;

            while (true) {
                potentialential_in.assign(n, 0);
                potentialential_out.assign(n, 0);
                level.assign(n, -1);
                alive.assign(n, true);
                level[source] = 0;
                q_head = 0; q_tail = 1;
                q[0] = source;

                if (!bfs()) {
                    break;
                }

                for (int i = 0; i < n; i++) {
                    out[i].clear();
                    in[i].clear();
                }

                for (int i = 0; i < m; i++) {
                    if (edges[i].capacity - edges[i].flow == 0) {
                        continue;
                    }

                    int node = edges[i].from;
                    int next_node = edges[i].to;

                    if (level[node] + 1 == level[next_node] && (level[next_node] < level[sink] || next_node == sink)) {
                        in[next_node].push_back(i);
                        out[node].push_back(i);
                        potentialential_in[next_node] += edges[i].capacity - edges[i].flow;
                        potentialential_out[node] += edges[i].capacity - edges[i].flow;
                    }
                }

                potentialential_in[source] = potentialential_out[sink] = LLONG_MAX;

                while (true) {
                    int node = -1;
                    for (int i = 0; i < n; i++) {
                        if (!alive[i]) {
                            continue;
                        }

                        if(node == -1 || potential(i) < potential(node)) {
                            node = i;
                        }
                    }

                    if(node == -1) {
                        break;
                    }

                    if (potential(node) == 0) {
                        alive[node] = false;
                        remove_node(node);
                        continue;
                    }

                    long long f = potential(node);
                    ans += f;

                    push(node, source, f, false);
                    push(node, sink, f, true);

                    alive[node] = false;
                    remove_node(node);
                }
            }

            return ans;
        }
};

void test() {
    MPM graph(6);
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
    cout.tie(nullptr);

    test();

    return 0;
}
