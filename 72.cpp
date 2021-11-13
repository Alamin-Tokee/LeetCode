class Solution {
public:
    int dp[501][501];
    int editDistance(string &word1,string &word2,int len1,int len2){
        if(dp[len1][len2]!=-1) return dp[len1][len2];
        if(len1==0 || len2==0) return max(len1,len2);
        if(word1[len1-1] == word2[len2-1]){
            return editDistance(word1,word2,len1-1,len2-1);
        }
        int in=editDistance(word1,word2,len1,len2-1);
        int dl=editDistance(word1,word2,len1-1,len2);
        int re=editDistance(word1,word2,len1-1,len2-1);
        return dp[len1][len2]=1+min({in,dl,re});
    }
    int minDistance(string word1, string word2) {
        int len1=word1.size();
        int len2=word2.size();
        memset(dp,-1,sizeof(dp));
        
        return editDistance(word1,word2,len1,len2);
    }
};

class Solution {
public:
    int minDistance(string word1, string word2) {
        int len1=word1.size(), len2=word2.size();
        vector<vector<int>> dp(len1+1,vector<int>(len2+1,0));
        for(int i=1;i<=len1;i++){
            dp[i][0]=i;
        }
        for(int i=1;i<=len2;i++){
            dp[0][i]=i;
        }
        for(int i=1;i<=len1;i++){
            for(int j=1;j<=len2;j++){
                if(word1[i-1]==word2[j-1])
                    dp[i][j]=dp[i-1][j-1];
                else
                    dp[i][j]=min(dp[i-1][j],min(dp[i][j-1],dp[i-1][j-1]))+1;
            }
        }
        return dp[len1][len2];
    }
};