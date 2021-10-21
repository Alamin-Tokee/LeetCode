class RandomizedCollection {
public:
    /** Initialize your data structure here. */
    unordered_map<int,set<int>>m;
    vector<int>v;
    RandomizedCollection() {
        v.clear();
        m.clear();
    }
    
    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    bool insert(int val) {
        
        m[val].insert(v.size());
        v.push_back(val);
        
        return m[val].size()==1;
    }
    
    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    bool remove(int val) {
        if(m.size()==0 or m[val].size()==0) return false;
        
        int idx=*m[val].begin();
        m[val].erase(idx);
        
        int sw=v[v.size()-1];
        v[idx]=sw;
        
        m[sw].insert(idx);
        m[sw].erase(v.size()-1);
        
        v.pop_back();
        
        return true;
    }
    
    /** Get a random element from the collection. */
    int getRandom() {
        return v[rand()%(v.size())];
    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */