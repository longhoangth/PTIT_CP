// find the number N whose largest prime factor is the largest
// in range of [L, R]
/*
    Author: Long Hoang Thanh 
    Date: 6/11/2022
*/

#include<bits/stdc++.h>
using namespace std;

// A function to find largest prime factor
int maxPrimeFactors(int n)
{
	// Initialize the maximum prime factor
	// variable with the lowest one
	int maxPrime = -1;

	// Print the number of 2s that divide n
	while (n % 2 == 0) {
		maxPrime = 2;
		n >>= 1; // equivalent to n /= 2
	}
    // n must be odd at this point
	while (n % 3 == 0) {
		maxPrime = 3;
		n=n/3;
	}

	// now we have to iterate only for integers
	// who does not have prime factor 2 and 3
	for (int i = 5; i <= sqrt(n); i += 6) {
		while (n % i == 0) {
			maxPrime = i;
			n = n / i;
		}
	while (n % (i+2) == 0) {
			maxPrime = i+2;
			n = n / (i+2);
		}
	}

	// This condition is to handle the case
	// when n is a prime number greater than 4
	if (n > 4)
		maxPrime = n;

	return maxPrime;
}

int main()
{
    int t;
    cin >> t;
    while(t--) {
        int l,r, ans{0}, ans_primeFactor{INT_MIN};
        cin >> l >> r;
        for(int i=l; i <= r; i++)
        {
            int tmp = maxPrimeFactors(i);
            if(tmp > ans_primeFactor)
            {
                ans = i;
                ans_primeFactor = tmp;
            }
        }
        cout << ans << endl;
    }
}
