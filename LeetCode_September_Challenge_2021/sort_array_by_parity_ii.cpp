
//It was my Intension
class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        int n=nums.size();
        deque<int>de;
        for(int i=0;i<n;i++){
            if(nums[i]%2==0){
                de.push_back(nums[i]);
            }else{
                de.push_front(nums[i]);
            }
        }
        for(int i=0;i<n;i++){
            if(i%2==0){
                nums[i]=de.back();
                de.pop_back();
            }else{
                nums[i]=de.front();
                de.pop_front();
            }
        }
        return nums;
    }
};


class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& A) {
        int n=A.size();
        int i=0,j=1;
        while(j<A.size() && i<A.size()){
            if(A[i]%2==1){
                swap(A[i],A[j]);
                j+=2;
            }else{
                i+=2;
            }
        }
        return A;
    }
};


class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& A) {
        int n = A.size();
        int next_odd{n - 1}, next_even{0};
        while(next_even < n){
            if(A[next_even] % 2 == 0){
                next_even += 2;
            } else {
                swap(A[next_even], A[next_odd]);
                next_odd -= 2;
            }
        }
        
        return A;
    }
};


class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums)
{
    vector<int> vec(nums.size());
    int j,k;
    j=0;k=1;
    for(int i=0;i<nums.size();i++)
    {
        if(nums[i]%2==0){
            vec[j]=nums[i];
            j=j+2;
        }
        else{
            vec[k]=nums[i];
            k=k+2;
        }
    }
    return vec;
}
};