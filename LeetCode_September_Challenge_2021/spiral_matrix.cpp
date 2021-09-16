//Iterative Soltion
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if(!matrix.size()) return vector<int>();
        
        vector<int>result;
        enum direction{Up,Right,Down,Left};
        direction dir=Right; 
        int rows=matrix.size(), cols=matrix[0].size();
        vector<vector<bool>> visited(rows,vector<bool>(cols,false));
        int x=0;
        int y=0;
        while(x < rows && y < cols && x >= 0 && y >= 0 && !visited[x][y]){
            switch(dir){
                case Right:
                    visited[x][y]=true;
                    result.push_back(matrix[x][y]);
                    
                    if(y+1 >= cols || visited[x][y+1]){
                        dir=Down;
                        x++;
                    }else{
                        y++;
                    }
                    break;
                case Down:
                    visited[x][y]=true;
                    result.push_back(matrix[x][y]);
                    
                    if(x+1 >= rows || visited[x+1][y]){
                        dir=Left;
                        y--;
                    }else{
                        x++;
                    }
                    break;
                case Left:
                    visited[x][y]=true;
                    result.push_back(matrix[x][y]);
                    
                    if(y-1 < 0 || visited[x][y-1]){
                        dir=Up;
                        x--;
                    }else{
                        y--;
                    }
                    break;
                case Up:
                    visited[x][y]=true;
                    result.push_back(matrix[x][y]);
                    
                    if(x-1 < 0 || visited[x-1][y]){
                        dir=Right;
                        y++;
                    }else{
                        x--;
                    }
                    break;
            }
        }
        return result;
    }
};



class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if(!matrix.size()) return vector<int>();
        vector<int>result;
        int rs=0,re=matrix.size(),cs=0,ce=matrix[0].size();
        while(rs<re && cs<ce){
            for(int i=cs;i<ce;i++){
                result.push_back(matrix[rs][i]);
            }
            rs++;
            for(int i=rs;i<re;i++){
                result.push_back(matrix[i][ce-1]);
            }
            ce--;
            if(rs<re){
            for(int i=ce-1;i>=cs;i--){
                result.push_back(matrix[re-1][i]);
            }
            re--;}
            if(cs<ce){
            for(int i=re-1;i>=rs;i--){
                result.push_back(matrix[i][cs]);
            }
            cs++;}
        }
        return result;
    }
};



//Recursive Solution

class Solution {
public:
    vector<int>ans;
    void solve(vector<vector<int>>& mat,vector<vector<bool>>& vis,int i,int j,int m,int n,char d){
        if(i<0 || j <0 || i>=m || j>=n) return;
        
        if(vis[i][j]){
            return;
        }
        
        if(!vis[i][j]){
            ans.push_back(mat[i][j]);
            vis[i][j]=true;
        }
        
        if(d=='r'){
            if(j+1<n && !vis[i][j+1]){
                solve(mat,vis,i,j+1,m,n,'r');
            }else{
                solve(mat,vis,i+1,j,m,n,'d');
            }
        }
        else if(d=='d'){
            if(i+1<m && !vis[i+1][j]){
                solve(mat,vis,i+1,j,m,n,'d');
            }else{
                solve(mat,vis,i,j-1,m,n,'l');
            }
        }
        else if(d=='l'){
            if(j-1>=0 && !vis[i][j-1]){
                solve(mat,vis,i,j-1,m,n,'l');
            }else{
                solve(mat,vis,i-1,j,m,n,'u');
            }
        }
        else if(d=='u'){
            if(i-1>=0 && !vis[i-1][j]){
                solve(mat,vis,i-1,j,m,n,'u');
            }else{
                solve(mat,vis,i,j+1,m,n,'r');
            }
        }
    }
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m=matrix.size(), n=matrix[0].size();
        vector<vector<bool>> visited(m,vector<bool>(n,false));
        solve(matrix,visited,0,0,m,n,'r');
        return ans;
    }
};


