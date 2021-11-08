class Solution {
public:
    int sizeX,sizeY;
    int getA(int i,int j,vector<vector<int>>& mat){
        if(i < 0 || j < 0) return 0;
        if(i >= sizeX ) {i = sizeX-1;}
        if(j >= sizeY ) {j = sizeY-1;}
        
        return mat[i][j];
    }
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        sizeX=mat.size();
        sizeY=mat[0].size();
        
        for(int i=0;i<sizeX;i++){
            for(int j=1;j<sizeY;j++){
                mat[i][j]+=mat[i][j-1];
            }
        }
        
        for(int i=0;i<sizeY;i++){
            for(int j=1;j<sizeX;j++){
                mat[j][i]+=mat[j-1][i];
            }
        }
        vector<vector<int>>ans(sizeX,vector<int>(sizeY,0));
        for(int i=0;i<sizeX;i++){
            for(int j=0;j<sizeY;j++){
                ans[i][j]+=getA(i+k,j+k,mat)-getA(i-k-1,j+k,mat)-getA(i+k,j-k-1,mat)+getA(i-k-1,j-k-1,mat);
            }
        }
        return ans;
    }
};