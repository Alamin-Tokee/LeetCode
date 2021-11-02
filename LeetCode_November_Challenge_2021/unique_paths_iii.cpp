class Solution {
public:
    int res=0,empty=1;
    void dfs(vector<vector<int>>& g,int r,int c,int count){
        if(r < 0 || c < 0 || r >= g.size() || c >= g[0].size() || g[r][c]==-1) return;
        
        if(g[r][c]==2){
            if(empty==count) res++;
            return;
        }
        
        g[r][c]=-1;
        
        dfs(g,r+1,c,count+1);
        dfs(g,r-1,c,count+1);
        dfs(g,r,c+1,count+1);
        dfs(g,r,c-1,count+1);
        
        g[r][c]=0;
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        this->res=res;
        this->empty=empty;
        int r,c;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1) r=i,c=j;
                else if(grid[i][j]==0) empty++;
            }
        }
        
        dfs(grid,r,c,0);
        
        return res;
    }
};