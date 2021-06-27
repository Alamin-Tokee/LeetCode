class Solution {
public:
    bool canBeIncreasing(vector<int>& arr) {
    int n=arr.size();
    int count = 0;
 
    int index = -1;
    for (int i = 1; i < n ; i++) {
 
        if (arr[i - 1] >= arr[i]) {
            count++;
            index = i;
        }
    }
    //cout<<count;
 
    if (count > 1)
        return false;
 
   
    if (count == 0)
        return true;
 
   
    if (index == n - 1 || index == 1)
        return true;
 
   
    if (arr[index - 1] < arr[index + 1])
        return true;
 
   
    if (arr[index - 2] < arr[index])
        return true;
 
    return false;
     }
};


bool canBeIncreasing(vector<int>& nums) {
    int previous = nums[0];
    bool used = false;
    for (int i = 1; i < nums.size(); i++){
        if (nums[i] <= previous){ // it's not strictly increasing
            if (used)
                return false;
            // we haven't used the element removal yet.
            used = true;
            if (i == 1 || nums[i] > nums[i - 2]) // we remove the element from i - 1 position because it's bigger, so we update previous.
                previous = nums[i];
            // else we remove current element and leave previous to it's existing value.
        } else
            previous = nums[i];
    }
    return true;
}