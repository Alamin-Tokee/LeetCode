//Time Complexity O(NlogN)
//Space Complexity O(N)
class Solution {
public:
    bool canReorderDoubled(vector<int>& arr) {
        int n=arr.size();
        sort(arr.begin(),arr.end());
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++) mp[arr[i]]++;
        
        int c=0;
        for(int i=0;i<n;i++){
            if(mp[2*arr[i]] && mp[arr[i]]){
                mp[2*arr[i]]--;
                mp[arr[i]]--;
            }
        }
        for(auto x:mp){
            if(x.second!=0) return false;
        }
        return true;
    }
};


//Time Complexity O(NlogN)
//Space Complexity O(N)
class Solution {
public:
    bool canReorderDoubled(vector<int>& arr) {
        
        // track freq count of numbers in the array
        unordered_map<int,int>track;
        
        int n = arr.size();
        int c = 0;
        
        // sort array based on their abs value
        sort(arr.begin(),arr.end(),[](int a, int b){return abs(a) < abs(b);});
        
        // store freq count of numbers in the Map
        for(int i=0;i<arr.size();i++)track[arr[i]]++;
        
        // loop through array and check 2a freq count for a if freq count a > 0 
        for(int i=0;i<arr.size();i++)
        {       
            // ignore 0 freq number
            if (track[arr[i]]==0)  continue;
            
            // check even count for zero number
            if(arr[i]==0 && track[arr[i]]>=2)c++,track[arr[i]]-=2;
            
            // check 2a freq count for number a
            if (arr[i]!=0 && track[arr[i]*2]>0)c++, track[arr[i]*2]--,track[arr[i]]--;
        }
        
        // total pair == length/2 for valid case
        return c == n/2;
    }
};





