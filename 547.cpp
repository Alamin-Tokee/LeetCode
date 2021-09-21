//DFS solution
//Time Complexity O(n*m)
//Space Complexity O(n)

class Solution {
public:
    void dfs(vector<vector<int>>& isConnected,int row,vector<bool>&vis){
        vis[row]=true;
        for(int i=0;i<isConnected[row].size();i++){
            if(isConnected[row][i]==1 && !vis[i]) dfs(isConnected,i,vis);
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector<bool>vis(n,false);
        int count=0;
        for(int i=0;i<n;++i){
            if(!vis[i]){
                count++;
                dfs(isConnected,i,vis);
            }
        }
        
        return count;
    }
};


//BFS solution
//Time Complexity O(n*m)
//Space Complexity O(n)
class Solution {
public:
    void bfs(vector<vector<int>>& g,int row,vector<bool>&v){
        queue<int>q;
        q.push(row);
        while(!q.empty()){
            int x=q.front();
            q.pop();
            v[x]=true;
            for(int i=0;i<g[x].size();++i){
                if(!v[i] && g[x][i]==1){
                    q.push(i);
                }
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector<bool>vis(n,false);
        int count=0;
        for(int i=0;i<n;++i){
            if(!vis[i]){
                count++;
                bfs(isConnected,i,vis);
            }
        }
        
        return count;
    }
};



//////////////////////////////////////////////////////////////////


class Solution {
public:
    
      vector<int>parent;
      vector<int>rank;
    
      int find(int x){
          
          if(parent[x]==-1) return x;
          
          return parent[x]=find(parent[x]);  // path compression
      }
    
   void union_op(int x,int y){
        
           if(x==y){
               return;
           }
        
        if(rank[x]>rank[y]){
            parent[y]=x;
            rank[x]+=rank[y];
        }
       else{
           parent[x]=y;
           rank[y]+=rank[x];
       }
    }
    int findCircleNum(vector<vector<int>>& nums) {
        
        int n=nums.size();
         parent.resize(n,-1);
          rank.resize(n,1);
        
          for(int i=0;i<n;i++){
              
              for(int j=i+1;j<n;j++){
                  
                  if(nums[i][j]==1){
                      
                      union_op(find(i),find(j));
                  }
              }
          }
        
          int cnt=0;
        
        for(int i=0;i<n;i++){
            if(parent[i]==-1) cnt++;
        }
        
        return cnt;
    }
};


/////////////////////////////////////////////////

class Solution {
public:

    vector<int>v;
    
    int find_set(int x){
        if(!v[x])
            return x;
        return v[x]=find_set(v[x]);
    }
    
    void union_(int a,int b){
        int s_a=find_set(a);
        int s_b=find_set(b);
        if(s_a==s_b) return;
        else v[s_a]=s_b;
    }
    
    int findCircleNum(vector<vector<int>>& M) {
        ios_base::sync_with_stdio(false);cin.tie(NULL);
        int n=M.size();
        vector<int> parent(n);
        v= vector<int>(n,0);
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++){
            if(M[i][j])
                union_(i,j);
        }
            int c=0;
            for(auto i:v)
                if(!i) c++;
        
        return c;
    }
};