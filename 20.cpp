class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        for(int i=0;i<s.length();i++){
            if(s[i]=='(' or s[i]=='{' or s[i]=='['){
                st.push(s[i]);
            }
            else if(s[i]==')' or s[i]=='}' or s[i]==']'){
                if(st.empty()) return false;
                else if(s[i] == ')' && st.top()!= '(') return false;
                else if(s[i] == ']' && st.top()!= '[') return false;
                else if(s[i] == '}' && st.top()!= '{') return false;
                else st.pop();
            }
        }
        return st.empty();
    }
};

class Solution {
public:
    bool isValid(string s) {
        map<char,char>mp;
        mp[')']='(';
        mp['}']='{';
        mp[']']='[';
        stack<char>st;
        for(int i=0;i<s.length();i++){
            if(s[i]=='(' or s[i]=='{' or s[i]=='['){
                st.push(s[i]);
            }
            else if(!st.empty() and st.top()==mp[s[i]]){
                st.pop();
            }else{
                st.push(s[i]);
            }
        }
        return st.empty();
    }
};


