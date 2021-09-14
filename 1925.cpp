//Tieme Complexity O(n)
//Space Complexity O(1)

class Solution {
public:
    int countTriples(int n) {
        int ans=0;
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                double tem=sqrt(i*i + j*j);
                if(int(tem)==tem &&  tem<= n){
                    ans+=2;
                }
            }
        }
        return ans;
    }
};


//Tieme Complexity O(n)
//Space Complexity O(1)
class Solution {
public:
    int countTriples(int n) {
        unordered_map <int, int> mp;
        int cnt=0;
        for(int i=1;i<=n;i++)
            mp[i*i]=i;
        for(int i=1;i<=n;i++){
            for(int j=i;j<=n;j++){
                if(mp.find(i*i + j*j)!=mp.end()) cnt++;
            }    
        }
        return 2*cnt;
        
    }
};