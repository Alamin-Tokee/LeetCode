//BFS solution

class Solution {
public:
    vector<pair<int,int>>dir={{1,0},{0,1},{-1,0},{0,-1}};
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        queue<pair<int,int>>q;
        q.push({sr,sc});
        int color=image[sr][sc];
        image[sr][sc]=newColor;
        
        while(!q.empty()){
            int x=q.front().first;
            int y=q.front().second;
            q.pop();
            
            for(int i=0;i<4;i++){
                int u=x+dir[i].first;
                int v=y+dir[i].second;
                
                if(u>=0 and v>=0 and u < image.size() and v < image[0].size() and image[u][v]==color and image[u][v]!=newColor){
                    image[u][v]=newColor;
                    q.push({u,v});
                }
            }
        }
        return image;
    }
};