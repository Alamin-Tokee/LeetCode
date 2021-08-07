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

//DP+Memoization(Accepted)
class Solution {
private:
    vector<vector<int>> memo_one, memo_two;
    
    bool isPalindromic(string &s, int i, int j){
        if(i >= j) return true;
        
        if(memo_two.at(i).at(j) != -1) 
            return memo_two.at(i).at(j); 
        
        if(s.at(i) == s.at(j)) 
            return memo_two.at(i).at(j) = isPalindromic(s, i + 1, j - 1);
        
        return memo_two.at(i).at(j) = false;
    }
    
    int minimumCuts(string &s, int i, int j){
        if(i >= j) return 0;
        
        if(memo_one.at(i).at(j) != -1) return memo_one.at(i).at(j);
        
        if(isPalindromic(s, i, j)) return 0;
        
        int answer = INT_MAX;
        for(int index = i; index < j; index++)
            if(isPalindromic(s, i, index)) 
                answer = min(answer, 1 + minimumCuts(s, index + 1, j));
        
        return memo_one.at(i).at(j) = answer;
    }
    
public:
    int minCut(string s) {
        memo_one = vector<vector<int>>(s.length(), vector<int>(s.length(), -1));
        memo_two = vector<vector<int>>(s.length(), vector<int>(s.length(), -1));
      
        return minimumCuts(s, 0, s.length() - 1);
    }
};

//DP+BottomUp(Accepted)
class Solution {
public:
    int solve(string s){
        int n=s.length();
        vector<int>t(n);
        vector<vector<bool>>P(n,vector<bool>(n,false));
        for(int i=0;i<n;i++){
            P[i][i]=true;
        }
        
        for(int L=2;L<=n;L++){
            for(int i=0;i<n-L+1;i++){
                int j=i+L-1;
                if(L==2){
                    P[i][j]=(s[i]==s[j]);
                }else{
                    P[i][j]=((s[i]==s[j]) && P[i+1][j-1]);
                }
            }
        }
        
        for(int i=0;i<n;i++){
            if(P[0][i]) t[i]=0;
            else{
                t[i]=INT_MAX;
                for(int k=0;k<i;k++){
                    if(P[k+1][i]==true && 1+t[k] < t[i])
                        t[i]=1+t[k];
                }
            }
        }
        return t[n-1];
    }
    int minCut(string s) {
        int n=s.length();
        if(n==0 || n==1) return 0;
        
        return solve(s);
    }
};
