//Optimal Approach
//Time Complexity O(n)
//Space Complexity O(1)

class Solution {
public:
    string removeDuplicates(string& s) {
        int i = 0;
        for(int j = 1; j < s.size(); ++j)
            if (i < 0 || s[i] != s[j]) s[++i] = s[j];
            else --i;
        return s.substr(0, i + 1);
    }
};

//Stack Approach(Sring)
//Time Complexity O(n)
//Space Complexity O(n)
class Solution {
public:
    string removeDuplicates(string s) {
         string res="";
         for(char c:s){
             if(!res.empty() && res.back()==c){
                 res.pop_back();
             }else{
                 res.push_back(c);
             } 
                 
         }
        return res;
   }
};
//Stack Approach
//Time Complexity O(n)
//Space Complexity O(n)

class Solution {
public:
    string removeDuplicates(string s) {
        int n=s.length();
        stack<char> st;
        int i=0;
        while(i<n){
            if(st.empty() || st.top()!=s[i]){
                st.push(s[i]);
                i++;
            }else {
                st.pop();
                i++;
            }
        }
        string res="";
        while(!st.empty()){
            res.push_back(st.top());
            st.pop();
        }
        
        reverse(res.begin(),res.end());

        return res;
    }
};

//Deque Approach
//Time Complexity O(n)
//Space Complexity O(n)

class Solution {
public:
    string removeDuplicates(string s) {
        int n=s.length();
        deque<char> dq;
        int i=0;
        while(i<n){
            if(dq.empty() || dq.back()!=s[i]){
                dq.push_back(s[i]);
                i++;
            }else {
                dq.pop_back();
                i++;
            }
        }
        string res="";
        while(!dq.empty()){
            res.push_back(dq.front());
            dq.pop_front();
        }
        
        return res;
    }
};