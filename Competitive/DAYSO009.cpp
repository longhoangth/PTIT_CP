// program show biggest difference between bit 0 and 1 in a binary string
/*
    Author: Long Hoang
    Date: 12/10/2022
*/
// CPP Program to find the length of
// substring with maximum difference of
// zeroes and ones in binary string.
#include <bits/stdc++.h>
#define MAX 100
using namespace std;

// Return true if there all 1s
bool allOnes(string s, int n)
{
	// Checking each index is 1 or not.
	int co = 0;
	for (int i = 0; i < s.size(); i++)
		co += (s[i] == '1');

	return (co == n);
}

// Find the length of substring with maximum
// difference of zeroes and ones in binary
// string
int findLength(int arr[], string s, int n, int ind, int st,
			int dp[][3])
{
	// If string is over.
	if (ind >= n)
		return 0;

	// If the state is already calculated.
	if (dp[ind][st] != -1)
		return dp[ind][st];

	if (st == 0) {
		return dp[ind][st] = max(arr[ind]+ findLength(arr, s, n, ind + 1, 1, dp), findLength(arr, s, n, ind + 1, 0, dp));
    }

	return dp[ind][st] = max(arr[ind] + findLength(arr, s, n, ind + 1, 1, dp), 0);
}

// Returns length of substring which is
// having maximum difference of number
// of 0s and number of 1s
int maxLen(string s, int n)
{
	// If all 1s return -1.
	if (allOnes(s, n))
		return -1;

	// Else find the length.
	int arr[MAX] = { 0 };
	for (int i = 0; i < n; i++)
		arr[i] = (s[i] == '0' ? 1 : -1);

	int dp[MAX][3];
	memset(dp, -1, sizeof dp);
	return findLength(arr, s, n, 0, 0, dp);
}

// Driven Program
int main()
{
    int t;
    cin >> t;
    while(t--) {
        string bin;
        cin >> bin;
        int n = bin.length();
        cout << maxLen(bin, n) << endl;
    }
    return 0;
}