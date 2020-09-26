#include <bits/stdc++.h>
using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    //test();

    int num = 23;
    for (int i = 1; i <= 60; i++) {
    	cout << num << " ";
    	num = (23 * num) % 60;
    }

    return 0;
}