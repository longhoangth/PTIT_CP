#include <bits/stdc++.h>

using namespace std;
void createHash(set<int>& hash, int maxElement)
{

	// Storing the first two numbers
	// in the hash
	int prev = 0, curr = 1;
	hash.insert(prev);
	hash.insert(curr);

	// Finding Fibonacci numbers up to N
	// and storing them in the hash
	while (curr < maxElement) {
		int temp = curr + prev;
		hash.insert(temp);
		prev = curr;
		curr = temp;
	}
}

// Function to find the Fibonacci pair
// with the given sum
void findFibonacciPair(int n)
{
	// creating a set containing
	// all fibonacci numbers
	set<int> hash;
	createHash(hash, n);

	// Traversing all numbers
	// to find first pair
	for (int i = 0; i < n; i++) {

		// If both i and (N - i) are Fibonacci
		if (hash.find(i) != hash.end()
			&& hash.find(n - i) != hash.end()) {

			// Printing the pair because
			// i + (N - i) = N
			cout << i << " "<< (n - i) << endl;
			return;
		}
	}

	// If no fibonacci pair is found
	// whose sum is equal to n
	cout << "-1\n";
}

// Driven code
int main()
{
	int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        findFibonacciPair(n);
    }
}