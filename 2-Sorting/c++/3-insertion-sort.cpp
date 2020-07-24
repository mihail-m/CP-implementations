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
    vector<int> testVector({5, 1, 4, 7, 13, 2});
    vector<int> sortedVector({1, 2, 4, 5, 7, 13});

    insertion_sort(testVector);
    
    assert(testVector == sortedVector);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    test();

    return 0;
}
