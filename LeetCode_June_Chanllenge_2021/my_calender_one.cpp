//First Approach
//Time Complexity O(n)
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