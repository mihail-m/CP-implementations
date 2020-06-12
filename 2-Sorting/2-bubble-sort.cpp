#include <bits/stdc++.h>
using namespace std;

void bubble_sort(vector<int>& arr) {
	for (int i = 0; i < arr.size(); i++) {
		for (int j = i; j > 0 && arr[j] < arr[j - 1]; j--) {
			swap(arr[j], arr[j - 1]);
		}
	}
}

void test() {
	int n;
	cin >> n;

	vector<int> arr(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	bubble_sort(arr);

	for (int i : arr) {
		cerr << i << " ";
	}
	cerr << "\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	test();

	return 0;
}
