//TC O(V+E)
//SC O(E+E+V)
class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& pr) {
        vector<vector<int>> g(n);
        vector<int> ans,indegree(n);
        
        for(auto& p:pr){
            g[p[1]].push_back(p[0]);
            indegree[p[0]]++;
        }
        queue<int> q;
        for(int i=0;i<n;i++){
            if(indegree[i] == 0) q.push(i);
        }
        
        while(size(q)){
            auto cur = q.front();q.pop();
            ans.push_back(cur);
            for(auto nextCourse : g[cur]){
                if(--indegree[nextCourse] == 0)
                    q.push(nextCourse);
            }
        }
        if(size(ans) == n) return ans;
        
        return {};
    }
};

//TC O((E+V)+V)
//SC O(E+E+V)
class Solution {
public:
    bool dfs(vector<vector<int>>&graph,vector<int>&color,vector<int>&res,int cur){
        color[cur] = 1;
        
        for(auto nb : graph[cur]){
            if(color[nb] == 1) return true;
            if(color[nb] == 0) {
                if(dfs(graph,color,res,nb)) return true;
            }
        }
        color[cur] =  2;
        res.push_back(cur);
        
        return false;
    }
    vector<int> findOrder(int numCourse, vector<vector<int>>& prerequisites) {
        vector<int>color (numCourse, 0), res;
        vector<vector<int>>graph(numCourse);
        
        for(auto pre : prerequisites){
            graph[pre[0]].push_back(pre[1]);
        }
        
        for(int i=0; i<numCourse; i++){
            if(!color[i]){
                if(dfs(graph,color,res,i)) return {};
            }
        }
        return res;
    }
};