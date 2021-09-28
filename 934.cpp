class Solution {
public:
    int x[4]={0,1,0,-1};
    int y[4]={1,0,-1,0};
    void dfs(vector<vector<int>>& g,queue<pair<int,int>>&q,int r,int c,int m,int n){
        g[r][c]=2;
        q.push({r,c});
        
        for(int i=0;i<4;i++){
            int u=r+x[i];
            int v=c+y[i];
            if(u < 0 or v < 0 or u >= m or v >= n or g[u][v] == 0 or g[u][v] == 2)
                continue;
            dfs(g,q,u,v,m,n);
        }
    }
    int bfs(vector<vector<int>>& g,queue<pair<int,int>>&que,int m,int n){
        int cnt=0;
        while(!que.empty()){
            int sz=que.size();
            cnt++;
            while(sz--){
                int p=que.front().first;
                int q=que.front().second;
                que.pop();
                for(int i=0;i<4;i++){
                    int u=p+x[i],v=q+y[i];
                    if(u < 0 or v < 0 or u >= m or v >= n or g[u][v] == 2)
                        continue;
                
                    if(g[u][v]==1) return cnt-1;
                    
                    g[u][v]=2;
                    que.push({u,v});
                }
            }
        }
        return 0;
    }
    int shortestBridge(vector<vector<int>>& A) {
        int m=A.size();
        int n=A[0].size();
        queue<pair<int,int>>q;
        bool istrue=false;
        int ans=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(A[i][j]==1){
                    dfs(A,q,i,j,m,n);
                    istrue=true;
                    break;
                }
            }
            if(istrue) break;
        }
        
        ans=bfs(A,q,m,n);
        
        return ans;
    }
};