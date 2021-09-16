//Time Complexity O(n)
//Space Complexity O(1)
class Solution {
public:
    int totalMoney(int n) {
        int sum=0,x=1,c=0;
        for(int i=0;i<n;i++){
            sum+=c+x;
            c++;
            if(c%7==0){
                x++;
                c=0;
            }
        }
        return sum;
    }
};

//Time Complexity O(n)
//Space Complexity O(1)
class Solution {
public:
    int totalMoney(int n,int sum=0,int k=0) {
        for(int i=0;i<n;i++){
            if(i%7==0)
                k=i/7+1;
            sum+=k++;        
        }
        return sum;
    }
}

//Time Complexity O(1)
//Space Complexity O(1)
class Solution {
public:
    int totalMoney(int n) {
        const int m = n / 7;
        const int r = n % 7;
        cout<<m << " " << r ;
        return 7 * (4 * m + (m - 1) * m / 2) + r * (r + 2 * m + 1) / 2;
    }
};


//Formula for finding sequence from specific loaction

// Sum of Arithmetic Sequence Formula
// When the Last Term is Given	S = n⁄2 (a + L)
// When the Last Term is Not Given	S = n⁄2 {2a + (n − 1) d}
// Notations:

// “S” is the sum of the arithmetic sequence,
// “a” as the first term,
// “d” the common difference between the terms,
// “n” is the total number of terms in the sequence and
// “L” is the last term of the sequence.
// Also Check: Arithmetic Sequence Formula

// Solved Example Using Sum of Arithmetic Sequence Formula
// Question: Find the sum of the first 30 terms of the sequence 1, 3, 5, 7, 9 ……

// Solution:

// Given,

// a = 1
// d = 2
// n = 30

// Using the formula: S = n/2 {2a + (n − 1)d}

// S = 30/2 {2(1) + (30 − 1)2}

// = 900