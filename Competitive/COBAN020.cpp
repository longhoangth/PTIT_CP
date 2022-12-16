// find maximum product of digits of numbers 
// which are less than or equal to N
/*
    Author: Long Hoang Thanh
    Date: 21/11/2022
*/

#include <bits/stdc++.h>
#define ll long long int 
using namespace std;

// Function that returns the maximum product of
// digits among numbers less than or equal to N
ll maxProd(ll N)
{
	if (N == 0)
		return 1;
	if (N < 10)
		return N;
	return max(maxProd(N / 10) * (N % 10), maxProd(N / 10 - 1) * 9);
}

// Driver code
int main()
{
    int t;
    cin >> t;
    while(t--)
	{
        ll N;
        cin >> N;
        cout << maxProd(N) << endl;
    }

	return 0;
}
