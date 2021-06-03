//Aproachh one 
//Time Complexity O(hlogh) + O(vlogv)
//Space Complexity O(1)

class Solution {
public:
    int max(long long a,int b){
        if(a>b)
            return a;
        return b;
    }
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        int m=horizontalCuts.size();
        int n=verticalCuts.size();
        sort(horizontalCuts.begin(),horizontalCuts.end());
        sort(verticalCuts.begin(),verticalCuts.end());
        
        long long int maxHor=max(horizontalCuts[0],h-horizontalCuts[m-1]);
        long long int maxVer=max(verticalCuts[0],w-verticalCuts[n-1]);
        
        for(int i=0;i<m-1;i++){
            maxHor=max(maxHor,(horizontalCuts[i+1]-horizontalCuts[i])%1000000007);
        }
        
        for(int i=0;i<n-1;i++){
            maxVer=max(maxVer,(verticalCuts[i+1]-verticalCuts[i])%1000000007);
        }
        
        return (( maxHor% 1000000007) * (maxVer%1000000007)) % 1000000007;
    }
};

//Aproach Two
//Time Complexity O(hlogh) + O(vlogv)
//Space Complexity O(1)

class Solution {
public:
    long long getArea(vector<int>& cuts,int size){
        cuts.push_back(0);
        cuts.push_back(size);
        
        sort(begin(cuts),end(cuts));
        
        int res=0;
        
        for(int i=0;i<cuts.size()-1;i++){
            res=max(res,cuts[i+1]-cuts[i]);
        }
        
        return res;
        
    }
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        
        long long ans=getArea(horizontalCuts,h)*getArea(verticalCuts,w);
        
        return ans % 1000000007;
    }
};

