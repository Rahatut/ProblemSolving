#include<iostream>
#include<vector>
#include<algorithm>
#include<bits/stdc++.h>

using namespace std;
using ll = long long;

void solve(){
    int m, n;
    cin>>n>>m;
    vector<ll> ratings(n);

    for(int i=0; i<n; i++){
        cin>>ratings[i];
    }
    //The score calculation formula of the bot if expanded - we find that over m values - score = m*am - (a1+ a2 + ... + am-1)
    //so target = minimizing (a1+a2+...+am-1). plus the order needs to be maintained
    //we need a data structure that holds m-1 values and always keeps the minimum vals iterating over the ratings sequence - max heap works

    priority_queue<ll> pq;
    ll max_score = LLONG_MIN;
    ll sum = 0;

    for(int i=0; i<n; i++){
        if(pq.size()==m-1){
            ll candidate = 1LL * m * ratings[i]-sum; //formula for score, only enter here when we have m-1 vals in pq to subtract from score
            max_score = max(max_score, candidate); //process all candidates
        }  

        if(m>1){ 
            pq.push(ratings[i]); // we keep pushing vals in pq until we have m-1 vals
            sum+=ratings[i]; //sum keep calculating continuously

            if(pq.size()>m-1){ //always remove large vals to keep minimum
                sum-=pq.top();
                pq.pop();
            }
        }


    }

    cout<<max_score<<endl;

    return;

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;
    while(t--) {
        solve();
    }
}
