#include <bits/stdc++.h>
using namespace std;

static const int MAX_SIZE = 1 << 18;

int n;
int arr[MAX_SIZE];

bool jump_search(int num) {
    int jump = sqrt(n);

    int i = 0;
    while (i < n) {
        if (arr[i] == num) {
            return true;
        }

        if (arr[i] > num) {
            break;
        }

        i = min(i + jump, n);
    }

    for (int j = 1; j < jump; j++) {
        if (arr[i - j] == num) {
            return true;
        }
    }

    return false;
}

void test() {
    int num;
    cin >> num;

    cerr << jump_search(num) << endl;
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