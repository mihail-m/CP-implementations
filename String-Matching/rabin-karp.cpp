#include <bits/stdc++.h>
using namespace std;

static const int MOD = 1000000000 + 7; // 10^9 + 7 (prime number)
static const int BASE = 257; // prime number
static const int MAX_SIZE = 100001;

long long basePowers[MAX_SIZE];
long long prefixHash[MAX_SIZE];

void getPowers(int to) {
	basePowers[0] = 1;
	for (int i = 1; i <= to; i++) {
		basePowers[i] = (basePowers[i - 1] * BASE) % MOD;
	}
}

void getPrefixHashes(string text) {
	for (int i = 0; i < text.size(); i++) {
		prefixHash[i + 1] = (prefixHash[i] + text[i] * basePowers[i]) % MOD;
	}
}

long long getHash(string word) {
	long long result = 0;

	for (int i = 0; i < word.size(); i++) {
		result = (result + word[i] * basePowers[i]) % MOD;
	}

	return result;
}

int rabinKarp(string text, string word) {
	getPowers(text.size());
	getPrefixHashes(text);

	long long wordHash = getHash(word);
	long long curHash = prefixHash[word.size()];

	int occurrences = (curHash == wordHash);

	for (int i = word.size() + 1; i <= text.size(); i++) {
		curHash = (prefixHash[i] + MOD - prefixHash[i - word.size()]) % MOD;
		occurrences += (curHash == ((wordHash * basePowers[i - word.size()]) % MOD));
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

	cout << rabinKarp(text, word) << endl;

	return 0;
}
