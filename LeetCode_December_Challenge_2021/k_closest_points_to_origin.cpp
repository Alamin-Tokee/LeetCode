//Time Complexity O(NlogN)
//Space Complexity O(logN)
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        sort(points.begin(),points.end(), [&](vector<int>& a,vector<int>&b){
            return squareDistance(a) < squareDistance(b);
        });
        return vector<vector<int>>(points.begin(),points.begin()+k);
    }
private:
    int squareDistance(vector<int>&point){
        return point[0]*point[0] + point[1]*point[1];
    }
};

//Time Complexity O(nlogk)
//Space Complexity O(k)
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int,int>>maxPQ;
        for(int i=0;i<points.size();i++){
            pair<int,int> entry = {squareDistance(points[i]),i};
            if(maxPQ.size() < k){
                maxPQ.push(entry);
            }else if(entry.first < maxPQ.top().first){
                maxPQ.pop();
                maxPQ.push(entry);
            }
        }
        vector<vector<int>>answer;
        while(!maxPQ.empty()){
            int entryIndex = maxPQ.top().second;
            maxPQ.pop();
            answer.push_back(points[entryIndex]);
        }
        return answer;
    }
private:
    int squareDistance(vector<int>&point){
        return point[0]*point[0] + point[1]*point[1];
    }
};


//Demp
 //        auto euclidean = [](auto& p){return p[0] * p[0] + p[1] * p[1];};
 //        sort(begin(P), end(P), [&](auto& a, auto& b){return euclidean(a) < euclidean(b);});
 //        P.resize(k);
 //        return P;