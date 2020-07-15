#include <bits/stdc++.h>
using namespace std;

void selection_sort(vector<int>& arr) {
    for (int i = 0; i < arr.size(); i++) {
        int selected = i;

        for (int j = i + 1; j < arr.size(); j++) {
            if (arr[selected] > arr[j]) {
                selected = j;
            }
        }

        swap(arr[i], arr[selected]);
    }
}

void test() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    selection_sort(arr);

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
