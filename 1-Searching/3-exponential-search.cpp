#include <bits/stdc++.h>
using namespace std;

static const int MAX_SIZE = 1 << 18;

int n;
int arr[MAX_SIZE];

bool bin_search(int l, int r, int num) {
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

bool exp_search(int num) {
    if (arr[0] == num) {
        return true;
    }

    int i = 1;
    while (i < n && arr[i] < num) {
        i *= 2;
    }

    return bin_search(i / 2, min(i, n - 1), num);
}

void test() {
    int num;
    cin >> num;

    cerr << exp_search(num) << endl;
}

void input() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    input();
    test();

    return 0;
}