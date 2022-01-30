//TC O(n)
//SC O(1)
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n=nums.size();
        if(n==0 || n<0) return;
        k=k%n;
        
        reverse(nums.begin(),nums.end());
        reverse(nums.begin(),nums.begin()+k);
        reverse(nums.begin()+k,nums.end());
    }
};

//TC O(n)
//SC O(1)
class Solution {
public:
    // void reverse(vector<int> &a,int l,int u){
    //     while(l<=u){
    //         int t=a[l];
    //         a[l]=a[u];
    //         a[u]=t;
    //         l++;
    //         u--;
    //     }
    // }
    void reverse(vector<int>&nums,int s,int e){
        while(s<=e){
            swap(nums[s],nums[e]);
            s++;
            e--;
        }
    }
    void rotate(vector<int>& nums, int k) {
        int n=nums.size();
        if(n<=0) return;
        
        k=k%n;
        
        reverse(nums,0,n-k-1);
        reverse(nums,n-k,n-1);
        reverse(nums,0,n-1);
    }
};


//TC O(n)
//SC O(1)
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        vector<int> v(nums.size(),0);
        for(int i=0;i<nums.size();i++){
            v[(i+k)%nums.size()]=nums[i];
        }
        copy(v.begin(),v.end(),nums.begin());
    }
};


//TC O(n)
//SC O(1)
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k %= nums.size();
            
        function<void(int, int)> reverseArray = [&](int start, int end) -> void {
            for(int i = 0; i < (end - start) / 2; i++){
                swap(nums[i + start], nums[end - i - 1]);
            }
        };
        
        reverseArray(0, nums.size());
        reverseArray(0, k);
        reverseArray(k, nums.size());
    }
};

//TC O(n)
//SC O(1)
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
	    // get how much displacement needed
        int x = (nums.size() - (k % nums.size())) % nums.size();
		
		// append that much displacement
        for (int i = 0;i < x;i++) {
            nums.push_back(nums[i]);
        }
		
		// slice the result
        nums = vector<int>(nums.begin()+x, nums.end());
    }
};