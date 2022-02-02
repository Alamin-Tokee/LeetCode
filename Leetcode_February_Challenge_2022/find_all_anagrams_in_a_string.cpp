//Time Complexity O(m*n)
///Space Complexity O(n)
class Solution {
public:
    bool checkAnagram(string s,string p){
        for(int i=0;i<s.length();i++){
            cout<<s[i];
        }
        cout<< " "<<endl;
        sort(begin(s),end(s));
        int i=0,j=0,n=p.length();
        while(i<n){
            if(p[i++]!=s[j++]) return false;
        }
        return true;
    }
    vector<int> findAnagrams(string s, string p) {
        int n=s.length();
        vector<int>ans;
        int j=0;
        for(int i=0;i<n;i++){
            if(i < p.size()) continue;
            else{
                bool f=checkAnagram(s.substr(j,i),p);
                if(f){
                    ans.push_back(j);
                }
                j++;
            }
        }
        return ans;
    }
};

//Time Complexity O(N)
//Space Complexity(n* 26)

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int>pv(26,0),res;
        vector<int>sv(26,0);
        
        if(s.size() < p.size()) return res;
        
        for(int i=0;i<p.size();i++){
            sv[s[i]-'a']++;
            pv[p[i]-'a']++;
        }
        
        if(sv==pv) res.push_back(0);
        for(int i=p.size();i<s.size();i++){
            ++sv[s[i]-'a'];
            --sv[s[i-p.size()]-'a'];
            if(pv==sv) res.push_back(i-p.size()+1);
        }
        
        return res;
    }
};



//Time Complexity O(N)
//Space Complexity(n* 26)
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int>res;
        unordered_map<int,int>sv,pv;
        
        if(s.size() < p.size()) return res;
        
        for(int i=0;i<p.size();i++){
            sv[s[i]-'a']++;
            pv[p[i]-'a']++;
        }
        
        if(sv==pv) res.push_back(0);
        for(int i=p.size();i<s.size();i++){
            ++sv[s[i]-'a'];
            if(--sv[s[i-p.size()]-'a']==0) sv.erase(s[i-p.size()]-'a');
            if(pv==sv) res.push_back(i-p.size()+1);
        }
        
        return res;
    }
};


//Time Complexity O(N)
//Space Complexity(n* 26)
class Solution {
    public:
    vector<int> findAnagrams(string s, string p) {
        int n = s.size(), m = p.size(), l = 0, r = 0;
        vector<int>sCount(26,0), pCount(26,0), res;
        for(auto &i:p) pCount[i-'a']++;
        while(r<n){
            sCount[s[r]-'a']++;
            
            if((r-l) >= m) sCount[s[l++]-'a']--;
            
            if(pCount == sCount) res.push_back(l);
            
            r++;
        }
        return res;
    }
};



//Time Complexity O(N)
//Space Complexity(n* 26)
   vector<int> findAnagrams(string s, string p) {
        int s_len = s.length();
        int p_len = p.length();
        
        if(s.size() < p.size()) return {};
        
        vector<int> freq_p(26,0);
        vector<int> window(26,0);
        
        //first window
        for(int i=0;i<p_len;i++){
            freq_p[p[i]-'a']++;
            window[s[i]-'a']++;
        }
        
        vector<int> ans;
        if(freq_p == window) ans.push_back(0);
        
        for(int i=p_len;i<s_len;i++){
            window[s[i-p_len] - 'a']--;
            window[s[i] - 'a']++;
            
            if(freq_p == window) ans.push_back(i-p_len+1);
        }
        return ans;
    }



//Time Complexity O(N)
//Space Complexity(n* 26)
class Solution {
public:
    bool check(int a[26],int b[26]){
        for(int i=0;i<26;i++)
            if(a[i]!=b[i])
                return false;
            return true;
        }
    vector findAnagrams(string s, string p) {
            vector ans;
            int arr[26]={0},n=p.size(),tmp[26]={0};

            if(s.size()<n) return {};
            for(int i=0;i<n;i++){
                tmp[s[i]-'a']++;
                arr[p[i]-'a']++;
            }
            if(check(tmp,arr)) ans.push_back(0);

            for(int i=n;i<s.size();i++){
                tmp[s[i]-'a']++;
                tmp[s[i-n]-'a']--;
                if(check(tmp,arr)) ans.push_back(i-n+1);
            }
        return ans;
    }
};

