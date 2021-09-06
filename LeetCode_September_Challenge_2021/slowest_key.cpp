//Time complexity O(n)
//Space Complexity O(n)
class Solution {
public:
    char slowestKey(vector<int>& releaseTimes, string keysPressed) {
        multimap<char,int>mp;
        mp.insert(make_pair(keysPressed[0],releaseTimes[0]));
        for(int i=1;i<releaseTimes.size();i++){
            mp.insert(make_pair(keysPressed[i],releaseTimes[i]-releaseTimes[i-1]));
        }
        int ans=INT_MIN;
        char st;
        
        auto i=mp.begin();

        while(i!=mp.end()){
            if(i->second>=ans){
                ans=i->second;
                st=i->first;
            }
            cout<<i->second <<endl;
            i++;
        }
        return st;
    }
};