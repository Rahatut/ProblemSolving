#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<stack>

using namespace std;

void solve(){
    int n,k;
    cin>>n>>k;

    vector<int> freq(n+1,0); //to store the occurences of each card 

    for(int i=0; i<n; i++){
        int x;
        cin>>x;
        if(x<=n) freq[x]++;
    }
    //the rule of the card game is such that A and B cannot have equal mexk(). Bobs goal is to take cards such that mexk equal, Alice - opposite
    // the smallest num that appears less than k times. - if card is available in 2k num, both player can have k copies of the card. if 2k-1 num of cards available, one person gets k and other gets k-1 since played in turns. 
    // freq ensures 1st smallest num is picked (i starting from 0)
    // Alice moves first. so taking 1 card first, she ultimately gets k cards max. 
    // so when fewer than k times looked - bob having 1 less than that, his ans is lesser while Alice gets bigger mexk. so alice wins
  
    for(int i = 0; i <= n; i++) { 
        if(freq[i] < 2*k) {
            if(freq[i] == 2*k-1) {
                cout << "YES" <<endl;
            }
            else{
                cout << "NO" <<endl;
            }
            return;
        }
    }

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