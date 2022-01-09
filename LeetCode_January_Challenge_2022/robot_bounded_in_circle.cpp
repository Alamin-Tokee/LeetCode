//Time Complexity O(N)
//Space Complexity O(1)
class Solution {
public:
    bool isRobotBounded(string instructions) {
        char dir = 'N';
        int x = 0, y = 0;
        for(int i=0;i<instructions.size();i++){
            if(instructions[i] == 'G'){
                switch(dir){
                    case 'N':
                        y++;
                        break;
                    case 'E':
                        x++;
                        break;
                    case 'S':
                        y--;
                        break;
                    case 'W':
                        x--;
                        break;
                }
            }else if(instructions[i] == 'L'){
                switch(dir){
                    case 'N':
                        dir='W';
                        break;
                    case 'E':
                        dir='N';
                        break;
                    case 'S':
                        dir='E';
                        break;
                    case 'W':
                        dir='S';
                        break;
                }
            }else if(instructions[i] == 'R'){
                switch(dir){
                    case 'N':
                        dir='E';
                        break;
                    case 'E':
                        dir='S';
                        break;
                    case 'S':
                        dir='W';
                        break;
                    case 'W':
                        dir='N';
                        break;
                }
            }
        }
        if(x == 0 && y == 0) return true;
        else if(dir == 'N') return false;
        else return true;
    }
};