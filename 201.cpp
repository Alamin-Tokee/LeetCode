class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int cnt=0;
        while(left!=right){
            left>>=1;
            right>>=1;
            cnt++;
        }
        return left << cnt;
    }
};


class Solution {
public:
    int rangeBitwiseAnd(int l, int r) {
        int res = l;
        while (res && l < r) res &= ++l;
        return res;
    }
};

class Solution {
public:
    int rangeBitwiseAnd(int l, int r) {
        int count = 0;
        while (l && l != r) l >>= 1, r >>= 1, count++;
        return l << count;
    }
};

class Solution{
public:
    int rangeBitwiseAnd(int l, int r) {
        return (l && l != r) ? (rangeBitwiseAnd(l >> 1, r >> 1) << 1) : l;
    }
};


class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        while (m < n) n-=(n&-n);
        return n;
    }
};