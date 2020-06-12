#include <bits/stdc++.h>
using namespace std;

void counting_sort(vector<int>& arr) {
	int MAX_ELEMENT = INT_MIN;
	int OFFSET = INT_MAX;

	for (int num : arr) {
		MAX_ELEMENT = max(MAX_ELEMENT, num);
		OFFSET = min(OFFSET, num);
	}

	if (OFFSET < 0) {
		OFFSET = -OFFSET;
	} else {
		OFFSET = 0;
	}

	vector<int> count(MAX_ELEMENT + OFFSET + 1, 0);

	for (int num : arr) {
		count[num + OFFSET]++;
	}

	int index = 0;

	for (int num = 0; num < count.size(); num++) {
		while (count[num] > 0) {
			arr[index++] = num - OFFSET;
			count[num]--;
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

	counting_sort(arr);

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
