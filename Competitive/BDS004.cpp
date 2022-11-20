// count ways to express number N equal to sum of K fibonacci numbers
// Long Hoang Thanh

#include <bits/stdc++.h>
using namespace std;

// to store fibonacci numbers
// 42 second number in fibonacci series
// largest possible integer
int fib[43] = { 0 };

// Function to generate fibonacci series
void fibonacci()
{
	fib[0] = 1;
	fib[1] = 2;
	for (int i = 2; i < 44; i++)
    {
		fib[i] = fib[i - 1] + fib[i - 2];
    }
}

// Recursive function to return the
// number of ways
int rec(int x, int y, int last)
{
	// base condition
	if (y == 0) {
		if (x == 0)
			return 1;
		return 0;
	}
	int sum = 0;
	// for recursive function call
	for (int i = last; i >= 0 and (float)fib[i] * (float)y >= (float)x; i--) {
		if (fib[i] > x)
			continue;
		sum += rec(x - fib[i], y - 1, i);
	}
	return sum;
}

// Driver code
int main()
{
	fibonacci();
	int t;
    cin >> t;
    while(t--)
    {
        int n, k;
        cin >> n >> k;
	    cout << rec(n, k, 43) << endl;
    }
	return 0;
}
