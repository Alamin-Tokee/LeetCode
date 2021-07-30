//Brute Force Solution
//Time Complexity O(n)
//Space Complexity O(n)
class MapSum {
public:
    /** Initialize your data structure here. */
    unordered_map<string,int> mp;
    MapSum() {
        mp.clear();
    }
    
    void insert(string key, int val) {
        mp[key]=val;
    }
    
    int sum(string prefix) {
        int n=prefix.size();
        int sum=0;
        for(auto it=mp.begin();it!=mp.end();it++){
            if(it->first.substr(0,n)==prefix){
                sum+=it->second;
            }
        }
        return sum;
    }
};

//     int sum(string prefix) {
//         int sum = 0, n = prefix.size();
//         for (auto it = mp.lower_bound(prefix); it != mp.end() && it->first.substr(0, n) == prefix; it++) 
//             sum += it->second;
//         return sum;
//     }

//         auto res = mismatch(prefix.begin(), prefix.end(), it.first.begin());
//         if( res.first == prefix.end() ){
//             total += it.second;
//         }



//HashMap Solution
//Time Complexity O(n)
//Space Complexity O(n)
class MapSum {
public:
    /** Initialize your data structure here. */
    unordered_map<string,int>mp;
    unordered_map<string,int>p;
    MapSum() {
        
    }
    
    void insert(string key, int val) {
        int v = val - mp[key];
        cout << v <<endl;
        mp[key] = val;
        string pre;
        for(char c : key){
            pre+=c;
            p[pre]+=v;
        }
    }
    
    int sum(string prefix) {
        return p[prefix];
    }
};



//Trie Solution
//Time Complexity O(n)
//Space Complexity O(n)
class MapSum {
public:
    /** Initialize your data structure here. */
    struct TrieNode{
        TrieNode* children[26];
        int sum = 0;
    };
    TrieNode* root;
    TrieNode* curr;
    unordered_map<string,int>mp;
    
    MapSum() {
        root = new TrieNode();
    }
    
    void insert(string key, int val) {
        curr = root;
        int temp = mp.count(key) ? mp[key] : 0;
        
        mp[key]=val;
        
        val-=temp;
        
        for(char& ch:key){
            if(!curr->children[ch - 'a']){
                curr->children[ch - 'a'] = new TrieNode();
            }
            curr = curr->children[ch - 'a'];
            curr->sum+=val;
        }
    }
    
    int sum(string prefix) {
        curr = root;
        for(char& ch:prefix){
            if(!curr->children[ch - 'a']){
                return false;
            }
            curr = curr->children[ch - 'a'];
        }
        
        return curr->sum;
    }
};
