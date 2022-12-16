/*
	Author: Long Hoang Thanh
	Date: 21/11/2022
*/
#include <bits/stdc++.h>
#define MAX 100000 
using namespace std;

int search(int arr[], int n, int x)
{
	// 1st comparison
	if (arr[n - 1] == x)
		return n;
	
	int backup = arr[n - 1];
	arr[n - 1] = x;
	
	// no termination condition and thus
	// no comparison
	for (int i = 0;; i++) {
		// this would be executed at-most n times
		// and therefore at-most n comparisons
		if (arr[i] == x) {
			// replace arr[n-1] with its actual element
			// as in original 'arr[]'
			arr[n - 1] = backup;
			
			// if 'x' is found before the '(n-1)th'
			// index, then it is present in the array
			// final comparison
			if (i < n - 1)
				return i+1;
			
			// else not present in the array
			return 0;
		}
	}
}

int main(void)
{
	// int t;
	// cin >> t;
	// while(t--)
	// {
		int n,m, arr1[MAX], arr2[MAX];
		cin >> n >> m;

		for(int i=0; i < n; i++)
			cin >> arr1[i];

		for(int i=0; i < m; i++)
			cin >> arr2[i];

		for(int i=0; i < m; i++)
			cout << search(arr1, n, arr2[i]) << " ";

	// 	cout << endl;
	// }
}
