class Solution {
public:
    string frequencySort(string s) {
        priority_queue<pair<int,char>,vector<pair<int,char>>>q;
        unordered_map<char,int>mp;
        for(int i=0;i<s.length();i++){
            mp[s[i]]++;
        }
        
        for(auto it=mp.begin();it!=mp.end();it++){
            q.push({it->second,it->first});
        }
        s.clear();
        for(;!q.empty();){
            auto it=q.top();
            q.pop();
            while(it.first--){
                s+=it.second;
            }
        }
        return s;
    }
};


class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int>mp;
        multimap<int,char,greater<int>>m;
        for(int i=0;i<s.length();i++){
            mp[s[i]]++;
        }
        
        for(auto it=mp.begin();it!=mp.end();it++){
            m.insert({it->second,it->first});
        }
        
        //sort(freq.begin(), freq.end(), greater<pair<int,int>> ());
        s.clear();
        for(auto it=m.begin();it!=m.end();it++){
            s+=string(it->first,it->second);
        }
        return s;
    }
};


class Solution {
public:
    static bool comp(pair<char,int> p1, pair<char,int> p2){
        return p1.second > p2.second;    
    }
    
    string frequencySort(string s) {
        unordered_map<char, int> mp;
        for(int i = 0; i < s.length(); i++){
            mp[s[i]]++;
        }
        vector<pair<char,int> > v(mp.begin(), mp.end());
        sort(v.begin(), v.end(), comp);
        s.clear();
        
        for(auto i: v){
            while(i.second){
                s += i.first;
                i.second--;
            }
        }
        
        return s;
    }
}




