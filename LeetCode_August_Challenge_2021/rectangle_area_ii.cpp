//Coordinate Compression
//Time Complexity O(n^3)
//Space Complexity O(n^2)

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPP(i, n) for(int i = 1; i <= n; i++)
#define ALL(obj) (obj).begin(), (obj).end()

class Solution {
private:
    unordered_map<int, int> zipx, zipy;
public:
    int rectangleArea(vector<vector<int>>& rectangles) {
        
        vector<int> xs, ys;
        for(vector<int>& rectangle: rectangles){
            xs.push_back(rectangle[0]);
            xs.push_back(rectangle[2]);
            ys.push_back(rectangle[1]);
            ys.push_back(rectangle[3]);
        }
        sort(ALL(xs));
        sort(ALL(ys));
        xs.erase(unique(ALL(xs)), xs.end());
        ys.erase(unique(ALL(ys)), ys.end());
        
        int numX = xs.size();
        int numY = ys.size();
        REP(i, numX) zipx[xs[i]] = i;
        REP(i, numY) zipy[ys[i]] = i;
        vector<vector<bool>> regions(numX + 1, vector<bool>(numY + 1, false));
        for(vector<int>& rectangle: rectangles){
            for(int zx = zipx[rectangle[0]] + 1; zx <= zipx[rectangle[2]]; zx++){
                for(int zy = zipy[rectangle[1]] + 1; zy <= zipy[rectangle[3]]; zy++){
                  regions[zx][zy] = true;
                }
            }
        }


//         REP(k, n){
//             for(int zx = zipx[rectangles[k][0]] + 1; zx <= zipx[rectangles[k][2]]; zx++){
//                 for(int zy = zipy[rectangles[k][1]] + 1; zy <= zipy[rectangles[k][3]]; zy++){
//                   regions[zx][zy] = true;
//                 }
//             }
//         }
        
//         long long ans = 0;
//         auto mod = [](long long m) -> long long {
//             long long res = ((m % 1'000'000'007) + 1'000'000'007) % 1'000'000'007;
//             return res;
//         };
        
        long long ans = 0;
        const long long mod = 1e9 + 7;
        REP(zx, numX + 1){
            REP(zy, numY + 1){
                if(!regions[zx][zy]) continue;
                long long dx = xs[zx] - xs[zx - 1];
                long long dy = ys[zy] - ys[zy - 1];
                ans += dx * dy;
            }
        }
        return ans % mod;        
    }
};