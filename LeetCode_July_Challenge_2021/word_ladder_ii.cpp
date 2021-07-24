//BFS + BackTracking
//Time complexity: O(NK^2 + α)
//Space Complexity O(N*K)
class Solution {
public:
    unordered_map<string,vector<string>> adj;
    vector<string> currPath;
    vector<vector<string>> shortestPaths;
    vector<string> findNeighbors(string &word,unordered_set<string>& wordList){
        vector<string> neighbors;
        for(int i=0;i<word.size();i++){
            char oldChar = word[i];
            for(char c='a'; c <= 'z'; c++){
                word[i] = c;
                if(c == oldChar || !wordList.count(word)){
                    continue;
                }
                neighbors.push_back(word);
            }
            word[i]=oldChar;
        }
        
        return neighbors;
    }
    void backtrack(string &source, string &destination){
        if(source == destination){
            shortestPaths.push_back(currPath);
        }
        for(int i=0;i<adj[source].size();i++){
            currPath.push_back(adj[source][i]);
            backtrack(adj[source][i],destination);
            currPath.pop_back();
        }
    }
    void bfs(string beginWord, string endWord, unordered_set<string> wordList){
        queue<string> q;
        q.push(beginWord);
        
        if(wordList.find(beginWord)!=wordList.end()){
            wordList.erase(wordList.find(beginWord));
        }
        
        unordered_map<string,int>visited;
        visited[beginWord] = 1;
        
        while(!q.empty()){
            vector<string>store;
            
            for(int i = q.size() - 1; i >= 0; i--){
                string currWord = q.front();
                q.pop();
                vector<string>neighbors = findNeighbors(currWord,wordList);
                for(auto word:neighbors){
                    store.push_back(word);
                    adj[currWord].push_back(word);
                    
                    if(visited.find(word) == visited.end()){
                        q.push(word);
                        visited[word]=1;
                    }
                }
            }
            for(int i=0;i<store.size();i++){
                if(wordList.find(store[i])!=wordList.end()){
                    wordList.erase(wordList.find(store[i]));
                }
            }
        }
    }
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> copyWordList(wordList.begin(),wordList.end());
        bfs(beginWord,endWord,copyWordList);
        
        currPath={beginWord};
        
        backtrack(beginWord,endWord);
        
        return shortestPaths;
    }
};