class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
        int m=nums.size();
        int n=nums[0].size();
        if(m==0 || r*c!=m*n){
            return nums;
        }
        vector<vector<int>>res(r,vector<int>(c,0));
        int count=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                res[count/c][count%c]=nums[i][j];
                count++;
            }
        }
        return res;
    }
};

class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int m=mat.size();
        int n=mat[0].size();
        if(m==0 || m*n != r*c) return mat;
        
        vector<vector<int>>ans(r,vector<int>(c,0));
        int x=0,y=0;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                ans[i][j]=mat[x][y++];
                if(y==n){
                    y%=n, x++;
                }
            }
        }
        return ans;
    }
};