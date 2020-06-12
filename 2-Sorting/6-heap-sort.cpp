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
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    heap_sort(arr);

    for (int i : arr) {
        cerr << i << " ";
    }
    cerr << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    srand(time(nullptr));

    test();

    return 0;
}