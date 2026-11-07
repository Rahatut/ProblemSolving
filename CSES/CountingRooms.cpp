#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

// direction vectors for 4-directional traversal
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

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

void solve() {
    int n, m;
    cin >> n >> m;

    vector<string> grid(n);
    for (int i = 0; i < n; ++i) {
        cin >> grid[i];
    }

    // Explicit visited array (n x m) initialized to false
    vector<vector<bool>> visited(n, vector<bool>(m, false));

    int room_count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == '.' && !visited[i][j]) {
                room_count++;
                bfs(i, j, grid, visited, n, m);
            }
        }
    }

    cout << room_count << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
    return 0;
}