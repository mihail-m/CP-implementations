#include <bits/stdc++.h>
using namespace std;

void merge(vector<int>& arr, int l, int mid, int r) {
    vector<int> left;
    vector<int> right;

    for (int i = l; i <= mid; i++) {
        left.push_back(arr[i]);
    }

    for (int i = mid + 1; i <= r; i++) {
        right.push_back(arr[i]);
    }

    int i = 0;
    int j = 0;

    int index = l;
    while (i < left.size() && j < right.size()) {
        if (left[i] < right[j]) {
            arr[index++] = left[i++];
        } else {
            arr[index++] = right[j++];
        }
    }

    while (i < left.size()) {
        arr[index++] = left[i++];
    }

    while (j < right.size()) {
        arr[index++] = right[j++];
    }
}

void merge_sort(vector<int>& arr, int l, int r) {
    if (r - l <= 0) {
        return;
    }

    int mid = (l + r) / 2;

    merge_sort(arr, l, mid);
    merge_sort(arr, mid + 1, r);

    merge(arr, l, mid, r);
}

void test() {
    vector<int> testVector({5, 1, 4, 7, 13, 2});
    vector<int> sortedVector({1, 2, 4, 5, 7, 13});

    merge_sort(testVector, 0, testVector.size() - 1);
    
    assert(testVector == sortedVector);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    test();

    return 0;
}