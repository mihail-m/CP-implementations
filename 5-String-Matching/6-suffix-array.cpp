#include <bits/stdc++.h>

using namespace std;

static const int SIZE = 1e5;
static const int LOG = 20;

int n, stp, cnt;

int P[LOG + 1][SIZE];
int suffix_array[SIZE];

pair<pair<int,int>, int> L[SIZE];

void build_suffix_array(const string& s) {
    for(int i = 0; i < n; i++) {
        P[0][i] = s[i];
    }
        
    suffix_array[0] = 0; 
    for(stp = 1, cnt = 1; cnt < n; stp++, cnt <<= 1) {
        for(int i = 0; i < n; i++) {
            if (i + cnt < n) {
                L[i] = {{P[stp - 1][i], P[stp - 1][i + cnt]}, i};
            } else {
                L[i] = {{P[stp - 1][i], -1}, i};
            }
        }
            
        sort(L, L + n);

        for(int i = 0; i < n; i++) {
            if (i > 0 && L[i].first == L[i - 1].first) {
                P[stp][L[i].second] = P[stp][L[i - 1].second];
            } else {
                P[stp][L[i].second] = i;
            }
        }
    }
        
    for(int i = 0; i < n; i++) {
        suffix_array[i] = L[i].second;
    }
}

// Longest common prefix of substrings x and y
int lcp(int x, int y) {
    if (x == y) {
        return n - x;
    }

    int ret = 0;
    for (int k = stp - 1; k >= 0 && x < n && y < n; k--) {
        if (P[k][x] == P[k][y]) {
            x += (1 << k);
            y += (1 << k);
            ret += (1 << k);
        }
    }
    
    return ret;
}

void test() {
    string s = "aabaabaa";

    n = s.size();

    build_suffix_array(s);

    assert(5 == lcp(0, 3));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    test();

    return 0;
}