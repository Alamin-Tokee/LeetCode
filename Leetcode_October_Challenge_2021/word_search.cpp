//Approach 1
class Solution {
public:
    int dx[4]={0,-1,0,1};
    int dy[4]={-1,0,1,0};
    bool dfs(vector<vector<char>>& g, string &w,int index,int r,int c){
        if(w.size()==index){
            return true;
        }
        if(r<0 || c<0 || r>=g.size() || c>=g[0].size() || w[index]!=g[r][c] || g[r][c]=='#') return false;
        
        char ch=g[r][c];
        g[r][c]='#';

        for(int i=0;i<4;i++){
            int x=r+dx[i];
            int y=c+dy[i];
            
            if(dfs(g,w,index+1,x,y)) return true;
        }
        g[r][c]=ch;
        
        return false;
        
    }
    bool exist(vector<vector<char>>& board, string word) {
        int m=board.size();
        int n=board[0].size();
        vector<vector<int>>vis;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]==word[0]){
                    if(dfs(board,word,0,i,j)) return true;
                }
            }
        }
        return false;
    }
};


//Approach 2
class Solution {
public:
    
    bool dfs(vector<vector<char>>& board,string word,int x,int y,int index){
        if (index==word.length())  return true;
        if (x>=board.size()  || x<0 || y<0 || y>=board[0].size() || board[x][y]=='#' || board[x][y]!=word[index])  return false;
        
        char c = board[x][y];
        board[x][y]='#';
        
        bool a = (dfs(board,word,x+1,y,index+1) || dfs(board,word,x-1,y,index+1) || dfs(board,word,x,y+1,index+1) || dfs(board,word,x,y-1,index+1));
                 
        board[x][y]=c;
        return a;
        
    }
                 
    bool exist(vector<vector<char>>& board, string word) {
        
        for (int i=0;i<board.size();i++){
            for (int j=0;j<board[0].size();j++){
                if (board[i][j]==word[0]){
                    if (dfs(board,word,i,j,0))   return true;
                }
            }
        }
        return false;
        
    }
};

//Approach 3
class Solution {
public:
    bool dfs(vector<vector<char>>& board,int i,int j, string &word,int idx,vector<vector<bool>>&vis)
    {
        if(idx==word.size()-1) return true;
        vis[i][j]=true;
        if(i>0 && !vis[i-1][j] && board[i-1][j]==word[idx+1] && dfs(board,i-1,j,word,idx+1,vis)) return true;
        if(j>0 && !vis[i][j-1] && board[i][j-1]==word[idx+1] && dfs(board,i,j-1,word,idx+1,vis)) return true;
        if(i<board.size()-1 && !vis[i+1][j] && board[i+1][j]==word[idx+1] && dfs(board,i+1,j,word,idx+1,vis)) return true;
        if(j<board[0].size()-1 && !vis[i][j+1] && board[i][j+1]==word[idx+1] && dfs(board,i,j+1,word,idx+1,vis)) return true;
        vis[i][j]=false;
        
        return false;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        int n=board.size(),m=board[0].size();
        vector<vector<bool>>vis(n,vector<bool>(m,false));
        
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(board[i][j]==word[0] && dfs(board,i,j,word,0,vis))
                    return true;
            }
        }
        return false;
    }
};