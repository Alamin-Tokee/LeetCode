//Time Complexity:O(m^2nlogn)
//Space Complexity O(n)

class Solution {
public:
    int result=INT_MIN;
    void updateResult(vector<int>& rowsum,int k){
        int sum=0;
        set<int>sortedSum;
        set<int>::iterator it;
        sortedSum.insert(0);
        
        for(auto num:rowsum){
            sum+=num;
            
            it=sortedSum.lower_bound(sum - k);
            
            if(it!=sortedSum.end())
                result=max(result, sum - *it);
            
            sortedSum.insert(sum);
        }
    }
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int m=matrix.size();
        int n=matrix[0].size();
        vector<int>rowSum(n);
        
        for(int i=0;i<m;i++){
            fill(rowSum.begin(),rowSum.end(),0);
            for(int row=i;row<m;row++){
                for(int col=0;col<n;col++){
                    rowSum[col]+=matrix[row][col];
                }
                
                updateResult(rowSum,k);
                
                if(result==k) return result;
            }
        }
        
        return result;
    }
};