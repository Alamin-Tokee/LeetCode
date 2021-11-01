//Brute Force Approach
//Give TLE
class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int n=values.size();
        int ans=INT_MIN;
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                ans=max(ans,values[i]+values[j]+i-j);
            }
        }
        return ans;
    }
};


class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int ans=0;
        for(int i=0,most=0;i<values.size();i++){
           if(i) ans=max(ans,most+values[i]-i);
            most=max(most,values[i]+i);
        }
        return ans;
    }
};

class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int maxScore = 0; 
        for (int i = 0, j = 1;  j < values.size(); j++) {
            maxScore = max(maxScore, values[i] + values[j] + i - j);
            if (values[j] >= values[i] + i - j)  i = j; 
        }
        return maxScore;
    }
};