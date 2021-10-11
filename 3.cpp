class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,bool>mpp;
        int i,j,len,maxlen;
        len=maxlen=0;
        for(i=0;i<s.length();i++){
            for(j=i;j<s.length();j++){
                if(mpp[s[j]]==0){
                    len++;
                    maxlen=max(maxlen,len);
                    mpp[s[j]]=true;
                }
                else{
                    mpp.clear();
                    len=0;
                    break;
                }
            }
        }
        return maxlen;
    }
};

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<int,int>mp;
        int n=s.length();
        int ma=0;
        int j=0;
        for(int i=0;i<n;i++){
            mp[s[i]]++;
            while(mp[s[i]]!=1){
                mp[s[j]]--;
                j++;
            }
            ma=max(ma,i-j+1);
        }
        return ma;
    }
};


class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans = 0, start = -1;
        vector<int> m(128, -1);
        for (int i = 0; i < s.size(); ++i) {
            start = max(start, m[s[i]]);
            m[s[i]] = i;
            ans = max(ans, i - start);
        }
        return ans;
    }
};

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<int>st;
        int n=s.length();
        int left=0,right=0,len=0;
        for(;right<n;){
            if(st.find(s[right])==st.end()){
                st.insert(s[right++]);
                len=max(len,right-left);
            }else{
                st.erase(s[left++]);
            }
        }
        return len;
    }
};