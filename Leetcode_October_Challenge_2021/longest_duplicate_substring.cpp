class Solution {
public:
    #define ll long long int
    string possible(string &s,int k){  //Rabin Karp
        unordered_map<ll,vector<int>>m;
        ll q=1000000007;
        ll d=26;
        ll hash=0,n=s.size(),h=1;
        for(int i=0;i<k-1;i++)
            h=(h*d)%q;
        for(int i=0;i<k;i++){
            hash=(hash*d+(s[i]-'a'))%q;
        }
        m[hash].push_back(0);
        for(int i=k,j=0;i<n;i++,j++){
            hash=(d*(hash-h*(s[j]-'a'))+(s[i]-'a'))%q;
            if(hash<0) hash+=q;
            
            for(auto x:m[hash]){
                if(s.substr(j+1,k)==s.substr(x,k))
                    return s.substr(j+1,k);
            }
            m[hash].push_back(j+1);
        }
        return "";
    }
    string longestDupSubstring(string s) {
        int i=0,j=s.size();
        string res="";
        while(i<=j){
            int mid=(i+j)/2;
            string temp=possible(s,mid);
            if(temp!=""){
                res=temp;
                i=mid+1;
            }
            else
                j=mid-1;
        }
        return res;
    }
};