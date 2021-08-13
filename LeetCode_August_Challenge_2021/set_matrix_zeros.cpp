//Time Complexity O(m*n)
//Space Complexity O(n+m)
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<int>row;
        vector<int>col;
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[i].size();j++){
                if(matrix[i][j]==0){
                    row.push_back(i);
                    col.push_back(j);
                }
            }
        }
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[i].size();j++){
                if(count(row.begin(), row.end(), i) || count(col.begin(), col.end(), j)){
                    matrix[i][j]=0;
                }
            }
        }
    }
};

    // for(int i:row)
    // {
    //     for(int j=0;j<n2;j++)
    //         matrix[i][j]=0;
    // }
    // for(int j:col)
    // {
    //     for(int i=0;i<n1;i++)
    //         matrix[i][j]=0;
    // }

//Time Complexity O(m*n)
//Space Complexity O(n+m)
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        map<int,int>r,c;
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[i].size();j++){
                if(matrix[i][j]==0){
                    r[i]=2;
                    c[j]=2;
                }
            }
        }
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[i].size();j++){
                if(r[i]==2 || c[j]==2){
                    matrix[i][j]=0;
                }
            }
        }
    }
};

//Time Complexity O(m*n)
//Space Complexity O(n+m)
class Solution {
public:
    void rowZero(vector<vector<int>>& matrix,int i){
        for(int j=0;j<matrix[0].size();j++){
            matrix[i][j]=0;
        }
    }
    void colZero(vector<vector<int>>& matrix,int j){
        for(int i=0;i<matrix.size();i++){
            matrix[i][j]=0;
        }
    }
    void setZeroes(vector<vector<int>>& matrix) {
        vector<pair<int,int>>v;
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[i].size();j++){
                if(matrix[i][j]==0){
                    v.push_back({i,j});
                }
            }
        }
        for(int i=0;i<v.size();i++){
            int x=v[i].first;
            int y=v[i].second;
            rowZero(matrix,x);
            colZero(matrix,y);
        }
    }
};

//Time Complexity O(m*n)
//Space Complexity O(1)
class Solution {
public:
    void setZeroes(vector<vector<int>>& ar) {
        int n = ar.size();
        int m = ar[0].size();
        int row = 0, col = 0;
        for(int i = 0; i < m; i++){
            if(ar[0][i] == 0){
                row = 1;
                break;
            }
        }
        for(int i = 0; i < n; i++){
            if(ar[i][0] == 0){
                col = 1;
                break;
            }
        }
        for(int i = 1; i < n; i++){
            for(int j = 1; j < m; j++){
                if(ar[i][j] == 0){
                    ar[i][0] = 0;
                    ar[0][j] = 0;
                }
            }
        }
        for(int i = 1; i < n; i++){
            if(ar[i][0] == 0)
                for(int j = 0; j < m; j++)
                    ar[i][j] = 0;
        }
        for(int i = 1; i < m; i++){
            if(ar[0][i] == 0)
                for(int j = 0; j < n; j++)
                    ar[j][i] = 0;
        }
        if(row == 1){
            for(int i = 0; i < m; i++)
                ar[0][i] = 0;
        }
        if(col == 1){
            for(int i = 0; i < n; i++)
                ar[i][0] = 0;
        }
    }
};

