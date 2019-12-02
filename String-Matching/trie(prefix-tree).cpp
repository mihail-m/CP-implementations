#include <bits/stdc++.h>
using namespace std;

static const int BASE = 256;

struct Node {
	bool isWord;
	Node* children[BASE];

	Node() {
		isWord = false;
		for (int i = 0; i < BASE; i++) {
			children[i] = nullptr;
		}
	}
};

Node* root;
Node memoryHolder[MAX_SIZE];
int memCnt;

void addWord(string word) {
	Node* node = root;
	for (char letter : word) {
		if (node->children[letter] == nullptr) {
			node->children[letter] = &memoryHolder[memCnt++];
		}
		node = node->children[letter];
	}
	node->isWord = true;
}

bool findWord(string word) {
	Node* node = root;
	for (char letter : word) {
		if (node->children[letter] == nullptr) {
			return false;
		}
		node = node->children[letter];
	}
	return node->isWord;
}

void build() {
	int n;
	cin >> n;

	root = new Node();

	for (int i = 0; i < n; i++) {
		string word;
		cin >> word;
		addWord(word);
	}
}

void solve() {
	int q;
	cin >> q;

	for (int i = 0; i < q; i++) {
		string word;
		cin >> word;
		cout << findWord(word) << endl;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	build();
	solve();

	return 0;
}
