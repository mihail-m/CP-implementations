#include <bits/stdc++.h>
using namespace std;

static const int SIZE = 1 << 10;

int n, m, q;
int mat[SIZE][SIZE];

struct segment_node_2D {
    int value;
    int carry;

    int top;
    int bottom;
    int left;
    int right;

    segment_node_2D* left_child;
    segment_node_2D* right_child;

    void push() {
        value += (top - bottom + 1) * (right - left + 1) * carry; // for min or max just value += carry
        
        if (left_child) {
            left_child->carry += carry;
            right_child->carry += carry;
        }

        carry = 0;
    }
};

segment_node_2D* root;
segment_node_2D memory_holder[4 * SIZE * SIZE];
int memory_cnt;

void build(segment_node_2D* node, int top, int bottom, int left, int right, int axis) {
    node->top = top;
    node->bottom = bottom;
    node->left = left;
    node->right = right;
    node->carry = 0;

    if (top == bottom && left == right) {
        node->value = mat[top][left];
        node->left_child = node->right_child = nullptr;
        return;
    }

    node->left_child = &memory_holder[memory_cnt++]; // new Node;
    node->right_child = &memory_holder[memory_cnt++]; // new Node;

    if ((axis == 0 || left == right) && top < bottom) {
        int mid = (top + bottom) / 2;
        build(node->left_child, top, mid, left, right, (axis + 1) % 2);
        build(node->right_child, mid + 1, bottom, left, right, (axis + 1) % 2);
    }

    if ((axis == 1 || top == bottom) && left < right) {
        int mid = (left + right) / 2;
        build(node->left_child, top, bottom, left, mid, (axis + 1) % 2);
        build(node->right_child, top, bottom, mid + 1, right, (axis + 1) % 2);
    }
    
    node->value = node->left_child->value + node->right_child->value;
}

void update(segment_node_2D* node, int top, int bottom, int left, int right, int v) {
    node->push();

    if (top > node->bottom || bottom < node->top || left > node->right || right < node->left) {
        return;
    }

    if (top <= node->top && bottom >= node->bottom && left <= node->left && right >= node->right) {
        node->carry += v;
        node->push();
        return;
    }

    update(node->left_child, top, bottom, left, right, v);
    update(node->right_child, top, bottom, left, right, v);

    node->value = node->left_child->value + node->right_child->value;
}

int find_sum(segment_node_2D* node, int top, int bottom, int left, int right) {
    node->push();

    if (top > node->bottom || bottom < node->top || left > node->right || right < node->left) {
        return 0;
    }

    if (top <= node->top && bottom >= node->bottom && left <= node->left && right >= node->right) {
        return node->value;
    }

    return find_sum(node->left_child, top, bottom, left, right) + find_sum(node->right_child, top, bottom, left, right);
}

void test() {
    n = 4;
    m = 6;

    int testMat[4][6] = {
        {5, 1, 3, 4, 11, 7},
        {7, 3, 14, 2, 11, 9},
        {99, 8, 34, 35, 17, 6}, 
        {31, 7, 9, 5, 15, 44}
    };

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            mat[i][j] = testMat[i][j];
        }
    }

    root = new segment_node_2D();
    build(root, 0, n - 1, 0, m - 1, 0);

    assert(387 == root->value);

    q = 3;
    int c[3][4] = {
        {0, 1, 2, 4},
        {1, 3, 3, 5},
        {2, 1, 3, 4}
    };

    int ans[3] = {143, 144, 130};

    for (int i = 0; i < q; i++) {
        assert(ans[i] == find_sum(root, c[i][0], c[i][2], c[i][1], c[i][3]));
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    test();

    return 0;
}