//DP+Memoization(TLE)
class Solution {
public:
    int t[2001][2001];
    bool isPalindrome(string s,int i,int j){
        while(i<j){
            if(s[i++]!=s[j--]) return false;
        }
        return true;
    }
    int solve(string s,int i,int j){
        if(i>=j) return 0;
        
        if(t[i][j]!=-1) return t[i][j];
        
        if(isPalindrome(s,i,j)) return 0;
        
        int cut=INT_MAX;
        for(int k=i;k<j;k++){
            int temp=1+solve(s,i,k)+solve(s,k+1,j);
            
            cut=min(cut,temp);
        }
        return t[i][j]=cut;
    }
    int minCut(string s) {
        int n=s.length();
        memset(t,-1,sizeof(t));
        
        return solve(s,0,n-1);
    }
};
