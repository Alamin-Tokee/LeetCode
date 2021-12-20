//Time Complexity O(nlogn)
//Space Complexity O(n)
class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        map<int,vector<vector<int>>>mp;
        sort(arr.begin(),arr.end());
        for(int i=0;i<arr.size()-1;i++){
            mp[abs(arr[i]-arr[i+1])].push_back({arr[i],arr[i+1]});
        }
        return mp.begin()->second;
    }
};


//Time Complexity O(nlogn)
//Space Complexity O(1)


class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        vector<vector<int>>answer;
        int minPairDiff = INT_MAX;
        for(int i=0;i<arr.size()-1;i++){
            minPairDiff = min(minPairDiff,arr[i+1]-arr[i]);
        }
        for(int i=0;i<arr.size()-1;i++){
            if(minPairDiff == arr[i+1]-arr[i]){
                answer.push_back({arr[i],arr[i+1]});
            }
        }
        return answer;
    }
};