#include <bits/stdc++.h>
using namespace std;

bool ternary_search(vector<int>& arr, int num) { 
    int l = 0;
    int r = arr.size() - 1;

    while (l <= r) {
        int mid1 = l + (r - l) / 3;
        int mid2 = r - (r - l) / 3;

        if (arr[mid1] == num || arr[mid2] == num) {
            return true;
        }

        if (num < arr[mid1]) { 
            r = mid1 - 1; 
        } 
        else if (num > arr[mid2]) { 
            l = mid2 + 1; 
        } 
        else { 
            l = mid1 + 1;
            r = mid2 - 1; 
        }
    }

    return false;
}

void test() {
    vector<int> testVector({1, 5, 9, 17, 33, 75});
    assert(ternary_search(testVector, 17));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    test();

    return 0;
}