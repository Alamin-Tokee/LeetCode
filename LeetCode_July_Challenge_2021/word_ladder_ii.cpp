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


//BFS + DFS
//Time Complexity( 26 * NK + NK)
//Space Complexity O(NK)
class Solution {
public:
    vector<vector<string>>  ans;    //Stores all possible paths
    
    void DFS(string& beginWord, string& endWord, unordered_map<string, unordered_set<string>>& adj, vector<string> &path) {
        path.push_back(beginWord);  //Push current word
        if(beginWord == endWord)
        {
            ans.push_back(path);
            path.pop_back();
            return;
        }
        for(auto x : adj[beginWord])
            DFS(x, endWord, adj, path);
        
        path.pop_back();    //Pop current word to Backtrack
    }
    
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string, unordered_set<string>> adj;   //Adjacency List
        unordered_set<string> dict(wordList.begin(),wordList.end());   //Insert WordList in SET
        
        //STEP-1: Find min-depth using BFS
        queue<string> Q;    //For BFS traversal
        Q.push(beginWord);  //Push start node (beginWord)
        unordered_map<string, int> visited; //Key->String (Node)...Value->Level (Depth of traversal)
        visited[beginWord] = 0; //Start node will always be at level 0
        while(!Q.empty())
        {
            string curr = Q.front();
            Q.pop();
            string temp = curr;
            for(int i = 0; i < curr.size(); ++i)    //For all characters
            {
                for(char x = 'a'; x <= 'z'; ++x)    //Try all possible 26 letters
                {
                    if(temp[i] == x)    //Skip if letter is same as in original word
                        continue;

                    temp[i] = x;    
                    if(dict.count(temp) > 0)    //Check if new word is present in wordList
                    {
                        if(visited.count(temp) == 0)    //check if the new word was already visited
                        {
                            visited[temp] = visited[curr] + 1;
                            Q.push(temp);
                            adj[curr].insert(temp);
                        } 
                        else if(visited[temp] == visited[curr] + 1) //If already visited and new word is the child (We should always move down)
                            adj[curr].insert(temp);
                    }
                }
                temp[i] = curr[i];  //Revert back temp to curr
            }
        }
        //STEP-2: Find all possible paths at min-depth using DFS
        vector<string> path;
        DFS(beginWord, endWord, adj, path); //Find all possible paths with min-depth
        return ans; 
    }
};