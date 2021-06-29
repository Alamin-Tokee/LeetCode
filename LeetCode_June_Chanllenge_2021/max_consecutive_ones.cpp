//Brute Force Solution
//Time Complexity O(n)
//Space Complexity O(1)

class Solution {
public:
    int longestOnes(vector<int>& a, int k) {
        int i=0;
        int j=0;
        int n=a.size();
        int zero=0;
        int ans=INT_MIN;
        
        while(j<n){
            if(zero < k){
                if(!a[j]) zero++;  
                j++;
            }
            else if(zero==k){
                if(a[j]) j++;
                else if(a[i]) i++;
                else if(!a[i]){
                    zero--;
                    i++;
                }
            }
            ans=max(ans,j-i);
        }
        return ans;
    }
};
//Sliding Window Solution
//Time Complexity O(n)
//Space Complexity O(1)

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int zero=0,start=0,res=0;
        for(int end=0;end<nums.size();end++){
            
            if(!nums[end]) zero++;
            
            while(zero > k){
                if(!nums[start]) zero--;
                start++;
            }
            
            res=max(res,end-start+1);
        }
        
        return res;
    }
};
//Sliding Window Solution
//Time Complexity O(n)
//Space Complexity O(1)
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {       
        int i=0,j,res=0;
        for(j=0;j<nums.size();++j){
            if(!nums[j]) k--;
            if(k < 0 && !nums[i++]) k++;
            
            // res=max(res,j-i+1);
        }
        
        return j-i;
    }
};

//Dqeque Solution
//Time Complexity O(n)
//Space Complexity O(n)
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {      
        deque<int>dq;
        int prev=-1,res=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0) dq.push_back(i);
            
            if(dq.size()>k && !nums[i]){
                prev=dq.front();
                dq.pop_front();
            }
            res=max(res,i-prev);
        }
        return res;
    }
};
        
//Queue Solution
//Time Complexity O(n)
//Space Complexity O(n)

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {           
        queue<int>q;
        int prev=-1,res=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0) q.push(i);
            
            if(q.size()>k && !nums[i]){
                prev=q.front();
                q.pop();
            }
            res=max(res,i-prev);
        }
        return res;
    }
};