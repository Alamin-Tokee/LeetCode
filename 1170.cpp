class Solution {
public:
    int binarySearch(vector<int>&word,int q){
        int left=0,right=word.size()-1;
        int greater=word.size();
        while(left<=right){
            int mid=left+(right-left)/2;
            if(word[mid] > q){
                greater=mid;
                right=mid-1;
            }
            else{
                left=mid+1;
            }
        }
        return word.size()-greater;
    }
    vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
        int n=queries.size();
        int m=words.size();
        vector<int>word;
        for(int i=0;i<m;i++){
            sort(words[i].begin(),words[i].end());
            int cnt=count(words[i].begin(),words[i].end(),words[i][0]);
            word.push_back(cnt);
        }
        vector<int>res;
        sort(word.begin(),word.end());
        for(int i=0;i<n;i++){
            sort(queries[i].begin(),queries[i].end());
            int cnt=count(queries[i].begin(),queries[i].end(),queries[i][0]);
            int cc=binarySearch(word,cnt);
            res.push_back(cc);
        }
        
        return res;
    }
};


class Solution {
public:
    vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
        vector<int>ans,freq;
        //for words frequency
        for(int i=0;i<words.size();i++)
        {
            sort(words[i].begin(),words[i].end());
            char c=words[i][0];
            int count=1;
            for(int j=1;j<words[i].size();j++)
            {
                if(words[i][j]==c)
                {
                    count++;
                }
            }
            ans.push_back(count);
        }
        //for queries frequency
        for(int i=0;i<queries.size();i++)
        {
            sort(queries[i].begin(),queries[i].end());
            char c=queries[i][0];
            int count=1;
            for(int j=1;j<queries[i].size();j++)
            {
                if(queries[i][j]==c)
                {
                    count++;
                }
            }
            freq.push_back(count);
        }
        sort(ans.begin(),ans.end());
        //sort(freq.begin(),freq.end());
        vector<int>sol;
        for(int i=0;i<freq.size();i++)
        {
            auto pos=upper_bound(ans.begin(),ans.end(),freq[i])-ans.begin();
            sol.push_back(words.size()-pos);
        }
        return sol;
        
    }
};