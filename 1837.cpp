//Time Complexity O(n)
//Space Complexity O(1)
class Solution {
public:
    int sumBase(int n, int k) {
        int sum=0;
        while(n>0){
            sum+=(n%k);
            n=n/k;
        }
        return sum;
    }
};


//Similar Decimal to binary
// C++ program to convert a decimal
// number to binary number

#include <iostream>
using namespace std;

// function to convert decimal to binary
void decToBinary(int n)
{
	// array to store binary number
	int binaryNum[32];

	// counter for binary array
	int i = 0;
	while (n > 0) {

		// storing remainder in binary array
		binaryNum[i] = n % 2;
		n = n / 2;
		i++;
	}

	// printing binary array in reverse order
	for (int j = i - 1; j >= 0; j--)
		cout << binaryNum[j];
}

// Driver program to test above function
int main()
{
	int n = 17;
	decToBinary(n);
	return 0;
}


// Binary to Decimal
// C++ program to convert binary to decimal
#include <iostream>
using namespace std;

// Function to convert binary to decimal
int binaryToDecimal(int n)
{
	int num = n;
	int dec_value = 0;

	// Initializing base value to 1, i.e 2^0
	int base = 1;

	int temp = num;
	while (temp) {
		int last_digit = temp % 10;
		temp = temp / 10;

		dec_value += last_digit * base;

		base = base * 2;
	}

	return dec_value;
}

// Driver program to test above function
int main()
{
	int num = 10101001;

	cout << binaryToDecimal(num) << endl;
}
