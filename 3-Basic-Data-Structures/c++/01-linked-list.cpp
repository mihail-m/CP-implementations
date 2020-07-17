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
            if (pos < 0 || pos > _elements) {
                throw invalid_argument("Possition out of bounds.");
            }

            _elements++;

            if (pos == _elements) {
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
            _elements--;

            Node* temp = first;
            first = first->link;
            delete temp;
        }

        void erase_end() {
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
            if (pos >= _elements || pos < 0) {
                throw invalid_argument("Possition out of bounds.");
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

        int get_begin() {
            return first->value;
        }

        int get_end() {
            return last->value;
        }

        int get(int pos) {
            if (pos >= _elements || pos < 0) {
                throw invalid_argument("Possition out of bounds.");
            }

            int cnt = 0;
            Node* cur = first;
            while (cnt < pos) {
                cur = cur->link;
                cnt++;
            }

            return cur->value;
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
