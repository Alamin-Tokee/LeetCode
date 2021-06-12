class Solution {
public:
    bool isCovered(vector<vector<int>>& ranges, int left, int right) {
        
        int h[100]={0};
        for(auto x:ranges){
            for(int i=x[0]; i<=x[1];i++){
                h[i]=1;
            }
        }
        
        for(int i=left;i<=right;i++){
            if(h[i]==0) return false;
        }
        
        return true;
    }
};