//Time Complexity O(1)
//Space Complexity O(1)
class Solution {
public:
    bool squareIsWhite(string coordinates) {
        int x=coordinates[0]-'a' + 1;
        int y=coordinates[1]-'0';
        
        return ((x%2==1 && y%2==1) or (x%2==0 && y%2==0)) ? false : true;
    }
};

class Solution {
public:
    bool squareIsWhite(string c) {
        return (c[0]-'a'+1 + c[1]-'0') & 1;
    }
};


class Solution {
public:
    bool squareIsWhite(string coordinates) {
        int x=coordinates[0]-'a' + 1;
        int y=coordinates[1]-'1' + 1;
        
        if((x+y) % 2 == 0) return false;
        else return true;
    }
};