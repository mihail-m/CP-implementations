#include <bits/stdc++.h>
using namespace std;

static const int SIZE = 1 << 10;
static const int LOG2 = 10;

int n, m, q;
int mat[SIZE][SIZE];

int log_2[SIZE];
int st[SIZE][SIZE][LOG2][LOG2];

void build() {
    log_2[1] = 0;
    for (int i = 2; i < n; i++) {
        log_2[i] = log_2[i / 2] + 1;
    }

    for (int r = 0; r < n; r++) {
        for (int c = 0; c < m; c++) {
            st[r][c][0][0] = mat[r][c];
        }
    }

    for (int r = 0; r < n; r++) {
        for (int j = 1; j < LOG2; j++) {
            for (int c = 0; c + (1 << j) <= m; c++) {
                st[r][c][0][j] = min (st[r][c][0][j - 1], st[r][c + (1 << (j - 1))][0][j - 1]);
            }
        }
    }

    for (int i = 1; i < LOG2; i++) {
        for (int j = 0; j < LOG2; j++) {
            for (int r = 0; r + (1 << i) <= n; r++) {
                for (int c = 0; c + (1 << j) <= m; c++) {
                    st[r][c][i][j] = min(st[r][c][i - 1][j], st[r + (1 << (i - 1))][c][i - 1][j]);
                }
            }
        }
    }
}

int find_min(int r1, int c1, int r2, int c2) {
    int i = log_2[r2 - r1 + 1];
    int j = log_2[c2 - c1 + 1];

    // top left
    int rectangle1 = st[r1][c1][i][j];
    // top right
    int rectangle2 = st[r1][c2 - (1 << j) + 1][i][j];
    // bottom left
    int rectangle3 = st[r2 - (1 << i) + 1][c1][i][j];
    // bottom right
    int rectangle4 = st[r2 - (1 << i) + 1][c2 - (1 << j) + 1][i][j];

    return min(min(rectangle1, rectangle2), min(rectangle3, rectangle4));
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

    build();

    q = 3;
    int c[3][4] = {
        {0, 1, 2, 4},
        {1, 3, 3, 5},
        {2, 1, 3, 4}
    };

    int ans[3] = {1, 2, 7};

    for (int i = 0; i < q; i++) {
        assert(ans[i] == find_min(c[i][0], c[i][1], c[i][2], c[i][3]));
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    test();

    return 0;
}