//First Approach
//Time Complexity O(n*n)
//Space ComplexityO(n)

class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> dead(deadends.begin(),deadends.end());
        
        if(dead.count("0000")) return -1;
        
        unordered_set<string>vis;
        queue<string>q;
        
        vis.insert("0000");
        q.push("0000");
        
        int level=0;
        
        while(!q.empty()){
            
            int sz=q.size();
            
            for(int i=0;i<sz;i++){
                string st=q.front();
                q.pop();
                
                if(st==target) return level;
                
                for(int i=0;i<4;i++){
                    
                    string increement=st;
                    increement[i]=(increement[i]-'0'==9) ? '0' : increement[i]-'0'+1+'0';
                    
                    string decreement=st;
                    decreement[i]=(decreement[i]-'0'==0) ? '9' : decreement[i]-'0'-1+'0';
                    
                   
                    if(!vis.count(increement) && !dead.count(increement)){
                        q.push(increement);
                        vis.insert(increement);
                    }
                    
                    if(!vis.count(decreement) && !dead.count(decreement)){
                        q.push(decreement);
                        vis.insert(decreement);
                    }
                    
                    
                }
            }
            level++;
        }
        
        return -1;
    }
};


//Second Apprach

class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> seen (begin(deadends),end(deadends));
        
        if(!seen.count("0000")){
            int ans=0;
            queue<string> q;
            q.push("0000");
            seen.insert("0000");
            
            while(!q.empty()){
                for(int n=size(q); n>0; --n){
                    string s=q.front(); q.pop();
                    if(s==target) return ans;
                    
                    for(int i=0; i < 4; ++i){
                        for(int chg= -1; chg <= 1; chg += 2){
                            string ss=s;
                            ss[i]= '0' + (ss[i] - '0' + chg + 10) % 10;
                            if(!seen.count(ss)){
                                seen.insert(ss);
                                q.push(ss);
                            }
                        }
                    }
                }
                ans++;
            }
        }
        return -1;
    }
};



//Third Approach 

class Solution {
public:
    
    #pragma GCC optimize("Ofast")
    
    bool check(string& s, unordered_set < string >& deadends, vector < bool >& vis){
        // check string to know if it tried before of is already exist in deadends
        return deadends.find(s) == deadends.end() && !vis[stoi(s)];
    }
    
    vector < string > moves(string& s, int idx){
        // forward one and backward one
        vector < string > res(2, s);
        res.front()[idx] = '0' + (res.front()[idx] - '0' + 1) % 10;
        res.back()[idx] = '0' + (res.back()[idx] - '0' - 1 + 10) % 10;
        return res;
    }
    
    int openLock(vector<string>& deadends, string target) {
        ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
        vector < bool > vis(1e5);
        unordered_set<string> dead(begin(deadends), end(deadends));
        string beg = "0000";
        if(dead.find(beg) != dead.end()) return -1;
        if(target == beg) return 0;
        int minimum_moves = 0, sz;
        queue < string > bfs({beg});
        while(!bfs.empty()){
            minimum_moves++, sz = bfs.size();
            for(int j = 0; j < sz; j++){
                string top = bfs.front();
                bfs.pop();
                for(int i = 0; i < 4; i++){
                    for(auto& option : moves(top, i))
                        if(check(option, dead, vis))
                           if(option == target) return minimum_moves;
                           else bfs.push(option), vis[stoi(option)] = true;
                }
            }
        }
        return -1;
    }
};