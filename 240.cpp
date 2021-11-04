
//Brute Force 
//Give TLE

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size();
        int m=matrix[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]==target){
                    return true;
                }
            }
        }
        return false;
    }
};


//Optimal Approach(Binary Search)
class Solution {
public:
    bool binarySearch(vector<int>&row,int target){
        int l=0,r=row.size()-1;
        
        while(l<=r){
            int m=l+(r-l)/2;
            if(row[m]==target) return true;
            else if(row[m] < target){
                l=m+1;
            }else{
                r=m-1;
            }
        }
        return false;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size();
        int m=matrix[0].size();
        for(int i=0;i<n;i++){
            if(binarySearch(matrix[i],target)) return true;
        }
        return false;
    }
};