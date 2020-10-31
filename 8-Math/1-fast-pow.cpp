#include <bits/stdc++.h>
using namespace std;

long long fast_pow(int num, int power) {
	if (power == 0) {
		return 1;
	}

	if (power == 1) {
		return num;
	}

	long long result = fast_pow(num, power / 2);

	if (power % 2 == 0) {
		return result * result;
	}// else
	return result * result * num;
}

void test() {
	assert(5764801 == fast_pow(7, 8));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    test();

    return 0;
}