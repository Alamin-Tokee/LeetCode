
class Solution {
    public:
    int minimumTotal(vector<vector<int>>& triangle) {
        for(int i = triangle.size() - 2; i >= 0; i--) {
            for(int j = 0; j <= i; j++) {
                triangle[i][j] += min(triangle[i+1][j], triangle[i+1][j+1]);
			}
		}
        return triangle[0][0];
    }
};

class Solution {
    public:
    int solveMinimumTotal(vector<vector<int>>& t,int i,int j,vector<vector<int>>&v){
        if(i >= t.size()) return 0;
        
        if(v[i][j]!=-1) return v[i][j];
        
        return v[i][j]=t[i][j]+min(solveMinimumTotal(t,i+1,j,v),solveMinimumTotal(t,i+1,j+1,v));
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        if(n==0) return 0;
        vector<vector<int>>vec(n,vector<int>(n,-1));
        
        return solveMinimumTotal(triangle,0,0,vec);
    }
};

class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) 
    {
        vector<int> mini = triangle[triangle.size()-1];
        for ( int i = triangle.size() - 2; i>= 0 ; --i )
            for ( int j = 0; j < triangle[i].size() ; ++ j )
                mini[j] = triangle[i][j] + min(mini[j],mini[j+1]);
        return mini[0];
    }
};