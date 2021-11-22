class Solution {
public:
    vector<int>original;
    Solution(vector<int>& nums) {
        original=nums;
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return original;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        vector<int>suffle=original;
        for(int i=original.size()-1;i>=0;i--){
            int r=rand() % (i+1);
            swap(suffle[i],suffle[r]);
        }
        return suffle;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */


class Solution {
public:
    Solution(vector<int>& nums) {
        _original = nums;
        _size = nums.size();
        srand(time(NULL));
    }
    
    vector<int> reset() {
        return _original;
    }
    
    vector<int> shuffle() {
        vector<int> result = _original;
        int generated = 0;
        while (generated < _size) {
            int availableLength = _size - generated;
            int index = rand() % (availableLength);
            int lastIndex = availableLength - 1; 
            int lastElement = result[lastIndex];
            result[lastIndex] = result[index];
            result[index] = lastElement;
            generated++;
        }
        return result;
    }

private:
    vector<int> _original;
    int _size;
};
