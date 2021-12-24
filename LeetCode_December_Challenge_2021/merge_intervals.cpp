//Time complexity O(n)
//Space Complexity O(n*2)
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>>merge;
        sort(intervals.begin(),intervals.end());
        merge.push_back(intervals[0]);
        int j=0;
        for(int i=1;i<intervals.size();i++){
            if(intervals[i][0] <= merge[j][1] && intervals[i][1] <= merge[j][1]) continue;
            else if(intervals[i][0] <= merge[j][1] && intervals[i][1] >= merge[j][1]){
                merge[j][1] = intervals[i][1];
            }else{
                merge.push_back(intervals[i]);
                j++;
            }
        }
        return merge;
    }
};


// Solution Part dfs very simple and intuitive