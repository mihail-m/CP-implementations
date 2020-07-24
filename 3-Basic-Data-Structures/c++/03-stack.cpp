#include <bits/stdc++.h>
using namespace std;

class stack_int {
    private:
        int* arr;
        int _cap;
        int _size;

        void resize(int newCap) {
            int* temp = new int[_size];
            for (int i = 0; i < _size; i++) {
                temp[i] = arr[i];
            }

            delete[] arr;
            arr = new int[newCap];

            for (int i = 0; i < _size; i++) {
                arr[i] = temp[i];
            }

            delete[] temp;
        }

    public:
        stack_int() {
            arr = new int[16];
            _size = 0;
            _cap = 16;
        }

        void push(int value) {
            if (_size >= (2 * _cap) / 3) {
                resize(_cap * 2);
            }

            arr[_size] = value;
            _size++;
        }

        void pop() {
            if (_size == 0) {
                return;
            }

            _size--;
            
            if (_size <= _cap / 3) {
                resize(min(_cap * 2, 16));
            }
        }

        int top() {
            return arr[_size - 1];
        }

        int poll() {
            int res = top();
            pop();
            return res;
        }

        int size() {
            return _size;
        }

        string to_string() {
            string result = "[";
            for (int i = 0; i < _size; i++) {
                result.append(std::to_string(arr[i]));
                if (i < _size - 1) {
                    result.append(", ");
                }
            }
            result.append("]");
            return result;
        }
};

void test() {
    stack_int stack;
    stack.push(1);
    stack.push(7);
    stack.push(73);
    stack.push(2);

    assert(2 == stack.poll());
    assert(73 == stack.top());
    assert("[1, 7, 73]" == stack.to_string());
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    test();

    return 0;
}
