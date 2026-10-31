#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

void solve() {
    string s;
    cin >> s;
    string copy = s, empty = "";

    for(int i=0; i<s.size(); i++){
        copy[i]= tolower(s[i]);
    }

    int pos = copy.find("bdgpc");
    
    while(pos!=string::npos){
        copy.erase(pos, 5);
        s.erase(pos,5);
        pos = copy.find("bdgpc");
    }

    if(copy==empty){
        cout<<-1<<'\n';
    }
    else{
        cout<<s<<'\n';
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

