
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