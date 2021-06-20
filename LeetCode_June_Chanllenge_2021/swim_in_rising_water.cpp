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