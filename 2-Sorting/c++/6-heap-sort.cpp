#include <bits/stdc++.h>
using namespace std;

int hepify(vector<int>& arr, int n, int node)  { 
    int left = 2 * node + 1;
    int right = 2 * node + 2;

    int root = node;

    if (left < n && arr[left] > arr[root]) {
        root = left;
    }

    if (right < n && arr[right] > arr[root]) {
        root = right;
    }

    if (root != node) {
        swap(arr[node], arr[root]);
        hepify(arr, n, root);
    }
} 

void heap_sort(vector<int>& arr) {
    for (int i = arr.size() / 2 - 1; i >= 0; i--) {
        hepify(arr, arr.size(), i);
    }

    for (int i = arr.size() - 1; i >= 0; i--) {
        swap(arr[i], arr[0]);
        hepify(arr, i, 0);
    }
}

void test() {
    vector<int> testVector({5, 1, 4, 7, 13, 2});
    vector<int> sortedVector({1, 2, 4, 5, 7, 13});

    heap_sort(testVector);
    
    assert(testVector == sortedVector);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    srand(time(nullptr));

    test();

    return 0;
}