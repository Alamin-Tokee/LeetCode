//TC O(2^N)
//SC O(2^N)

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


//TC O(2^N)
//SC O(2^N)
class Solution{
public:
    vector<vector<int>> res;
    void dfs(int idx,int currtotal, vector<int>& can, vector<int>& currlist,int target){
        if(currtotal == target){
            res.push_back(currlist);
            return;
        }
        if(idx >= can.size() || currtotal > target) return;
        currlist.push_back(can[idx]);
        dfs(idx, currtotal+can[idx],can,currlist,target);
        currlist.pop_back();
        dfs(idx+1,currtotal,can,currlist,target);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int>currlist;
        dfs(0,0,candidates,currlist,target);
        return res;
    }
};

