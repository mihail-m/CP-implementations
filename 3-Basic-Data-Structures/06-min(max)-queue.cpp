#include <bits/stdc++.h>
using namespace std;

class min_queue {
    private:
        queue<int> q;
        deque<int> _min;

    public:
        void push(int num) {
            q.push(num);

            while (_min.size() > 0 && _min.back() > num) {
                _min.pop_back();
            }

            _min.push_back(num);
        }

        void pop() {
            if (q.front() == _min.front()) {
                _min.pop_front();
            }

            q.pop();
        }

        int front() {
            return q.front();
        }

        int get_min() {
            return _min.front();
        }

        int size() {
            return q.size();
        }
};

void test() {
    int n;
    cin >> n;

    min_queue q;

    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        q.push(num);
    }

    while (q.size() > 0) {
        cerr << q.get_min() << endl;
        q.pop();
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    test();

    return 0;
}
