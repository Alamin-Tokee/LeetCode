class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[i].size();j++){
                if(matrix[i][j]==target) return true;
            }
        }
        return false;
    }
};


class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size();
        int m=matrix[0].size();
        
        int i=0,j=m-1;
        
        while(i < n && j >= 0){
            if(matrix[i][j]==target) return true;
            
            if(matrix[i][j] > target){
                j--;
            }else{
                i++;
            }
        }
        return false;
    }
};


class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size();
        int m=matrix[0].size();
        
        int low=0,high=n*m-1;
        
        while(low <= high){
            int mid=low+(high-low)/2;
            if(matrix[mid/m][mid%m]==target) return true;
            
            if(matrix[mid/m][mid%m] < target){
                low=mid+1;
            }else{
                high=mid-1;
            }
        }
        return false;
    }
};


class Solution {
public:
    bool binarySearch(vector<int>a,int target){
        int l=0,h=a.size()-1;
        while(l<=h){
            int m=l+(h-l)/2;
            if(a[m]==target) return true;
            else if(a[m] > target){
                h=m-1;
            }else{
                l=m+1;
            }
        }
        return false;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size();
        int m=matrix[0].size();
        int low=0,high=n-1;
        while(low <= high){
            int mid=low+(high-low)/2;
            if(matrix[mid][0] > target){
                high=mid-1;
            }else if(matrix[mid][m-1] < target){
                low=mid+1;
            }else{
                return binarySearch(matrix[mid],target);
            }
        }
        return false;
    }
};