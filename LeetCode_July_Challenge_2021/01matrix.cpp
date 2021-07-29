//BFS Solution
//Time Complexity O(r*c)
//Space Complexity O(r*c)
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        vector<vector<int>>dist(n,vector<int>(m,-1));
        queue<pair<int,int>>q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!mat[i][j]) {
                    dist[i][j] = 0;
                    q.push({i,j});
                }
            }
        }
        vector<vector<int>>dir={{1,0},{-1,0},{0,1},{0,-1}};
        while(!q.empty()){
            auto curr = q.front();
            q.pop();
            for(int i=0;i<4;i++){
                int x=curr.first+dir[i][0];
                int y=curr.second+dir[i][1];
                if(x >= 0 && y >= 0 && x < n && y < m && dist[x][y] == -1){
                    dist[x][y] = dist[curr.first][curr.second] + 1;
                    q.push({x,y});
                }
            }
        }
        return dist;
    }
};