#include <bits/stdc++.h>
using namespace std;

inline bool _lesser(const int a, const int b) { return a < b; }
inline bool _greater(const int a, const int b) { return a > b; }

class heap {
    private:
        int* arr;
        int _cap;
        int _size;
        bool (*compare)(int, int);

        void heapify(int i) {
            int left = 2 * i + 1;
            int right = 2 * i + 2;

            int node = i;

            if (left < _size && compare(arr[left], arr[node])) {
                node = left;
            }

            if (right < _size && compare(arr[right], arr[node])) {
                node = right;
            }

            if (node != i) {
                swap(arr[node], arr[i]);
                heapify(node);
            }
        }

        void push_up(int i) {
            int parent = (i - 1) / 2;
            while (i != 0 && compare(arr[i], arr[parent])) {
                swap(arr[i], arr[parent]);
                i = parent;
                parent = (i - 1) / 2;
            }
        }

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
        heap(bool (*f)(int, int)) {
            arr = new int[16];
            _cap = 16;
            _size = 0;
            compare = (*f);
        }

        void push(int num) {
            if (_size >= (2 * _cap) / 3) {
                resize(2 * _cap);
            }

            arr[_size++] = num;
            push_up(_size - 1);
        }

        void pop() {
            if (_size == 0) {
                return;
            }

            if (_size <= _cap / 3 && _cap != 16) {
                resize(_cap / 2);
            }

            _size--;
            swap(arr[0], arr[_size]);
            heapify(0);
        }

        int top() {
            return arr[0];
        }

        int poll() {
            int ret = top();
            pop();
            return ret;
        }

        int size() {
            return _size;
        }
};

void test() {
    int n;
    cin >> n;

    heap h1(_lesser);
    heap h2(_greater);

    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        h1.push(num);
        h2.push(num);
        cerr << h1.top() << " " << h2.top() << "\n";
    }

    cerr << "\n";

    while (h1.size() > 0 && h2.size() > 0) {
        cerr << h1.poll() << " " << h2.poll() << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    test();

    return 0;
}
