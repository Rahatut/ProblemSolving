#include<bits/stdc++.h>
#include<algorithm>

using namespace std;

void solve(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    int ans=0;
    int total_ones = 0;
    int first_one = -1;

    if(s[0]=='1'){
        ans = count(s.begin(), s.end(), '0');
        cout<<ans<<endl;
        return;
    }

    for(int i=0; i<n; i++){
        if(s[i]=='1'){
            total_ones++;
            if(first_one==-1) first_one = i;
        }
    }

    if(first_one == -1){
        cout<< 0 <<endl;
        return;
    }
    ans = total_ones;
    int total_zeros = n - total_ones;
    int ones_left =0;
    int zeros_right = total_zeros;

    for(int i = 0; i<n; i++){
        if(i>=1 && first_one<=i){
            ans = min(ans, ones_left+zeros_right);
        }
        if(s[i]=='1'){
            ones_left++;
        }
        else{
            zeros_right--;
        }
    }

    cout<<ans<<endl;

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