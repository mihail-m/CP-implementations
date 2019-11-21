#include <bits/stdc++.h>
using namespace std;

static const int SIZE = 1 << 18;
static const int SQRT_SIZE = 1 << 9;

int n, q;
int arr[SIZE];

int block_size;
int sqrtDecomp[SQRT_SIZE];
int updateValue[SQRT_SIZE];

void input() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
}

void build() {
	block_size = sqrt((double)n) + 1;
	for (int i = 0; i < n; i += block_size) {
		sqrtDecomp[i] = arr[i];
		for (int j = 1; j < block_size; j++) {
			sqrtDecomp[i + j] = min(sqrtDecomp[i + j - 1], arr[i + j]);
		}
	}
}

int findMin(int l, int r) {
	int ans = INT_MAX;
	
	int i = l;
	while (i <= r) {
		if (i % block_size == 0 && i + block_size - 1 <= r) {
			ans = min(ans, sqrtDecomp[i / block_size] + updateValue[i / block_size]);
			i += block_size;
		} else {
			ans = min(ans, arr[i] + updateValue[i / block_size]);
			i++;
		}
	}

	return ans;
}

void update(int l, int r, int v) {
	int i = l;
	while (i <= r) {
		if (i % block_size == 0) {
			updateValue[i / block_size] += v;
			i += block_size;
		} else {
			arr[i] += v;
			i++;
		}
	}
}

void solve() {
	cin >> q;
	for (int i = 0; i < q; i++) {
		char type;
		cin >> type;

		int l, r;
		cin >> l >> r;

		if (type == 'U') {
			int v;
			cin >> v;
			update(l, r, v);
		} else {
			cout << findMin(l, r) << "\n";
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	input();
	build();
	solve();

	return 0;
}