#include<bits/stdc++.h>

using namespace std;

void solve(){
    string A, B;
    int n;

    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, A);
    getline(cin, B);
    cin>>n;

    int freq1[256] = {0}, freq2[256] = {0};
    for(char c : A){
        freq1[tolower(c)]++;
    }
    for(char c : B){
        freq2[tolower(c)]++;
    }
    bool valid = true;

    for(int i=0; i<256;i++){
        if(freq1[i]==freq2[i]) continue;
        else{
            valid = false;
            break;
        }
    }

    if(!valid) cout<<"No\n";
    else if(valid){
        cout<<"Yes\n";

        int size = A.size();
        string copy = A;
        bool next = true;

        for(int i=0; i<size; i++){
            copy[(i+n)%size] = A[i];
        }
        A = copy;

        for(int i=0; i<size; i++){
            if(A[i]==' ') {
                next = true;
            }
            else if(next){
                A[i]=toupper(A[i]);
                next = false;
            } 
            else{
                A[i]=tolower(A[i]);
            }
        }
        cout<<A<<'\n';

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