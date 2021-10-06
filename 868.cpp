//DFS 1
class Solution {
public:
    void dfs(int node,vector<vector<int>>&g,vector<int>&color,vector<int>&vis,int temp,bool &bi){
        if(vis[node]){
            if(color[node]!=temp)
                bi=false;
            return;
        }
        vis[node]=1;
        color[node]=temp;
        int tmp = temp == 0 ? 1 : 0;
        for(int i=0;i<g[node].size();i++){
            dfs(g[node][i],g,color,vis,tmp,bi);
        }
    }
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>>v(n+1);
        vector<int>color(n+1,-1);
        bool bi=true;
        vector<int>vis(n+1,0);
        int temp=0;
        
        for (int i = 0; i < dislikes.size(); i++)
        {
            int x, y;
            x = dislikes[i][0];
            y = dislikes[i][1];
            v[y].push_back(x);
            v[x].push_back(y);
        }
        
        for(int i=0;i<n;i++){
            if(!vis[i]) {
                dfs(i,v,color,vis,temp,bi);
                if(!bi) break;
            }
        }
        
        return bi;
    }
};

//DFS 2
class Solution {
public:
	bool dfs(int n,vector<vector<int>>&v,vector<int>&vis,int i)
	{    
		for(auto l:v[i]){
             if(vis[l]==vis[i]) return false;
             else if(vis[l]==0){
             	vis[l]=-vis[i];
             	if(!dfs(n,v,vis,l)) return false;
             }
		}
		return true;

	}
	bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
		vector<vector<int>>v(n+1);
		vector<int>vis(n + 1, 0);
		for (int i = 0; i < dislikes.size(); i++)
		{
			int x, y;
			x = dislikes[i][0];
			y = dislikes[i][1];
			v[y].push_back(x);
			v[x].push_back(y);
		}
		for(int i=1;i<=n;i++)
		{
			if(vis[i]!=0)continue;
			vis[i]=1;
            if(!dfs(n,v,vis,i))
              return false;
		}
          return true;	
	}
};

//BFS 1
class Solution {
public:
    bool Bipartite(vector<vector<int>> &adj,vector<int> &color,int src){
    queue<int> q;
    q.push(src);
    color[src]=1;
    
    while(!q.empty()){
        int node=q.front();
        q.pop();
    
        for(auto it:adj[node]){
            if(color[it]==-1){
               color[it]=1-color[node];
               q.push(it);
            }
            else if(color[it]==color[node]){
               return false;
            }
         }
     }
      return true;
    }
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>> adj(n+1);
    
        
        for(int i=0;i<dislikes.size();i++){
            adj[dislikes[i][0]].push_back(dislikes[i][1]);
            adj[dislikes[i][1]].push_back(dislikes[i][0]);
        }
        vector<int> color(n+1,-1);
        for(int i=0;i<n;i++){
            if(color[i]==-1){
                if(Bipartite(adj,color,i)==false)
                    return false;
            }
        }
        return true;
    }
};

//DFS 3
class Solution {
public:
    bool bipartiteDFS(int node, vector<vector<int>> &graph, vector<int> &color)
    {
        if(color[node] == -1)
            color[node] = 1;
        for(auto it : graph[node])
        {
            if(color[it] == -1)
            {
                color[it] = 1 - color[node];
                if(!bipartiteDFS(it, graph, color))
                    return false;
            }
            else if(color[it] == color[node])
                return false;
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, -1);
        for(int i = 0; i < n; i++)
        {
            if(color[i] == -1)
            {
                if(!bipartiteDFS(i, graph, color))
                    return false;
            }
        }
        return true;
    }
};

//DFS 4
class Solution {
public:

    bool isBipartite(vector<vector<int>>& graph) {
    int n=graph.size();
    vector<int>vis(n,-1);
    
    for(int i=0;i<n;i++){
        if(vis[i]==-1){ 
        if(dfs(i,-1,0,graph,vis)==false)
                return false;
    }
    }
   return true;     
    
}

bool dfs(int source,int par,int color,vector<vector<int>>&g,vector<int>&vis){
    vis[source]=color;
    for(int x:g[source]){
        if(vis[x]==-1){
            if(dfs(x,source,!color,g,vis)==false)
                return false;
        }
       else 
       {
           if(x!=par && vis[x]==color)
              return false;
       }
 }
        return true;    
}
};