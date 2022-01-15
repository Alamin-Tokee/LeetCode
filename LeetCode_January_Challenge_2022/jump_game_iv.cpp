//TC O(N)
//SC O(N)
class Solution {
public:
    int minJumps(vector<int>& arr) {
        unordered_map<int,vector<int>>m;
        int n=arr.size();
        //chaeck if size is 1 then return 0
        if(n==1){
            return 0;
        }
        //store track of elements in map with there indexes
        for(int i=0;i<n;i++){
            m[arr[i]].push_back(i);
        }
        // we will simply do bfs(start exploring from every node or element)
        queue<int>q;
        q.push(0);
        int ans=0;
        while(!q.empty()){
            int cnt=q.size();
            ++ans;
            for(int i=0;i<cnt;i++){
                int ind=q.front();
                q.pop();
                // go for (ind-1) then (ind+1).
                if(ind-1>=0 && m.find(arr[ind-1])!=m.end()){
                    if(ind-1==n-1){
                        return ans;
                    }
                    q.push(ind-1);
                }
                if(ind+1<n && m.find(arr[ind+1])!=m.end()){
                    if(ind+1==n-1){
                        return ans;
                    }
                    q.push(ind+1);
                }
                // check for same element because we jump to same element to
                if(m.count(arr[ind])){
                    for(auto x:m[arr[ind]]){
                        if(x==n-1){
                            return ans;
                        }
                        q.push(x);
                    }
                }
                m.erase(arr[ind]);
            }
        }
        return ans;
    }
};