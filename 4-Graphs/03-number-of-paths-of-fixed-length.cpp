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
	int n, m;
	cin >> n >> m;

	int** mat = init_matrix(n);

	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		u--, v--;

		mat[u][v] = 1;
		mat[v][u] = 1;
	} 

	int k;
	cin >> k;

	int** index = pow_matrix(mat, n, k);

	int q;
	cin >> q;
	for (int i = 0; i < q; i++) {
		int f, t;
		cin >> f >> t;
		f--, t--;

		cerr << paths(index, f, t) << "\n";
	}
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    test();

    return 0;
}