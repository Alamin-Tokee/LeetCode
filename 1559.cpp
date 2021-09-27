class Solution {
public:
    bool isValid(vector<vector<char>>& g,int u,int v,int prex,int prey){
        if (u < 0 || u >= g.size() || v < 0 || v >= g[0].size() || g[u][v] != g[prex][prey]){
            return false;
        }
        return true;
    }
    bool bfs(vector<vector<char>>& g,int r,int c,vector<vector<bool>>&vi){
        int offsets[] = {0, 1, 0, -1, 0};
        queue<pair<pair<int,int>,pair<int,int>>>q;
        q.push({{-1,-1},{r,c}});
        vi[r][c]=true;
        while(!q.empty()){
            int prex=q.front().first.first;
            int prey=q.front().first.second;
            int x = q.front().second.first;
            int y = q.front().second.second;
            q.pop();
            for (int k = 0; k < 4; k++) {
                int u = x + offsets[k], v = y + offsets[k + 1];
                if (isValid(g,u,v,x,y)) {
                    if(vi[u][v]){
                        if(prex!=u or prey!=v){
                            return true;
                        } 
                    }else{
                        vi[u][v] = true;
                        q.push({{x,y},{u, v}});
                    }
                }
            }
        }
        return false;
    }
    bool containsCycle(vector<vector<char>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<bool>>vis(m,vector<bool>(n,false));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!vis[i][j]){
                    if(bfs(grid,i,j,vis)) return true;
                }
            }
        }
        return false;
    }
}




// bool bfs(int i,int j,vector<vector>&grid,vector<vector>&vis){
//     queue<pair<pair<int,int>,pair<int,int>>>q;
//     q.push({{i,j},{-1,-1}});
//     vis[i][j]=1;
//     while(!q.empty()){
//          auto k=q.front();
//          q.pop();
//          int x=k.first.first,y=k.first.second,pari=k.second.first,parj=k.second.second;
//          for(int l=0;l<4;l++){
//              if(isvalid(x+dx[l],y+dy[l],grid,x,y)){
//                  if(vis[x+dx[l]][y+dy[l]]){
//                      if(pari!=(x+dx[l])||parj!=(y+dy[l]))
//                          return true;
//                  }else{
//                      vis[x+dx[l]][y+dy[l]]=1;
//                      q.push({{x+dx[l],y+dy[l]},{x,y}});

//                  }
//             }
//         }
//     }
//     return false;
// }
