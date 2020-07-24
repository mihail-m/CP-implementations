#include <bits/stdc++.h>
using namespace std;

int partition(vector<int>& arr, int l, int r)  { 
    int pivot = l + rand() % (r - l + 1);
    swap(arr[r], arr[pivot]);

    int i = l;

    for (int j = l; j < r; j++) {
        if (arr[j] <= arr[r]) {
            swap(arr[i], arr[j]); 
            i++; 
        } 
    } 

    swap(arr[i], arr[r]);

    return i; 
} 

void quick_sort(vector<int>& arr, int l, int r) {
    if (r - l <= 0) {
        return;
    }

    int pivot = partition(arr, l, r);

    quick_sort(arr, l, pivot - 1);
    quick_sort(arr, pivot + 1, r);
}

void test() {
    vector<int> testVector({5, 1, 4, 7, 13, 2});
    vector<int> sortedVector({1, 2, 4, 5, 7, 13});

    quick_sort(testVector, 0, testVector.size() - 1);

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