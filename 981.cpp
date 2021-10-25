class TimeMap {
public:
    map<string,map<int,string>>mp;
    TimeMap() {
        mp.clear();
    }
    
    void set(string key, string value, int timestamp) {
        mp[key][timestamp]=value;
    }
    
    string get(string key, int timestamp) {
        if(mp.find(key)==mp.end()) return "";
        
        auto &map=mp[key];
        auto it=map.upper_bound(timestamp);
        
        return it==map.begin() ? "" : prev(it)->second;
    }
    
    // string get(string key, int timestamp) {
    //      if(!mp.count(key)) return "";
    //      auto it=mp[key].upper_bound(timestamp);
    //      --it;
    //      if(it==mp[key].end() || it->first>timestamp) return "";
    //      return it->second; 
    // }
    
    // string get(string key, int timestamp) {
    // if (!mp.count(key)) return "";
    // auto it = mp[key].upper_bound(timestamp);
    // if (it == mp[key].begin()) return "";
    // --it;
    // return it->second; 
    // }
};

class TimeMap {
public:
    /** Initialize your data structure here. */
    unordered_map<string,vector<pair<string,int>>> map;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        map[key].push_back({value,timestamp});
    }
    
    string get(string key, int timestamp) {
        if(map.find(key)==map.end()) return "";
        
        int idx = find(map[key], timestamp);
        
        return idx==-1 ? "" : map[key][idx].first;
    }
    
    int find(vector<pair<string, int>>& v, int timestamp)
    {
        if(v.size()==0 || v[0].second > timestamp) return -1;
        int l = 0;
        int h = v.size()-1;
        int mid = l + (h-l)/2;
        while(l <= h)
        {
            mid = l+(h-l)/2;
            if(timestamp == v[mid].second) return mid;
            else if(timestamp > v[mid].second) l = mid+1;
            else h = mid-1;
        }
        return h;
    }
};


/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */