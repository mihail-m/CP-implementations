#include <bits/stdc++.h>
using namespace std;

static const int MAX_SIZE = 1 << 18;

int n;
int arr[MAX_SIZE];

int partition(int l, int r)  { 
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

int kth_smallest(int k) {
    int l = 0;
    int r = n - 1;

    while (l <= r) {
    	int pivot = partition(l, r);

    	if (pivot == k - 1) {
    		return arr[pivot];
    	}

    	if (arr[pivot] < k) {
    		l = pivot + 1;
    	} else {
    		r = pivot - 1;
    	}
    }

    return INT_MIN;
} 


void test() {
	int k;
	cin >> k;

	srand(time(nullptr));

	cerr << kth_smallest(k) << endl;
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