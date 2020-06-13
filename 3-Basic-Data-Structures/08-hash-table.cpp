#include <bits/stdc++.h>
using namespace std;

inline bool _lesser(const int a, const int b) { return a < b; }
inline bool _greater(const int a, const int b) { return a > b; }

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

            for (int i : arr[pos]) {
                if (i == num) {
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
    int n;
    cin >> n;

    hash_table ht;

    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        ht.add(num);
    }

    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        int num;
        cin >> num;

        cerr << ht.contains(num) << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    test();

    return 0;
}
