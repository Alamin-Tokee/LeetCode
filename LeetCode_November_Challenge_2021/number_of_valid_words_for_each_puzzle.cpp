class Solution {
public:
    struct TrieNode{
        int countEnd;
        TrieNode* children[26];
        TrieNode(){
            countEnd=0;
            memset(children,0,sizeof(TrieNode*)*26);
        }
    };
    TrieNode trie;
    void insert(int countChar[26]){
        TrieNode* currNode=&trie;
        for(int i=0;i<26;i++){
            if(countChar[i]==1){
                if(currNode->children[i]==nullptr)
                    currNode->children[i]=new TrieNode();
                currNode=currNode->children[i];
            }
        }
        currNode->countEnd++;
    }
    void buildTrie(vector<string>&words){
        int countChar[26];
        for(int i=0;i<words.size();i++){
            memset(countChar,0,sizeof(int)*26);
            string& w=words[i];
            for(auto c:w) countChar[c-'a']=1;
            int count=0;
            for(int i=0;i<26;i++) count+=countChar[i];
            if(count>7) continue;
            insert(countChar);
        }
    }
    int search(TrieNode* node,string& p,int idx,char firstChar,bool metFirst){
        int res=0;
        if(node->countEnd>0 && metFirst) res+=node->countEnd;
        
        for(int i=idx;i<p.length();i++){
            if(node->children[p[i]-'a']!=nullptr){
                res+=search(node->children[p[i]-'a'],p,i+1,firstChar,metFirst || (p[i]==firstChar));
            }
        }
        return res;
    }
    vector<int> findNumOfValidWords(vector<string>& words, vector<string>& puzzles) {
        buildTrie(words);
        vector<int>res;
        for(int i=0;i<puzzles.size();i++){
            char firstChar=puzzles[i][0];
            sort(puzzles[i].begin(),puzzles[i].end());
            int cnt=search(&trie,puzzles[i],0,firstChar,false);
            res.push_back(cnt);
        }
        return res;
    }
};


class Solution {
    int getMask(string& s){
        int mask = 0;
        for(auto c:s)
            mask |= (1<<(c-'a'));
        return mask;
    }
public:
    vector<int> findNumOfValidWords(vector<string>& words, vector<string>& puzzles) {
        unordered_map<int,int>freq;
        for(auto & w: words){
            int mask=getMask(w);
            freq[mask]++;
        }
        vector<int>res;
        for(auto & p : puzzles){
            int mask = getMask(p);
            int cnt = 0;
            int maskFirstChar = 1<<(p[0]-'a');
            for(int i = mask; i > 0; i = ((i-1) & mask)){
                if((i & maskFirstChar) > 0 && freq.count(i)){
                    cnt+=freq[i];
                }
            }
            res.push_back(cnt);
        }
        return res;
    }
};