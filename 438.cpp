//It was my Intution
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

//Time complexity O(n*m)
//Space Complexity O(n+m)
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