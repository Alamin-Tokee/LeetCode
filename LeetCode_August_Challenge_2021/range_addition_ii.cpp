//Intution (Memory Limit Exceeded)

class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {
        vector<vector<int>>vec(m,vector<int>(n,0));
        int ma=0;
        for(auto x : ops){
            int u=x[0];
            int v=x[1];
            for(int i=0;i<u;i++){
                for(int j=0;j<v;j++){
                    vec[i][j]=vec[i][j]+1;
                    ma=max(ma,vec[i][j]);
                }
            }
        }
        int c=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(vec[i][j]==ma) c++;
            }
        }
        return c;
    }
};