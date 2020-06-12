#include <bits/stdc++.h>
using namespace std;

void insertion_sort(vector<int>& arr) {
	for (int i = 1; i < arr.size(); i++) {
		int value = arr[i];

		int j = i - 1;

		while (j >= 0 && arr[j] > value) {
			arr[j + 1] = arr[j];
			j--;
		}

		arr[j + 1] = value;
	}
}

void test() {
	int n;
	cin >> n;

	vector<int> arr(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	insertion_sort(arr);

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
