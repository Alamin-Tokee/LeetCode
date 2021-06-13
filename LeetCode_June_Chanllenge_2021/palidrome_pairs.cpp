class Solution {
public:
    bool checkPalindrome(const string& s1, const string& s2) {
        int n1 = s1.length(), n2 = s2.length();
        for (int i=0, j=n1+n2-1; i<j; i++, j--) {
            char a = (i<n1) ? s1[i] : s2[i-n1];
            char b = (j<n1) ? s1[j] : s2[j-n1];
            if (a!=b)
                return false;
        }
        return true;
    }
    vector<vector<int>> palindromePairs(vector<string>& words) {
        int n=words.size();
        vector<vector<int>>ans;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i==j) continue;
                if(checkPalindrome(words[i],words[j])) ans.push_back({i,j});
            }
        }
        
        return ans;
    }
};