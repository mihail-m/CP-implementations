#include <bits/stdc++.h>
using namespace std;

int** init_matrix(int n) {
    int** res = new int*[n];

    for (int i = 0; i < n; i++) {
        res[i] = new int[n];

        for (int j = 0; j < n; j++) {
            res[i][j] = 0;
        }
    }

    return res;
}

int** identity_matrix(int n) {
    int** res = init_matrix(n);

    for (int i = 0; i < n; i++) {
        res[i][i] = 1;
    }

    return res;
}

int** multiply_matrix(int** a, int** b, int n) {
    int** res = init_matrix(n);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int p = 0; p < n; p++) {
                  res[i][j] += a[i][p] * b[p][j];
            }
          }
    }

    return res;
}


int** pow_matrix(int** mat, int n, int degree) {
    if (degree == 0) {
        return identity_matrix(n);
    }

    if (degree == 1) {
        return mat;
    }

    int** res = pow_matrix(mat, n, degree / 2);

    res = multiply_matrix(res, res, n);

    if (degree % 2 == 0) {
        return res;
    }

    return multiply_matrix(res, mat, n);
}

int paths(int** mat, int from, int to) {
    return mat[from][to];
}

void test() {
    int** mat = new int*[9];
    
    //                     Graph adjacency matrix
    mat[0] = new int[9] {0, 1, 0, 0, 0, 0, 0, 1, 0};
    mat[1] = new int[9] {1, 0, 1, 0, 0, 0, 0, 1, 0};
    mat[2] = new int[9] {0, 1, 0, 1, 0, 1, 0, 0, 1};
    mat[3] = new int[9] {0, 0, 1, 0, 1, 1, 0, 0, 0};
    mat[4] = new int[9] {0, 0, 0, 1, 0, 1, 0, 0, 0};
    mat[5] = new int[9] {0, 0, 1, 1, 1, 0, 1, 0, 0};
    mat[6] = new int[9] {0, 0, 0, 0, 0, 1, 0, 1, 1};
    mat[7] = new int[9] {1, 1, 0, 0, 0, 0, 1, 0, 1};
    mat[8] = new int[9] {0, 0, 1, 0, 0, 0, 1, 1, 0};

    int** index = pow_matrix(mat, 9, 4);
    assert(16 == index[2][4]);
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    test();

    return 0;
}