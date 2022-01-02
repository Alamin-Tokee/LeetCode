// class Solution {
// public:
//     int numPairsDivisibleBy60(vector<int>& time) {
//         ios_base::sync_with_stdio(false);
//         cin.tie(NULL);
//         cout.tie(NULL);
//         /*vector<int>map(60,0);
//         int res=0;
//         for(int i=0;i<time.size();++i){
//             time[i]%=60;
//             int now=(60-time[i])%60;
//             res+=map[now];
//             ++map[time[i]];
//         }
//         return res;*/
//         /*int count=0;
//         unordered_multiset<int>mod;
//         for(int t:time){
//             count+=mod.count((t%=60) ? 60-t:0);
//             mod.insert(t);
//         }
//         return count;*/
//         /*int count=0;
//         vector<int>res(60);
//         for(int t:time){
//             count+=res[(t%=60)?60-t:0];
//             ++res[t];
//         }
//         return count;*/
        
//         int n=time.size();
//         int ans=0,j;
//         for(int i=0;i<n;i++){
//             time[i]%=60;
//         }
//         map<int,int>mp;
//         for(int i=0;i<n;i++){
//             mp[time[i]]++;
//         }
        
//         for(auto x:mp){
//             if(x.first==30 || x.first==0){
//                 ans+=(x.second*(x.second-1))/2;
//             }
//             else{
//                 if(mp.count(60-x.first)!=0){
//                     j=x.second*mp[60-x.first];
//                     ans+=j;
//                     mp[x.first]=0;
//                 }
//             }
//         }
//         return ans;
//     }
// };


class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        vector<int>cnt(60,0);
        int res = 0;
        for(int i=0;i<time.size();i++){
            int a=time[i]%60;
            if(a==0) res += cnt[0];
            else res += cnt[60-a];
            cnt[a]++;
        }
        return res;
    }
};