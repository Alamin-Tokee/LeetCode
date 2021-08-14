//Time Complexity O(n^4)
//Space Complexity O(n^3)

class Solution {
public:
    int removeBoxes(vector<int>& boxes) {
        
        int n = boxes.size();
        
        int dp[100][100][100] = {0};
        
        return calculateSubProb(0, n-1, 0, boxes, dp);
    }
    
    int calculateSubProb(int left, int right, int sameBoxes, vector<int>& boxes, int dp[100][100][100]){
        //base cases
        if(left>right)
            return 0;
        if(dp[left][right][sameBoxes]){
            return dp[left][right][sameBoxes];
        }
        
        //remove all the boxes of the same color lying together 
        // for(;left<right && boxes[left+1]==boxes[left] ; left++, sameBoxes++);
        
        int points = (sameBoxes+1)*(sameBoxes+1) + calculateSubProb(left+1, right, 0, boxes, dp);
        
        //find the same color box
        for(int mid = left+1; mid<=right; mid++){
            if(boxes[left]==boxes[mid]){
                points = max(points, calculateSubProb(left+1, mid-1, 0, boxes, dp)+ calculateSubProb(mid, right, sameBoxes+1, boxes, dp));
            }
        }
        
        dp[left][right][sameBoxes] = points;
        return points;
    }
};