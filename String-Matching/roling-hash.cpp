#include <bits/stdc++.h>
using namespace std;

static const int MOD = 1000000000 + 7; // 10^9 + 7 (prime number)
static const int BASE = 257; // prime number
static const int MAX_SIZE = 100001;

long long basePowers[MAX_SIZE];

void getPowers(int to) {
	basePowers[0] = 1;
	for (int i = 1; i <= to; i++) {
		basePowers[i] = (basePowers[i - 1] * BASE) % MOD;
	}
}
 
long long getHash(string word) {
	long long result = 0;

	for (int i = 0; i < word.size(); i++) {
		result = (result + word[i] * basePowers[i]) % MOD;
	}

	return result;
}

int rollingHash(string text, string word) {
	getPowers(word.size());

	long long wordHash = getHash(word);
	long long curHash = getHash(text.substr(0, word.size()));

	int occurrences = (curHash == wordHash);

	for (int i = word.size(); i < text.size(); i++) {
		curHash -= (text[i - word.size()] * basePowers[word.size() - 1]) % MOD;
		curHash = ((curHash * BASE) % MOD + text[i]) % MOD;

		occurrences += (curHash == wordHash);
	}

	return occurrences;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	string text;
	string word;

	cin >> text;
	cin >> word;

	cout << rollingHash(text, word) << "\n";

	return 0;
}
