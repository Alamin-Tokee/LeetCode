//DFS solution 

class Solution {
public:
    bool dfs(vector<vector<int>> &m,int node, vector<int>visited, int parent){
        if(find(visited.begin(),visited.end(),node)!=visited.end())return true;
        
        visited.push_back(node);
        
        for(int v:m[node]){
            if(v==parent) 
                continue;
            if(dfs(m,v,visited,node)) {
                return true;
            }
        }
        
        return false;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        vector<int>visited;
        
        vector<vector<int>> m(n+1);
        
        for(int i=0;i<n;i++){
            int u=edges[i][0];
            int v=edges[i][1];
            
            m[u].push_back(v);
            m[v].push_back(u);
            
            if(dfs(m,u,visited,-1))         
            {
              return {u,v};
            }
            visited.clear();
        }
        
        return {};
    }
};

//Rank by Comprehension Approcah
class Solution {
public:
    vector<int>nodes,rank;
    int find(int a){
        if(nodes[a]==-1) return a;
        else return nodes[a]=find(nodes[a]);
    }
    void Union(int a,int b){
        int fa=find(a), fb=find(b);
        
        if(rank[fa] > rank[fb])
            nodes[fb]=fa;
        else if(rank[fa] < rank[fb])
            nodes[fa]=fb;
        else{
            nodes[fb]=fa;
            rank[fa]++;
        }
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        nodes.resize(1001,-1);
        rank.resize(1001,-1);
        
        for(auto edg:edges){
            if(find(edg[0])==find(edg[1])) return edg;
            else Union(edg[0],edg[1]);
        }
        return {};
    }
};

//Union find solution 

class Solution {
public:
    vector<int>parent;
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<int> ans(2);
        parent.resize(edges.size()+1,-1);
        ans=detectCycle(edges);
        return ans;
    }
    void unionOperation(int from,int to){
        from=find(from);
        to=find(to);
        parent[from]=to;
    }
    int find(int v){
        if(parent[v]==-1) return v;
        else return find(parent[v]);
    }
    vector <int> detectCycle(vector<vector<int>>& edges){
        vector<int> ans(2);
        for(int i=0;i<edges.size();i++){
            if(find(edges[i][0])==find(edges[i][1])) {
            ans[0]=edges[i][0]; ans[1]=edges[i][1]; break;
            }
            else unionOperation(find(edges[i][0]),find(edges[i][1]));
        }
       return ans;
    }
};

