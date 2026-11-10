#include<bits/stdc++.h>
using namespace std;

void solve(){

    int n, m;
    cin>>n>>m;
    vector<vector<int>> graph(n+1);
    for(int i=0; i<m; i++){
        int a, b;
        cin>>a>>b;
        graph[b].push_back(a);
        graph[a].push_back(b);
    }
    vector<int> parent(n+1, 0);
    queue<int> q;

    q.push(1);
    parent[1]=-1;

    while(!q.empty()){
        int u = q.front();
        q.pop();

        if(u==n) break;
        for(int v : graph[u]){
            if(parent[v]==0){
                parent[v]=u;
                q.push(v);
            }
        }
    }


    if(parent[n]==0){
        cout<<"IMPOSSIBLE"<<"\n";
        return;
    }

    vector<int> path;
    for(int curr=n; curr!=-1; curr = parent[curr]){
        path.push_back(curr);
    }

    reverse(path.begin(), path.end());

    cout << path.size() << "\n";
    for (int i = 0; i < (int)path.size(); i++) {
        cout << path[i] << " ";
    }
    cout << "\n";

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t=1;
    //cin>>t;
    while(t--){
        solve();
    }
}