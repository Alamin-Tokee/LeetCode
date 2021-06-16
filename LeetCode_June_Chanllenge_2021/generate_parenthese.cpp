class Solution {
public:
    vector<string>res;
    void dfs(int &n,int o,int c,string path){
        if(o==n and c==n){
            res.push_back(path);
            return;
        }
        if(o<n){
            path.push_back('(');
            dfs(n,o+1,c,path);
            path.pop_back();
        }
        if(c<o){
            path.push_back(')');
            dfs(n,o,c+1,path);
            path.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        dfs(n,0,0,"");
        
        return res;
    }
};