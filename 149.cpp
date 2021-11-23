class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int ans = 1;
        if(points.size() == 1) return ans;
        for(int i=0;i<points.size()-1;i++){
            unordered_map<double,int>mp;
            for(int j=i+1;j<points.size();j++){
                if((points[j][0]-points[i][0])==0) mp[INT_MAX]++;
                else{
                    double slope= ((double)points[j][1]-(double)points[i][1])/((double)points[j][0]-(double)points[i][0]);
                    mp[slope]++;
                }
            }
            for(auto it:mp)
            {
                ans = max(ans,it.second);
            }
        }
        return ans+1;
    }
};
