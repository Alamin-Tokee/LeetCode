class Solution {
public:
    struct TrieNode{
        TrieNode *children[26];
        bool isWordEnd;
    };
    TrieNode* root;
    TrieNode* getNode(){
        TrieNode* node=new TrieNode();
        for(int i=0;i<26;i++){
            node->children[i]=nullptr;
        }
        node->isWordEnd=false;
        return node;
    }
    void insert(TrieNode* root,string key){
        TrieNode* curr=root;
        for(int i=0;i<key.size();i++){
            int index=key[i]-'a';
            if(!curr->children[index]){
                curr->children[index]=getNode();
            }
            curr=curr->children[index];
        }
        curr->isWordEnd=true;
    }
    bool search(string s,TrieNode* root){
        TrieNode* curr=root;
        for(int i=0;i<s.size();i++){
            int index=s[i]-'a';
            if(!curr->children[index]){
                curr->children[index]=getNode();
            }
            curr=curr->children[index];
        }
        return curr->isWordEnd;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        root=getNode();
        for(auto word:wordDict){
            insert(root,word);
        }
        int n=s.size();
        vector<bool>dp(n+1,false);
        dp[0]=true;
        for(int i=1;i<=n;i++){
            for(int j=i-1;j>=0;j--){
                if(dp[j]){
                    string word=s.substr(j,i-j);
                    if(search(word,root)){
                        dp[i]=true;
                        break;
                    }
                }
            }
        }
        return dp[n];
    }
};


class Solution {
public:
     bool wordBreak(string s, vector<string>& dict) {
         if(dict.size()==0) return false;
         
         vector<bool>dp(s.size()+1,false);
         dp[0]=true;
         
         for(int i=1;i<=s.size();i++){
             for(int j=i-1;j>=0;j--){
                 if(dp[j]){
                     string word=s.substr(j,i-j);
                     if(find(dict.begin(),dict.end(),word)!=dict.end()){
                         dp[i]=true;
                         break;
                     }
                 }
             }
         }
         return dp[s.size()];
     }
};