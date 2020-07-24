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

int kth_smallest(vector<int>& arr, int k) {
    int l = 0;
    int r = arr.size() - 1;

    while (l <= r) {
        int pivot = partition(arr, l, r);

        if (pivot == k - 1) {
            return arr[pivot];
        }

        if (pivot < k - 1) {
            l = pivot + 1;
        } else {
            r = pivot - 1;
        }
    }

    return INT_MIN;
} 

void test() {
    vector<int> testVector({1, 5, 9, 17, 33, 75});
    random_shuffle(testVector.begin(), testVector.end());
    
    assert(9 == kth_smallest(testVector, 3));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    test();

    return 0;
}