//Bfs Solution
//Time Complexity O(n*m)
//Space Complexity O(1)

class Solution {
public:
    void bfs(vector<vector<char>>& g,int r,int c){
        int offsets[] = {0, 1, 0, -1, 0};
        queue<pair<int,int>>q;
        int cnt=0;
        q.push({r,c});
        g[r][c]='A';
        while(!q.empty()){
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            for (int k = 0; k < 4; k++) {
                int u = x + offsets[k], v = y + offsets[k + 1];
                if (u >= 0 && u < g.size() && v >= 0 && v < g[0].size() && g[u][v] == 'O') {
                    g[u][v] = 'A';
                    q.push({u, v});
                }
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if((board[i][j]=='O') && (i==0 || j==0 || i==n-1 || j==m-1)) {
                    bfs(board,i,j);
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]=='A'){
                   board[i][j]='O'; 
                }else{
                    board[i][j]='X'; 
                }
            }
        }
    }
};


//DFS Approach
class Solution {
public:
    void dfs(vector<vector<char>>& g,int r,int c){
        if(r < 0 || c < 0 || r >= g.size() || c >= g[0].size() || g[r][c]!='O') return;
        
        g[r][c]='A';
        
        dfs(g,r+1,c);
        dfs(g,r-1,c);
        dfs(g,r,c+1);
        dfs(g,r,c-1);
    }
    void solve(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();
        for(int i=0;i<m;i++){
            dfs(board,0,i);
            dfs(board,n-1,i);
        }
        for(int i=0;i<n;i++){
            dfs(board,i,0);
            dfs(board,i,m-1);
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]=='A'){
                   board[i][j]='O'; 
                }else{
                    board[i][j]='X'; 
                }
            }
        }
    }
};




class Solution {
public:
    const int DX[4] = {-1, 0, 1, 0};
    const int DY[4] = {0, 1, 0, -1};
    void dfs(vector<vector<char>>& g,int r,int c){
        if(r < 0 || c < 0 || r >= g.size() || c >= g[0].size() || g[r][c]!='O') return;
        
        g[r][c] = 'A';
        for (int i = 0; i < 4; i++)
            dfs(g, r + DX[i], c + DY[i]);  
    }
    void solve(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if((i==0 || i==n-1 || j==0 || j==m-1) && board[i][j]=='O')
                    dfs(board,i,j);
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                board[i][j]=board[i][j] == 'A' ? 'O' : 'X';
            }
        }
    }
};




