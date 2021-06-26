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


//Merge Sort

class Solution {
public:
    int ans[100004];
    void merge(int l,int mid,int r,vector<pair<int,int> > &v){
        vector<pair<int,int>>temp(r-l+1);
        int ct=0;
        int i=l,j=mid+1,k=0;
        while(i<=mid && j<=r){
            if(v[i].first<=v[j].first){
                ans[v[i].second]+=ct;
                temp[k]=v[i];i++;k++;
            }
            else{
                temp[k]=v[j];
                ct++;j++;k++;
            }
        }
        while(i<=mid)
        {
            ans[v[i].second]+=ct;
            temp[k]=v[i];i++,k++;
        }
        while(j<=r){
            temp[k]=v[j];j++,k++;
        }
        
        k=0;
        for(i=l;i<=r;i++){
            v[i]=temp[k];k++;
        }
    }
    void mergeSort(vector<pair<int,int> > &v,int l,int r){
        if(l<r){
            int mid = (l+r)/2;
            mergeSort(v,l,mid);
            mergeSort(v,mid+1,r);
            merge(l,mid,r,v);
        }
    }
    vector<int> countSmaller(vector<int>& nums) {
        memset(ans,0,sizeof(ans));
        vector<pair<int,int> > v;
        
        for(int i=0;i<nums.size();i++){
            v.push_back({nums[i],i});
        }
        mergeSort(v,0,nums.size()-1);
        
        vector<int> res;
        for(int i=0;i<nums.size();i++) res.push_back(ans[i]);
        return res;
    }
};


//Binary Index Tree

class Solution {
public:
    void update(vector<int>& bit, int id, int num)
    {
        for (int i = id+1; i < bit.size(); i += i&(-i))
            bit[i] += num;
    }
    int rangeSum(vector<int>& bit, int id)
    {
        int ret = 0;
        for (int i = id+1; i > 0; i -= i&(-i))
            ret += bit[i];
        return ret;
    }
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<int> cnt(n);
        vector<int> bit(20002);
        int offset =  10000;
        for (int i = n-1; i >= 0; --i)
        {
            cnt[i] = rangeSum(bit, offset + nums[i]-1);
            update(bit, offset + nums[i], 1);
        }
        return cnt;
    }
};



