#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

void solve() {
    int n; 
    cin >> n;

    if(n%2==0){
        cout<<"Welcome to BdGPC! Happy problem-solving!"<<'\n';
    }
    else{
        cout<<"Welcome to BdGPC! Happy coding!"<<'\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }
}

