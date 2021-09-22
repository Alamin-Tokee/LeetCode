class Solution {
public:
    int maxLength(vector<string>& arr) {
        vector<string>results={""};
        int best=0;
        for(string word:arr){
            int rsize=results.size();
            for(int i=0;i<rsize;i++){
                string newres=word+results[i];
                unordered_set<char>newset(newres.begin(),newres.end());
                if(newres.size()!=newset.size()) continue;
                
                results.push_back(newres);
                
                best=max(best,(int)newres.size());
            }
        }
        return best;
    }
};


class Solution {
public:
    int maxLength(vector<string>& arr) {
        vector<string>results={""};
        int best=0;
        for(int i=0;i<(1<<arr.size());i++){
            for(int j=0;j<arr.size();j++){
                if(i&(1<<j)){
                    unordered_set<char>newset(arr[j].begin(),arr[j].end());
                    if(arr[j].size()!=newset.size()) continue;
                
                    //results.push_back(newres);
                
                    best=max(best,(int)newset.size());
                } 
            }
        }
        return best;
    }
};



class Solution {
public:
     int res = 0;
     bool isunique(string str)
     {
           unordered_set<char> s(str.begin(), str.end());
           return s.size() == str.length();
     }
     
    void util(vector<string>& arr, string progress, int index) {

	    res = max(res, (int)progress.length());  

        for(int i=index; i<arr.size(); i++) 
        {
            if(isunique(progress+arr[i])) 
                util(arr, progress+arr[i], i+1);
        }
    }
    
    int maxLength(vector<string>& arr) {
        util(arr, "", 0);
        return res;
    }
};


class Solution {
public:
     int maxUniqueChar(string str){
         int count[26]={0};
         for(int i=0;i<str.size();i++){
             if(count[str[i]-'a']++ > 0) return -1;
         }
         return str.size();
     }
     
    void util(vector<string>& arr, string progress, int index,vector<int>&ans) {
        if(index==arr.size() && maxUniqueChar(progress) > ans[0]){
            ans[0]=progress.size();
            return;
        }
        if(index==arr.size()) return;
        
        util(arr,progress,index+1,ans);
        util(arr,progress+arr[index],index+1,ans);
    }
    
    int maxLength(vector<string>& arr) {
        vector<int>ans(1);
        util(arr, "", 0,ans);
        return ans[0];
    }
};



class Solution {
public:
    //Used to map characters
    int m[26];
    
    //Storing ans globally
    int ans=0;
    
    void fun(vector<string>& v,int st,int n)
    {
        //Used to store temp ans upto index st in vector v.
        int res=0;
        for(int i=0;i<26;i++)
        {
            //If any character appears more than 1 time, just return and try next possibilities
            if(m[i]>1)return;
            if(m[i]==1)res++;
        }
        
        //Updating ans
        ans=max(ans,res);
        for(int i=st;i<n;i++)
        {
            //Including string v[i] and then calling the function again with starting index as i+1.
            for(char ch:v[i])m[ch-'a']++;
            fun(v,i+1,n);
            //After the function call excluding string v[i]
            for(char ch:v[i])m[ch-'a']--;
        }
    }
    
    int maxLength(vector<string>& arr) {
        memset(m,0,sizeof(m));
        ans=0;
        fun(arr,0,arr.size());
        return ans;
    }
};



class Solution {
public:
    int recurse(vector<string>& arr,vector<int> &mask,int i,int cur)
    {
        if(i==mask.size()) return 0;
        if(mask[i]==-1) return recurse(arr,mask,i+1,cur);
        int x=0,y=0;
        if(!(mask[i]&cur))  x=arr[i].size()+recurse(arr,mask,i+1,(mask[i]|cur));
        y=recurse(arr,mask,i+1,cur);
        return max(x,y);
    }
    
    int maxLength(vector<string>& arr) {
    vector<int> mask(arr.size(),0);
    int ans=0;
    for(int i=0;i<arr.size();i++)
    {
        int freq[26]={0};
        for(int j=0;j<arr[i].size();j++)
        {
            if(freq[arr[i][j]-'a']++) 
            {
                mask[i]=-1;
                break;
            }
            mask[i]|=1<<(arr[i][j]-'a');
        }
    }
    return recurse(arr,mask,0,0);
    }
};
  