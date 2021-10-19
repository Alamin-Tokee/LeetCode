class Solution {
private:
    void checkGreater(int pos,vector<int>&num,int val,vector<int>&res){
        int index=find(num.begin(),num.end(),val)-num.begin()+1;
        for(int i=index;i<num.size();i++){
            if(val < num[i]){
                res[pos]=num[i];
                break;
            }
        }
    }
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int m=nums1.size();
        vector<int>res(m,-1);
        for(int i=0;i<m;++i){
            checkGreater(i,nums2,nums1[i],res);
        }
        
        return res;
    }
};


class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        stack<int> st;
        unordered_map<int, int> mp;
        for(auto x: nums2){
            while(st.size() && st.top() < x){
                mp[st.top()] = x;
                st.pop();
            }
            st.push(x);
        }
        for(auto x: nums1) ans.push_back(mp[x] ? mp[x] : -1);
        return ans;
    }
};

