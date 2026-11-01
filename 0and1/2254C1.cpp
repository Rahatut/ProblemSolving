#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

void solve() {
    int n; 
    cin >> n;
    string a, b;
    cin>>ws;
    getline(cin, a);
    getline(cin, b);
    //001 to 100 here, even index 1 is moving 2 steps back forth
    //110 to 011 odd index 1 moves to odd index. 
    // so, the num of 1s at even index and odd index for both a and b should be equal.

    //or, a 0 based version can also be used - 001 to 100 even 0 to even index, odd to odd
    // 110 to 011 even to even;
    // so num of 0 in even and odd index for a and b respectively should be equal for the changes to happen
    //so that a=b

    int a_even = 0, a_odd = 0;
    int b_even = 0, b_odd = 0;

    for (int i = 0; i < n; ++i) {
            if (a[i] == '1') {
                if (i % 2 == 0) a_even++;
                else a_odd++;
            }
            if (b[i] == '1') {
                if (i % 2 == 0) b_even++;
                else b_odd++;
            }
    }
    if (a_even == b_even && a_odd == b_odd) {
        cout << "YES\n";
    } 
    else {
        cout << "NO\n";
    }

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
}

