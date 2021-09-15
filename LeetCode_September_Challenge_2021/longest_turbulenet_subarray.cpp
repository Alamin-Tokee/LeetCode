//Intution
//Time Complexity O(n)
//Space Complexity O(1)

class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int countMaxSubarray=1;
        int flip=false;
        int ans=1;
        for(int i=0;i<arr.size()-1;i++){
            if(arr[i]==arr[i+1]){
                countMaxSubarray=1;
                continue;
            }
            
            if(arr[i]>arr[i+1]){
                if(flip){
                    countMaxSubarray++;
                }else{
                    countMaxSubarray=2;
                }
                flip=false;
            }
            if(arr[i]<arr[i+1]){
                if(!flip){
                    countMaxSubarray++;
                }else{
                    countMaxSubarray=2;
                }
                flip=true;
            }
            ans=max(ans,countMaxSubarray);
        }
        return ans;
    }
};

//Sliding Window(Two pointer)
//Time Complexity O(n)
//Space Complexity O(1)
class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int left = 0, right = 0, maxSize = INT_MIN, flip = -1;
		
        for(right = 0; right < arr.size() - 1; right++){                        
            if((flip == -1 || flip == 1) && arr.at(right) > arr.at(right + 1)) 
                flip = 0;
            
            else if((flip == -1 || flip == 0) && arr.at(right) < arr.at(right + 1))
                flip = 1;
            
            else{
                maxSize = max(maxSize, right - left + 1);
                left = (arr.at(right) != arr.at(right + 1)) ? right : right + 1;
            }
        }
        
        maxSize = max(maxSize, right - left + 1);
        
        return maxSize;
    }
};