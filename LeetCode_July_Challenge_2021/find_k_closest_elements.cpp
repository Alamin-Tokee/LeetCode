//Using Vector

class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        
        vector<pair<int, int>> vp;
        vector<int> diff;
        
        
        for(int i = 0; i < arr.size(); i++)
        {
            int y = abs(x - arr[i]);
            vp.push_back({y, arr[i]});
        }
        
        sort(vp.begin(), vp.end());
        
        for(int i = 0; i < k; i++)
        {
            diff.push_back(vp[i].second);
        }
        sort(diff.begin(), diff.end());
        
        return diff;
    }
};