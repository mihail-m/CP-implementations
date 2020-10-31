#include <bits/stdc++.h>
using namespace std;

static const int LOG2 = 18;
static const int MAX_SIZE = 1 << LOG2;

int n; // nodes
vector<int> tree[MAX_SIZE];

int index[MAX_SIZE][LOG2];
int pw2[MAX_SIZE];

void dfs(int node, int par = -1) {
    index[node][0] = par;

    for (int child : tree[node]) {
        if (child != par) {
            dfs(child, node);
        }
    }
}

void build() {
    dfs(0);
    index[0][0] = 0;

    for (int deg = 1; deg < LOG2; deg++) {
        for (int node = 0; node < n; node++) {
            index[node][deg] = index[index[node][deg - 1]][deg - 1];
        }
    }

    for (int i = 2; i < n; i++) {
        pw2[i] = pw2[i / 2] + 1;
    }
}

int kth_ancestor(int node, int k) {
    int res = node;

    while (k > 0 && res > 0) {
        res = index[res][pw2[k]];
        k -= (1 << pw2[k]);
    }

    return res + 1;
}

void test() {
    int q;
    cin >> q;

    for (int i = 0; i < q; i++) {
        int node, k;
        cin >> node >> k;

        cerr << kth_ancestor(node - 1, k) << "\n";
    }
}

void input() {
    cin >> n;

    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;

        tree[u].push_back(v);
        tree[v].push_back(u);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    input();
    build();
    test();

    return 0;
}