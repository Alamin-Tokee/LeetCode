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