#include <bits/stdc++.h>
using namespace std;

static const int SIZE = 1000000;

struct Node {
    int val;
    int from, to;
    Node* left;
    Node* right;
};

int arr[SIZE];
vector<Node*> roots;

void build(Node* node, int from, int to) {
    node->from = from;
    node->to = to;

    if (from == to) {
        node->val = arr[from];
        node->left = nullptr;
        node->right = nullptr;
        return;
    }

    node->left = new Node;
    node->right = new Node;

    int mid = (from + to) / 2;
    build(node->left, from, mid);
    build(node->right, mid + 1, to);
}

Node* update(Node* node, int index, int val) {
    Node* newNode = new Node;
    newNode->from = node->from;
    newNode->to = node->to;

    if (node->from == node->to) {
        newNode->val = val;
        newNode->left = nullptr;
        newNode->right = nullptr;

        return newNode;
    }

    if (index <= node->left->to) {
        newNode->left = update(node->left, index, val);
        newNode->right = node->right;
    } else {
        newNode->right = update(node->right, index, val);
        newNode->left = node->left;
    }

    return newNode;
}

int get_val(Node* node, int index) {
    if (node->from == node->to && node->from == index) {
        return node->val;
    }

    if (index <= node->left->to) {
        return get_val(node->left, index);
    }

    return get_val(node->right, index);
}

void test() {
    int n = 6;
    int testArr[6] = {1, 2, 3, 4, 5, 6};
    
    for (int i = 0; i < n; i++) {
        arr[i] = testArr[i];
    }

    Node* root = new Node;
    build(root, 0, n - 1);

    roots.push_back(root);

    int q = 11;

    vector<pair<string, vector<int>>> queries;

    queries.push_back({"create", {1, 6, 10}});
    queries.push_back({"create", {2, 5, 8}});
    queries.push_back({"create", {1, 5, 30}});

    queries.push_back({"get", {1, 6}});
    queries.push_back({"get", {1, 5}});
    queries.push_back({"get", {2, 6}});
    queries.push_back({"get", {2, 5}});
    queries.push_back({"get", {3, 6}});
    queries.push_back({"get", {3, 5}});
    queries.push_back({"get", {4, 6}});
    queries.push_back({"get", {4, 5}});

    int ansCnt = 0;
    int ans[8] = {6, 5, 10, 5, 10, 8, 6, 30};

    for (int i = 0; i < q; i++) {
        string type = queries[i].first;

        if (type == "create") {
            int time = queries[i].second[0]; 
            int ind = queries[i].second[1];
            int val = queries[i].second[2];
            
            Node* newRoot = update(roots[time - 1], ind - 1, val);
            roots.push_back(newRoot);
        }
        else {
            int time = queries[i].second[0]; 
            int ind = queries[i].second[1];
            assert(ans[ansCnt++] == get_val(roots[time - 1], ind - 1));
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    test();

    return 0;
}