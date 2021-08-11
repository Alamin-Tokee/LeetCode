//Time Complexity O(NlogN)
//Space Complexity O(N)
class Solution {
public:
    bool canReorderDoubled(vector<int>& arr) {
        int n=arr.size();
        sort(arr.begin(),arr.end());
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++) mp[arr[i]]++;
        
        int c=0;
        for(int i=0;i<n;i++){
            if(mp[2*arr[i]] && mp[arr[i]]){
                mp[2*arr[i]]--;
                mp[arr[i]]--;
            }
        }
        for(auto x:mp){
            if(x.second!=0) return false;
        }
        return true;
    }
};


