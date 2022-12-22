// C++ program to count ways to write
// number as sum of odd integers
#include<iostream>
using namespace std;
const int modulo = 1e9 + 7;
// Function to calculate n'th Fibonacci number
int fib(int n)
{
    /* Declare an array to store Fibonacci numbers. */
    int f[n+1];
    int i;

    /* 0th and 1st number of the series are 0 and 1*/
    f[0] = 0;
    f[1] = 1;

    for (i = 2; i <= n; i++)
    {
        /* Add the previous 2 numbers in the series
            and store it */
        f[i] = (f[i-1] % modulo) + (f[i-2] % modulo);
        f[i] = f[i] % modulo;
    }

    return f[n];
}

// Return number of ways to write 'n'
// as sum of odd integers
int countOddWays(int n)
{
	return fib(n);
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        cout << countOddWays(n) << endl;
    }
    return 0;
}
