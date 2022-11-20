// Count ways that express a number is equal to sum of even numbers. 
/*
    Author: Long Hoang Thanh
    Date: 21/10/2022
*/
#include<iostream>
#include<vector>
#define ll long long
using namespace std;
const int MOD = 1e9 + 7;

/* Iterative Function to calculate (x^y)%p in O(log y) */
int power(int x, unsigned int y, int p)
{
	int res = 1;	 // Initialize result

	x = x % p; // Update x if it is more than or
				// equal to p

	while (y > 0)
	{
		// If y is odd, multiply x with result
		if (y & 1)
			res = (1LL * res * x) % p;

		// y must be even now
		y = y>>1; // y = y/2
		x = (1LL * x * x) % p;
	}
	return res;
}

// Return number of ways to write 'n'
// as sum of even integers
int countEvenWays(int n)
{
    if(n%2 != 0)    return -1;
    return power(2, n/2 - 1, MOD);
}

int t, n;
int main()
{
	cin >> t;
    while(t--) {
        cin >> n;
        cout << countEvenWays(n) << endl;
    }
    return 0;
}