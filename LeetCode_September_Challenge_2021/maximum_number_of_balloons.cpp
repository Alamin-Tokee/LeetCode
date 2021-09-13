//Time Complexity O(n)
//Space Complexity O(1)
class Solution {
public:
    int maxNumberOfBalloons(string text) {
        unordered_map<char,int>mp;
        for(int i=0;i<text.length();i++){
            mp[text[i]]++;
        }
        int c=0,ans=0;
        string b="balloon";
        for(int i=0;i<b.length();i++){
            if(mp[b[i]]){
                mp[b[i]]--;
                c++;
            }else{
                break;
            }
            if(c==6){
                ans++;
                c=0;
                i=0;
            }
        }
        return ans;
    }
};

//Time Complexity O(n)
//Space Complexity O(1)
