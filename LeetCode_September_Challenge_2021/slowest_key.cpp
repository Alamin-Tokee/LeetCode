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

//Time Complexity O(n+m)
//Space Complexity (n) (linear space)
class Solution {
public:
    char slowestKey(vector<int>& releaseTimes, string keysPressed) {
        int durationArray[26]={0};
        durationArray[keysPressed[0]-'a']=releaseTimes[0];
        for(int i=1;i<releaseTimes.size();i++){
            int currentDuration=releaseTimes[i]-releaseTimes[i-1];
            char currentKey=keysPressed[i];
            durationArray[currentKey-'a']=max(durationArray[currentKey-'a'],currentDuration);
        }
        int slowKey = 25;
        for(int currKey=24;currKey>=0;currKey--){
            if(durationArray[currKey] > durationArray[slowKey]){
                slowKey=currKey;
            }
        }
        return slowKey+'a';
    }
};