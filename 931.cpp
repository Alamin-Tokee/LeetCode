//DFS (Top-Down Approach) 
//Memoization tecnique

class Solution {
public:
    int dfs(vector<vector<int>>&g,vector<vector<int>>&m,int start,int h){
        if(start < 0 || h < 0 || start >= g.size() || h >= g[0].size()) return INT_MAX;
        if(m[start][h]!=INT_MAX) return m[start][h];
        
        int a=dfs(g,m,start+1,h);
        int b=dfs(g,m,start+1,h-1);
        int c=dfs(g,m,start+1,h+1);
        
        int val=min(a,min(b,c));
        if(val==INT_MAX){
            return m[start][h]=g[start][h];
        }else{
            return m[start][h]=g[start][h]+val;
        }
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        if(n<1) return 0;
        int m=matrix[0].size();
        if(m<1) return 0;
        int ans=INT_MAX;
        vector<vector<int>>cache(n,vector<int>(m,INT_MAX));
        for(int i=0;i<m;i++){
            ans=min(ans,dfs(matrix,cache,0,i));
        }
        return ans;
    }
};

//Bottom-Up Approach(Tabular Method)
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<vector<int>> t(n,vector<int>(m,0));
        for(int i=0;i<m;i++)
        {
            t[0][i] = matrix[0][i];
        }
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(j==0)
                {
                    t[i][j]=matrix[i][j]+min(t[i-1][j],t[i-1][j+1]);
                }
                else if(j==m-1)
                {
                    t[i][j] = matrix[i][j] + min(t[i-1][j],t[i-1][j-1]);
                }
                else
                    t[i][j]=matrix[i][j] + min(t[i-1][j+1],min(t[i-1][j],t[i-1][j-1]));
            }
        }
        int mini=INT_MAX;
        for(int i=0;i<m;i++)
        {
            mini = min(t[n-1][i],mini);
        }
        return mini;
    }
};