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
    vector<int> testVector({5, 1, 4, 7, 13, 2});
    vector<int> sortedVector({1, 2, 4, 5, 7, 13});

    selection_sort(testVector);
    
    assert(testVector == sortedVector);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    test();

    return 0;
}
