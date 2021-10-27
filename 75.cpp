class Solution {
public:
    void mergeArray(vector<int>&nums,int left,int mid,int right){
        int l=mid-left+1;
        int r=right-mid;
        int le[l],ri[r];
        for(int i=0;i<l;i++)le[i]=nums[left+i];
        for(int i=0;i<r;i++)ri[i]=nums[mid+1+i];
        int m=0,n=0,k;
        for(k=left;m<l && n<r;k++){
            if(le[m]<=ri[n]){
                nums[k]=le[m];
                m++;
            }else{
                nums[k]=ri[n];
                n++;
            }
        }
        while(m<l){
            nums[k++]=le[m++];
        }
        while(n<r){
            nums[k++]=ri[n++];
        }
    }
    void mergeSort(vector<int>&nums,int left,int right){
        if(left>=right) return;
        int mid=left+(right-left)/2;
        mergeSort(nums,left,mid);
        mergeSort(nums,mid+1,right);
        mergeArray(nums,left,mid,right);
    }
    void sortColors(vector<int>& nums) {
        mergeSort(nums,0,nums.size()-1);
    }
};


class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low = 0, mid = 0, high = nums.size()-1;
        while(mid <= high){
            if(nums[mid] == 0) swap(nums[low++], nums[mid++]);
            else if(nums[mid] == 1) mid++;
            else swap(nums[mid], nums[high--]);
        }
    }
};


class Solution {
public:
    void sortColors(vector<int>& nums) {
        unordered_map<int,int> hash;
        for(int i=0;i<nums.size();i++)
            hash[nums[i]]++;
        
        int j=0;
        while(j<nums.size() && hash[0]){
            nums[j++]=0;
            hash[0]--;
        }
        while(j<nums.size() && hash[1]){
            nums[j++]=1;
            hash[1]--;
        }
        while(j<nums.size() && hash[2]){
            nums[j++]=2;
            hash[2]--;
        }
    }
}


