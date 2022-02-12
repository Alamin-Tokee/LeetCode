//TC O(N*M)
//SC O(N)

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> words(wordList.begin(), wordList.end());
        
        queue<vector<string>>q;
        q.push({beginWord});
        
        while(!q.empty()){
            int size = q.size();
            unordered_set<string> vis;
            
            while(size--){
                auto cur = q.front();q.pop();
                string last = cur.back();
                if(last==endWord) return cur.size();
                
                for(int i=0;i<last.size();i++){
                    string tmp = last;
                    for(char c='a';c<='z';c++){
                        tmp[i]=c;
                        if(words.find(tmp)!=words.end()){
                            auto now=cur;
                            now.push_back(tmp);
                            vis.insert(tmp);
                            q.push(now);
                        }
                    }
                }
            }
            for(auto it:vis) words.erase(it);
        }
        return 0;
    }
};