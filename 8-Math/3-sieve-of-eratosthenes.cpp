#include <bits/stdc++.h>
using namespace std;

static const int SIZE = 1e8;

int lp[SIZE + 1];
vector<int> prime;

void sieve_of_eratosthenes(int n) {
	for (int i = 2; i <= n; i++) {
	    if (lp[i] == 0) {
	        lp[i] = i;
	        prime.push_back(i);
	    }

	    for (int j = 0; j < prime.size() && prime[j] <= lp[i] && i * prime[j] <= n; j++) {
	        lp[i * prime[j]] = prime[j];
	    }
	}
}

void test() {
	sieve_of_eratosthenes(20);

	int expected[8] = {2, 3, 5, 7, 11, 13, 17, 19};

	assert(8 == prime.size());

	for (int i = 0; i < 8; i++) {
		assert(expected[i] == prime[i]);
	}
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    test();

    return 0;
}