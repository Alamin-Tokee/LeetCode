class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
        int m=A.size();
        int n=B.size();
        
        int i=0,j=0;
        vector<vector<int>>ans;
        while(i < m and j < n){
            if(A[i][1] >= B[j][0] and A[i][0] <= B[j][1]){
                int lo=max(A[i][0],B[j][0]);
                int hi=min(A[i][1],B[j][1]);
                ans.push_back({lo,hi});
            }
            A[i][1] < B[j][1] ? i++ : j++;
        }
        return ans;
    }
};