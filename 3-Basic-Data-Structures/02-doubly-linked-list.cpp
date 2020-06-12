#include <bits/stdc++.h>
using namespace std;

struct Node {
    int value;
    Node* prev;
    Node* next;

    Node() {
        value = 0;
        prev = nullptr;
        next = nullptr;
    }
};

class doubly_linked_list {
    private:
        Node* first;
        Node* last;

        int _elements;

    public:
        doubly_linked_list() {
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
            temp->prev = last;
            last->next = temp;
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
            temp->next = first;
            first->prev = temp;
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
                cur = cur->next;
                cnt++;
            }

            Node* temp = new Node();
            temp->value = num;
            temp->next = cur->next;
            temp->prev = cur;
            temp->next->prev = temp;
            temp->prev->next = temp;
        }

        void erase_begin() {
            if (first == nullptr) {
                return;
            }

            _elements--;

            Node* temp = first;
            first = first->next;
            first->prev = nullptr;
            delete temp;
        }

        void erase_end() {
            if (last == nullptr) {
                return;
            }

            _elements--;

            Node* temp = first;
            while (temp->next != last) {
                temp = temp->next;
            }
            
            last = temp;
            temp = temp->next;
            delete temp;
            last->next = nullptr;
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
                cur = cur->next;
                cnt++;
            }

            Node* temp = cur->next;
            cur->next = temp->next;
            cur->next->prev = cur;
            delete temp;
        }

        void reverse() {
            if (_elements == 2) {
                swap(first->value, first->next->value);
                return;
            }

            Node* forward = first;
            Node* backward = last;

            int cnt = 0;
            while (cnt < _elements / 2) {
                swap(forward->value, backward->value);
                forward = forward->next;
                backward = backward->prev;
                cnt++;
            }
        }

        int elements() {
            return _elements;
        }

        void print() {
            Node* cur = first;
            while (cur != nullptr) {
                cout << cur->value << " ";
                cur = cur->next;
            }
            cout << "\n";
        }

        void free() {
            if (first == nullptr) {
                return;
            }

            Node* temp = first;
            Node* cur = first->next;

            while (cur != nullptr) {
                delete temp;

                temp = cur;
                cur = cur->next;
            }

            delete temp;
            _elements = 0;
        }
};

void test() {
    int n;
    cin >> n;

    doubly_linked_list l;

    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        l.insert_end(num);
    }

    l.print();
    l.reverse();
    l.print();
    l.free();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    test();

    return 0;
}
