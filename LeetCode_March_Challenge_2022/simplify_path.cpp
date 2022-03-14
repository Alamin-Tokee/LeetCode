//TC O(n)
//SC O(n)
class Solution {
public:
    string simplifyPath(string path) {
        stringstream ss(path);
        string s;
        vector<string> pa;
        while(getline(ss, s, '/')){
            if(s == "." || s == "") continue;
            else if(s == ".."){
                if(!pa.empty()) pa.pop_back();
            }else{
                pa.push_back(s);
            }
        }
        string res = "";
        for(auto x : pa){
            res += "/" + x;
        }
        if(res == "") res = "/";
        
        return res;
    }
};


//TC O(n)
//SC O(n)
class Solution {
public:
    string simplifyPath(string path) {
        vector<string> v;
        int n = path.size();
        for (int i = 0; i < n; i++) {
            string tmp;
            while (i < n && path[i] != '/')  tmp += path[i++];
            if (tmp.size()) v.push_back(tmp);
        }
        vector<string> res;
        for (string &token : v) {
            if (token == ".") continue; 
            if (token == "..") {
                if (res.size()) res.pop_back();
            } else {
                res.push_back(token);
            }
        }
        string ans = "/";
        for (string s : res) ans += s + '/';
        if (ans.size() > 1) ans.pop_back();
        return ans;
    }
};


//TC O(n)
//SC O(n)
class Solution {
public:
    string simplifyPath(string path) {
        string ans="";
        stack<string> st; 
        for(int i=0;i<path.size();i++){
            string temp; 
            
            //Ignore all /
            if(path[i]=='/') continue;
            
            //to copy each path using temp one at a time 
            for(;i<path.size() && path[i]!='/';i++){
                temp = temp+path[i];
            }
            // Ignore . path
            if(temp==".") continue;
            
            //Go back to the previous directory by popping stack
            else if(temp==".."){
                if(!st.empty()) st.pop();
            }
            
            //Otherwise push the element to the stack
            else st.push(temp);
        }
        //Join all the stack elements to form the required path
        while(!st.empty()){
            ans = "/" + st.top() + ans;
            st.pop();
        }
        
        //If there is no path return /
        if(ans.size()==0) return "/";
        
        //Return the required path
        return ans;
    }
};