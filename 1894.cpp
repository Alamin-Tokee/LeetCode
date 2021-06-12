class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        int  n=chalk.size();
        int ans=0;
//         while(i < n){
            
//             if(k < chalk[i]){
//                 ans=i;
//                 break;
//             }
//             k-=chalk[i];
            
//             if(i==n-1){
//                 i=0;
//             }else i++;
            
//         }
        
//         return ans;
        long sum=0;
        for(int k=0;k<n;k++) sum+=chalk[k];
        k=k%sum;
        for(int i=0;i<n;i++){
            if(k < chalk[i]){
                ans=i;
                break;
            }
            k-=chalk[i];
            
            if(i==n-1) i=0;
        }
        return ans;
    }
};