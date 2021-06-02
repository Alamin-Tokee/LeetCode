//First Approach

class Solution {
public:
    int x[4] = {0, 0, -1, 1};
    int y[4] = {-1, 1, 0, 0};
    
    bool isValid(int row,int col,vector<vector<int>>& grid){
        if(row < 0 || col < 0 || row >=grid.size() || col >= grid[0].size() || grid[row][col]==0){
            return true;
        }
        
        return false;
    }
    void dfs(int row,int col,vector<vector<int>>& grid,int& count){
        
        if(isValid(row,col,grid)) return;
        
        grid[row][col]=0;
        
        count++;
        
        for(int i=0;i<4;i++){
            int a=row+x[i];
            int b=col+y[i];
            dfs(a,b,grid,count);
        }
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        
        vector<vector<int>>vis(m,vector<int>(n,0));
        int ans=0;
        int ma=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    ans=0;
                    dfs(i,j,grid,ans);
                    ma=max(ma,ans);
                }
            }
        }
        
        return ma;
    }
};

//Time Complexity O(N*M);
//Space Complexity O(1)

class Solution {
public:
    void dfs(int row,int col,vector<vector<int>>&grid,int& ans){
        if(row < 0 || col < 0 || row >= grid.size() || col >= grid[0].size() || grid[row][col]==0) return;

        grid[row][col]=0;

        ans++;

        dfs(row+1,col,grid,ans);
        dfs(row-1,col,grid,ans);
        dfs(row,col+1,grid,ans);
        dfs(row,col-1,grid,ans);

    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int ans=0,mi=0;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    ans=0;
                    dfs(i,j,grid,ans);
                    mi=min(mi,ans);
                }
            }
        }

        return mi;
    }
};

//Time Complexity O(N*M)
//Space Complexity O(1)
