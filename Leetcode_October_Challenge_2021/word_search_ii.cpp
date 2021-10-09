class Solution {
public:
    bool dfs(vector<vector<char>>& board,string &word,int x,int y,int index){
        if(word.size()==index){
            return true;
        }
        if(x < 0 or y < 0 or x >= board.size() or y >= board[0].size() or board[x][y]!=word[index] or board[x][y]=='#') return false;
        
        char ch=board[x][y];
        
        board[x][y]='#';
        
        bool a = (dfs(board,word,x+1,y,index+1) || dfs(board,word,x-1,y,index+1) || dfs(board,word,x,y+1,index+1) || dfs(board,word,x,y-1,index+1));
        
        board[x][y]=ch;
        
        return a;
    }
    
   vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        int n = board.size();
        int m = board[0].size();
        vector<string> res;
        set <char> seen;
        for(auto i = 0; i < n; i++)
            for(auto j = 0; j < m; j++)
                seen.insert(board[i][j]);
				
        for(auto w : words){
            bool found = true;
            for(int i = 0; i < w.length();i++){
                if(!seen.count(w[i])){
                    found = false;
                    break;
                }
            }
            if(!found)
                continue;
            found = false;
            for(int i = 0; i < n; i++){
                for(int j = 0; j < m; j++){
                    if(board[i][j] == w[0] && dfs(board,w,i,j,0)){
                        res.push_back(w);
                        found = true;
                        break;
                    }
                }
                if(found)
                    break;
            }
        }
        return res;
    }
};


class Solution {
public:
    bool solve(vector<vector<char>> &board, string &word, int i, int j, int k, vector<vector<bool>> &visited) {
        if(k == word.length())
            return true;
        
        if(i<0 || i==board.size() || j<0 || j==board[0].size() || board[i][j] != word[k] || visited[i][j])
            return false;
        
        visited[i][j] = true;
        bool l = solve(board, word, i, j-1, k+1, visited);
        bool r = solve(board, word, i, j+1, k+1, visited);
        bool t = solve(board, word, i-1, j, k+1, visited);
        bool b = solve(board, word, i+1, j, k+1, visited);
        visited[i][j] = false;
        return l || r || t || b;
    }
    
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
                
        vector<vector<bool>>visited(board.size(), vector<bool>(board[0].size(), false));
        vector<string> res;
        
        for(auto &word : words) {
            int flag = 0;
            reverse(word.begin(), word.end());
            for (int i=0; i<board.size(); i++) {
                for (int j=0; j<board[0].size(); j++) { 
                    if(solve(board, word, i, j, 0, visited)) {
                        flag=1; break;
                    }
                }
                if(flag) break;
            }
            if(flag) {
                reverse(word.begin(), word.end());
                res.push_back(word);
            }
        }
        return res;
    }
};


class Solution {
public:
    bool search(vector<vector<char>>& board,int i,int j,int temp_idx,string temp,vector<vector<bool>>& visited)
    {
        if(temp_idx==temp.length()-1)
            return true;
        
        visited[i][j]=true;
        
        if(i>0 && !visited[i-1][j] && board[i-1][j]==temp[temp_idx+1] && search(board,i-1,j,temp_idx+1,temp,visited))
            return true;
        if(j>0 && !visited[i][j-1] && board[i][j-1]==temp[temp_idx+1] && search(board,i,j-1,temp_idx+1,temp,visited))
            return true;
        if(i<board.size()-1 && !visited[i+1][j] && board[i+1][j]==temp[temp_idx+1] && search(board,i+1,j,temp_idx+1,temp,visited))
            return true;
        if(j<board[0].size()-1 && !visited[i][j+1] && board[i][j+1]==temp[temp_idx+1] && search(board,i,j+1,temp_idx+1,temp,visited))
            return true;
        
         visited[i][j]=false; 
        
        return false;
    }
    
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        
        int r=board.size(),c=board[0].size(),l=words.size(),i,j,k;
        string temp;
        vector<string> ans;
        
        for(k=0;k<l;k++)
        {
            int flag=0;
            temp=words[k];
            reverse(temp.begin(),temp.end());
            vector<vector<bool>> visited(r,vector<bool>(c,false));
            for(i=0;i<r;i++)
            {
                for(j=0;j<c;j++)
                {
                    if(board[i][j]==temp[0] && search(board,i,j,0,temp,visited))
                    {
                        reverse(temp.begin(),temp.end());
                        ans.push_back(temp);
                        flag=1;
                        break;
                    }
                }
                if(flag)
                    break;
            }
        }
        
        return ans;
    }
};



