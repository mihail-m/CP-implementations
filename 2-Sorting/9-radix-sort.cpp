#include <bits/stdc++.h>
using namespace std;

void counting_sort(vector<int>& arr, int pos) {
    vector<int> count(10, 0);

    for (int num : arr) {
        count[(num / pos) % 10]++;
    }

    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }

    vector<int> res(arr.size());

    for (int i = arr.size() - 1; i >= 0; i--) {
        int digit = (arr[i] / pos) % 10;

        res[count[digit] - 1] = arr[i];

        count[digit]--;
    }

    arr = res;
}

void radix_sort(vector<int>& arr) {
    int max_num = INT_MIN;
    for (int num : arr) {
        max_num = max(max_num, num);
    }

    for (int pos = 1; max_num / pos > 0; pos *= 10) {
        counting_sort(arr, pos);
    }
}

void test() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    radix_sort(arr);

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
