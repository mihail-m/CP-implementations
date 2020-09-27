#include <bits/stdc++.h>

using namespace std;

const double PI = acos(-1);
const int MAXN = (1 << 21);

struct complex_base {
    double x, y;

    complex_base(double _x = 0, double _y = 0) {
        x = _x; y = _y;
    }

    friend complex_base operator-(const complex_base &a, const complex_base &b) {
        return complex_base(a.x - b.x, a.y - b.y);
    }

    friend complex_base operator+(const complex_base &a, const complex_base &b) {
        return complex_base(a.x + b.x, a.y + b.y);
    }

    friend complex_base operator*(const complex_base &a, const complex_base &b) {
        return complex_base(a.x * b.x - a.y * b.y, a.y * b.x + b.y * a.x);
    }

    friend void operator/=(complex_base &a, const double &P) {
        a.x /= P; a.y /= P;
    }
};

int bit_rev[MAXN];
int last_n_fft = -1, ilast_n_fft = -1;
complex_base root[MAXN], iroot[MAXN];

void fft(complex_base *a, int lg) {
    int n = (1 << lg);

    if(last_n_fft != n) {
        double ang = 2 * PI / n;

        for(int i = 0; i < (n >> 1); i++) {
            root[i] = complex_base(cos(ang * i), sin(ang * i));
        }

        last_n_fft = n;
    }

    for(int i = 1; i < n; i++) {
        bit_rev[i] = (bit_rev[i >> 1] >> 1) | ((i & 1) << (lg - 1));
        if(bit_rev[i] < i) {
        	swap(a[i], a[bit_rev[i]]);
        }
    }

    for(int len = 2; len <= n; len <<= 1) {
        int step = (n / len);
        for(int j = 0; j < (len >> 1); j++) {
            for(int i = 0; i < n; i += len) {
                complex_base u = a[i + j], v = root[step * j] * a[i + j + (len >> 1)];
                a[i + j] = u + v;
                a[i + j + (len >> 1)] = u - v;
            }
        }
    }
}

void inv_fft(complex_base *a, int lg) {
    int n = (1 << lg);

    if(ilast_n_fft != n) {
        double ang = -2 * PI / n;

        for(int i = 0; i < (n >> 1); i++) {
            iroot[i] = complex_base(cos(ang * i), sin(ang * i));
        }

        ilast_n_fft = n;
    }

    for(int i = 1; i < n; i++) {
        bit_rev[i] = (bit_rev[i >> 1] >> 1) | ((i & 1) << (lg - 1));

        if(bit_rev[i] < i) {
        	swap(a[i], a[bit_rev[i]]);
        }
    }

    for(int len = 2; len <= n; len <<= 1) {
        int step = (n / len);
        for(int j = 0; j < (len >> 1); j++) {
            for(int i = 0; i < n; i += len) {
                complex_base u = a[i + j], v = iroot[step * j] * a[i + j + (len >> 1)];
                a[i + j] = u + v;
                a[i + j + (len >> 1)] = u - v;
            }
        }
    }

    for(int i = 0; i < n; i++) {
        a[i] /= n;
    }
}

complex_base A[MAXN], B[MAXN];

vector<int> mult(vector<int> a, vector<int> b) {
    int lg = 0; 

    while((1 << lg) < (int)(a.size() + b.size())) {
    	lg++;
    }

    for(int i = 0; i < (1 << lg); i++) {
    	A[i] = B[i] = complex_base(0, 0);
    }
    for(int i = 0; i < (int)a.size(); i++) {
    	A[i] = complex_base(a[i], 0);
    }
    for(int i = 0; i < (int)b.size(); i++) {
    	B[i] = complex_base(b[i], 0);
    }

    fft(A, lg); fft(B, lg);

    for(int i = 0; i < (1 << lg); i++) {
        A[i] = A[i] * B[i];
    }

    inv_fft(A, lg);

    vector<int> ans(a.size() + b.size(), 0);

    for(int i = 0; i < (int)ans.size(); i++) {
        ans[i] = (int)(A[i].x + 0.5);
    }

    return ans;
}

string multiply(string num1, string num2) {
	if (num1 == "0" || num2 == "0") {
        return "0";
    }

    vector<int> a;
    vector<int> b;

    for (int i = 0; i < num1.size(); i++) {
    	a.push_back((int)(num1[i] - '0'));
    }
    for (int i = 0; i < num2.size(); i++) {
    	b.push_back((int)(num2[i] - '0'));
    }

    vector<int> res = mult(a, b);
    int carry = 0;
    int i = res.size() - 2;

    stack<int> ans;
    for (; i >= 0; i--) {
        res[i] += carry;
        ans.push(res[i] % 10);
        carry = res[i] / 10;
    }

    string result = "";

    if (carry > 0) {
    	result.append(to_string(carry));
    }

    while (ans.empty() == false) {
        result.append(to_string(ans.top())); 
        ans.pop();
    }
    
    return result;
}

void test() {
	string num1 = "123456789";
	string num2 = "123454321";

	assert("15241274058835269" == multiply(num1, num2));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

   	test();

    return 0;
}