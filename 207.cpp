class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& pre) {
        vector<vector<int>>adj(numCourses);
        int m=pre.size();
        vector<int>indegree(numCourses,0);
        for(int i=0;i<m;i++){
            adj[pre[i][1]].push_back(pre[i][0]);
            indegree[pre[i][0]]++;
        }
        queue<int>q;
        for(int i=0;i<numCourses;i++){
            if(indegree[i]==0) q.push(i);
        }
        int cnt=0;
        while(!q.empty()){
            int x=q.front();q.pop();
            cnt++;
            for(auto y:adj[x]){
                if(--indegree[y]==0){
                    q.push(y);
                }
            }
        }
        
        return numCourses == cnt ? true : false;
    }
};