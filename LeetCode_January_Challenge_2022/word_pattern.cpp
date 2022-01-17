class Solution {
public:
    bool wordPattern(string pattern, string s) {
        vector<string>words;
        string word;
        stringstream iss(s);
        while(iss >> word){
            words.push_back(word);
        }
        if(words.size() != pattern.length())return false;
        unordered_map<char,string>mp;
        set<string>uniq;
        for(int i=0;i<pattern.length();i++){
            if(mp.find(pattern[i])!=mp.end()){
                if(mp[pattern[i]] != words[i])return false;
            }else{
                
                if(uniq.count(words[i]))return false;
                mp[pattern[i]] = words[i];
                uniq.insert(words[i]);
            }
        }
        return true;
    }
};