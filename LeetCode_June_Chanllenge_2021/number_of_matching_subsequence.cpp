//Backtracking(Time Limit Execced)

class Solution {
public:
	vector<sting> sub;
	void findAllSub(string input,int n,int index=-1,string curr=""){
		if(index==n) return;

		sub.push_back(curr);

		for(int i=index+1;i<n;i++){
			curr=curr+index[i];
			findAllSub(input,n,i,curr);
			curr=curr.erase(curr.size()-1);
		}
	}
	int numMatchingSubseq(string s, vector<string>& words) {
		int count=0;
		findAllSub(s,s.size());
		for(string w:words){
			if(find(sub.begin(),sub.end(),w)!=sub.end()) count++;
		}
		return count;
	}
};


//Optimize solution using hasing
class Solution {
public:
    bool matchString(string a,string b){
        int size1 = a.size();
        int size2 = b.size();
        int i=0,j=0;
        for(i=0,j=0; i<size1 && j < size2 ;i++){
            if(a[i]==b[j]){
                 j++;
            }
        }
        
        return j==size2;
    }
    int numMatchingSubseq(string s, vector<string>& words) {
        int n=words.size();
        unordered_map<string,int>mp;
        int ans=0;
        for(auto& x:words){
            if(mp.find(x)!=mp.end()) ans+=mp[x];
            else {
                mp[x]=matchString(s,x);
                ans+=mp[x];
            }
        }
        
        return ans;
    }
};