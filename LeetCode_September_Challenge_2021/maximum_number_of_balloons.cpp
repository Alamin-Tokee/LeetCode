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
class Solution {
public:
    int maxNumberOfBalloons(string text) {
        int aCount=0,bCount=0,lCount=0,oCount=0,nCount=0;
        for(int i=0;i<text.length();i++){
            if(text[i]=='b'){
                bCount++;
            }else if(text[i]=='a'){
                aCount++;
            }else if(text[i]=='l'){
                lCount++;
            }else if(text[i]=='o'){
                oCount++;
            }else if(text[i]=='n'){
                nCount++;
            }
        }
        lCount=lCount/2;
        oCount=oCount/2;
        return min({aCount,bCount,lCount,oCount,nCount});
    }
};