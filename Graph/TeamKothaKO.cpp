#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

int n, m, timer;
vector<vector<int>> adj;
vector<int> visited, firstvisit;
vector<bool> ispivot;

void dfs(int u, int parent) {
    visited[u] = firstvisit[u] = ++timer;
    int children = 0;
    for (int v : adj[u]) {
        if (v == parent) continue;
        if( visited[v]) {
            firstvisit[u] = min(firstvisit[u],visited[v]);
        } 
        else {
            children++;
            dfs(v, u);
            firstvisit[u] = min(firstvisit[u], firstvisit[v]);
            if (parent != -1 && firstvisit[v] >=visited[u]) ispivot[u] = true;
        }
    }
    if (parent == -1 && children >= 2) ispivot[u] = true;
}


void solve(int tc) {
    cin >> n >> m;
    adj.assign(n + 1, {});
    visited.assign(n + 1, 0);
    firstvisit.assign(n + 1, 0);
    ispivot.assign(n + 1, false);
    timer = 0;

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for (int i = 1; i <= n; i++)
        if (!visited[i]) dfs(i, -1);

    int cnt = 0;
    for (int i = 1; i <= n; i++) cnt += ispivot[i];
    cout << "Case " << tc << ": " << cnt << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    for (int tc = 1; tc <= t; tc++) solve(tc);
}
