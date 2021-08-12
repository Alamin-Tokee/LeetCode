//Time Complexity (m*nlogn)
//Space Complexity O(n*m)

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n=strs.size();
        unordered_map<string,vector<string>>mp;
        for(auto x:strs){
            string y=x;
            sort(x.begin(),x.end());
            mp[x].push_back(y);
        }
        vector<vector<string>>ans;
        for(auto a:mp){
            ans.push_back(a.second);
        }
        
        return ans;
    }
};

//Time Complexity O(n*m)
//Space Complexity O(nm)

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> m;
        string tmp_sorted;
        
        for (auto word : strs) {
            tmp_sorted = countSort(word);
            m[tmp_sorted].push_back(word);
        }
        
        vector<vector<string>> res;
        for (auto [word, list] : m) {
            res.push_back(list);
        }
        
        return res;
    }
    
    string countSort(string word) {
        vector<int> count(26);
        string res;
        
        for (auto ch : word) count[ch - 'a']++;
        for (int i = 0; i < 26; i++) res += string(count[i], i+'a');
        return res;
    }
};


//Time Complexity (m*nlogn)
//Space Complexity O(n*m)
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<pair<string,int>>v;
        vector<string>sub;
        vector<vector<string>>vv;
        string x;
        for(int i=0;i<strs.size();i++)
        {
          x=strs[i];
          sort(x.begin(),x.end()); 
          v.push_back({x,i});  
        }
        sort(v.begin(),v.end());
      
        for(int i=0;i<v.size()-1;i++)
        {
            sub.push_back(strs[v[i].second]);
            if(v[i].first!=v[i+1].first)
            {
                vv.push_back(sub);
                sub.clear();
            }
        }
        sub.push_back(strs[v[v.size()-1].second]);
        vv.push_back(sub);
        return vv;
    }
};