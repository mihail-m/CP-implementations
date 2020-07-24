#include <bits/stdc++.h>
using namespace std;

bool jump_search(vector<int>& arr, int num) {
    int jump = sqrt(arr.size());

    int i = 0;
    while (i < arr.size()) {
        if (arr[i] == num) {
            return true;
        }

        if (arr[i] > num) {
            break;
        }

        i = min(i + jump, (int)arr.size());
    }

    for (int j = 1; j < jump; j++) {
        if (arr[i - j] == num) {
            return true;
        }
    }

    return false;
}

void test() {
    vector<int> testVector({1, 5, 9, 17, 33, 75});
    assert(jump_search(testVector, 17));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    test();

    return 0;
}