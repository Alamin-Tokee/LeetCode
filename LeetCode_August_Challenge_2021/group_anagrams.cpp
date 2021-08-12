//Time Complexity (m*nlogn)
//Space Complexity O(n*m)

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n=strs.size();
        unordered_map<string,vector<string>>mp;
        for(auto x:strs){
            string y=x;
            sort(x.begin(),x.end());
            mp[x].push_back(y);
        }
        vector<vector<string>>ans;
        for(auto a:mp){
            ans.push_back(a.second);
        }
        
        return ans;
    }
};

