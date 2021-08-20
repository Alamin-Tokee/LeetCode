//Time Complexity O(9*9)
//Space Complexity(9*9)
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