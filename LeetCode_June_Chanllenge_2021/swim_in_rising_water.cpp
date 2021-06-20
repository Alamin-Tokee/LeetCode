//BFS + Priority_Queue
// T=O(N^2)
// S=O(N^2)

class Solution {
public:
    bool isValid(int i,int j,int n){
        if(i < 0 || i >= n || j < 0 || j >= n) return false;
        
        return true;
    }
    int swimInWater(vector<vector<int>>& grid) {
        int n=grid.size();
        
        vector<int>visited(n*n,false);
        
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        
        pq.push(make_pair(grid[0][0],make_pair(0,0)));
        visited[grid[0][0]]=true;
        pair<int,pair<int,int>>temp;
        int ans=0;
        
        while(!pq.empty()){
            temp=pq.top();
            pq.pop();
            
            ans=max(ans,temp.first);
            
            int x=temp.second.first;
            int y=temp.second.second;
            
            if(x==n-1 && y==n-1) return ans;
            
            if(isValid(x+1,y,n) && visited[grid[x+1][y]]==false){
                visited[grid[x+1][y]]=true;
                pq.push(make_pair(grid[x+1][y],make_pair(x+1,y)));
            }
            if(isValid(x-1,y,n) && visited[grid[x-1][y]]==false){
                visited[grid[x-1][y]]=true;
                pq.push(make_pair(grid[x-1][y],make_pair(x-1,y)));
            }
            if(isValid(x,y+1,n) && visited[grid[x][y+1]]==false){
                visited[grid[x][y+1]]=true;
                pq.push(make_pair(grid[x][y+1],make_pair(x,y+1)));
            }
            if(isValid(x,y-1,n) && visited[grid[x][y-1]]==false){
                visited[grid[x][y-1]]=true;
                pq.push(make_pair(grid[x][y-1],make_pair(x,y-1)));
            }
        }
        
        return ans;
    }
};

// Method 2 - Djikstra's Algorithm
// T=O(V^2)=O(n^4)

class Solution {
public:
    vector<pair<int,int>>directions{{0,1},{-1,0},{0,-1},{1,0}};
    
    bool isValid(vector<vector<bool>>& visited,int r,int c){
        if(r < 0 || c < 0 || r >= visited.size() || c >= visited[0].size() || visited[r][c]) return false;
        
        return true;
    }
    
    pair<int,int> findMin(vector<vector<bool>>& visited, vector<vector<int>>& distance){
        int minDis=INT_MAX;
        pair<int,int>minIndex={-1,-1};
        for(int i=0;i<distance.size();i++){
            for(int j=0;j<distance.size();j++){
                if(!visited[i][j] && distance[i][j] < minDis){
                    minDis=distance[i][j];
                    minIndex={i,j};
                }
            }
        }
        
        return minIndex;
    }
    
    int swimInWater(vector<vector<int>>& grid) {
        int n=grid.size();
        
        vector<vector<bool>>visited(n,vector<bool>(n,false));
        vector<vector<int>>distance(n,vector<int>(n,INT_MAX));
        distance[0][0]=grid[0][0];
        int done=0;
        
        while(done!=n*n){
            pair<int,int> u=findMin(visited,distance);
            
            int i=u.first;
            int j=u.second;
            
            visited[i][j]=true;
            done++;
            
            for(int k=0;k<4;k++){
                int ii=i+directions[k].first;
                int jj=j+directions[k].second;
                
                if(isValid(visited,ii,jj)){
                    int possibleDistance=max(distance[i][j],grid[ii][jj]);
                    if(possibleDistance < distance[ii][jj]) {
                        distance[ii][jj]=possibleDistance;
                    }
                }
            }
        }
        return distance[n-1][n-1];
    }
};


//Binary Search and DFS approach
// Time complexity ==>
// For Binary search : O(log(2499)) {n is atmost 50 * 50 -1}
// For Recursive call : O(n^2) {we visit each element once ,and mark it as visited }
// Total = O(n^2)

// Space Complexity ==>
// Recurrsion stack : O(n^2)
// For visited array : O(n^2)
// Total = O(n^2)

class Solution {
public:
    vector<vector<int>>dirs ={{0,1},{1,0},{-1,0},{0,-1}};
    bool dfs(vector<vector<int>>& grid,int i,int j,int time,vector<vector<int>> &dp){
        dp[i][j]=1;
        
        for(auto &dir:dirs){
            int r=i+dir[0];
            int c=j+dir[1];
            if(r>=0 && c>=0 && r<grid.size() && c<grid[0].size() && grid[r][c]<=time  &&dp[r][c]==0){
                if(r==grid.size()-1 && c==grid.size()-1) return true;
                
                if(dfs(grid,r,c,time,dp)) return true;
            }
        }
        return false;
    }
    int swimInWater(vector<vector<int>>& grid) {
        int n=grid.size();
        
        int low=grid[0][0],high=n*n-1;
        while(low < high){
            int mid=low+(high-low)/2;
            vector<vector<int>>dp(n,vector<int>(n,0));
            if(dfs(grid,0,0,mid,dp)){
                high=mid;
            }else{
                low=mid+1;
            }
        }
        
        return low;
    }
};