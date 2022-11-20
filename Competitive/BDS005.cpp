// count ways that a number is equal to sum of square numbers
/*
    Author: Long Hoang Thanh 
    Date: 1/11/2022
*/

#include <bits/stdc++.h>
using namespace std;
#define NUM 31622

// Store perfect squares less than 10^9
vector<int> psquare;

// Utility function to calculate perfect
// squares less than or equal to N
void calcPsquare()
{
	for (int i = 1; i * i <= NUM; i++)
		psquare.push_back(i * i);
}

// Function to find the number
// of ways to represent a number
// as sum of perfect squares
int countWays(int index, int target)
{
	// Handle the base cases
	if (target == 0)
		return 1;

	if (index < 0 || target < 0)
		return 0;

	// Include the i-th index element
	int inc = countWays(
		index, target - psquare[index]);

	// Exclude the i-th index element
	int exc = countWays(index - 1, target);

	// Return the result
	return inc + exc;
}

// Driver Code
int main()
{
    calcPsquare();
    int t;
    cin >> t;
    while(t--)
    {
        int N;
        cin >> N;
        cout << countWays(psquare.size() - 1, N) << endl;
    }
	return 0;
}