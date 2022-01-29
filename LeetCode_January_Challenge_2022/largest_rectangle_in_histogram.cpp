//TC O(n)
//SC O(n)
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size(), res = 0;
        stack<int> s;
        vector<int>left(n), right(n);
        s.push(-1);
        for(int i = 0; i < heights.size(); i++){
            while(s.top()!=-1 and heights[s.top()] >= heights[i]) s.pop();
            left[i] = s.top();
            s.push(i);
        }
        while(s.size()) s.pop();
        s.push(n);
        for(int i = n-1; i >= 0; i--){
            while(s.top()!=n and heights[s.top()] >= heights[i]) s.pop();
            right[i] = s.top();
            s.push(i);
        }
        for(int i = 0; i < n; i++){
            res = max(res, (right[i]-left[i]-1) * heights[i]);
        }
        return res;
    }
};