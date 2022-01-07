//Time Complexity O(n)
//Space Complexity O(1)
class Solution {
public:
    bool carPooling(vector<vector<int>>& a, int cap) {
        int sum=0, maxi=0;
        int A[1001]={0};
        for(auto x: a){
            A[x[1]]+=x[0];
            A[x[2]]-=x[0];
        }
        for(auto x: A){
            sum+=x;
            if(sum>cap) return 0;
        }
        return 1;
    }
};