#include <bits/stdc++.h>
using namespace std;

class queue_int {
    private:
        int* arr;
        int _cap;
        int left;
        int right;

        void resize(int newCap) {
            int _size = right - left + 1;
            int* temp = new int[_size];
            for (int i = 0; i < _size; i++) {
                temp[i] = arr[left + i];
            }

            delete[] arr;
            arr = new int[newCap];

            for (int i = 0; i < _size; i++) {
                arr[i] = temp[i];
            }

            left = 0;
            right = _size - 1;

            delete[] temp;
        }

        void shift() {
            int _size = right - left + 1;

            for (int i = 0; i < _size; i++) {
                arr[i] = arr[left + 1];
            }

            left = 0;
            right = _size - 1;
        }

    public:
        queue_int() {
            arr = new int[16];
            left = 0;
            right = -1;
            _cap = 16;
        }

        void push(int value) {
            int _size = right - left + 1;

            if (_size >= (2 * _cap) / 3) {
                resize(_cap * 2);
            } else if (right + 1 == _cap) {
                shift();
            }

            right++;
            arr[right] = value;
        }

        void pop() {
            if (left > right) {
                return;
            }

            left++;

            int _size = right - left + 1;
            if (_size <= _cap / 3 && _cap != 16) {
                resize(_cap / 2);
            }
        }

        int front() {
            if (left > right) {
                throw invalid_argument("empty queue");
            }

            return arr[left];
        }

        int poll() {
            int res = front();
            pop();
            return res;
        }

        int size() {
            return right - left + 1;
        }

        string to_string() {
            string result = "[";
            for (int i = left; i <= right; i++) {
                result.append(std::to_string(arr[i]));
                if (i < right) {
                    result.append(", ");
                }
            }
            result.append("]");
            return result;
        }
};

void test() {
    queue_int queue;
    queue.push(1);
    queue.push(7);
    queue.push(73);
    queue.push(2);

    assert(1 == queue.poll());
    assert(7 == queue.front());
    assert("[7, 73, 2]" == queue.to_string());
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    test();

    return 0;
}
