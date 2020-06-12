#include <bits/stdc++.h>
using namespace std;

struct Node {
    int value;
    Node* link;

    Node() {
        value = 0;
        link = nullptr;
    }
};

class linked_list {
    private:
        Node* first;
        Node* last;

        int _elements;

    public:
        linked_list() {
            first = nullptr;
            last = nullptr;
            _elements = 0;
        }

        void insert_end(int num) {
            _elements++;

            if (last == nullptr) {
                first = new Node();
                first->value = num;
                last = first;
                return;
            }

            Node* temp = new Node();
            temp->value = num;
            last->link = temp;
            last = temp;
        }

        void insert_begin(int num) {
            _elements++;

            if (first == nullptr) {
                first = new Node();
                first->value = num;
                last = first;
                return;
            }

            Node* temp = new Node();
            temp->value = num;
            temp->link = first;
            first = temp;
        }

        void insert_pos(int num, int pos) {
            _elements++;

            if (pos >= _elements) {
                insert_end(num);
                return;
            }

            if (pos == 0) {
                insert_begin(num);
                return;
            }

            int cnt = 0;
            Node* cur = first;
            while (cnt < pos - 1) {
                cur = cur->link;
                cnt++;
            }

            Node* temp = new Node();
            temp->value = num;
            temp->link = cur->link;
            cur->link = temp;
        }

        void erase_begin() {
            if (first == nullptr) {
                return;
            }

            _elements--;

            Node* temp = first;
            first = first->link;
            delete temp;
        }

        void erase_end() {
            if (last == nullptr) {
                return;
            }

            _elements--;

            Node* temp = first;
            while (temp->link != last) {
                temp = temp->link;
            }
            
            last = temp;
            temp = temp->link;
            delete temp;
            last->link = nullptr;
        }

        void erase_pos(int pos) {
            if (pos >= _elements) {
                return;
            }

            if (pos == 0) {
                erase_begin();
                return;
            }

            if (pos == _elements - 1) {
                erase_end();
                return;
            }

            _elements--;

            int cnt = 0;
            Node* cur = first;
            while (cnt < pos - 1) {
                cur = cur->link;
                cnt++;
            }

            Node* temp = cur->link;
            cur->link = temp->link;
            delete temp;
        }

        void reverse() {
            if (_elements == 2) {
                swap(first->value, first->link->value);
                return;
            }

            Node* prev = first;
            Node* cur = first->link;
            Node* next = cur->link;

            while (next != nullptr) {
                cur->link = prev;

                prev = cur;
                cur = next;
                next = next->link;
            }

            cur->link = prev;
            first->link = nullptr;
            swap(first, last);
        }

        int elements() {
            return _elements;
        }

        void print() {
            Node* cur = first;
            while (cur != nullptr) {
                cout << cur->value << " ";
                cur = cur->link;
            }
            cout << "\n";
        }

        void free() {
            if (first == nullptr) {
                return;
            }

            Node* prev = first;
            Node* cur = first->link;

            while (cur != nullptr) {
                delete prev;

                prev = cur;
                cur = cur->link;
            }

            delete prev;
            _elements = 0;
        }
};

void test() {
    int n;
    cin >> n;

    linked_list l;

    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        l.insert_end(num);
    }

    l.print();
    l.insert_begin(15);
    l.print();
    l.reverse();
    l.print();
    l.erase_pos(0);
    l.print();
    l.erase_pos(3);
    l.print();
    l.insert_pos(14, 2);
    l.erase_end();
    l.print();
    l.free();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    freopen("test.in", "r", stdin);

    test();

    return 0;
}
