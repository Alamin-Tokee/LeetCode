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