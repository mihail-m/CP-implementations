#include <bits/stdc++.h>
using namespace std;

static const int MAX_SIZE = 1 << 18;
static const int LOG2 = 18;

int n, q;
vector<int> g[MAX_SIZE];
bool used[MAX_SIZE];
bool important[MAX_SIZE];

int t = 0;
int in[MAX_SIZE];
int out[MAX_SIZE];

int cnt = 0;
int depth[2 * MAX_SIZE];
int oiler[2 * MAX_SIZE];
int occur[MAX_SIZE];

int pw_2[2 * MAX_SIZE];
pair<int, int> min_st[MAX_SIZE][32];

vector<int> vt[MAX_SIZE];
int subtree_sz[MAX_SIZE];

void dfs(int v, int d) {
    used[v] = true;
    in[v] = t;
    t++;

    depth[cnt] = d;
    oiler[cnt] = v;
    occur[v] = cnt;
    cnt++;

    for (int u : g[v]) {
        if (!used[u]) {
            dfs(u, d + 1);

            depth[cnt] = d;
            oiler[cnt] = v;
            cnt++;
        }
    }

    out[v] = t++;
}

void build_lsa(int root) {
    dfs(root, 0);

    for (int i = 2; i < 2 * n; i++) {
        pw_2[i] = pw_2[i / 2] + 1;
    }

    for (int i = 0; i < 2 * n; i++) {
        min_st[i][0] = { depth[i], oiler[i] };
    }

    for (int pw = 1; pw < LOG2; pw++) {
        for (int i = 0; i + (1 << pw) <= 2 * n; i++) {
            min_st[i][pw] = min(min_st[i][pw - 1], min_st[i + (1 << (pw - 1))][pw - 1]);
        }
    }
}

bool upper(int u, int v) {
    return in[u] < in[v] && out[u] > out[v];
}

int lsa(int u, int v) {
    int f = occur[u];
    int t = occur[v];

    if (f > t) swap(f, t);

    int sz = pw_2[t - f];

    return min(min_st[f][sz], min_st[t - (1 << sz)][sz]).second;
}

bool cmp(int a, int b) {
    return in[a] < in[b];
}

int build_vt(vector<int> &nodes) {
    sort(nodes.begin(), nodes.end(), cmp);

    int to = nodes.size();
    for (int i = 1; i < to; i++) {
        nodes.push_back(lsa(nodes[i - 1], nodes[i]));
    }

    sort(nodes.begin(), nodes.end(), cmp);
    nodes.erase(unique(nodes.begin(), nodes.end()), nodes.end());

    vector<int> vt_stack;
    vt_stack.push_back(nodes[0]);

    for (int i = 1; i < nodes.size(); i++) {
        int u = nodes[i];

        while (vt_stack.size() >= 2 && !upper(vt_stack.back(), u)) {
            vt[vt_stack[vt_stack.size() - 2]].push_back(vt_stack.back());
            vt_stack.pop_back();
        }

        vt_stack.push_back(u);
    }

    while (vt_stack.size() >= 2) {
        vt[vt_stack[vt_stack.size() - 2]].push_back(vt_stack.back());
        vt_stack.pop_back();
    }

    return vt_stack[0];
}

long long sum_dist(int u, int par, int total) {
    long long res = 0;

    subtree_sz[u] = important[u];
    for (int v : vt[u]) {
        res += sum_dist(v, u, total);
        subtree_sz[u] += subtree_sz[v];
    }

    if (par != -1) {
        int dist = depth[occur[u]] - depth[occur[par]];
        res += dist * (total - subtree_sz[u]) * subtree_sz[u];
    }

    return res;
}

void solve() {
    build_lsa(0);

    for (int i = 0; i < q; i++) {
        int k;
        cin >> k;

        vector<int> nodes;
        for (int i = 0; i < k; i++) {
            int node;
            cin >> node;
            node--;

            nodes.push_back(node);
            important[node] = true;
        }

        cout << sum_dist(build_vt(nodes), -1, k) << "\n";

        for (int i : nodes) {
            important[i] = false;
            vt[i].clear();
            subtree_sz[i] = 0;
        }
    }
}

void input() {
    cin >> n >> q;

    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;

        g[u].push_back(v);
        g[v].push_back(u);
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

