class Solution {
public:
    // bool isValidSubGrid(vector<vector<char>>& board,int row,int col){
    //     int beginRow=(row/3)*3;
    //     int endRow=beginRow+2;
    //     int beginColumn=(col/3)*3;
    //     int endColumn=beginColumn+2;
    //     for(int i=beginRow;i<=endRow;i++){
    //         for(int j=beginColumn;j<=endColumn;j++){
    //             if(board[i][j]==board[row][col] && row!=i && col!=j) return false;
    //         }
    //     }
    //     return true;
    // }
    // bool isValidColumn(vector<vector<char>>& board,int row,int col){
    //     for(int i=0;i<9;i++){
    //         if(board[i][col]==board[row][col] && row!=i) return false;
    //     }
    //     return true;
    // }
    // bool isValidRow(vector<vector<char>>& board,int row,int col){
    //     for(int i=0;i<9;i++){
    //         if(board[row][i]==board[row][col] && col!=i) return false;
    //     }
    //     return true;
    // }
    // bool isValid(vector<vector<char>>& board,int row,int col){
    //     return isValidRow(board,row,col) && isValidColumn(board,row,col) && isValidSubGrid(board,row,col);
    // }
    
    bool isValid(vector<vector<char>>& board,int r,int c){
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
    bool solveCell(vector<vector<char>>& board,int row,int col){
        if(board[row].size()==col){
            row++;
            col=0;
        }
        if(board.size()==row){
            std::cout << "SUCCESS" <<std::endl;
            return true;
        }
        if(board[row][col]!='.'){
            return solveCell(board,row,col+1);
        }
        for(int i=1;i<=9;i++){
            board[row][col]='0'+i;
            if(isValid(board,row,col)){
                bool solve=solveCell(board,row,col+1);
                if(solve) return true;
            }
        }
        board[row][col]='.';
        return false;
    }
    void solveSudoku(vector<vector<char>>& board) {
        bool success=solveCell(board,0,0);
    }
};