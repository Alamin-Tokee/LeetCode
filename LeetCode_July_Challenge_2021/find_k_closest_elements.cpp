//Using Vector

class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        
        vector<pair<int, int>> vp;
        vector<int> diff;
        
        
        for(int i = 0; i < arr.size(); i++)
        {
            int y = abs(x - arr[i]);
            vp.push_back({y, arr[i]});
        }
        
        sort(vp.begin(), vp.end());
        
        for(int i = 0; i < k; i++)
        {
            diff.push_back(vp[i].second);
        }
        sort(diff.begin(), diff.end());
        
        return diff;
    }
};

//Using Multiset
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<int>v(k);
        multimap<int,int>mp;
        for(int i=0;i<arr.size();i++)
        {
            mp.insert({abs(x-arr[i]),arr[i]});
        }
        multimap<int,int>::iterator it;
        int i=0;
        for( it=mp.begin();i<k and it!=mp.end();++it)
        {
            v[i]=(it->second);
            i++;
        }
        sort(v.begin(),v.end());
        return v;
    }
};


//Using Lamda sort
class Solution {
public:
    vector<int> findClosestElements(vector<int>& A, int k, int x) {
        sort(arr.begin(),arr.end(),[&x](int a,int b){
            return (abs(a-x) < abs(b-x) || (abs(a-x) == abs(b-x) && a<b));
        });
        vector<int> ans = {arr.begin(),arr.begin()+k};
        sort(ans.begin(),ans.end());
        
        return ans;
    }
};