// count ways that a number is equal to sum of k unique numbers
/*
    Author: Long Hoang Thanh 
    Date: 3/11/2022
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> vt;
// DP array
int dp[200][20][20] = {0};

int t, n ,k;
void Init()
{
    for(int i=0; i <= 20; i++)
    {
        vt.push_back(i);
    }
}
int CountWays(int i, int j, int sum, int n, int k)
{

	// If index went out of vector
	// ize or the sum became
	// larger than n return 0
	if (i > vt.size() || sum > n)
	{
		return 0;
	}

	// If sum becomes equal to n and
	// j becomes exactly equal to k.
	// Return 1, else if j is still
	// not equal to k, return 0
	if (sum == n) {
		if (j == k) {
			return 1;
		}
		return 0;
	}

	// If sum != n and still j as exceeded, return 0
	if (j == k) {return 0;}

	// If that state is already calculated, return directly the ans
	if (dp[i][j][sum]) {return dp[i][j][sum];}

	int inc = 0, exc = 0;
	// Include the current number
	inc = CountWays(i + 1, j + 1, sum + vt[i], n, k);

	// Exclude the current number
	exc = CountWays(i + 1, j, sum, n, k);

	// Return by memoizing the ans
	return dp[i][j][sum] = inc + exc;
}

int main()
{
    Init();
	cin >> t;
    while(t--)
    {
        cin >> n >> k;
	    cout << CountWays(0, 0, 0, n, k) << endl;
        memset(dp, 0, sizeof(dp));
    }
}
