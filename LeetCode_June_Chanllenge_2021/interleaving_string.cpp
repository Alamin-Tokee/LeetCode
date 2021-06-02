//Time Complexity O(n*m)
//Space Complexity O(n*m)
//2D Array Using

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

//Time Complexity O(n*m)
//Space Complexity O(n*m)
//2D Array Using
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        #define S1 (dp[j] && s1[i-1] == s3[i+j-1])
        #define S2 (dp[j-1] && s2[j-1] == s3[i+j-1])
        
        int n = s1.size(), m = s2.size(), k = s3.size();
        if (n + m != k) return false;
        vector<bool> dp(m+1, 0);
        
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= m; j++) {
                dp[j] = (i==0 && j==0) ? true : i==0 ? S2 : j==0 ? S1 : S1 || S2;
            }
        }

        return dp[m];
    }
};


//Memoization Tecnique used to solve 
//Time Complexity O(n*m)
//Space Complexity O(n*m)

class Solution {
public:
        
    int m, n, N;
    int t[101][101];
    
    bool check(string s1, string s2, string s3, int i, int j) {
        if(i >= m && j >= n && i+j >= N) //solution
            return true;
        
        if(i+j >= N) //other string didn't get consumed whole
            return false;
            
        if(t[i][j] != -1)
            return t[i][j];
        
        //Note that, k is same for both calls because it increases in both cases
        //Also, at any time k = i + j;
        return t[i][j] = ((s1[i]==s3[i+j] && check(s1, s2, s3, i+1, j)) || (s2[j]==s3[i+j] && check(s1, s2, s3, i, j+1)));
    }
    bool isInterleave(string s1, string s2, string s3) {
        memset(t, -1, sizeof(t));
        m = s1.length();
        n = s2.length();
        N = s3.length();
        
        if(m + n != N)
            return false;
        
        return check(s1, s2, s3, 0, 0);
    }
};