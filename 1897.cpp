class Solution {
public:
    bool makeEqual(vector<string>& words) {
        unordered_map<char,int>mp;
        
        if(words.size()==1) return true;
        
        for(auto x:words){
            for(auto a:x){
                mp[a]++;
            }
        }
        
        // unordered_map<char,int>::iterator it;
        // auto x=it->second;
        // for(auto it=mp.begin();it!=mp.end();it++){
        //     if(it->second!=x) return false;
        // }
        
        for(auto& z:mp){
            if(z.second % words.size()!=0) return false;
        }
        
        return true;
    }
}