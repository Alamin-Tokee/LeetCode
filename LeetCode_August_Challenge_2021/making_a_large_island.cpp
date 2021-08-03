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

 // DFS Solution
 // TIME COMPLEXITY:- O(n*m)
 // SPACE COMPLEXITY:- O(n*m)
class Solution {
public:
    vector<int>offset={0,1,0,-1,0};
    void dfs(vector<vector<int>>& grid,int i,int j,int& curArea,int& island){
        curArea++;
        grid[i][j]=island;
        for(int k=0;k<4;k++){
            int x=i+offset[k];
            int y=j+offset[k+1];
            if(x < 0 || y < 0 || x >=grid.size() || y>=grid.size() || grid[x][y]!=1) continue;
            dfs(grid,x,y,curArea,island);
        }
    }
    int largestIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        unordered_map<int,int>area;
        
        int maxArea = 0;
        int curArea = 0;
        int island_id = 2;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    dfs(grid,i,j,curArea,island_id);
                    maxArea=max(maxArea,curArea);
                    area[island_id]=curArea;
                    curArea = 0;
                    island_id++;
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0){
                    unordered_set<int>st;
                    for(int k=0;k<4;k++){
                        int x=i+offset[k];
                        int y=j+offset[k+1];
                        if(x < 0 || y < 0 || x >=n || y>=n || grid[x][y]==0) continue;
                        st.insert({grid[x][y]});
                    }
                    int total = 1;
                    for(int q : st){
                        total+=area[q];
                    }
                    maxArea=max(maxArea,total);
                }
            }
        }
        return maxArea;
    }
};

 // Union-Find Solution
 // TIME COMPLEXITY:- O(n*m*log(n*m))
 // SPACE COMPLEXITY:- O(n*m)

class Solution {
public:
    
    #define F first
    #define S second
    #define pii pair<int,int>
    
    vector<pair<int,int>> parent; // {parent,rank}
    vector<int> cmp_size;
    // every cell has unique identity, (i,j) --> i*m + j;
    // find set function with path compresssion
    int find_set(int x){
        if(parent[x].F==x)
            return x;
        return parent[x].F = find_set(parent[x].F);
    }
    // union set function with rank compression
    void union_set(int x,int y){
        int xroot = find_set(x);
        int yroot = find_set(y);
        if(xroot==yroot)
            return;
        if(parent[xroot].S==parent[yroot].S)
            parent[xroot].S++; // increment the rank when rank of the two components are same
        if(parent[xroot].S>parent[yroot].S)
            parent[yroot].F = xroot, cmp_size[xroot]+=cmp_size[yroot]; // increment the size of the connected component on union
        else
            parent[xroot].F = yroot, cmp_size[yroot]+=cmp_size[xroot]; // increment the size of the connected component on union
            
    }
    int largestIsland(vector<vector<int>>& mat) {
        int n = mat.size(),m = mat[0].size();
        for(int i=0;i<n*m;i++){
            parent.push_back({i,0});
            cmp_size.push_back(0);
            if(mat[i/m][i%m])
                cmp_size[i]++;
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i+1<n and mat[i][j] and mat[i+1][j])
                    union_set(i*m+j,(i+1)*m+j);
                if(i-1>=0 and mat[i][j] and mat[i-1][j])
                    union_set(i*m+j,(i-1)*m+j);
                if(j+1<m and mat[i][j] and mat[i][j+1])
                    union_set(i*m+j,i*m+j+1);
                if(j-1>=0 and mat[i][j] and mat[i][j-1])
                    union_set(i*m+j,i*m+j-1);
            }
        }
        int ans = 0;
        unordered_set<int> distinct;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]){
                    ans = max(ans,cmp_size[i*m+j]);
                    continue;
                }
                int curr_ans = 1;
                distinct.clear();
                if(i+1<n and mat[i+1][j])
                    distinct.insert(find_set((i+1)*m+j));
                if(i-1>=0 and mat[i-1][j])
                    distinct.insert(find_set((i-1)*m+j));
                if(j+1<m and mat[i][j+1])
                    distinct.insert(find_set(i*m+j+1));
                if(j-1>=0 and mat[i][j-1])
                    distinct.insert(find_set(i*m+j-1));
                for(auto f:distinct)
                    curr_ans+=cmp_size[f];
                ans = max(ans,curr_ans);
            }
        }
        return ans;
    }
};
