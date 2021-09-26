#define pii pair<int,pair<int,int>>
class Solution {
public:
    int m,n;
    int bfs(vector<vector<int>>& g,int r,int c,vector<vector<bool>>&vis) {
        int offsets[]  = {-1,0,1,0,-1};
        priority_queue<pii,vector<pii>,greater<pii>> pq;
        pq.push({0,{r,c}});

        while(!pq.empty()){
            //pii top = pq.top();
            int l=pq.top().first;
            int x=pq.top().second.first;
            int y=pq.top().second.second;
            pq.pop();

            if(vis[x][y])continue;
            vis[x][y] = true;
            
            if(x==m-1 && y==n-1)return l;
            
            for(int k=0;k<4;k++){
                int u = x + offsets[k], v = y + offsets[k+1];
                if(u<0 || v<0 || u>=m || v>=n || (u==x && v==y))continue;
                
                int le=abs(g[x][y]-g[u][v]);
                int la=max(le,l);
                //pq.push({max(l,abs(g[x][y]-g[u][v])),{u,v}});
                pq.push({la,{u,v}});
                
            }
        }
        return 0;
    }
    int minimumEffortPath(vector<vector<int>>& heights) {
        this->m = heights.size();
        this->n = heights[0].size();
        vector<vector<bool>> vis(m,vector<bool>(n,false));
        int ans=0;
        ans=bfs(heights,0,0,vis);
        return ans;
    }
};
