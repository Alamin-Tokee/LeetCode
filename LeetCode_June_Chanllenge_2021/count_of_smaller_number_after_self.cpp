//Intution(TLE)
class Solution{
public:
    vector<int> countSmaller(vector<int>& nums) {

        int n=nums.size();
        vector<int>res;
        int c=0;
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(nums[i] > nums[j]){
                   c++;
                }
            }
            res.push_back(c);
            c=0;
        }
        
        return res;
        
    }
};

//Segment Tree
class Solution {
public:
    int seg[400001];
    void update(int st,int end,int si,int ind){
        if(st==ind && end==ind){
            seg[si]++;
            return;
        }
        int mid=(st+end)/2;
        if(end<ind || st>ind) {return;}
        update(st,mid,2*si,ind);
        update(mid+1,end,2*si+1,ind);
        seg[si]=seg[2*si]+seg[2*si+1];
        return;
    }
    int query(int st,int end,int l,int r,int si){
        if(st>=l && end<=r) {
            return seg[si];}
        if(( r<st) || (l>end)){;return 0;} 
        int mid=(st+end)/2;
        return query(st,mid,l,r,2*si)+query(mid+1,end,l,r,2*si+1);
        
        
    }
    vector<int> countSmaller(vector<int>& nums) {
//         int n=nums.size();
//         vector<int>res;
//         int c=0;
//         for(int i=0;i<n;i++){
//             for(int j=i;j<n;j++){
//                 if(nums[i] > nums[j]){
//                    c++;
//                 }
//             }
//             res.push_back(c);
//             c=0;
//         }
        
//         return res;
        memset(seg,0,sizeof(seg));
        int n=nums.size();
        vector<int> ans(n);
        for(int i=n-1;i>=0;i--){
            ans[i]=query(0,20001,0,nums[i]-1+10001,1);
            update(0,20001,1,nums[i]+10001);
        }
        return ans;
    }
};