//First Approach
//Time Complexity O(n^2)
//Space Complexity O(n)

class MyCalendar {
public:
    vector<pair<int,int>>vec;
    MyCalendar() {}
    
    bool book(int start, int end) {
        for(int i=0;i<vec.size();i++){
            if(vec[i].first < end && start < vec[i].second) return false;
        }
        vec.push_back({start,end});
        
        return true;
    }
};

// Binary Search And Set
// Time Complexity O(NlogN)
// Space Complexity O(N)

class MyCalendar {
    set<pair<int, int>> store; 
public:
    MyCalendar() {}
    
    bool book(int start, int end) {
        auto it = store.lower_bound({start, end}); 
        if (it != store.begin() && prev(it)->second > start) return false; 
        if (it != store.end() && end > it->first) return false; 
        store.insert({start, end}); 
        return true; 
    }
};