#include <bits/stdc++.h>

using namespace std;

static const int MAX_SYMBOLS = 256;
static const int MAX_SIZE = 100001;

struct Node {
    bool isWord;
    char letter;
    Node* par;
    Node* link;
    Node* child[MAX_SYMBOLS + 1];

    Node() {
        isWord = false;
        link = nullptr;
        letter = ' ';
        for (int i = 0; i < MAX_SYMBOLS; i++) {
            child[i] = nullptr;
        }
    }
};

Node* root;
Node memoryHolder[MAX_SIZE];
int memCnt;

void addWord(string word) {
    Node* node = root;                              
    for (char letter : word) {         
        if (node->child[letter] == nullptr) {
            node->child[letter] = &memoryHolder[memCnt++];
            node->child[letter]->par = node;
            node->child[letter]->letter = letter;
        }
        node = node->child[letter];               
    }
    node->isWord = true;                        
}

void putLinks() {
    root->link = root;
    root->par = root;
    
    queue<Node*> q;     
    q.push(root);

    while (q.empty() == false) {
        Node* node = q.front();
        q.pop();

        for (int i = 0; i < MAX_SYMBOLS; i++) {
            if (node->child[i] != nullptr) {
                q.push(node->child[i]);
            }
        }

        Node* linkTo = node->par->link;

        while (linkTo->child[node->letter] == nullptr && linkTo != root) {
            linkTo = linkTo->link;
        }

        node->link = linkTo->child[node->letter];

        if (node->link == NULL || node->link == node) {
            node->link = root;
        }
    }
}

void checkText(string text) {
    Node* node = root;                      
    for (int i = 0; i < text.size(); i++) { 
        Node* n = node;

        while (n->child[text[i]] == nullptr && n != root) {
            n = n->link;
        }

        if (n == root) {            
            n = n->child[text[i]];

            if (n == nullptr) {
                n = root;
            }
        } else {
            n = n->child[text[i]];
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
        if (node->child[letter] == nullptr) {
            return false;
        }
        node = node->child[letter];
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