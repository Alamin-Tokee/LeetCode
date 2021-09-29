//Time Complexity O(n*m)
//Space Complexity O(1)
class Solution {
public:
    int m,n;
    void dfs(vector<vector<char>>& g,int i,int j){
        if(i < 0 || j < 0 || i >= m || j >= n || g[i][j]=='.') 
            return;
        
        g[i][j]='.';
        dfs(g,i,j+1); //Move left
        dfs(g,i+1,j); //Move down
    }
    int countBattleships(vector<vector<char>>& board) {
        m=board.size();
        n=board[0].size();
        int cnt=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]=='X'){
                    dfs(board,i,j);
                    cnt++;
                }
            }
        }
        return cnt;
    }
};