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

//Using binary search
class Solution {
public:
    vector<int> findClosestElements(vector<int>& A, int k, int x) {
        
        int left=0,right=A.size()-k;
        while(left < right){
            int mid=(left + right) / 2;
            if(x - A[mid] > A[mid+k] - x)
                left=mid+1;
            else 
                right=mid;
        }
        
        return vector<int>(A.begin()+left,A.begin()+left+k);
       }
   };

class Solution {
public:

       vector<int> findClosestElements(vector<int>& arr, int k, int x) {

            priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

            for (int i = 0; i < arr.size(); i++)
                 pq.push({abs(arr[i] - x), arr[i]});
        
            vector<int> ans;

           for (int i = 0; i < k; i++){
                ans.push_back(pq.top().second);
                pq.pop(); 
           }

           sort(ans.begin(), ans.end());
           return ans;
    }

};