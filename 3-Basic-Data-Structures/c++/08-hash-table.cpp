#include <bits/stdc++.h>
using namespace std;

class hash_table {
    private:
        static const int MOD = 100003;

        int _size;

        vector<int>* arr;

    public:
        hash_table() {
            arr = new vector<int>[MOD];

            _size = 0;
        }

        void add(int num) {
            int pos = num % MOD;
            arr[pos].push_back(num);
            _size++;
        }

        void remove(int num) {
            int pos = num % MOD;

            for (int i = 0; i < arr[pos].size(); i++) {
                if (arr[pos][i] == num) {
                    arr[pos].erase(arr[pos].begin() + i);
                    _size--;

                    return;
                }
            }
        }

        bool contains(int num) {
            int pos = num % MOD;

            for (int i : arr[pos]) {
                if (i == num) {
                    return true;
                }
            }

            return false;
        }

        int size() {
            return _size;
        }
};

void test() {
    hash_table map;

    map.add(1);
    map.add(2);
    map.add(3);
    map.add(4);
    assert(false == map.contains(7));
    assert(true == map.contains(3));

    map.remove(3);
    assert(false == map.contains(3));

    assert(true == map.contains(1));
    assert(true == map.contains(2));
    assert(true == map.contains(4));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    test();

    return 0;
}
