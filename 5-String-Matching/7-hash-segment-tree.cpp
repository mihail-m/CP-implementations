#include <bits/stdc++.h>
using namespace std;

const int MAX = 1 << 18;

const int base = 257;
const int mod = 1000000000 + 7;

/**
 * The node covering the interval [from, to] contains the hash of the substring (Sfrom, Sfrom+1, ..., Sto)
 */
struct Node {
    long long value;
    int from, to;

    Node* left;
    Node* right;
};

Node mem[4 * MAX];
int memCnt;

long long degree[MAX];

void build(Node* node, int from, int to, string &s) {
    node->from = from;
    node->to = to;

    if (from == to) {
        node->value = (int)s[from];
        node->left = nullptr;
        node->right = nullptr;
        return;
    }

    node->left = &mem[memCnt++];
    node->right = &mem[memCnt++];

    int mid = (from + to) >> 1;

    build(node->left, from, mid, s);
    build(node->right, mid + 1, to, s);

    int len = node->right->to - node->right->from + 1;
    node->value = node->value = (((degree[len] * node->left->value) % mod) + node->right->value) % mod;
}

void update(Node* node, int pos, char c) {
    if (node->from == node->to) {
        node->value = (int)c;
        return;
    }

    if (node->left->to >= pos) {
        update(node->left, pos, c);
    }
    else {
        update(node->right, pos, c);
    }

    int len = node->right->to - node->right->from + 1;
    node->value = (((degree[len] * node->left->value) % mod) + node->right->value) % mod;
}

pair<long long, int> getHash(Node* node, int from, int to) {
    if (node->from >= from && node->to <= to) {
        return make_pair(node->value, node->to - node->from + 1);
    }
    if (node->from > to || node->to < from) {
        return make_pair(0, 0);
    }

    pair<long long, int> l = getHash(node->left, from, to);
    pair<long long, int> r = getHash(node->right, from, to);

    long long h = (((l.first * degree[r.second]) % mod) + r.first) % mod;
    return make_pair(h, l.second + r.second);
}

/**
 * Given two strings s1 and s2 support the following operations:
 * 
 * - change the letter at position i in s1
 *
 * - change the letter at position j in s2
 *
 * - check if the substrings starting at positition i in s1 and at position j in s2 with length n match
 *
 */
void test() {
    int n, m;
    cin >> n >> m;

    string s1, s2;
    cin >> s1 >> s2;

    degree[0] = 1;
    for (int i = 1; i < MAX; i++) {
        degree[i] = (degree[i - 1] * base) % mod;
    }

    Node* root1 = new Node;
    build(root1, 0, s1.size() - 1, s1);

    Node* root2 = new Node;
    build(root2, 0, s2.size() - 1, s2);

    int q; // Number of queries
    cin >> q;
    for (int i = 0; i < q; i++) {
        int type;
        cin >> type;

        // change letter at position x in s1 to c
        if (type == 1) { 
            int x;
            char c;

            cin >> x >> c;
            update(root1, x, c);
        }

        // change letter at position y in s2 to c
        if (type == 2) { 
            int y;
            char c;

            cin >> y >> c;
            update(root2, y, c);
        }

        // check if the substring starting at position x in s1 with lenght k
        // and the substring starting at position y in s2 with lenght k match
        if (type == 3) {
            int k, x, y;
            cin >> k >> x >> y;

            int hashx = getHash(root1, x, x + k - 1).first;
            int hashy = getHash(root2, y, y + k - 1).first;

            cout << ((hashx == hashy) ? "YES" : "NO") << "\n";
        }
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    test();

    return 0;
}