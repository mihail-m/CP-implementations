#include <bits/stdc++.h>
using namespace std;

bool bin_search(vector<int>& arr, int num) {
    int l = 0;
    int r = arr.size() - 1;

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

void test() {
    vector<int> testVector({1, 5, 9, 17, 33, 75});
    assert(bin_search(testVector, 17));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    test();

    return 0;
}
