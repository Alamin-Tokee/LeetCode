//Time Complexity O(ElogN)
//Space Complexity O(E)
class Solution {
public:
    int reachableNodes(vector<vector<int>>& edges, int maxMoves, int n) {
        int graph[n][n];
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                graph[i][j]=-1;
            }
        }
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            graph[u][v]=edges[i][2];
            graph[v][u]=edges[i][2];
        }
        int ans=0;
        priority_queue<pair<int,int>>pq;
        bool visited[n];
        fill(visited,visited+n,false);
        pq.push({maxMoves,0});
        
        while(!pq.empty()){
            int nearestNodeId=pq.top().second;
            int maxMovesRemaining=pq.top().first;
            pq.pop();
            if(visited[nearestNodeId]) continue;
            
            visited[nearestNodeId]=true;
            ans++;
                
            for(int nei=0;nei<n;nei++){
                if(graph[nearestNodeId][nei]!=-1){
                    if(!visited[nei] && maxMovesRemaining >= graph[nearestNodeId][nei]+1){
                        pq.push({maxMovesRemaining-graph[nearestNodeId][nei]-1,nei});
                    }
                    int movecost=min(graph[nearestNodeId][nei],maxMovesRemaining);
                    graph[nearestNodeId][nei]-=movecost;
                    graph[nei][nearestNodeId]-=movecost;
                    ans+=movecost;
                }
            }
        }
        return ans;
    }
};