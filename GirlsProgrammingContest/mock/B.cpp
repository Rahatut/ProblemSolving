#include<bits/stdc++.h>

using namespace std;

void solve(){
    double x;
    cin>>x;

    double pi = acos(-1.0);

    double area = x*x - pi*x*x/4;
    cout<<fixed<<setprecision(10)<<area<<'\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;
    while(t--){
        solve();
    }

}