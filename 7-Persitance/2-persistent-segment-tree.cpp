#include <bits/stdc++.h>
using namespace std;

static const int SIZE = 1 << 18;

struct Node {
    long long  value;
    long long carry;

    int from;
    int to;

    Node* left;
    Node* right;
};

vector<Node*> roots;

long long numbers[SIZE];

Node* build(Node *node, int from, int to) {
    node->from = from;
    node->to = to;
    node->carry = 0;

    if (from == to) {
        node->value = numbers[to];
        return node;
    }

    node->left = new Node;
    node->right = new Node;
    
    int mid = (from + to) >> 1;
    node->left = build(node->left, from, mid);
    node->right = build(node->right, mid + 1, to);

    node->value = node->left->value + node->right->value;

    return node;
}

Node* updateSpecific(Node *node, int from, int to, long long value) {
    Node *uptNode = new Node;
    uptNode->from = node->from;
    uptNode->to = node->to;

    if (node->from >= from and node->to <= to) {
        uptNode->value = node->value + (long long)(node->to - node->from + 1) * value;
        uptNode->carry = node->carry + value;
        uptNode->left = node->left;
        uptNode->right = node->right;

        return uptNode;
    }

    uptNode->carry = node->carry;

    if (node->left->to >= from) {
        uptNode->left = updateSpecific(node->left, from, to, value);
    } else {
        uptNode->left = node->left;
    }

    if (node->right->from <= to) {
        uptNode->right = updateSpecific(node->right, from, to, value);
    } else {
        uptNode->right = node->right;
    }

    long long intervalCarry = (long long)(node->to - node->from + 1) * uptNode->carry;
    uptNode->value = uptNode->left->value + uptNode->right->value + intervalCarry;

    return uptNode;
}

long long getSumSpecific(Node *node, int from, int to) {
    if (node->from >= from and node->to <= to) {
        return node->value;
    }

    long long returnValue = 0;

    if (node->left->to >= from) {
        returnValue += getSumSpecific(node->left, from, to);
    }

    if (node->right->from <= to) {
        returnValue += getSumSpecific(node->right, from, to);
    }

    int intervalFrom = max(node->from, from);
    int intervalTo = min(node->to, to);

    return returnValue + (long long)(intervalTo - intervalFrom + 1) * node->carry;
}

long long getSum(int from, int to, int time) {
    return getSumSpecific(roots[time], from, to);
}

void update(int from, int to, long long value, int time) {
    Node* newRoot = new Node;
    newRoot = updateSpecific(roots[time], from, to, value);
    roots.push_back(newRoot);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    return 0;
}