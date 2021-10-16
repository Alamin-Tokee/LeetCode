class Solution {
public:
    void permutationHelper(string s,int i,vector<string>&ans){
        if(i==s.size()){
            ans.push_back(s);
            return;
        }
        if(s[i]>='a' and s[i]<='z'){
            permutationHelper(s,i+1,ans);
            s[i]=toupper(s[i]);
            permutationHelper(s,i+1,ans);
        }else if(s[i]>='A' and s[i]<='Z'){
            permutationHelper(s,i+1,ans);
            s[i]=tolower(s[i]);
            permutationHelper(s,i+1,ans);
        }else{
            permutationHelper(s,i+1,ans);
        }
    }
    vector<string> letterCasePermutation(string s) {
        vector<string>ans;
        permutationHelper(s,0,ans);
        
        return ans;
    }
};