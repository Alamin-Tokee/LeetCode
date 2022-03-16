//TC O(n+n)
//SC O(n)
class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int>stk;
        stack<int>st;
        for(int i=popped.size()-1;i>=0;i--){
            st.push(popped[i]);
        }
        for(int i=0;i<pushed.size();i++){
            stk.push(pushed[i]);
            while(!stk.empty() && !st.empty() && stk.top() == st.top()){
                stk.pop();
                st.pop();
            }
        }
        return stk.empty() ? true : false;
    }
};

//TC O(n)
//SC O(n)
class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int>st;
        int j = 0;
        for(int i=0;i<pushed.size();i++){
            st.push(pushed[i]);
            while(!st.empty() && st.top() == popped[j]){
                st.pop();
                j++;
            }
        }
        return st.empty();
    }
};

//TC O(n)
//SC O(n)
class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int>st;
        int j = 0;
        auto doPop = [&](){
            while(!st.empty() && st.top() == popped[j]){
                st.pop();
                j++;
            }
        };
        
        for(int i=0;i<pushed.size();i++){
            st.push(pushed[i]);
            doPop();
        }
        return st.empty();
    }
};


