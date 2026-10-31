#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;


void solve() {
    int n; 
    cin >> n;
    string s;
    cin>>s;

    string vowels = "aeiou";

    vector<char> array;

    for(char c : s){
        if(vowels.find(c)!=string::npos){
            array.push_back(c);
        }
    }
    int times = 0;
    int left = 0, right = array.size()-1;

    while(left<right){
        if(array[left]!=array[right]){
            times++;
        }
        left++;
        right--;
    }
    
    cout<<times<<'\n';


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

