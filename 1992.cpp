
//Time Complexity O(n*m(m+n))
//Space Complexity O(1)
class Solution {
public:
    vector<vector<int>>dir={{1,0},{0,1},{-1,0},{0,-1}};
    void bfs(vector<vector<int>>& g,int r,int c,int m,int n,pair<int,int>&last){
        queue<pair<int,int>>q;
        q.push({r,c});
        g[r][c]=0;
        int x,y;
        while(!q.empty()){
            x=q.front().first;
            y=q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                int ii=x+dir[i][0];
                int jj=y+dir[i][1];
                
                if(ii >= 0 and ii < m and jj >= 0 and jj < n and g[ii][jj]==1){
                    g[ii][jj]=0;
                    q.push({ii,jj});
                }
            }
        }
        last={x,y};
    }
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        int m=land.size();
        int n=land[0].size();
        //vector<vector<bool>>vis(m,vector<bool>(n,false));
        vector<vector<int>>ans;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(land[i][j]==1){
                    pair<int,int>first={i,j};
                    pair<int,int>last=first;
                    bfs(land,i,j,m,n,last);
                    ans.push_back({first.first,first.second,last.first,last.second});
                }
            }
        }
        return ans;
    }
};

//Time Complexity O(n*m(m+n))
//Space Complexity O(m*n)
class Solution {
public:
    vector<vector<int>>dir={{1,0},{0,1},{-1,0},{0,-1}};
    vector<int> bfs(vector<vector<int>>& g,vector<vector<bool>>& v,int r,int c,int m,int n){
        queue<pair<int,int>>q;
        q.push({r,c});
        v[r][c]=true;
        int x,y;
        while(!q.empty()){
            x=q.front().first;
            y=q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                int ii=x+dir[i][0];
                int jj=y+dir[i][1];
                
                if(ii >= 0 and ii < m and jj >= 0 and jj < n and g[ii][jj]==1 and v[ii][jj]==false){
                    v[ii][jj]=true;
                    q.push({ii,jj});
                }
            }
        }
        return {x,y};
    }
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        int m=land.size();
        int n=land[0].size();
        vector<vector<bool>>vis(m,vector<bool>(n,false));
        vector<vector<int>>ans;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                vector<int>v;
                if(land[i][j]==1 && !vis[i][j]){
                    v.push_back(i);
                    v.push_back(j);
                    vector<int>vv=bfs(land,vis,i,j,m,n);
                    v.push_back(vv[0]);
                    v.push_back(vv[1]);
                    ans.push_back(v);
                }
            }
        }
        return ans;
    }
};