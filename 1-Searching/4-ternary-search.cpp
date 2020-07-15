#include <bits/stdc++.h>
using namespace std;

static const int MAX_SIZE = 1 << 18;

int n;
int arr[MAX_SIZE];

bool ternary_search(int num) { 
    int l = 0;
    int r = n - 1;

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
    int num;
    cin >> num;

    cerr << ternary_search(num) << endl;
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