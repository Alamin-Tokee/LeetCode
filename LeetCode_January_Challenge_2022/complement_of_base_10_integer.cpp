class Solution {
public:
    void decToBinary(vector<int>&v,int n){
        //vector<int>bin;
        for(int i=n;i>=0;i--){
            if((n>>i)&1){
                v.push_back(1);
            }else{
                v.push_back(0);
            }
        }
    }
    int bitwiseComplement(int N) {
        vector<int>v;
        //vector<int>res;
        decToBinary(v,N);
        for(int i=v.size()-1;i>=0;i--){
            if(v[i]==1) v.push_back(0);
            else v.push_back(1);
        }
        int sum=0;
        for(int i=v.size()-1;i>=0;i--){
            sum+=v[i]*pow(2,i);
        }
        return sum;
    }
};



class Solution {
public:
    int bitwiseComplement(int n) {
        if(n==0) return 1;
        int m = n;
        int mask=0;
    
        while(m!=0){
            mask = (mask<<1) | 1;
            m = m>>1;
        }
        int ans = (~n) & mask;
        return ans;
    }
};


class Solution {
public:
    int bitwiseComplement(int n) {
        int temp=1;
        while(temp<n){
             temp=(temp<<1)+1;             
        }
        return temp^n;
    }
};