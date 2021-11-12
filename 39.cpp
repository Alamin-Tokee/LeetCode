class Solution {
public:
    void combination(vector<vector<int>>&res,int index,vector<int>&can,vector<int>&com,int t){
        if(t==0){
            res.push_back(com);
            return;
        }
        for(int i=index;i!=can.size() && t>=can[i];i++){
            com.push_back(can[i]);
            combination(res,i,can,com,t-can[i]);
            com.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>>res;
        vector<int>comb;
        combination(res,0,candidates,comb,target);
        
        return res;
    }
};
