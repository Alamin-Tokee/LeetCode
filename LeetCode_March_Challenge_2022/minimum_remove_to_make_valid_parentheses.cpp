class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<pair<char,int>>stk;
        for(int i=0;i<s.length();i++){
            if(s[i]=='('){
                stk.push({s[i], i});
            }
            else if(!stk.empty() && stk.top().first == '(' && s[i]==')'){
                stk.pop();
            } 
            else if(s[i]==')'){
                stk.push({s[i], i});
            }
        }
        while(!stk.empty()){
            s.erase(s.begin()+stk.top().second);
            stk.pop();
        }                 
        return s;
    }
};


class Solution {
public:
    string minRemoveToMakeValid(string &str) {
        stack<int>s; // keeps unbalanced paranthesis
        string res; //stores final string
        
        for(int i=0;i<str.length();i++){
            char c=str[i];
            if(s.empty()){ 
                if(c==')') // if the the ith value can't be balanced make it '0'
                    str[i]='0';
                else if(c=='(')
                    s.push(i);
            }
            else {
                if(c=='(')
                    s.push(i);
                else if(c==')')
                    s.pop();
            }
        }
        
        while(!s.empty()){ // contains remaining unbalanced paranthesis at last 
            str[s.top()]='0'; // make these values as '0'
            s.pop();
        }
        
        for(char &c: str) //creates a final string leaving all '0' values
            if(c!='0')
                res.push_back(c);
        return res;
    }
};


class Solution {
public:
    string minRemoveToMakeValid(string s) {
        //forword pass
        int cnt = 0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='(') cnt++;
            if(s[i]==')'){
                if(cnt==0) s[i] = '#';
                else cnt--;
            }
        }
        //backword pass
        cnt = 0;
        for(int i=s.length()-1;i>=0;i--){
            if(s[i]==')') cnt++;
            if(s[i]=='('){
                if(cnt==0) s[i] = '#';
                else cnt--;
            }
        }
        
        string ans = "";
        for(int i=0;i<s.length();i++){
            if(s[i]!='#') ans+=s[i];
        }
        return ans;
    }
};

