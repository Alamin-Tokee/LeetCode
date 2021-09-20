//First Approach

class Solution {
public:
    string tictactoe(vector<vector<int>>& moves) {
        vector<vector<char>>grid(3,vector<char>(3));
        char val='x';
        
        for(auto a:moves){
            grid[a[0]][a[1]]=val;
            if(val=='x') val='o';
            else val='x';
        }
        
        for(int i=0;i<3;i++){
            //check row;
            if(grid[i][0]=='x' && grid[i][1]=='x' && grid[i][2]=='x') return "A";
            if(grid[i][0]=='o' && grid[i][1]=='o' && grid[i][2]=='o') return "B";
            
            //check col
            if(grid[0][i]=='x' && grid[1][i]=='x' && grid[2][i]=='x') return "A";
            if(grid[0][i]=='o' && grid[1][i]=='o' && grid[2][i]=='o') return "B";
            
            //check diagonal
            if(i==0){
                if(grid[i][i]=='x' && grid[i+1][i+1]=='x' && grid[i+2][i+2]=='x') return "A";
                if(grid[i][i]=='o' && grid[i+1][i+1]=='o' && grid[i+2][i+2]=='o') return "B";
            }else if(i==2){
                if(grid[i-2][i]=='x' && grid[i-1][i-1]=='x' && grid[i][i-2]=='x') return "A";
                if(grid[i-2][i]=='o' && grid[i-1][i-1]=='o' && grid[i][i-2]=='o') return "B";
            }
        }
        if(moves.size() < 9) return "Pending";
        
        return "Draw";
    }
};

//Second Approach
class Solution {
public:
    string tictactoe(vector<vector<int>>& moves) {
        vector<vector<bitset<3>>> grid(2, vector<bitset<3>>(3));
        string result = "Pending";
        int i = 0;
        for(auto move: moves) {
            if(i & 1)
                grid[1][move[0]].set(move[1], 1);
            else 
                grid[0][move[0]].set(move[1], 1);
            i++;
        }
        bool A = check_victory(grid[0]);
        bool B = check_victory(grid[1]);
        if(A)
            result = "A";
        if(B)
            result = "B";
        if(!A && !B && moves.size() == 9)
            result = "Draw";
        return result;
    }
private:
    bool check_victory(const vector<bitset<3>>& grid) {
        // horizontal
        for(auto agrid: grid) {
            if(agrid.all()) {
                return true;
            }
        }
        // vertical
        if(grid[0].test(0) && grid[1].test(0) && grid[2].test(0) ||
           grid[0].test(1) && grid[1].test(1) && grid[2].test(1) ||
           grid[0].test(2) && grid[1].test(2) && grid[2].test(2)) {
               return true;
         }
         // diagonal
         if(grid[0].test(0) && grid[1].test(1) && grid[2].test(2) ||
           grid[0].test(2) && grid[1].test(1) && grid[2].test(0)) {
               return true;
         }  
         return false;
    }
};


//Third Approach
class Solution {
public:
    string tictactoe(vector<vector<int>>& moves) {
       
       
        char mat[3][3];
        int c=0;
        for(auto &i:moves)
        {
            if(c%2==0)
            mat[i[0]][i[1]]='X';
            else 
            mat[i[0]][i[1]]='0';
            c++;
        }
        string x,y;
        for(int i=0;i<3;i++)
        {
            x.clear();
            y.clear();
            for(int j=0;j<3;j++)
            {
                x+=mat[i][j];
                y+=mat[j][i];
            }
            if(x=="XXX" || y=="XXX")
            {
                 return "A";
            }           
            else if(x=="000" || y=="000")
            {
                return "B";
            }                
        }
        x.clear();
        x+= mat[0][0];
        x+= mat[1][1];
        x+= mat[2][2];
        if(x=="XXX")
            return "A";
        else if(x=="000")
            return "B";
        x.clear();
        x += mat[2][0];
        x+= mat[1][1];
        x+= mat[0][2];
        if(x=="XXX")
            return "A";
        else if(x=="000")
            return "B";
         if(moves.size()==9)
            return "Draw";
        else
            return "Pending";
        
        
    }
};

//Fourth Approach 
class Solution {
public:

string check(vector<vector<int>> T)
{
    int cnt1 = 0 , cnt2 = 0;
    
    // row checking 
    
    for(int i=0 ; i<3 ; i++)
    {
        cnt1 = 0;
        cnt2 = 0;
        for(int j=0 ; j<3 ; j++)
        {
             if(T[i][j] == 1) cnt1++;
             if(T[i][j] == 2) cnt2++;
        }
        
        if(cnt1 == 3) return "A";
        if(cnt2 == 3) return "B";
    }
    
    // column checking 
    
    for(int i=0 ; i<3 ; i++)
    {
        cnt1 = 0;
        cnt2 = 0;
        for(int j=0 ; j<3 ; j++)
        {
             if(T[j][i] == 1) cnt1++;
             if(T[j][i] == 2) cnt2++;
        }
        
        if(cnt1 == 3) return "A";
        if(cnt2 == 3) return "B";
    }
    
    // 1st diagonal checking 
    
     cnt1 = 0;
     cnt2 = 0; 
    
    for(int i=0 ; i<3 ; i++)
    {
        if(T[i][i] == 1) cnt1++;
        if(T[i][i] == 2) cnt2++;
    }
    
    if(cnt1 == 3) return "A";
    if(cnt2 == 3) return "B";
    
    // 2nd diagonal checking 
    
    
     cnt1 = 0;
     cnt2 = 0; 
    
    for(int i=0 ; i<3 ; i++)
    {
        if(T[i][2-i] == 1) cnt1++;
        if(T[i][2-i] == 2) cnt2++; 
    }
    
    if(cnt1 == 3) return "A";
    if(cnt2 == 3) return "B";
    
    return "";
}

string tictactoe(vector<vector<int>>& moves) {
    
    
    vector<vector<int>> T(3 , vector<int> (3)) ;
    
    for(int i=0 ; i<moves.size() ; i++)
    {
         int m = moves[i][0];
         int n = moves[i][1];
         
         if(i%2 == 0) T[m][n] = 1;
         else T[m][n] = 2;            
    }
    
    string winner = check(T);
    if(winner.size()) return winner;
    
    if(moves.size() < 9) return "Pending";
    
    return "Draw";
    
    
    
}
};

//Fifth Approach
class Solution {
public:
    string tictactoe(vector<vector<int>>& moves) {
        vector<vector<int>> score(2, vector<int>(8)); 
        for (int i = 0, k = 0; i < moves.size(); ++i, k ^= 1) {
            int x = moves[i][0], y = moves[i][1]; 
            score[k][x]++; 
            score[k][3+y]++; 
            if (x == y) score[k][6]++; 
            if (x+y == 2) score[k][7]++; 
            if (score[k][x] == 3 || score[k][3+y] == 3 || score[k][6] == 3 || score[k][7] == 3) return k == 0 ? "A" : "B"; 
        }
        return moves.size() == 9 ? "Draw" : "Pending"; 
    }
};