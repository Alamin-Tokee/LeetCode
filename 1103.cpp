//Iterative
class Solution {
public:
    vector<int> distributeCandies(int c, int n) {
        vector<int>ans(n,0);
        int i=0,rem=0;
        while(rem<=c){
            ans[i%n]+=i+1;
            i++;
            rem+=i;
        }
        if(rem!=c){
            rem=rem-i;
            ans[(i-1)%n]-=i;
            ans[(i-1)%n]+= c-rem;
        }
        return ans;
    }
};

//Recursion
class Solution {
public:
    void solve(int n, int k, int index, vector<int> &ans){
        if(n <= 0)
            return;
        if(n < index + 1){
            ans[index%k] += n;
            return;
        }
        else
            ans[index%k] += (index + 1);
        solve(n - index - 1, k, index + 1, ans);
        return;
    }
    
    vector<int> distributeCandies(int n, int k) {
        vector<int> ans;
        for(int i = 0; i < k; ++i)
            ans.push_back(0);
        solve(n, k, 0, ans);
        return ans;
    }
};

//Iterative (circle find)
class Solution {
public:
    vector<int> distributeCandies(int N, int K) {
        vector<int>ans(K);
        int i,circle;
        i=circle=0;
        while(N>0)
        {
            int curr_N=(circle*K)+(i+1);
            if(N-curr_N<0)
            ans[i]+=N;
            else
            ans[i]+=curr_N;
            i++;
            N-=curr_N;
            if(i==K)
            {
                i=0;
                circle++;
            }
        }
        return ans;
    }
};