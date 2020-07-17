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
};

void test() {
    int n;
    cin >> n;

    stack_int s;

    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        s.push(num);
    }

    while (s.size() > 0) {
        cerr << s.poll() << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    test();

    return 0;
}
