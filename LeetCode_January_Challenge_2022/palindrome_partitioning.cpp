//Time Complexity O(N * 2^N)
//Space Complexity O(N)

class Solution {
public:
    bool isPanlindrome(string s,int low,int high){
        while(low < high){
            if(s[low++] != s[high--]) return false;
        }
        return true;
    }
    void dfs(vector<vector<string>>& result, string &s, int start, vector<string>currentList){
        if(start >= s.length()) result.push_back(currentList);
        for(int end = start; end < s.length(); end++){
            if(isPanlindrome(s,start,end)){
                currentList.push_back(s.substr(start, end-start+1));
                dfs(result, s, end+1, currentList);
                currentList.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string &s) {
        vector<vector<string>>result;
        vector<string>currentList;
        dfs(result, s, 0, currentList);
        return result;
    }
};

//TC O(N * 2^N)
//SC O(N*N)
class Solution {
public:
    void dfs(vector<vector<string>>& result, string &s, int start, vector<string>currentList, vector<vector<bool>>&dp){
        if(start >= s.length()) result.push_back(currentList);
        for(int end = start; end < s.length(); end++){
            if(s[start] == s[end] && (end-start <= 2 || dp[start+1][end-1])){
                dp[start][end] = true;
                currentList.push_back(s.substr(start, end-start+1));
                dfs(result, s, end+1, currentList,dp);
                currentList.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string &s) {
        int len = s.length();
        vector<vector<bool>>dp (len,vector<bool>(len,false));
        vector<vector<string>>result;
        vector<string>currentList;
        dfs(result, s, 0, currentList,dp);
        return result;
    }
};

//TC O(N * 2^N)
//SC O(N*N)
class Solution {
public:
    void dfs(vector<vector<int>> &arr,int ind,vector<vector<string>> &ans,vector<string> &now,string &s){
		//if reached till end, these substrings make up the whole string
        if(ind==s.size()){
            ans.push_back(now);
        }
        for(int i=ind;i<s.size();i++){
			//if string is palindrome check further combinations with it
            if(arr[ind][i]==1){
                now.push_back(s.substr(ind,1+i-ind));
                dfs(arr,i+1,ans,now,s);
                now.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        int n=s.size();
        vector<vector<int>> arr(n,vector<int>(n));
		//calculating all possible palindromic substrings
        for(int i=0;i<n;i++)
            arr[i][i]=1;
        for(int i=2;i<=n;i++)
        {
            for(int j=0;j<1+n-i;j++){
                int k=j+i-1;
                if(s[j]==s[k]&&(arr[j+1][k-1]==1||i==2))
                    arr[j][k]=1;
                
            }           
        }
        vector<vector<string>> ans;
        vector<string> now;
		//select substrings which makes the complete string
        dfs(arr,0,ans,now,s);
        return ans;
    }
};