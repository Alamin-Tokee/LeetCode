class Solution {
public:
    int trap(vector<int>& height) {
        stack<int>st;
        int ans = 0, index = 0;
        while(index < height.size()){
            while(!st.empty() && height[st.top()]<height[index]){
                int top = st.top();
                st.pop();
                if(st.empty())
                    break;
    
                int distance = index - st.top() - 1;
             
                int add_height = min(height[st.top()],height[index]) - height[top];
               
                ans += add_height * distance;
            }
            st.push(index++);
        }
        return ans;
    }
};

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


class Solution {
public:
    int trap(vector<int>& height) {
        int left=0,right=height.size()-1;
        int ans=0;
        int leftmax=0,rightmax=0;
        
        while(left < right){
            if(height[left] < height[right]){
                height[left] >= leftmax ? leftmax=height[left] : ans+=leftmax-height[left];
                left++;
            }else{
                height[right] >= rightmax ? rightmax=height[right] : ans+=rightmax-height[right];
                right--;
            }
        }
        return ans;
    }
};

