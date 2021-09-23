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




