// count ways that a number equal to sum of k unique numbers
/*
    Author: Long Hoang Thanh 
    Date: 3/11/2022
*/

#include <bits/stdc++.h>
using namespace std;

// Prime vector
vector<int> prime;

// Sieve array of prime
bool isPrime[100000];

void sieve()
{
	// Initialise all numbers as prime
	memset(isPrime, true, sizeof(isPrime));

	// Sieve of Eratosthenes.
	for (int i = 2; i * i <= 100000; i++)
	{
		if (isPrime[i])
		{
			for (int j = i * i; j <= 100000; j += i)
			{
				isPrime[j] = false;
			}
		}
	}
	// Push all the primes into
	// prime vector
	for (int i = 2; i <= 100000; i++)
	{
		if (isPrime[i])
		{
			prime.push_back(i);
		}
	}
}

bool checkPrime(long long n)
{
    if(n==0 || n == 1) return false;
    if(n == 2)  return true;

    for(long long i=2; i <= sqrt(n); i++)
    {
        if(n % i == 0) {return false;}
    }
    return true;
}

void solve(long long n)
{
    vector<int> divisor;
    vector<int> times;
    int inx = 0;

    while(n)
    {
        int divisor_e = prime[inx];
        int times_e = 0;
        while(n % divisor_e == 0)
        {
            times_e += 1;
            n /= divisor_e;
        }
        if(times_e != 0)
        {
            divisor.push_back(divisor_e);
            times.push_back(times_e);
        }
        inx++;
    }

    for(int i=0; i < times.size(); i++)
    {
        // for(int j = i + 1; j < times.size(); j++)
        // {
        //     if(times[i] < times[j] || (times[i] == times[j] && divisor[i] > divisor[j]))
        //     {
        //         int tmp = times[i];
        //         times[i] = times[j];
        //         times[j] = tmp;

        //         int tmp2 = divisor[i];
        //         divisor[i] = divisor[j];
        //         divisor[j] = tmp2;
        //     } 
        // }
        cout << divisor[i] << " " << times[i] << endl;
    }

    //cout << divisor[0] << " " << times[0] << endl;
}

int main()
{

	// Precompute primes by sieve
	sieve();
    int t;
	cin >> t;
    while(t--)
    {
        long long n;
        cin >> n;
        if(checkPrime(n))
        {
            cout << n << " " << 1 << endl;
        } 
        else
        {
            solve(n);
        }
    }
    return 0;
}
