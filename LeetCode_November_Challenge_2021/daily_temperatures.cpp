//Time Complexity O(n^2) (Brute Force) TLE
//Space Complexity O(n)

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& tem) {
        int n=tem.size();
        vector<int>ans(n,0);
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(tem[i] < tem[j]){
                    ans[i]=j-i;
                    break;
                }
            }
        }
        return ans;
    }
};

//Time Complexity O(n) Increasing Monotonic Stack)
//Space Complexity O(n)

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& tem) {
        int n=tem.size();
        vector<int>ans(n,0);
        stack<int>st;
        for(int curDay=0;curDay<n;curDay++){
            int curTemp=tem[curDay];
            while(!st.empty() && tem[st.top()] < curTemp){
                int prevDay=st.top();
                st.pop();
                ans[prevDay]=curDay-prevDay;
            }
            st.push(curDay);
        }
        return ans;
    }
};


//Time Complexity O(n) Space Optimized Solution
//Space Complexity O(1)
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& t) {
        vector<int>ans(size(t));
        for(int n=size(t),cur=n-2;cur>=0;cur--){
            int next=cur + 1;
            while(next < n && t[next] <= t[cur]){
                next+= ans[next] ? ans[next] : n;
            }
            if(next < n) ans[cur] = next-cur;
        }
        return ans;
    }
};






