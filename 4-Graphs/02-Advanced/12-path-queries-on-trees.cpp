 #include <bits/stdc++.h>
using namespace std;

static const int MAX_SIZE = 1 << 18;
static const int LOG2 = 18;

int n;
vector<pair<int, int>> tree[MAX_SIZE];

int cnt = 0;
int depth[2 * MAX_SIZE];
int oiler[2 * MAX_SIZE];
int occur[MAX_SIZE];
int dist[MAX_SIZE];

int pw_2[2 * MAX_SIZE];
pair<int, int> min_st[MAX_SIZE][32];


void dfs(int node, int dpth = 0, int dst = 0, int par = -1) {
    depth[cnt] = dpth;
    oiler[cnt] = node;
    occur[node] = cnt;
    dist[node] = dst;
    cnt++;

    for (auto p : tree[node]) {
        int child = p.first;
        int cost = p.second;

        if (child != par) {
            dfs(child, dpth + 1, dst + cost, node);

            depth[cnt] = dpth;
            oiler[cnt] = node;
            cnt++;
        }
    }
}

void build_lca(int root) {
    dfs(root);

    for (int i = 2; i < 2 * n; i++) {
        pw_2[i] = pw_2[i / 2] + 1;
    }

    for (int i = 0; i < 2 * n; i++) {
        min_st[i][0] = {depth[i], oiler[i]};
    }

    for (int pw = 1; pw < LOG2; pw++) {
        for (int i = 0; i + (1 << pw) <= 2 * n; i++) {
            min_st[i][pw] = min(min_st[i][pw - 1], min_st[i + (1 << (pw - 1))][pw - 1]);
        }
    }
}

int lca(int u, int v) {
    int f = occur[u];
    int t = occur[v];

    if (f > t) swap(f, t);

    int sz = pw_2[t - f];

    return min(min_st[f][sz], min_st[t - (1 << sz)][sz]).second + 1;
}

void test() {
	int q;
    cin >> q;

    for (int i = 0; i < q; i++) {
        int u, v;
        cin >> u >> v;

        cerr << lca(u - 1, v - 1) << "\n";
    }
}

void input() {
    cin >> n;

    for (int i = 0; i < n - 1; i++) {
        int u, v, cost;
        cin >> u >> v >> cost;
        u--, v--;

        tree[u].push_back({v, cost});
        tree[v].push_back({u, cost});
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    input();
    build_lca(0);
    test();

    return 0;
}

