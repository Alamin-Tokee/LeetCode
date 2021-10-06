class Solution {
public:
    int dfs(vector<vector<int>>& graph,int i,vector<int>&v){
        if(v[i]!=-1) return v[i];
        
        v[i]=1;
        
        for(int x:graph[i]){
            if(dfs(graph,x,v)) return 1;
        }
        v[i]=0;
        return v[i];
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int>res;
        vector<int>vis(graph.size(),-1);
        
        for(int i=0;i<graph.size();i++){
            if(dfs(graph,i,vis)==0) res.push_back(i);
        }
        return res;
    }
};


class Solution {
public:
    int dfs(vector<vector<int>>& graph,vector<int>&safe,int parent,vector<int>&vis,vector<int>&localvisit){
        vis[parent]=true;
        localvisit[parent]=true;
        for(auto child:graph[parent]){
            if(!vis[child]){
                if(dfs(graph,safe,child,vis,localvisit)){
                    safe[child]=false;
                    safe[parent]=false;
                    return true;
                }
            }
            else if(localvisit[child]){
                safe[parent]=false;
                return true;
            }
        }
        localvisit[parent]=false;
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int>vis(n,false);
        vector<int>localvisit(n,false);
        vector<int>safe(n,true);
        
        for(int i=0;i<n;i++){
            if(!vis[i]) dfs(graph,safe,i,vis,localvisit);
        }
        vector<int>res;
        for(int i=0;i<n;++i){
            if(safe[i]) res.push_back(i);
        }
        return res;
    }
};