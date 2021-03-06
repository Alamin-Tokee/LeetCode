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


//Hash + Binary Search

/*
     * Approach followed is a Hashmap + Binary search
     * where we save all indices of each char of s in a map ie..,
     * Eg:  s = abacedba
     *            key   value
     *     map =  [a]   0, 2, 7
     *            [b]   1, 6
     *            [c]   3
     *            [e]   4
     *
     * Now traverse each word in the input vector and check whether it is a
     * subsequence of s using a binary search approach
     *
     * Eg:  word = aad, traverse each char by char
     *   As a is present twice and in the map when we check for the 2nd char a
     * then we need to take the 2nd index instead of the 1st index. 
     *
    */
    int numMatchingSubseq(string s, vector<string>& words) {
        // Initialize a map to store the indicies of all chars in s
        unordered_map<char, vector<int>> mp;
        
        // Traverse all the chars in s and add the indices to map
        for (int i = 0; i < s.length(); i++) {
            // push the index to map for the current char
            // The indices will be in ascending order for the character
            mp[s[i]].push_back(i);
        }
        
        // Variable to store result
        int numSubseq = 0;
        
        // Temporary variables
        int low;
        bool isSubseq;
        
        // Traverse all the words of the input 
        for (string& word: words) {
            // Lower Index
            // Index that needs to be found should be greater than this low index
            low = -1;
            // Assume current word is a subsequence
            isSubseq = true;
            
            for (char& ch : word) {                
                // Perform a binary search 
                int pos = upper_bound(mp[ch].begin(), mp[ch].end(), low) - mp[ch].begin();
                // Check if the current char is present in map or not
                if (pos == mp[ch].size()) {
                    // no such char present,
                    isSubseq = false;
                    break;
                }
                
                low = mp[ch][pos];
            }

            // Increment result if current word is subsequence of s
            numSubseq += isSubseq;
        }
        
        return numSubseq;
    }
