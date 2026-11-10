#include<bits/stdc++.h>
using namespace std;

int start = -1; int ending =-1;

bool dfs(int u, int p, const vector<vector<int>>& graph, vector<bool>& visited, vector<int>& parent){
    visited[u] = true;
    parent[u] = p;

    for (int v : graph[u]) {
        if (v == p) continue; 

        if (visited[v]) {
            start = v;
            ending = u;
            return true;
        }

        if (dfs(v, u, graph, visited, parent)) {
            return true;
        }
    }
    return false;
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

    vector<bool> visited(n + 1, false);
    vector<int> parent(n + 1, 0);

    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            if (dfs(i, 0, graph, visited, parent)) {
                break; 
            }
        }
    }
    if (start == -1) {
            cout << "IMPOSSIBLE\n";
            return;
    }

    vector<int> cycle;
    cycle.push_back(start);
    for (int curr = ending; curr !=start; curr = parent[curr]) {
        cycle.push_back(curr);
    }
    cycle.push_back(start);

    cout << cycle.size() << "\n";
    for (int i = 0; i < (int)cycle.size(); i++) {
        cout << cycle[i] << " ";
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