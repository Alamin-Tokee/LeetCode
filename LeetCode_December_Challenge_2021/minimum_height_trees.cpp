

class Solution {
public:
    // Time Complexity:- O(V+E)
    // Space Complexity:- O(V)
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n==1) return {0};
        vector<int> deg(n),adj[n];
        for(auto& edge:edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
            deg[edge[1]]++;deg[edge[0]]++;
        }
        for(int i=0;i<n;i++){
            cout<< deg[i] << endl;
        }
        queue<int> q;
        vector<int> ans;
        for(int i=0;i<n;i++){
            if(deg[i]==1){ // start with leaves
                deg[i]--;
                q.push(i);
            }
        }
        
        while(!q.empty()){
            int sz = q.size();
            ans.clear();
            while(sz--){
                int v = q.front();
                q.pop();
                ans.push_back(v);
                for(auto& u:adj[v]){
                    if(--deg[u]==1) // when the current node becomes a leaf push it into queue
                        q.push(u);
                }
            }
        }
        return ans;
    }
};


//Brute Force Technique(Intution)
class Solution {
public:
    int dfs( vector<vector<int>>&adj,int node,vector<bool>&vis){
        vis[node]=true;
        int ma=INT_MIN;
        for(auto x:adj[node]){
            if(!vis[x]){
                ma=max(ma,1+dfs(adj,x,vis));
            }
        }
        return ma+1;
    }
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<vector<int>>adj(n);
        
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        int min=INT_MAX;
        vector<bool>vis(n,false);
        unordered_map<int,int>rootMap;
        for(int i=0;i<n;i++){
            int d=dfs(adj,i,vis);
            if(d < min) min = d;
            rootMap[i]=d;
            fill(vis.begin(),vis.end(), false);
        }
        vector<int>ans;
        for(auto it=rootMap.begin();it!=rootMap.end();it++){
            if(it->second == min) ans.push_back(it->first);
        }
        return ans;
    }
};

class Solution {
public:
    int dfs( vector<vector<int>>&adj,int node,int pa){
        int ma=INT_MIN;
        for(auto x:adj[node]){
            if(x!=pa){
                ma=max(ma,1+dfs(adj,x,node));
            }
        }
        return ma;
    }
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<vector<int>>adj(n);
        
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        int min=INT_MAX;
        int d=INT_MIN;
        unordered_map<int,int>rootMap(n,INT_MAX);
        for(int i=0;i<n;i++){
            for(auto node:adj[i]){
                d=max(d,1+dfs(adj,node,i));
                if(d < min) min=d;
            }
            int m=min(rootMap[i],d);
            rootMap[i]=m;
        }
        vector<int>ans;
        for(auto it=rootMap.begin();it!=rootMap.end();it++){
            if(it->second == min) ans.push_back(it->first);
        }
        return ans;
    }
};




 class Solution {
  public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
      list<int> *adj = new list<int>[n];

      for (auto e : edges) {
        adj[e[0]].push_back(e[1]);
        adj[e[1]].push_back(e[0]);
      }
      unordered_map<int, int> rootMap;
      int min = INT_MAX;
      vector<bool> visited(n, false);
      for (int i = 0; i < n; i++) {
        int d = dfs(i, adj, visited);
        if (min > d)
          min = d;
        rootMap[i] = d;
        fill(visited.begin(), visited.end(), false);
      }

      vector<int> res;
      for (auto e : rootMap) {
        if (min == e.second) {
          res.push_back(e.first);
        }
      }
      return res;
    }
    int dfs(int i, list<int> *adj, vector<bool> &visited) {
      visited[i] = true;
      int max = 0;
      int d = 0;
      for (auto it = adj[i].begin(); it != adj[i].end(); it++) {
        if (!visited[*it])
            d = dfs(*it, adj, visited);
        if (d > max)
          max = d;
      }
      return max + 1;
    }
  };