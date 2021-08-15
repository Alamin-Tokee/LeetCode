//Time Complexity O(m+n)
//Space Complexity O(m+n)

class Solution {
public:
    string minWindow(string s, string t) {
        //It was my intution

        // int sLen=s.length();
        // int tLen=t.length();
        // string tem="";
        // string ans="";
        // int i=0,j=0,c=0;
        // bool flag = false;
        // int len=INT_MAX;
        // while(i<sLen && j<tLen){
        //     if(s[i]==s[j]){
        //         c++;
        //         flag=true;
        //     }
        //     if(flag){
        //         tem+=s[i];
        //     }
        //     i++,j++;
        //     if(c==tLen){
        //         if(len > tem.length()){
        //             ans.clear();
        //             ans+=tem;
        //             len=ans.length();
        //         }
        //         tem.clear();
        //         c=0;
        //         j=0;
        //         flag=false;
        //     }
        // }
        // return ans.length()!=0 ? ans : "";
        
        unordered_map<char,int>mp;
        for(char x:t) mp[x]++;
        
        int start=0,end=0,begin=0,len=INT_MAX,n=s.length(),counter=t.length();
        
        while(end < n){
            mp[s[end]]--;
            if(mp[s[end]] >= 0){
                counter--;
            }
            end++;
            while(counter==0){
                if(end-start < len){
                    len=end-start;
                    begin=start;
                }
                
                mp[s[start]]++;
                if(mp[s[start]]>0) counter++;
                
                start++;
            }
        }
        
        return len==INT_MAX ? "" : s.substr(begin,len);
    }
};

//Time Complexity O(m+n)
//Space Complexity O(m+n)

class Solution {
public:
    string minWindow(string s, string t) {
        vector<int>hist(128,0);
        
        for(char c:t) hist[c]++;
        
        int remaining = t.length();
        int left=0,right=0,minStart=0,minLen=numeric_limits<int>::max();
        while(right < s.length()){
            if(--hist[s[right++]] >=0) remaining--;
            while(remaining == 0){
                if(right-left < minLen){    
                    minLen=right-left;
                    minStart=left;
                }
                if(++hist[s[left++]] > 0) remaining++;
            }
        }
        return minLen < numeric_limits<int>::max() ? s.substr(minStart,minLen) : "";
    }
};
