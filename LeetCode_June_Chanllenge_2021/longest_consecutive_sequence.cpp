//Time complexity O(nlogn) and for loop take O(n)
//Space complexity O(n) or O(1)

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n=nums.size();
        
        //At first solve simple test case
        if(n==0) return 0;
        if(n==1) return 1;
        if(n==2 && nums[0]==nums[1]) return 1;
        
        //Sort the array
        sort(nums.begin(),nums.end());
        
        //Unique valus store in a vector
        vector<int>v;
        v.push_back(nums[0]);
        for(int i=1;i<n;i++){
            if(nums[i]!=nums[i-1])
                v.push_back(nums[i]);
        }
        
        //Count the consecutive sequence 
        int c=1;
        int ma=0;
        for(int i=1;i<v.size();i++){
            if(v[i]==v[i-1]+1){
                c++;
            }else{
                c=1;
            }
            ma=max(ma,c);
        }
        
        return ma;
    }
};


//Second Approach using map

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int,int> m;
        for(int x:nums)
            m[x]++;
        int ans=0,count;
        for(int x:nums)
        {
            if(m.find(x-1)==m.end())  // find first element of all consecutive subsequence 
            {
                int k=x;
                count=0;
                while(m.find(k)!=m.end())
                {
                    k++;
                    count++;
                }
                ans=max(ans,count);
            }
        }
        
        // O(2N) ==> O(N)
        return ans;
    }
};

//Third approach using set

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s(nums.begin(),nums.end());
        
        int longest=0;
        
        for(auto& num: s){
            if(s.count(num-1)) continue;
            
            int j=1;
            
            while(s.count(num+j)) j++;
            
            longest=max(longest,j);
        }
        
        return longest;
    }
};

//Time Complexity o(n)

//Space Complexity O(1)



