class Trie {
public:
    class TrieTree{
        public:
        TrieTree *child[26];
        bool isEnd = false;
    };
    
    TrieTree* root;
    Trie() {
        root=new TrieTree();
    }
    
    void insert(string word) {
        TrieTree* cur = root;
        for(auto &ch:word){
            if(!cur->child[ch-'a']) cur->child[ch-'a'] = new TrieTree();
            cur=cur->child[ch-'a'];
        }
        cur->isEnd=true;
    }
    
    bool search(string word) {
        TrieTree* cur = root;
        for(auto &ch:word){
            if(!cur->child[ch-'a']) return false;
            cur=cur->child[ch-'a'];
        }
        return cur->isEnd ? true : false;
    }
    
    bool startsWith(string prefix) {
        TrieTree* cur = root;
        for(auto &ch:prefix){
            if(!cur->child[ch-'a']) return false;
            cur=cur->child[ch-'a'];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */