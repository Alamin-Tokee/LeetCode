class Solution {
public:
    vector<vector<int>>dp;
    int R(string& s,int i,int j){
        if(i > j) return 0;
        if(i==j) return 1;
        if(dp[i][j]!=-1) return dp[i][j];
        if(s[i]==s[j]){
            return dp[i][j]=2+R(s,i+1,j-1);
        }else{
            return dp[i][j]=max(R(s,i+1,j),R(s,i,j-1));
        }
    }
    int longestPalindromeSubseq(string s) {
        if(s.length() == 1) return 1;
        dp.assign(s.length(),vector<int>(s.length(),-1));
        return R(s,0,s.length()-1);
    }
};
