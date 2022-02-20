//Brute force 
//TC O(n^2)
//SC O(1)
class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        int ans=0;
        
        for(int i=0;i<intervals.size();i++){
            for(int j=0;j<intervals.size();j++){
                
                if(i!=j and intervals[i][0]>=intervals[j][0] and intervals[i][1]<=intervals[j][1])
                {
                    ans++;
                    break;
                }
            }
        }
        
        return intervals.size()-ans;
    }
};


//Optimal
//TC O(n)
//SC O(1)
class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        int cnt = 1;
        sort(intervals.begin(),intervals.end());
        int first = intervals[0][0];
        int second = intervals[0][1];
        for(int i=1;i<n;i++){
            if(intervals[i][0] > first && intervals[i][1] > second){
                cnt++;
            }
            if(intervals[i][1] > second){
                first = intervals[i][0];
                second = intervals[i][1];
            }
        }
        return cnt;
    }
};


//Optimal
//TC O(n)
//SC O(1)
class Solution{
public:
    static int cmp(vector<int>v1, vector<int>v2){
        if(v1[0]==v2[0]) return v1[1] > v2[1];
        return v1[0] < v2[0]; 
    }
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        if(n==1) return 1;
        sort(intervals.begin(),intervals.end(), cmp);
        for(int i=0;i<n;i++){
            cout<<intervals[i][0] << " " << intervals[i][1] <<endl;
        }
        int cnt = 0;
        int mini = intervals[0][0];
        int maxi = intervals[0][1];
        for(int i=1;i<n;i++){
            if(intervals[i][0] >=mini && intervals[i][1] <= maxi) cnt++;
            mini = min(mini,intervals[i][0]);
            maxi = max(maxi,intervals[i][1]);
        }
        return n-cnt;
    }
};




//Optimal
//TC O(n)
//SC O(1)

// [[1,4],[1,8],[2,7],[3,6],[4,10]]

class Solution{
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(),intervals.end());
        
        int cnt = 0, current = 0;
        for(int i = 1; i < n; i++){
            if(intervals[i][0] >= intervals[current][0] && intervals[i][1] <= intervals[current][1]) {
                cnt++;
            }else if(intervals[i][0] <= intervals[current][0] && intervals[i][1] >= intervals[current][1]){
                current = i;
                cnt++;
            }else if(intervals[i][0] >= intervals[current][0] && intervals[i][1] >= intervals[current][1]){
                current = i;
            }
        }
        return n-cnt;
    }
};


