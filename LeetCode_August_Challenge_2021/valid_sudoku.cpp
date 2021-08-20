//Time Complexity O(9*9)
//Space Complexity O(9*9)
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int grid[9][9];
        for(int i=0;i<9;++i){
            for(int j=0;j<9;++j){
                if(board[i][j]!='.')
                    grid[i][j]=board[i][j]-'0';
                
                if(board[i][j]=='.')
                    grid[i][j]=-1;
            }
        }
        
        for(int i=0;i<9;i++){
            int has[10]={0};
            for(int j=0;j<9;j++){
                if(grid[i][j]!=-1){
                    if(has[grid[i][j]]!=0)
                        return false;
                    else
                        has[grid[i][j]]++;
                }
            }
        }
        for(int j=0;j<9;j++){
            int has[10]={0};
            for(int i=0;i<9;i++){
                if(grid[i][j]!=-1){
                    if(has[grid[i][j]]!=0)
                        return false;
                    else
                        has[grid[i][j]]++;
                }
            }
        }
        for(int n=0;n<9;n++){
            int has[10]={0};
            for(int i=(3*n)%9;i<=(3*n)%9 +2;i++){
                for(int j=(n/3)*3;j<=(n/3)*3+2;j++){
                    if(grid[i][j]!=-1){
                        if(has[grid[i][j]]!=0)
                            return false;
                        else
                            has[grid[i][j]]++;
                   }
                }
            }
        }
        return true;
    }
};


//Time Complexity O(9*9)
//Space Complexity O(1)
class Solution {
public:
    bool isCheck(int r,int c,vector<vector<char>>& board){
        int val=(r/3)*3+c/3;
        for(int i=0;i<9;i++){
            if(board[i][c]==board[r][c] && (r!=i)) return false;
            if(board[r][i]==board[r][c] && (i!=c)) return false;
        }
        
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                int idx = (i/3)*3+j/3;
                if(idx==val && board[i][j]==board[r][c] && !(r==i && c==j)) return false;
            }
        }
        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {

        for(int i=0;i<9;++i){
            for(int j=0;j<9;++j){
                if(board[i][j]=='.') continue;
                
                if(isCheck(i,j,board)==false) return false;
            }
        }
        
        return true;
    }
};