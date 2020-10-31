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
    min_queue queue;

    queue.push(9);
    assert(9 == queue.get_min());

    queue.push(7);
    assert(7 == queue.get_min());

    queue.push(2);
    assert(2 == queue.get_min());

    queue.push(73);
    assert(2 == queue.get_min());

    queue.push(5);
    assert(2 == queue.get_min());

    queue.pop();
    queue.pop();
    queue.pop();
    assert(5 == queue.get_min());
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    test();

    return 0;
}
