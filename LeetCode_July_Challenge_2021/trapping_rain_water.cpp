//Dynamic Programming
//Time Complexity O(n)
//Space Complexity O(n)
class Solution {
public:
    int trap(vector<int>& height) {
        if(height.empty()) return 0;
        int n=height.size();
        vector<int>left(n),right(n);
        left[0]=height[0];
        for(int i=1;i<n;i++){
            left[i]=max(height[i],left[i-1]);
        }
        right[n-1]=height[n-1];
        for(int i=n-2;i>=0;i--){
            right[i]=max(height[i],right[i+1]);
        }
        int ans=0;
        for(int i=0;i<n-1;i++){
            ans+=min(left[i],right[i])-height[i];
        }
        return ans;
    }
};

//Stack Solution
//Time Complexity O(n)
//Space Complexity O(n)
class Solution {
public:
    int trap(vector<int>& height) {
        stack<int>st;
        int ans = 0, index = 0;
        while(index < height.size()){
            while(!st.empty() && height[st.top()]<height[index]){
                int top = st.top();
                st.pop();
                // agar left mei koi bdi nhi h, toh paani nhi store ho skta naa, isliye break
                if(st.empty())
                    break;
                // jo two unchi building h current building se, unke beech ka distance 
                int distance = index - st.top() - 1;
                // height nikal rhe h kitni increase ho skti h 
                int add_height = min(height[st.top()],height[index]) - height[top];
                // mutiple building jo current building se choti h uske left aur right mei uske liye mutiply krenge                        distance se 
                ans += add_height * distance;
            }
            st.push(index++);
        }
        return ans;
    }
};

//Two Pointer Solution
//Time Complexity O(n)
//Space Complexity O(n)
class Solution {
public:
    int trap(vector<int>& height) {
        int left = 0, right = height.size() - 1;
        int ans = 0;
        int left_max = 0, right_max = 0;
        
        while(left < right){
           if(height[left] < height[right]){
               height[left] >= left_max ? left_max = height[left] : ans+=(left_max-height[left]);
               left++;
           }
           else{
               height[right] >= right_max ? right_max = height[right] : ans+=(right_max-height[right]);
               right--;
           }
        }
        return ans;
    }
};
