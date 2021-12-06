//Time Complexity O(n)
//Space Complexity O(1)
class Solution {
public:
    int minCostToMoveChips(vector<int>& position) {
        int odd=0;
        int even=0;
        for(int i:position){
            if(i&1){
                odd++;
            }else{
                even++;
            }
        }
        return min(odd,even);
    }
};