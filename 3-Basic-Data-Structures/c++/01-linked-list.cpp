#include <bits/stdc++.h>
using namespace std;

struct Node {
    int value;
    Node* link;

    Node() {
        value = 0;
        link = nullptr;
    }

    Node(int v, Node* l) {
        value = v;
        link = l;
    }
};

class linked_list {
    private:
        Node* first;
        Node* last;

        int _elements;

        Node* goToPos(int pos) {
            int cnt = 0;
            Node* cur = first;
            while (cnt < pos) {
                cur = cur->link;
                cnt++;
            }
            return cur;
        }

    public:
        linked_list() {
            first = nullptr;
            last = nullptr;
            _elements = 0;
        }

        void insert_end(int num) {
            _elements++;

            if (last == nullptr) {
                first = new Node(num, nullptr);
                last = first;
                return;
            }

            last->link = new Node(num, nullptr);
            last = last->link;
        }

        void insert_begin(int num) {
            _elements++;

            if (first == nullptr) {
                first = new Node(num, nullptr);
                last = first;
                return;
            }

            first = new Node(num, first);
        }

        void insert_at(int num, int pos) {
            if (pos < 0 || pos > _elements) {
                throw invalid_argument("Possition out of bounds.");
            }

            if (pos == _elements) {
                insert_end(num);
                return;
            }

            if (pos == 0) {
                insert_begin(num);
                return;
            }

            _elements++;

            Node* temp = goToPos(pos - 1);
            temp->link = new Node(num, temp->link);
        }

        void erase_begin() {
            _elements--;

            Node* temp = first;
            first = first->link;
            delete temp;
        }

        void erase_end() {
            _elements--;

            Node* temp = goToPos(_elements - 1);
            
            last = temp;
            temp = temp->link;
            delete temp;
            last->link = nullptr;
        }

        void erase_at(int pos) {
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

            Node* cur = goToPos(pos - 1);

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

            return goToPos(pos)->value;
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

        string to_string() {
            string res = "[";

            Node* cur = first;
            while (cur != nullptr) {
                res.append(std::to_string(cur->value));
                if (cur->link != nullptr) {
                    res.append(", ");
                }

                cur = cur->link;
            }

            res.append("]");
            return res;
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
    linked_list list;

    list.insert_begin(1);
    list.insert_end(5);
    list.insert_at(4, 1);
    list.insert_at(19, 2);
    assert("[1, 4, 19, 5]" == list.to_string());

    list.reverse();
    assert("[5, 19, 4, 1]" == list.to_string());

    list.erase_at(1);
    list.erase_end();
    assert("[5, 4]" == list.to_string());
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    test();

    return 0;
}
