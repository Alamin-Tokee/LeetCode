class Solution {
public:
    bool matchString(string a,string b){
        int size1 = a.size();
        int size2 = b.size();
        int i=0,j=0;
        for(i=0,j=0; i<size1 && j < size2 ;i++){
            if(a[i]==b[j]){
                 j++;
            }
        }
        
        return j==size2;
    }
    int numMatchingSubseq(string s, vector<string>& words) {
        int n=words.size();
        unordered_map<string,int>mp;
        int ans=0;
        for(auto& x:words){
            if(mp.find(x)!=mp.end()) ans+=mp[x];
            else {
                mp[x]=matchString(s,x);
                ans+=mp[x];
            }
        }
        
        return ans;
    }
};