//O(nlogn)
//o(n)
class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        priority_queue<int>maxh;
        int mi = INT_MAX;
        int diff = INT_MAX;
        for(auto i:nums){
            if(i%2!=0) i=i*2;
            mi = min(mi, i);
            maxh.push(i);
        }
        while(maxh.top()%2==0){
            int mx=maxh.top();
            maxh.pop();
            diff=min(diff,mx-mi);
            mi = min(mi,mx/2);
            maxh.push(mx/2);
        }
        return min(diff, maxh.top()-mi);
    }
};