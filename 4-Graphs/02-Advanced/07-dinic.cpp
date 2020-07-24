#include <bits/stdc++.h>
using namespace std;

struct NetworkEdge {
    int from;
    int to;

    long long capacity;
    long long flow = 0;

    NetworkEdge(int v, int u, long long cap) : v(v), u(u), cap(cap) {}
};

class Dinic {
	private:
		int n;
		int m;

		vector<NetworkEdge> edges;
		vector<vector<int>> graph;

		int source;
		int sink;


		vector<int> level;
		vector<int> 
}