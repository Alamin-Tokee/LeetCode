//Time Complexity O(n)
//Space Complexity O(1)
class Solution {
public:
    string orderlyQueue(string s, int k) {
        if(k==1){
            string ans=s;
            for(int i=0;i<s.length();i++){
                ans=min(ans,s.substr(i)+s.substr(0,i));
            }
            return ans;
        }
        sort(s.begin(),s.end());
        
        return s;
    }
};