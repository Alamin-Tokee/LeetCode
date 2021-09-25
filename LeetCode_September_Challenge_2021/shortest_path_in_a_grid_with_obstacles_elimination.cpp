//Time Complexity O(n*m*k)
//Space Complexity O(n*m*k)
class Solution {
public:
    int bfs(vector<vector<int>>& g,int r,int c,int step, vector<vector<vector<int>>>&vis){
        int offsets[] = {0, 1, 0, -1, 0};
        queue<pair<pair<int,int>,pair<int,int>>>q;
        //int cnt=0;
        q.push({{r,c},{0,0}});
        //g[r][c]='0';
        while(!q.empty()){
            int x = q.front().first.first;
            int y = q.front().first.second;
            int d1=q.front().second.first;
            int d2=q.front().second.second;
            q.pop();
            if(x==g.size()-1 && y==g[0].size()-1) return d1;
            for (int k = 0; k < 4; k++) {
                int u = x + offsets[k], v = y + offsets[k + 1];
                if (u >= 0 && u < g.size() && v >= 0 && v < g[0].size()) {
                    int newEliminated=d2+g[u][v];
                    if(newEliminated <= step && vis[u][v][newEliminated]==0){
                        vis[u][v][newEliminated]=1;
                        q.push({{u,v},{d1+1,newEliminated}});
                    }
                }
            }
        }
        return -1;
    }
    int shortestPath(vector<vector<int>>& grid, int k) {
        int n=grid.size();
        int m=grid[0].size();
        int ans=0;
        // int vis[n][m][k+1];
        // memset(vis,0,sizeof(vis));
        
        vector<vector<vector<int>>> seen(n, vector<vector<int>>(m, vector<int>(k + 1)));
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<m;j++){
        //         if(grid[i][j]=='1'){
        //             ans++;
        //             bfs(grid,i,j);
        //         }
        //     }
        // }
        
        ans=bfs(grid,0,0,k,seen);
        return ans;
    }
};


//     class Node {
//         public:
//         int r;
//         int c;
//         int k;
        
//         Node(int r, int c, int k) {
//             this->r = r;
//             this->c = c;
//             this->k = k;
//         }
//     };


//    struct node{
//         int x, y, steps, el;
//         node(int _x, int _y, int _steps, int _el){
//             x = _x;
//             y = _y;
//             steps = _steps;
//             el = _el;
//         }
//     };

// TC: O(mn)
// SC: O(mn)

    class Solution {
	public:
	
     int shortestPath(vector<vector<int>>& grid, int k) {
		int m = grid.size();
		int n = grid[0].size();
		// This vector stores the number of obstacles that we can still remove after walking through that cell
	vector<vector<int>> visited(m, vector<int>(n, -1));
    queue<vector<int>> q;
    // x, y, currentLength, remaining k
    q.push({0,0,0,k});
    while(!q.empty()){
        
        auto t = q.front();
        q.pop();
        
        int x = t[0], y = t[1];
        
        // Invalid cases being dealt here since it's easier to write one condition instead of 4 while pushing.
        if(x<0 || x>=m || y<0 || y>=n)
            continue;
        
        // If you've reached the end, great, return the currentLength!
        if(x == m-1 && y == n-1)
            return t[2]; //currentLength of the path
         
        // If we hit an obstacle & we don't have any Ks remaining, continue
        // If we still have Ks to spend, we spend 1.
        if(grid[x][y] == 1){
            if(t[3] > 0)
                t[3]--;
            else
                continue;
        }
        
        // If this cell is already visited with a K value lesser than this one, we would want to save Ks for future use, so we continue
        // This is the most important condition and part of the solution!
        if(visited[x][y]!=-1 && visited[x][y] >= t[3]){
            continue;
        }
        
        // We store the currentRemaining K after spending K (if required) into the visited matrix.
        visited[x][y] = t[3];
            
        // Push the adjacent nodes in the queue.
        q.push({x+1, y, t[2]+1, t[3]});
        q.push({x-1, y, t[2]+1, t[3]});
        q.push({x, y+1, t[2]+1, t[3]});
        q.push({x, y-1, t[2]+1, t[3]});
    }
    
    return -1;
   }
};

