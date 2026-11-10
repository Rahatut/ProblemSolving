#include<bits/stdc++.h>
using namespace std;

void dfs(int node, const vector<vector<int>>& graph, vector<bool>& visited){
    visited[node]=true;
    for(int neighbour : graph[node]){
        if(!visited[neighbour]){
            dfs(neighbour, graph, visited);
        }
    }
    return;
}

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
    vector<bool> visited(n+1,false);
    vector<int> component;

    for(int i=1; i<=n; i++){
        if(!visited[i]){
            component.push_back(i);
            dfs(i, graph, visited);
        }
    }

    int k = component.size()-1;
    cout<<k<<"\n";

    for(int i=0; i<k; i++){
        cout<< component[i]<<" "<<component[i+1]<<"\n";
    }

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