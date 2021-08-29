// Example nums{1,2,4,14,43} n = 100

// the first value we need is 1 and we can see in nums that we have it
// new_nums{1}
// we need 2, we take it from nums
// new_nums{1,2}
// adding 2 new_nums become from 1 to 1(last value of origini new_nums) + 2(new value added) = 3 (last value of new_nums)
// new_nums{1,2,3}
// we need 4, since we already have it in nums, take if
// new_nums{1,2,3,4}
// 4)adding 4 new_nums become from 1 to 3(last value of origini new_nums) + 4(new value added) = 7 (last value of new_nums)
// new_nums{1,2,3,4,5,6,7}
// we need 8, since we don' have it add it (count ++)
// new_nums{1,2,3,4,5,6,7,8}
// adding 8 new_nums become from 1 to 7(last value of origini new_nums) + 8(new value added) = 15 (last value of new_nums)
// new_nums{1,2,3,4,5,6,7,8,9,10,11,12,13,14,15}
// we know that with the current new_nums we can get number from 1 to 15, since 14 is less than 15 we can add 14 in new_nums
// with 14 new_nums become from 1 to 15(last value of origini new_nums) + 14(new value added) = 29 (last value of new_nums)
// new_nums{1,2,3,4,5,6,7,8,9,10,11,12,13,14,15...27,28,29}
// we need 30, since we don' have it add it (count ++)
// new_nums{1,2,3,4,5,6,7,8,9,10,11,12,13,14,15...27,28,29,30}
// adding 30 new_nums become from 1 to 29(last value of origini new_nums) + 30(new value added) = 59 (last value of new_nums)
// new_nums{1,2,3,4,5,6,7,8,9,10,11,12,13,14,15... 57,58,59}
// we know that with the current new_nums we can get number from 1 to 59, since 59 is less than 43 we can add 34 in new_nums
// with 43 new_nums become from 1 to 59(last value of origini new_nums) + 43(new value added) 102 (last value of new_nums)
// new_nums{1,2,3,4,5,6,7,8,9,10,11,12,13,14,15...99,100,101,102}
// now we get numbers from 1 to 102 adding 8,30
// so return 2

class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        int index = 0;
        int count = 0;
        long long Value_need = 1;
      
        while (Value_need <= n) {

            if (index <nums.size() && Value_need >= nums[index]) {
                Value_need += nums[index];
                index++;
            }
            else {
                Value_need += Value_need;
                count++;
            }
        }

        return count;
    }
};