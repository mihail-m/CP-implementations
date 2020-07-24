#include <bits/stdc++.h>
using namespace std;

bool bin_search(vector<int> arr, int l, int r, int num) {
    while (l <= r) {
        int mid = (l + r) / 2;

        if (arr[mid] == num) {
            return true;
        }

        if (arr[mid] < num) {
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }

    return false;
}

bool exp_search(vector<int>& arr, int num) {
    if (arr[0] == num) {
        return true;
    }

    int i = 1;
    while (i < arr.size() && arr[i] < num) {
        i *= 2;
    }

    return bin_search(arr, i / 2, min(i, (int)arr.size() - 1), num);
}

void test() {
    vector<int> testVector({1, 5, 9, 17, 33, 75});
    assert(exp_search(testVector, 17));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    test();

    return 0;
}