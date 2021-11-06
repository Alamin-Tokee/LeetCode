class Solution {
public:
    int maxArea(vector<int>& height) {
        int l=0,r=height.size()-1;
        int maxarea=0;
        while(l<r){
            maxarea=max(maxarea,min(height[l],height[r])*(r-l));
            
            if(height[l] < height[r]){
                l++;
            }else{
                r--;
            }
        }
        return maxarea;
    }
};


class Solution {
public:
    int maxArea(vector<int>& height) {
        int l=0,r=height.size()-1;
        int maxarea=0;
        while(l<r){
            maxarea=max(maxarea,min(height[l],height[r])*(r-l));
            min(height[l],height[r])==height[l] ? l++ : r--;
        }
        return maxarea;
    }
};