//Time Complexity O(n^2)
//Space Complexity O(1)


class Solution {
public:
    vector<int> threeEqualParts(vector<int>& arr) {
        vector<int> ans={-1,-1};
        int numOf1s = 0;
        for(int x:arr){
            numOf1s += x;
        }
        if(numOf1s == 0){
            return {0,2};
        }
        if(numOf1s % 3 != 0){
            return ans;
        }   
        int noOfOnesInEachPart = numOf1s / 3;
        int indexOfFirst1InPart0 = -1;
        int indexOfFirst1InPart1 = -1;
        int indexOfFirst1InPart2 = -1;
        numOf1s = 0;
        for(int i = 0; i < arr.size(); i++){
            if(arr[i] == 1){
                numOf1s++;
                if(numOf1s == noOfOnesInEachPart + 1){
                    indexOfFirst1InPart1 = i;
                }else if(numOf1s == 2 * noOfOnesInEachPart + 1){
                    indexOfFirst1InPart2 = i;
                }else if(numOf1s == 1){
                    indexOfFirst1InPart0 = i;
                }
            }
        }
        while(indexOfFirst1InPart2 < arr.size()){
            if(arr[indexOfFirst1InPart0] == arr[indexOfFirst1InPart1] && arr[indexOfFirst1InPart1]==arr[indexOfFirst1InPart2]){
                indexOfFirst1InPart0++;
                indexOfFirst1InPart1++;
                indexOfFirst1InPart2++;
            }else{
                return ans;
            }
        }
        return {indexOfFirst1InPart0-1, indexOfFirst1InPart1};
    }
};