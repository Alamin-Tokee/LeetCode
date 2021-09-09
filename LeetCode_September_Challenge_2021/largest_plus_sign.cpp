//Time Complexity 4O(n^2)
//Space Complexity O(n^2)
class Solution {
public:
    int orderOfLargestPlusSign(int n, vector<vector<int>>& mines) {
        vector<vector<int>>mat(n,vector<int>(n,1));
        for(auto it:mines){
            int x=it[0];
            int y=it[1];
            mat[x][y]=0;
        }
        vector<vector<int>>lef,rig,top,bot;
        lef=rig=top=bot=mat;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                int x=n-i-1;
                int y=n-j-1;
                if(i>0 && top[i][j]) top[i][j]+=top[i-1][j];
                if(j>0 && lef[i][j]) lef[i][j]+=lef[i][j-1];
                if(x<n-1 && bot[x][y]) bot[x][y]+=bot[x+1][y];
                if(y<n-1 && rig[x][y]) rig[x][y]+=rig[x][y+1];
            }
        }
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                ans=max(ans,min({lef[i][j],rig[i][j],top[i][j],bot[i][j]}));
            }
        }
        return ans;
    }
};


//Time Complexity 4O(n^2)(Another Approach)
//Space Complexity O(n^2)
class Solution {
public:
    int orderOfLargestPlusSign(int n, vector<vector<int>>& mines) {
        vector<vector<int>>mat(n,vector<int>(n,1));
        for(auto it:mines){
            int x=it[0];
            int y=it[1];
            mat[x][y]=0;
        }
        vector<vector<int>>lef(n,vector<int>(n)),rig(n,vector<int>(n)),top(n,vector<int>(n)),bot(n,vector<int>(n));
        //left to right
        for(int i=0;i<n;i++){
            int runingSum=0;
            for(int j=0;j<n;j++){
                if(mat[i][j]==0) runingSum=0;
                else runingSum+=mat[i][j];
                lef[i][j]=runingSum;
            }
        }
        //Right to Left
        for(int i=0;i<n;i++){
            int runingSum=0;
            for(int j=n-1;j>=0;j--){
                if(mat[i][j]==0) runingSum=0;
                else runingSum+=mat[i][j];
                rig[i][j]=runingSum;
            }
        }
        //Top to Bottom
        for(int i=0;i<n;i++){
            int runingSum=0;
            for(int j=0;j<n;j++){
                if(mat[j][i]==0) runingSum=0;
                else runingSum+=mat[j][i];
                top[j][i]=runingSum;
            }
        }
        //Bottom to Top
        for(int i=0;i<n;i++){
            int runingSum=0;
            for(int j=n-1;j>=0;j--){
                if(mat[j][i]==0) runingSum=0;
                else runingSum+=mat[j][i];
                bot[j][i]=runingSum;
            }
        }
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                ans=max(ans,min({lef[i][j],rig[i][j],top[i][j],bot[i][j]}));
            }
        }
        return ans;
    }
};