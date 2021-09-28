class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n=rooms.size();
        // vector<bool>vis(n,false);
        unordered_set<int>s;
        queue<int>q;
        q.push(0);
        // vis[0]=true;
        s.insert(0);
        while(!q.empty()){
            int x=q.front();
            q.pop();
            for(auto y:rooms[x]){
                if(!s.count(y)){
                    //vis[y]=true;
                    s.insert(y);
                    q.push(y);
                }
            }
        }
        return s.size()==rooms.size();
        // int flag=true;
        // for(int i=0;i<n;i++){
        //     if(vis[i]==false){
        //         flag=false;
        //         break;
        //     }
        // }
        // return flag;
    }
};