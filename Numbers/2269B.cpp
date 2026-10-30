#include<iostream>
#include<bits/stdc++.h>
#include<map>
#include<unordered_set>
#include<unordered_map>

using namespace std;


int forever(int num){
    int sum = 0;

    while(num>0){
        sum+=(num%10)*(num%10);
        num=num/10;
    }
    return sum;
}

//the pattern of the numbers squared digit sum is such that, considering 10^9 the max num - 1st step of sum of 999...9 makes it 9x9^2 = 729. if we keep summing - we find the number
// entering the loop of 4->16->37->58->...->145->42->20->4->... - calculating it seems in around 12 ish steps reaches this loop
//another case is reaching 1.
//brute forcing 100 steps, should reach loop or const state by then

int getVal(int x){
    for(int i=0; i<100; i++){
        x = forever(x);
    }
    return x;

}

void solve() {
    int n;
    cin>>n;

    unordered_map<int,int> freq;

    for(int i=0; i<n; i++){
        int x;
        cin>>x;

        freq[getVal(x)]++;
        
    }

    long long ans = 0;
    for(auto const& [val,count]:freq){
        ans+= count * (count -1)/2;
    }

    cout<<ans<<endl;
    

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
