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


//Time Complexity O(ElogN)
//Space Complexity O(E)
class Solution {
public:
    int reachableNodes(vector<vector<int>>& edges, int M, int N) {
        vector<int> dist(N, INT_MAX);
        unordered_map<int, unordered_map<int, int>> g;
        for(auto& e:edges) g[e[0]][e[1]] = g[e[1]][e[0]] = e[2] + 1;
        auto cmp = [](const pair<int, int>& a, const pair<int, int>& b){ return a.second > b.second; };
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> pq(cmp);
        pq.push({0,0});
        dist[0] = 0;
        while(!pq.empty()){
            auto u = pq.top().first; pq.pop();
            if( dist[u] >= M ) break;
            for(auto n_w: g[u]){
                int v = n_w.first, w = n_w.second;
                if( dist[u] + w < dist[v]){
                    dist[v] = w + dist[u];
                    pq.push({v, dist[v]});
                }
            }
        }
        
        
        int res = 0;
        for(int i = 0; i < N; i++) if(dist[i] <= M) res++;
        /** the smart part **/
        for(auto& e: edges){
            //couting the reachable nodes lying on edge e from node e[0] 
            int a = dist[e[0]] >= M ? 0: min(M-dist[e[0]], e[2]);
            //couting the reachable nodes lying on edge e from node e[1] 
            int b = dist[e[1]] >= M ? 0: min(M-dist[e[1]], e[2]);
            res += min(a + b, e[2]);
        }
        /******************/
        return res;
        
    }
};