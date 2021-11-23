class Solution {
public:
    vector<int>parent;
    vector<int>rank;
    int find(int x){
        if(parent[x]==x) return x;
        return parent[x]=find(parent[x]);
    }
    void unionDSU(int x,int y){
        int u=find(x),v=find(y);
        if(u==v) return;
        
        if(rank[u] < rank[v]){
            parent[u]=v;
        }else if(rank[u] > rank[v]){
            parent[v]=u;
        }else{
            parent[v]=u;
            rank[u]+=1;
        }
    }
    int largestComponentSize(vector<int>& nums) {
        int size=*max_element(nums.begin(),nums.end());
        parent.resize(size+1);
        for(int i=0;i<size+1;++i) parent[i]=i;
        rank.resize(size+1,1);
        
        for(int i=0;i<nums.size();++i){
            for(int j=2;j<=sqrt(nums[i]);++j){
                if(nums[i]%j==0){
                    unionDSU(nums[i],j);
                    unionDSU(nums[i]/j,j);
                }
            }
        }
        unordered_map<int,int>mp;
        for(int i=0;i<nums.size();++i){
            int x=find(nums[i]);
            mp[x]++;
        }
        int maxCount = 0;
        for(auto &m:mp) maxCount=max(maxCount,m.second);
        
        return maxCount;
    }
};


class DSU{
    private:
    vector<int>parent;
    
    public:
    DSU(int n){
        for(int i=0;i<n;i++){
            parent.push_back(i);
        }
    }
    int findParent(int node){
        if(parent[node]==node) return node;
        return parent[node]=findParent(parent[node]);
    }
    void unionOperation(int u,int v){
        int uParent=findParent(u);
        int vParent=findParent(v);
        if(uParent!=vParent)
            parent[uParent] = parent[vParent];
    }
};
class Solution {
public:
    int largestComponentSize(vector<int>& nums) {
        int n=*max_element(nums.begin(),nums.end());
        DSU dsu(n+1);
        
        for(auto &val : nums){
            for(int i = 2; i*i <= val; i++){
                if(val % i == 0){
                    dsu.unionOperation(val,i);
                    dsu.unionOperation(val/i,i);
                }
            }
        }
        unordered_map<int,int>mp;
        int res=1;
        for(auto val : nums){
            res = max(res,++mp[dsu.findParent(val)]);
        }
        return res;
    }
};