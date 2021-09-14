//Using Multimap
class Solution {
public:
    vector<vector<int>> allCellsDistOrder(int rows, int cols, int rCenter, int cCenter) {
        multimap<int,pair<int,int>>mp;
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                int dis=abs(rCenter-i)+abs(cCenter-j);
                mp.insert({dis,{i,j}});
            }
        }
        vector<vector<int>>v;
        for(auto it=mp.begin();it!=mp.end();it++){
            vector<int>p;;
            p.push_back(it->second.first);
            p.push_back(it->second.second);
            v.push_back(p);
        }
        return v;
    }
};

//Using Priority Queue
class Solution {
public:
    vector<vector<int>> allCellsDistOrder(int rows, int cols, int rc, int cc) {
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                int dis=abs(rc-i)+abs(cc-j);
                pq.push({dis,{i,j}});
            }
        }
        vector<vector<int>>v;
        while(!pq.empty()){
            pair<int,int> p=pq.top().second;
            v.push_back({p.first,p.second});
            pq.pop();
        }
        return v;
    }
};