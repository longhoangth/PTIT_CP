// give p(prime number), n, s
// find all combination of n prime numbers greater than p
// and all of them has sum equal to s 

#include<bits/stdc++.h>

using namespace std;

vector<int> prime;
vector<vector<int>> res;
// Sieve array of prime
bool isPrime[1000];

int dp [200][20][20];

void sieve()
{
	// Initialise all numbers as prime
	memset(isPrime, true, sizeof(isPrime));

	// Sieve of Eratosthenes.
	for (int i = 2; i * i <= 1000; i++)
	{
		if (isPrime[i])
		{
			for (int j = i * i; j <= 1000; j += i)
			{
				isPrime[j] = false;
			}
		}
	}
	// Push all the primes into
	// prime vector
	for (int i = 2; i <= 1000; i++)
	{
		if (isPrime[i])
		{
			prime.push_back(i);
		}
	}
}



void represent(int i, int sum, int j, int p, int n, int s)
{
    vector<int> tmp;
	// If index went out of vector
	// size or the sum became
	// larger than s return 0
	if (i > prime.size() || sum > s)
	{
		return;
	}

	// If sum becomes equal to s and
	// j becomes exactly equal to n.
	// Return 1, else if j is still
	// not equal to k, return 0
	if (sum == s) {
		if (j == n) {
			return;
		}
		return;
	}

	// If sum != n and still j as exceeded, return 0
	if (j == s) {return;}
}
int main()
{
    sieve();
    int p, n, s, begin, end;

    cin >> p >> n >> s;

    for(int i=0; i < prime.size(); i++)
    {
        if(prime[i] == p)
        {
            begin = i+1;
        }
        if(prime[i] > s)
        {
            end = i-1;
            break;
        }
    }
}