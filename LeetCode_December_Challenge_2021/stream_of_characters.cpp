//Time Complexiy O(NL+QL)
//Space Complexity O(NL+Q)
class Trie{
    Trie* chars[26]{};
    bool endHere = false;
public:
    void insert(string& s){
        auto cur=this;
        for(int i=size(s)-1;~i;i--){
            if(!cur->chars[s[i]-'a']) 
                cur->chars[s[i]-'a']=new Trie();
            cur=cur->chars[s[i]-'a'];
        }
        cur->endHere=true;
    }
    
    bool search(string& s){
        auto cur=this;
        for(int i=size(s)-1;~i;i--){
            if(!cur->chars[s[i]-'a']) return false;
            cur=cur->chars[s[i]-'a'];
            if(cur->endHere) return true;
        }
        return false;
    }
};
class StreamChecker {
public:
    Trie* T=new Trie();
    string queryStream = "";
    StreamChecker(vector<string>& words) {
        for(auto& w:words){
            T->insert(w);
        }
    }
    
    bool query(char letter) {
        queryStream+=letter;
        return T->search(queryStream);
    }
};

/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker* obj = new StreamChecker(words);
 * bool param_1 = obj->query(letter);
 */