
//TC O(nlong)
//SC O(n*n)
class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        map<int,int>dp;
        vector<vector<int>>jobs;
        for(int i=0;i<startTime.size();i++){
            jobs.push_back(vector<int>{startTime[i],endTime[i],profit[i]});
        }
        sort(jobs.begin(),jobs.end(),[](const vector<int>& a,const vector<int>& b){
            return a[0] > b[0];
        });
        int maxT=0;
        for(auto job : jobs){
            auto it=dp.lower_bound(job[1]);
            int pre=(it==dp.end()) ? 0 : it->second;
            maxT=max(maxT,job[2]+pre);
            dp[job[0]]=maxT;
        }
        return maxT;
    }
};


class Solution {
public:
    #define MAX 50505
    typedef tuple<int, int, int> t;    
    int get_pos(int x, vector<t> &v, int end){
        int l=0; int r=end;
        while(r - l > 1){
            int c = (l+r)/2;
            if(get<0>(v[c]) <= x){
                l = c;
            }else{
                r = c;
            }
        }
        return l;
    }
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        vector<t> v;
        int N=startTime.size();
        for(int i=0;i<N;i++){
            v.emplace_back(endTime[i], startTime[i], profit[i]);
        }
        v.emplace_back(0,0,0);
        sort(v.begin(), v.end());
        int dp[MAX];
        for(int i=1;i<=N;i++){
            int start = get<1>(v[i]);
            int pos = get_pos(start, v, i+1);
            int p = get<2>(v[i]) + dp[pos];
            dp[i] = max(dp[i-1], p);
        }
        int ans = 0;
        return dp[N];
    }
};


class Solution {
public:
    vector<pair<pair<int,int>,int>>vec ; 
    int dp[(int) 5e4 + 5 ]  ; 
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        memset(dp , -1 , sizeof(dp ) ) ;
        for( int i = 0 ; i < startTime.size() ; i ++ )
        {
            vec.push_back( {{startTime[i] , endTime[i]} , profit[i]}); 
        }
        sort( vec.begin() , vec.end() ) ;
        return solve( 0  ) ; 
        
    }
    int solve(int cur ){
        if( cur == vec.size() ) return 0 ; 
        int &ans = dp[cur]      ;  
        if(~ans ) return ans    ; 
        int nxt = findnext(cur) ; 
        int inc = vec[cur].second + ( nxt == 1e9 + 5 ? 0 : solve( nxt ) ) ;
        int exc = solve(cur + 1 )    ; 
        return ans = max( inc , exc ) ;
    }
    int findnext(int ind ){
        int l = ind + 1 , r = vec.size() - 1 , mid = 0 , st = 1e9 + 5 ; 
        while( l <= r  )
        {
            mid = ( l + r ) >> 1 ; 
            if( vec[mid].first.first >= vec[ind].first.second ){
                st = min(st , mid ) ; 
                r = mid - 1 ; 
            }
            else{
                l = mid + 1 ; 
            }
        }
        return st ; 
    } 

};