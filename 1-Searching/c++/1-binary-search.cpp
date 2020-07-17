#include <bits/stdc++.h>
using namespace std;

static const int MAX_SIZE = 1 << 18;

int n;
int arr[MAX_SIZE];

bool bin_search(int num) {
    int l = 0;
    int r = n - 1;

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
    int num;
    cin >> num;

    cerr << bin_search(num) << endl;
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
