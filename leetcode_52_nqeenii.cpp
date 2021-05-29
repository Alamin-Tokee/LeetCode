class Solution {
public:
    int ans=0;
    bool isSafePosition(int &row,int &col,vector<vector<string>>& board,int &n){

        //Same row
        for(int j=0;j<n;j++){
            if(board[row][j]=="Q") return false;
        }


        // we do not need to check column clashes as we place queens in different columns only
        
        // Diagonals
        // since we are placing queens from left column to right column we need to check upper left and lower left diagonals only
        
        for(int i=row,j=col;i>=0 and j>=0;i--,j--){
            if(board[i][j]=="Q") return false;
        }
        
        for(int i=row,j=col;i<n and j>=0;i++,j--){
            if(board[i][j]=="Q") return false;
        }
        
        
        return true;
    }
    void solveNQueen(int col,vector<vector<string>>& board,int &n){
        if(col==n){
            ans++;
            return;
        }
        
        for(int i=0;i<n;i++){
            if(isSafePosition(i,col,board,n)){
                board[i][col]="Q";
                solveNQueen(col+1,board,n);
                board[i][col]=".";
            }
        }
    }
    int totalNQueens(int n) {
        vector<vector<string>>board(n,vector<string>(n, "."));
        
        solveNQueen(0,board,n);
        
        return ans;
    }
};