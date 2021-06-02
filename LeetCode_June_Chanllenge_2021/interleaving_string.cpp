//Time Complexity O(n*m)
//Space Complexity O(n*m)

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        
        if(s3.length()!=s1.length()+s2.length()) return false;
        
        vector<vector<int>> dp(s1.length()+1,vector<int>(s2.length()+1,0));
        
        for(int i=0;i<=s1.length();i++){
            for(int j=0;j<=s2.length();j++){ 
                if(i==0 && j==0) dp[i][j]=1;
                
                else if(i==0) {
                    dp[i][j]=dp[i][j-1] && s2[j-1]==s3[i+j-1];
                }
                else if(j==0) {
                    dp[i][j]=dp[i-1][j] && s1[i-1]==s3[i+j-1];
                }
                else {
                    dp[i][j]=(dp[i][j-1] && s2[j-1]==s3[i+j-1]) || (dp[i-1][j] && s1[i-1]==s3[i+j-1]);
                }
            }
        }
        return dp[s1.length()][s2.length()];
    }
};

