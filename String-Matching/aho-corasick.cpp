#include <bits/stdc++.h>

using namespace std;

static const int BASE = 256;
static const int MAX_SIZE = 100001;

struct Node {
    bool isWord;
    char letter;
    Node* parent;
    Node* link;
    Node* children[BASE + 1];

    Node() {
        isWord = false;
        link = nullptr;
        letter = ' ';
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
            node->children[letter]->parent = node;
            node->children[letter]->letter = letter;
        }
        node = node->children[letter];               
    }
    node->isWord = true;                        
}

void putLinks() {
    root->link = root;
    root->parent = root;
    
    queue<Node*> q;     
    q.push(root);

    while (q.empty() == false) {
        Node* node = q.front();
        q.pop();

        for (int i = 0; i < BASE; i++) {
            if (node->children[i] != nullptr) {
                q.push(node->children[i]);
            }
        }

        Node* linkTo = node->parent->link;

        while (linkTo->children[node->letter] == nullptr && linkTo != root) {
            linkTo = linkTo->link;
        }

        node->link = linkTo->children[node->letter];

        if (node->link == NULL || node->link == node) {
            node->link = root;
        }
    }
}

void checkText(string text) {
    Node* node = root;                      
    for (int i = 0; i < text.size(); i++) { 
        Node* n = node;

        while (n->children[text[i]] == nullptr && n != root) {
            n = n->link;
        }

        if (n == root) {            
            n = n->children[text[i]];

            if (n == nullptr) {
                n = root;
            }
        } else {
            n = n->children[text[i]];
        }

        Node* n1 = n;  

        while (n1 != root) {     
            if (n1->isWord) { 
                cout << "Word ending at index: " << i << endl;
            }

            n1 = n1->link;
        }

        node = n;
    }
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
    root = new Node();

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string word;
        cin >> word;
        addWord(word);
    }
    putLinks();
}

void solve() {
    string text;
    cin >> text;
    checkText(text);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    build();
    solve();

    return 0;
}