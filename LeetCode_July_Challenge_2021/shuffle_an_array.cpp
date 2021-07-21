//Time Complexity O(n)
//Space Complexity O(n)
// Fisher–Yates Shuffle O(N)
class Solution {
public:
    Solution(vector<int>& nums) {
        original = nums;
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return original;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        vector<int> shuffled=original;
        for(int i=original.size()-1; i >= 0; i--){
            int r=rand()% (i+1);
            //cout << r <<" "<< i << endl;
            //cout<< rand() % i+1<<endl;
            swap(shuffled[i],shuffled[r]);
        }
        return shuffled;
    }


    // vector<int> shuffle() {
    //     int n=original.size();
    //     for (int i=0;i<n;++i)
    //     {
    //         int randomIndex=(rand()%(n-i))+i;
    //         swap(&original[i],&original[randomIndex]);
    //     }
        
    //     return original;
    // }
private:
    vector<int>original;
};


//Usign Next Permutation


class Solution {
public:
    vector<int> ori, temp, track;
    Solution(vector<int>& nums) {
        ori = temp = track = nums;
    }
    vector<int> reset() {
        return ori;
    }
    vector<int> shuffle() {
        do{
            if(temp != track && temp != ori)
                break;   
        }while(next_permutation(temp.begin(), temp.end()));
        track = temp;
        return temp;
    }
};