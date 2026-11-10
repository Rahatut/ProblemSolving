#include<bits/stdc++.h>
using namespace std;
bool possible = true;

void dfs(int node, int c, const vector<vector<int>>& graph, vector<int>& color) {
    color[node] = c;
    for (int neighbor : graph[node]) {
        if (color[neighbor] == 0) {
            dfs(neighbor, 3 - c, graph, color);//opposite colour , to remove friends
        } 
        else if (color[neighbor] == c) {
            possible = false; //cycles
        }
    }
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
    vector<int> color(n + 1, 0);

    for (int i = 1; i <= n; i++) {
        if (color[i] == 0) {
            dfs(i, 1, graph, color);
        }
    }
    if (!possible) {
        cout << "IMPOSSIBLE\n";
        return;
    }

    for (int i = 1; i <= n; i++) {
        cout << color[i] << " ";
    }
    cout << "\n";

    return;

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