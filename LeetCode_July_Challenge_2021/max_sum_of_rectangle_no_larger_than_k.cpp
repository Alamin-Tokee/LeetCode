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


// Time complexity: O(\min(m,n)^2\max(m,n)\log \max(m,n)).Using the same thought process as approach 1.

// Space complexity: O(\max(m, n)). Using the same thought process as approach 1.
class Solution {
public:
    int result = INT_MIN;
    void updateResult(vector<int>& nums, int k) {
        int sum = 0;

        // Container to store sorted prefix sums.
        set<int> sortedSum;
        set<int>::iterator it;

        // Add 0 as the prefix sum for an empty sub-array.
        sortedSum.insert(0);
        for (int& num : nums) {
            // Running Sum.
            sum += num;

            // Get X where Running sum - X <= k such that sum - X is closest to k.
            it = sortedSum.lower_bound(sum - k);

            // If such X is found in the prefix sums.
            // Get the sum of that sub array and update the global maximum result.
            if (it != sortedSum.end())
                result = max(result, sum - *it);

            // Insert the current running sum to the prefix sums container.
            sortedSum.insert(sum);
        }
    }
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        if (matrix[0].size() > matrix.size()) {
            // Stores the 1D representation of the matrix row wise.
            vector<int> rowSum(matrix[0].size());
            for (int i = 0; i < matrix.size(); i++) {
                // Initialize the 1D representation with 0s.
                fill(rowSum.begin(), rowSum.end(), 0);

                // We convert the matrix between rows i..row inclusive to 1D array
                for (int row = i; row < matrix.size(); row++) {
                    // Add the current row to the previous row.
                    // This converts the matrix between i..j to 1D array
                    for (int col = 0; col < matrix[0].size(); col++)
                        rowSum[col] += matrix[row][col];

                    // Run the 1D algorithm for `rowSum`
                    updateResult(rowSum, k);

                    // If result is k, this is the best possible answer, so return.
                    if (result == k)
                        return result;
                }
            }
        } else {
            // Stores the 1D representation of the matrix column wise.
            vector<int> colSum(matrix.size());
            for (int i = 0; i < matrix[0].size(); i++) {
                // Initialize the 1D representation with 0s.
                fill(colSum.begin(), colSum.end(), 0);

                // We convert the matrix between columns i..col inclusive to 1D array
                for (int col = i; col < matrix[0].size(); col++) {
                    // Add the current column to the previous column.
                    for (int row = 0; row < matrix.size(); row++)
                        colSum[row] += matrix[row][col];

                    // Run the 1D algorithm for `colSum`
                    updateResult(colSum, k);

                    // If Max is k, this is the best possible answer, so return.
                    if (result == k)
                        return result;
                }
            }
        }
        return result;
    }
};