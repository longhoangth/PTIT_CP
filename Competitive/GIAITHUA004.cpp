// find remainder of nCk divide by m

#include <bits/stdc++.h>
using namespace std;

// Function to find the nCk
long long calcNCK(int n, int k)
{

	// p holds the value of n*(n-1)*(n-2)...,
	// r holds the value of k*(k-1)...
	long long p = 1, r = 1;

	// C(n, k) == C(n, n-k),
	// choosing the smaller value
	if (n - k < k) 	{k = n - k;}

	if (k != 0) 
	{
		while (k) 
		{
			p *= n;
			r *= k;

			// gcd of p, k
			long long m = __gcd(p, r);

			// dividing by gcd, to simplify
			// product division by their gcd
			// saves from the overflow
			p /= m;
			r /= m;

			n--;
			k--;
		}

		// r should be simplified to 1
		// as C(n, k) is a natural number
		// (denominator should be 1 ) .
	}

	else	{p = 1;}

	// if our approach is correct p = ans and r =1
	return p;
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n, k, m;
        cin >> n >> k >> m;
        cout << calcNCK(n, k) % m << endl;
    }	
}

