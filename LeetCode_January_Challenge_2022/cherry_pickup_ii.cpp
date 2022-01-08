//Time Complexity O(M*N^2)
//Space Complexity O(M*N^2)
class Solution {
public:
	int m,n;
	int solve(vector<vector<int>>& grid,int row,int col1,int col2,vector<vector<vector<int>>> &dp){
		if(row>=m or col1<0 or col1>=n or col2<0 or col2>=n) return 0;
		else if(dp[row][col1][col2]!=-1) return dp[row][col1][col2];
		int res=grid[row][col1],mx=0;;
		if(col1!=col2) res+=grid[row][col2];
		for(int c1=col1-1;c1<=col1+1;c1++){
			for(int c2=col2-1;c2<=col2+1;c2++){
				mx=max(mx,solve(grid,row+1,c1,c2,dp));
			}
		}
		res+=mx;
		return dp[row][col1][col2]=res;
	}
	int cherryPickup(vector<vector<int>>& grid) {
		m=grid.size();
		n=grid[0].size();
		vector<vector<vector<int>>> dp(m,vector<vector<int>>(n,vector<int>(n,-1)));
		return solve(grid,0,0,n-1,dp);
	}
};