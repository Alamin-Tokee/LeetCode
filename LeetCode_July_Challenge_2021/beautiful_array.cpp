
// Simple Solution
//Time Complexity O(n)
//Space Complexity O(n)
class Solution {
public:
    vector<int> beautifulArray(int n) {
        vector<int>ret={1};
        while(ret.size() < n){
            vector<int> temp;
            for(int r : ret){
                // int i=2*r-1;
                int i = (r << 1) - 1;
                if(i <= n){
                    temp.push_back(i);
                }
            }
            for(int r : ret){
                // int i=2*r;
                int i = r << 1;
                if(i <= n){
                    temp.push_back(i);
                }
            }
            ret=temp;
        }
        return ret;
    }
};


//Recursive Solution
//Time Complexity O(NlogN)
//Space Complexity O(NlogN)

class Solution {
public:
    unordered_map<int,vector<int>> mp;
    vector<int> beautifulArray(int n) {
        if(mp.find(n)!=mp.end()) return mp[n];
        
        vector<int> ans(n,0);
        if(n == 1) ans[0] = 1;
        else{
            int index = 0;
            for(int x : beautifulArray((n+1)/2)){
                cout<< x <<endl;
                ans[index++]=2*x-1;
            }
            
            for(int x : beautifulArray(n/2))
                ans[index++]=2*x;
        }
        mp[n]=ans;
        
        return ans;
    }
};