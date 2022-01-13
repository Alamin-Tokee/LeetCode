//Time Complexity O(nlogn)
//Space Complexity O(1)
class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int n = points.size();
        sort(points.begin(),points.end());
        int i = 1;
        int ans = 1;
        vector<int> top = points[0];
        while(i < n){
            if(points[i][0] <= top[1]){
                top[0] = max(top[0],points[i][0]);
                top[1] = min(top[1],points[i][1]);
            }else{
                top = points[i];
                ans++;
            }
            i++;
        }
        return ans;
    }
};

//Time Complexity O(nlogn)
//Space Complexity O(1)
class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int n = points.size();
        auto cmp = [](vector<int>& a, vector<int>& b) {return a[1] < b[1];};
        sort(points.begin(), points.end(), cmp);
        
        long cur = LONG_MIN; // position of current arrow
        int res = 0;
        int i = 0;
        while (i < n) {
            if (cur >= (long)points[i][0]) {
                i++;
            }
            else {
                cur = points[i][1];
                res++;
            }
        }
        
        return res;
    }
};

//Time Complexity O(nlogn)
//Space Complexity O(1)
class Solution {
public:
    static bool comp(vector<int>&v1, vector<int>&v2){
        return v1[1] < v2[1];  //compare function to sort based on the first index
    }   
    

    int findMinArrowShots(vector<vector<int>>& points) {
        int n = points.size();
        if(points.size()<2) return n;  //if there are 0 or 1 elements, we can simply return the size

        sort(points.begin(), points.end(), comp);  //sort based on the first index
        int ans = 1;
        int prev = points[0][1];  //store the first X-end value
        
        
        for(int i = 1; i < n; i++){
            if(points[i][0] <= prev)  //if the value of current point lies within the previous, we simply continue
             continue;
			 
            ans++;  //the current and previous points don't overlap so we increase our answer
            prev = points[i][1];  // and modify our previous stored X-end with current
        }
        return ans;
    }
};