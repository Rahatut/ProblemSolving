# Graph basics : DFS & BFS

## Problem type 1: Grid
For adjacent search- use dx, dy to move from current coordinates
dx={-1,0,1,0}
dy={0,1,0,-1}

then run bfs

```
void bfs(int start_r, int start_c, const vector<string>& grid, vector<vector<bool>>& visited, int n, int m) {
    queue<pair<int, int>> q;
    q.push({start_r, start_c});
    visited[start_r][start_c] = true;

    while (!q.empty()) {
        auto [r, c] = q.front();
        q.pop();

        for (int i = 0; i < 4; ++i) {
            int nr = r + dx[i];
            int nc = c + dy[i];

            // check boundary limits, visited state, and floor status
            if ((nr >= 0 && nr < n) && (nc >= 0 && nc < m)) {
                if (!visited[nr][nc] && grid[nr][nc] == '.') {
                    visited[nr][nc] = true; // mark visited upon pushing
                    q.push({nr, nc});
                }
            }
        }
    }
}
```
next upgrade on this problem is counting certain points on grid - pacman grid search style - pellet points

## Problem type 2: Components finding and connecting

- Using DFS to find connected components over graph, mark visited.
- Connecting - colouring nodes on same group
- Counting number of groups


## Problem type 3: Path reconstruction

- Using BFS to find connection between 1 node to another - shortest
- Path construct code
```
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
```
- finding cycle and path of that cycle - keep a parent vector as well, 
```
int start = -1; int ending =-1;

bool dfs(int u, int p, const vector<vector<int>>& graph, vector<bool>& visited, vector<int>& parent){
    visited[u] = true;
    parent[u] = p;

    for (int v : graph[u]) { //iterating over graph to find cycle
        if (v == p) continue; 

        if (visited[v]) { //already visited once, cycle
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
```
