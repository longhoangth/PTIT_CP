// Calculate 2^N * N!

#include <iostream>
#include <vector>
using namespace std;

// Maximum number of digits in output
#define MAX 100000

int multiply(int x, int res[], int res_size);

// Multiplies str1 and str2, and prints result.
string multiply_string(string num1, string num2)
{
	int len1 = num1.size();
	int len2 = num2.size();
	if (len1 == 0 || len2 == 0)
	return "0";

	// will keep the result number in vector
	// in reverse order
	vector<int> result(len1 + len2, 0);

	// Below two indexes are used to find positions
	// in result.
	int i_n1 = 0;
	int i_n2 = 0;
	
	// Go from right to left in num1
	for (int i=len1-1; i>=0; i--)
    {
		int carry = 0;
		int n1 = num1[i] - '0';

		// To shift position to left after every
		// multiplication of a digit in num2
		i_n2 = 0;
		
		// Go from right to left in num2			
		for (int j=len2-1; j>=0; j--)
		{
			// Take current digit of second number
			int n2 = num2[j] - '0';

			// Multiply with current digit of first number
			// and add result to previously stored result
			// at current position.
			int sum = n1*n2 + result[i_n1 + i_n2] + carry;

			// Carry for next iteration
			carry = sum/10;

			// Store result
			result[i_n1 + i_n2] = sum % 10;

			i_n2++;
		}

		// store carry in next cell
		if (carry > 0)
			result[i_n1 + i_n2] += carry;

		// To shift position to left after every
		// multiplication of a digit in num1.
		i_n1++;
	}

	// ignore '0's from the right
	int i = result.size() - 1;
	while (i>=0 && result[i] == 0)
	i--;

	// If all were '0's - means either both or
	// one of num1 or num2 were '0'
	if (i == -1)
	return "0";

	// generate the result string
	string s = "";
	
	while (i >= 0)
		s += std::to_string(result[i--]);

	return s;
}

// This function finds factorial of large numbers
// and prints them
string factorial(int n)
{
    string str;
	int res[MAX];

	// Initialize result
	res[0] = 1;
	int res_size = 1;

	// Apply simple factorial formula n! = 1 * 2 * 3
	// * 4...*n
	for (int x = 2; x <= n; x++)
		res_size = multiply(x, res, res_size);

	for (int i = res_size - 1; i >= 0; i--)
		str += (res[i] + '0');
    
    return str;
}

// This function multiplies x with the number
// represented by res[].
// res_size is size of res[] or number of digits in the
// number represented by res[]. This function uses simple
// school mathematics for multiplication.
// This function may value of res_size and returns the
// new value of res_size
int multiply(int x, int res[], int res_size)
{
	int carry = 0; // Initialize carry

	// One by one multiply n with individual digits of res[]
	for (int i = 0; i < res_size; i++) {
		int prod = res[i] * x + carry;

		// Store last digit of 'prod' in res[]
		res[i] = prod % 10;

		// Put rest in carry
		carry = prod / 10;
	}

	// Put carry in res and increase result size
	while (carry) {
		res[res_size] = carry % 10;
		carry = carry / 10;
		res_size++;
	}
	return res_size;
}

// This function finds
// power of a number x
string power(int x, int n) {
    string str;
    //printing value "1" for power = 0
    if(n == 0 ){
        str = "1";
        return str;
    }


    int res[MAX];
    int res_size = 0;
    int temp = x;

    // Initialize result
    while (temp != 0) {
        res[res_size++] = temp % 10;
        temp = temp / 10;
    }

    // Multiply x n times
    // (x^n = x*x*x....n times)
    for (int i = 2; i <= n; i++)
        res_size = multiply(x, res, res_size);

    for (int i = res_size - 1; i >= 0; i--)
        str += (res[i] + '0');

    return str;
}

int main()
{
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        string exp, fact;
        fact = factorial(n);
        exp = power(2, n);
        cout << multiply_string(exp, fact) << endl;
    }
}