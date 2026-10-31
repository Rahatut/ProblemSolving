#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

void solve() {
    ll n, r; 
    cin >>n>>r;

    ll mid = (n+1)/2;
    ll total = 0;

    vector<bool> flag(n+1, false);

    for(int i=0; i<r; i++){
        ll x;
        cin>>x;
        if(flag[x]==true){
            continue;
        }
        else{
            if(x>mid) total += mid - (x - mid);
            else{
                total+=x;
            }
            flag[x] = true;
        }
    }

    cout<<total<<'\n';
    
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

