 // BFS Solution
 // TIME COMPLEXITY:- O(n*m)
 // SPACE COMPLEXITY:- O(n*m)
class Solution {
public:
    int n, idx = 2;
    pair<int, int> dir[4] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    void bfs(int r, int c, vector<vector<int>> &grid, vector<int> &area) {
        queue<pair<int, int>> q;
        q.emplace(r, c);
        int cnt = 0;
        grid[r][c] = idx;
        for (; !q.empty();) {
            auto [i, j] = q.front();
            cnt++;
            q.pop();
            for (auto &d : dir) {
                int ni = i + d.first, nj = j + d.second;
                if (ni >= 0 && nj >= 0 && ni < n && nj < n && grid[ni][nj] == 1) {
                    grid[ni][nj] = idx;
                    q.emplace(ni, nj);
                }
            }
        }
        area[idx++] = cnt; 
    }
    int largestIsland(vector<vector<int>>& grid) {
        n = grid.size();
        if (n == 1) return 1;
        vector<int> area(n * n * 2);
        int ans = 0;
        for (int r = 0; r < n; r++) {
            for (int c = 0; c < n; c++) {
                if (grid[r][c] == 1)
                    bfs(r, c, grid, area);
            }
        }
        for (int r = 0; r < n; r++) {
            for (int c = 0; c < n; c++) {
                unordered_set<int> s;
                s.emplace(grid[r][c]);
                for (auto &d : dir) {
                    int nr = r + d.first, nc = c + d.second;
                    if (nr >= 0 && nr < n && nc >= 0 && nc < n) {
                        s.emplace(grid[nr][nc]);
                    }
                }
                int sum = !grid[r][c];
                for (auto idx : s)
                    sum += area[idx];
                ans = max(ans, sum);
            }
        }
        return ans;
    }
};
