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

void test() {
    int** mat = new int*[4];
    
    mat[0] = new int[4] {3, 1, 2, 1};
    mat[1] = new int[4] {1, 2, 1, 3};
    mat[2] = new int[4] {3, 1, 4, 7};
    mat[3] = new int[4] {1, 9, 1, 6};

    int** result = pow_matrix(mat, 4, 4);

    int expectedResult[4][4] = {
        {1475, 3876, 1474, 4016},
        {1541, 4425, 1541, 4450},
        {3751, 10624, 3752, 10734},
        {3271, 9544, 3271, 9551}
    };
    
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            assert(expectedResult[i][j] == result[i][j]);
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