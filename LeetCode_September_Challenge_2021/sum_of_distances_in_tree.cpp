// TIME COMPLEXITY:- O(N)
// SPACE COMPLEXITY:- O(N)
class Solution {
public:
    vector<unordered_set<int>> tree;
    vector<int> v, count;
    // Counts the path to each node and sums them for every particular node
    void func1(int root, int x) {
        for(auto i: tree[root]) {
            if(i == x) continue;
            func1(i, root);
            count[root] += count[i];
            v[root] += v[i] + count[i];
        }
    }
    // Parent node count - count of closer nodes + count of farther nodes
    void func2(int root, int x) {
        for(auto i: tree[root]) {
            if(i == x) continue;
            count[root] += count[i];
            v[i] = v[root] - count[i] + count.size() - count[i];
            func2(i, root);
        }
    }
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& a) {
        tree.resize(n);
        v.assign(n,0);
        count.assign(n,1);
        for(auto i: a) {
            tree[i[0]].insert(i[1]);
            tree[i[1]].insert(i[0]);
        }
        func1(0, -1);
        func2(0, -1);
        return v;
    }
};



// TIME COMPLEXITY:- O(N)
// SPACE COMPLEXITY:- O(N)
class Solution {
public:
    int dfs(int v,int par,vector<int> adj[],vector<int>& subtree){
        int curr = 0;
        for(auto u:adj[v]){
            if(u!=par){
                curr+=dfs(u,v,adj,subtree);
                curr+=subtree[u];
                subtree[v]+=subtree[u];
            }
        }
        return curr;
    }
    void dfs(int v,int par,vector<int> adj[],vector<int>& ans,vector<int>& subtree,int now){
        ans[v] = now;
        for(auto u:adj[v]){
            if(u!=par)
                dfs(u,v,adj,ans,subtree,now-subtree[u]+subtree[0]-subtree[u]);
        }
    }
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        vector<int> ans(n),subtree(n,1),adj[n];
        for(auto v:edges){
            adj[v[0]].push_back(v[1]);
            adj[v[1]].push_back(v[0]);
        }
        int root_ans = dfs(0,-1,adj,subtree);
        dfs(0,-1,adj,ans,subtree,root_ans);
        return ans;
    }
};

//Optimize Solution O(nlogn)
class Solution {
public:
    vector<vector<int>> adj;
    map<pair<int,int>, pair<int,int>> mem;
    
    pair<int,int> sumDist(int node, int par=-1){
        if(mem.count({node,par}))
            return mem[{node,par}];
        
        int res = 0;
        int visits = 1;
        for(auto x: adj[node]){
            if(x == par) continue;
            auto sd = sumDist(x, node);
            res += sd.first + sd.second;
            visits += sd.second;
        }
        
        return mem[{node,par}] = {res, visits};
    }
    
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        adj = vector<vector<int>>(n);
        mem.clear();
        
        for(auto e: edges){
            int a = e[0], b = e[1];
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        
        vector<int> ans(n);
        for(int i=0;i<n;i++){
            ans[i] = sumDist(i).first;
        }
        return ans;
    }
};














    }
};