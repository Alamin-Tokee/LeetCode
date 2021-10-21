class RandomizedSet {
public:
    unordered_map<int,int>mp;
    RandomizedSet() {
        //map<int,int>mp;
    }
    
    bool insert(int val) {
        if(mp.find(val)==mp.end()){
            mp[val]=1;
            return true;
        }
        return false;
    }
    
    bool remove(int val) {
        if(mp.find(val)==mp.end()){
            return false;
        }
        mp.erase(val);
        return true;
    }
    
    int getRandom() {
        auto it = mp.begin();
        std::advance(it, rand() % mp.size());
       
        return it->first;
    }
};


class RandomizedSet {
public:
    vector<int>v;
    RandomizedSet() {
        //map<int,int>mp;
    }
    
    bool insert(int val) {
        auto it=find(v.begin(),v.end(),val);
        if(it!=v.end()){
            return false;
        }
        v.push_back(val);
        return true;
    }
    
    bool remove(int val) {
        auto it=find(v.begin(),v.end(),val);
        if(it==v.end()){
            return false;
        }
        v.erase(it);
        return true;
    }
    
    int getRandom() {
        return v[rand()%v.size()];
    }
};


class RandomizedSet {
    unordered_map<int, int> loc; 
    vector<int> vals; 
public:
    RandomizedSet() {}
    
    bool insert(int val) {
        if (loc.count(val)) return false; 
        loc[val] = vals.size(); 
        vals.push_back(val); 
        return true; 
    }
    
    bool remove(int val) {
        if (!loc.count(val)) return false; 
        int i = loc[val]; 
        loc[vals.back()] = i; 
        loc.erase(val); 
        vals[i] = vals.back(); 
        vals.pop_back(); 
        return true; 
    }
    
    int getRandom() {
        return vals[rand() % vals.size()]; 
    }
};

class RandomizedSet {
public:
    unordered_set<int> S;
    
    RandomizedSet() {
        S.clear();
    }
    
    bool insert(int val) {
        
        if(S.find(val) == S.end())
        {
            S.insert(val);
            return true;
        }
        
        return false;
    }
    
    bool remove(int val) {
        
        if(S.find(val) != S.end())
        {
            S.erase(val);
            return true;
        }
        
        return false;
    }
    
    int getRandom() {
        
        int r = rand()%S.size();
        
        auto it = S.begin();
        
        while(r--)
            it++;
        
        return *it;
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */