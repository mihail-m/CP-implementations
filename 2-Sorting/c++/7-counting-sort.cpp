#include <bits/stdc++.h>
using namespace std;

void counting_sort(vector<int>& arr) {
    int MAX_ELEMENT = INT_MIN;
    int OFFSET = INT_MAX;

    for (int num : arr) {
        MAX_ELEMENT = max(MAX_ELEMENT, num);
        OFFSET = min(OFFSET, num);
    }

    if (OFFSET < 0) {
        OFFSET = -OFFSET;
    } else {
        OFFSET = 0;
    }

    vector<int> count(MAX_ELEMENT + OFFSET + 1, 0);

    for (int num : arr) {
        count[num + OFFSET]++;
    }

    int index = 0;

    for (int num = 0; num < count.size(); num++) {
        while (count[num] > 0) {
            arr[index++] = num - OFFSET;
            count[num]--;
        }
    }
}

void test() {
    vector<int> testVector({5, 1, 4, 7, 13, 2});
    vector<int> sortedVector({1, 2, 4, 5, 7, 13});

    counting_sort(testVector);
    
    assert(testVector == sortedVector);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    test();

    return 0;
}
