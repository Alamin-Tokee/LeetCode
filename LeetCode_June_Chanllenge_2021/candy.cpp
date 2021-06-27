//Tw Array
class Solution {
public:
    int candy(vector<int>& r) {
        int n=r.size();
        vector<int>v1(n,1),v2(n,1);
        for(int i=1;i<n;i++){
            if(r[i-1] < r[i]){
                v1[i]=v1[i-1]+1;
            }
        }
        for(int i=n-2;i>=0;i--){
            if(r[i+1] < r[i]){
                v2[i]=v2[i+1]+1;
            }
        }
        int sum=0;
        for(int i=0;i<r.size();i++){
            sum+=max(v1[i],v2[i]);
        }
        
        return sum;
    }
};

//One Array
// class Solution {
// public:
//     int candy(vector<int>& r) {        
//         int n=r.size();
//         vector<int>v(n,1);
//         for(int i=1;i<n;i++){
//             if(r[i-1] < r[i]){
//                 v[i]=v[i-1]+1;
//             }
//         }
//         int sum=v[n-1];
//         for(int i=n-2;i>=0;i--){
//             if(r[i+1] < r[i]){
//                 v[i]=max(v[i],v[i+1]+1);
//             }
//             sum+=v[i];
//         }
        
//         return sum;
//     }
// };