class Trienode{
public:
    bool end;
    Trienode* child[26];
    Trienode(){
        end=false;
        for(int i=0;i<26;i++) child[i]=NULL;
    }
};
class Solution {
public:
    Trienode *root=new Trienode();
    vector<string>res;
    void insert(string &word){
        Trienode* node=root;
        for(char c:word){
            if(!node->child[c-'a']){
                node->child[c-'a']=new Trienode();
            }
            node=node->child[c-'a'];
        }
        node->end=true;
    }
    void dfs(int i,int j,vector<vector<char>>&board,string &word,Trienode *node){
        if(!(i>=0&&j>=0&&i<board.size()&&j<board[0].size()&&board[i][j]!=' ')) return;
        
        char c=board[i][j];
        if(!node->child[c-'a']) return;
        
        node=node->child[c-'a'];
        word.push_back(c);
        if(node->end){
            res.push_back(word), node->end=false;
        }
        
        board[i][j]=' ';
        dfs(i+1,j,board,word,node);
        dfs(i-1,j,board,word,node);
        dfs(i,j+1,board,word,node);
        dfs(i,j-1,board,word,node);
        
        board[i][j]=c;
        word.pop_back();
        
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words){
        for(string &w:words) insert(w);
        string s;
        for(int i=0;i<board.size();i++)
            for(int j=0;j<board[0].size();j++)
                dfs(i,j,board,s,root);
            
        return res;
    }
};



class Solution {
public:
    
    vector<string> ans;
    int dx[4]={0,0,1,-1};
    int dy[4]={1,-1,0,0};
    
    class Trie {
        public:
            Trie *arr[26];
            bool isEnd = false;
    };
    
    void insert(string &word, Trie* root){
        Trie *cur = root;
        for(int i=0; i<word.size(); ++i){
            int idx = word[i]-'a';
            if(!cur->arr[idx]){
                cur->arr[idx] = new Trie();
            }
            cur=cur->arr[idx];
        }
        cur->isEnd = true;
        return;
    }
    
    bool isValid(vector<vector<char>>& board, int x, int y){
        int row = board.size(), col = board[0].size();
        if(x<0 || x>=row || y<0 || y>=col || board[x][y]=='*') return false;
        return true;
    }
    
    void search(vector<vector<char>>& board, int x, int y, Trie* root, string& str){
        if(board[x][y]=='*') return;
        
        int idx = board[x][y]-'a';
        if(!root->arr[idx]) return;
        
        str.push_back(board[x][y]);
        
        char ch = board[x][y];
        board[x][y]='*';
        
        if(root->arr[idx]->isEnd){
            ans.push_back(str);
            root->arr[idx]->isEnd = false;
        }
        
        for(int i=0;i<4;++i){
            int x1 = x+dx[i], y1 = y+dy[i];
            if(isValid(board,x1,y1)) search(board,x1,y1,root->arr[idx],str);
        }
        
        board[x][y]=ch;
        str.pop_back();
        return;
    }
    
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        Trie *root = new Trie();
        for(auto &word : words) insert(word,root);
        
        int row = board.size(), col = board[0].size();
        string str="";
        for(int i=0;i<row;++i){
            for(int j=0;j<col;++j){
                search(board,i,j,root,str);
            }
        }
        
        return ans;
    }
};


class Solution {
public:
    struct TrieNode{
        unordered_map <char, TrieNode*> children;
        bool endofword;
        string word = "";
    };
    
    TrieNode* getNewNode(){
        TrieNode *new_node= new TrieNode();
        new_node->endofword=false;
        return new_node;
    }
    
    void insertInTrie(string s, TrieNode **root){
        if(*root==NULL) *root= getNewNode();
        TrieNode* ptr= *root;
        for(int i=0;i<s.length();i++){
            if(ptr->children.find(s[i])==ptr->children.end()){
                ptr->children[s[i]]=getNewNode();
            }
            ptr= ptr->children[s[i]];
        }
        ptr->endofword=true;   
        ptr->word=s;
    }
    
    void dfs(vector<vector<char>>& board, int i, int j, TrieNode *root, vector <string> &res){
        char c= board[i][j];
        if(c=='#' || root->children.find(c)==root->children.end()) return;
        
        root = root->children[c];
        
        board[i][j]= '#';
        if(root->endofword==true) root->endofword=false, res.push_back(root->word);
        
        if (i > 0) dfs(board, i - 1, j, root, res);
        if (j > 0) dfs(board, i, j - 1, root, res);
        if (i < board.size() - 1) dfs(board, i + 1, j, root, res);
        if (j < board[0].size() - 1) dfs(board, i, j + 1, root, res);
        board[i][j] = c;
        
    }
    
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        TrieNode *head= NULL;
        vector <string> res;
        int m= board.size();
        int n= board[0].size();
        for(int i=0;i<words.size();i++){
            insertInTrie(words[i], &head);
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                dfs(board, i, j, head, res);
            }
        }
        return res;
    }
};




