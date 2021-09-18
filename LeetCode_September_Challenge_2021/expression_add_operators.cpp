//First Approach

class Solution {
public:
    vector<string>ans;
    int target;
    void dfs(string& num,int i,string curr,long long val,long long prev,bool sign){
        if(i==num.size()){
            if(val==target)
            ans.push_back(curr);return;
        }
        
        long long temp=0;
        
        for(int j=i;j<num.size();j++){
            if((j>i) && (num[i]=='0')) break;
            
            temp=(long long)temp*10+num[j]-'0';
            
            dfs(num,j+1,curr+'+'+to_string(temp),val+temp,temp,0);
            dfs(num,j+1,curr+'-'+to_string(temp),val-temp,temp,1);
            
            if(sign==0){
                dfs(num,j+1,curr+'*'+to_string(temp),val-prev+(prev*temp),prev*temp,0);
            }else{
                dfs(num,j+1,curr+'*'+to_string(temp),val+prev-(prev*temp),prev*temp,1);
            }
        }
    }
    vector<string> addOperators(string num, int target) {
        ans.clear();
        this->target=target;
        
        long long temp=0;
        
        for(int j=0;j<num.size();j++){
            if((j>0) && (num[0]=='0')) break;
            
            temp=(long long)temp*10+num[j]-'0';
            
            dfs(num,j+1,num.substr(0,j+1),temp,temp,0);
        }
        
        return ans;
    }
};

//Second Approach
class Solution {
public:
    vector<string> res;
    
    void solve(string str, int idx, string temp, long long last, long long  value, int target) {
        
        if(idx == str.length()) {
            if(value == target)
                res.push_back(temp);
            return;
        }
        
        
        for(int i=idx; i<str.length(); i++) {
            
            string s = str.substr(idx, i - idx + 1);
            
            if(s.length() > 1 and s[0] == '0')
                return;
            
            long long curr = stoll(s);
            
            if(temp.empty()) {
                solve(str, i+1, temp + s, curr, curr, target);
            }

            else {
                solve(str, i+1, temp + "+" + s, curr, value + curr, target);
                solve(str, i+1, temp + "-" + s, -curr, value - curr, target);
                solve(str, i+1, temp + "*" + s, curr*last, (value - last) + (curr*last) , target);                
            }
        }
    }
        
        
    vector<string> addOperators(string str, int target) {
        
        solve(str,0,"",0,0,target);
        
        return res;
    }
};

//Third Approach
class Solution {
public:
    vector<string> ans;
    string buf;
    long t;
    int last;
    
    vector<string> addOperators(string num, int target) {
        buf.resize(20);
        t = target;
        last = num.size()-1;
        
        dfs(num, 0, 0, 0, 0, '+');
        
        return ans;
    }
    
    void dfs(string& num, int i, int j, long sum, long sumtmp, char prevop){                
        long v = 0;
        
        for (int k = i ; ; k++){
            v *= 10;
            v += long(num[k]-'0');
            buf[j] = num[k];
            j++;
            
            long sumtmptmp = (prevop == '*'?sumtmp*v: (prevop == '+'?sumtmp+v:sumtmp-v));
            
            if (k == last){
                if (sum+sumtmptmp == t) ans.push_back(buf.substr(0, j));

                return;
            }
            
            buf[j] = '*';
            dfs(num, k+1, j+1, sum, sumtmptmp, '*');
            buf[j] = '+';
            dfs(num, k+1, j+1, sum+sumtmptmp, 0, '+');
            buf[j] = '-';
            dfs(num, k+1, j+1, sum+sumtmptmp, 0, '-');
            
            if (!v) return;
        }
    }
    
};