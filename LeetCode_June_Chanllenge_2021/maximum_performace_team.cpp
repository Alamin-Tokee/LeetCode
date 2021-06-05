
//Time Complexity O(NlogN + NlogK) NlogN need to sort the vector and NlogK need to iterate all the engineers logK time.
//Space Complexity O(N+K)

class Solution {
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
    
        vector<pair<int,int>>vec;
        
        for(int i=0;i<n;i++){
            vec.push_back({efficiency[i],speed[i]});
        }
        
        sort(vec.rbegin(),vec.rend());
        
        priority_queue<int, vector<int> , greater<int>>pq;
        
        long sum=0, ans=0;
        
        for(auto x : vec){
            sum+=x.second;
            pq.push(x.second);
            if(pq.size() > k){
                sum-=pq.top();
                pq.pop();
            }
            
            ans=max(ans, sum*x.first);
        }
        
        return ans % (int)(1e9+7);
    }
};



sort(engineers.begin(), engineers.end(), [](pair<int, int>& a, pair<int, int>& b) {return a.first > b.first;});      
auto comp = [](int n1, int n2) { return n1 > n2; };
priority_queue<int, vector<int>, decltype(comp)> pq(comp);