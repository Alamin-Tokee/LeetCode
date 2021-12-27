//Brute Force Approach
//TC O(n) //RE
//SC O(n)
class Solution {
public:
    int findComplement(int num) {
		vector<int> v;
		while (num != 0) {    //convert the number to it's binary form & store the bits in "v"
			v.push_back(num%2);
			num = num / 2;
		}
		reverse(v.begin(), v.end());
		for (int i = 0; i < v.size(); i++) v[i] = (v[i]==0) ? 1 : 0;    //Flip the bits in the binary form
		// convert back to number representation
		int two = 1;
		for (int i = v.size() - 1; i >= 0; i--) {
			num = num + v[i] * two;
			two = two * 2;
		}
        return num;
    }
};

//Time Complexity O(logn)
//space O(1)
class Solution {
public:
    int findComplement(int num) {
		int n=num, ans=1; 
		while(n != 1){
            n >>= 1;
            ans <<= 1;
            ans |= 1;
            
        }
        return num^ans;
    }
};

class Solution {
public:
    int findComplement(int num) {
        int mask = 0;                                 
        for(int tmp = num; tmp; tmp >>= 1)            
            mask = (mask << 1) | 1;                   
			
        return mask ^ num;                            
    }
};
