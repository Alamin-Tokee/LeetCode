//Time Complexity O(n*n2)
//Space Complexity O(1)
class Solution {
public:
    bool isSubString(string a,string b){
        int A=a.length();
        int B=b.length();
        while(A > 0 && B > 0){
            int i=a.length()-A;
            int j=b.length()-B;
            if(a[i]==b[j]){
                A--;
            }
            B--;
        }
        return A==0;
    }
    int findLUSlength(vector<string>& strs) {
        int maxlen=-1;
        for(int i=0;i<strs.size();i++){
            int currlen=strs[i].length();
            bool flag=true;
            for(int j=0;j<strs.size();j++){
                if(i!=j && isSubString(strs[i],strs[j])){
                    flag=false;
                    break;
                }
            }
            if(flag) maxlen=max(maxlen,currlen);
        }
        return maxlen;
    }
};



class Solution {
public:
    int findLUSlength(vector<string>& strs) {
        unordered_map<string,int> mp;
        for(auto& s:strs){
            for(int i=0;i < (1<<s.size()); i++){
                string t;
                for(int j=0;j<s.size();j++){
                    if((i>>j) & 1) t+=s[j];
                }
                mp[t]++;
            }
        }
        int ans = -1;
        for(auto& a: mp){
            if(a.second == 1)
                ans=max(ans, (int)a.first.size());
        }
        return ans;
    }
};


class Solution {
public:
    
    bool isSubseq(string a, string b){
        int j=0;
        for(int i=0;i<b.size();i++){
            if(b[i]==a[j]){
                j++;
            }
            if(j==a.size())
                break;
        }
        return j==a.size();
    }
    int findLUSlength(vector<string>& strs) {
        sort(strs.begin(), strs.end(), [](string& a, string& b){
            return a.length()>b.length();
        });
        for(int i=0;i<strs.size();i++){
            bool istrue=false;
            for(int j=0; j<strs.size() && strs[j].length()>=strs[i].length();j++){
                if(i!=j && isSubseq(strs[i], strs[j])){
                    istrue=true;
                    break;
                }
            }
            if(!istrue)
                return strs[i].length();
        }
          return -1;
    }
};