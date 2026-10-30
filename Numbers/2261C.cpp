#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<stack>

using namespace std;

void solve(){
    int n;
    cin>>n;

    int even = 0;
    for(int i=0; i<n;i++){
        int x;
        cin>>x;
        if(x%2==0){
            even++;
        }
    }
    int odd = n-even;
    if((even==1 && odd==1)||(even==0 && odd==3)) cout<<"Larpity"<<endl;
   
    else{
        cout<<"Moggity"<<endl;
    }

    //the soln lies in the number of odd and even numbers, building a matrix of diff vals of odd and even, paritywise & 0, 1 - find that 
    //Larpity wins only when e=1, o=1 and e=0, o=3 (checking o=5, extra step added which makes Moggity win - odd steps: M, even: L)
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