/*
    Return the first and last M numbers in expression N^K
*/
#include <bits/stdc++.h>
#define ll long long int
using namespace std;
 
// Function to find a^b modulo M
ll modPower(ll a, ll b, ll M)
{
    ll res = 1;
    while (b) {
        if (b & 1)
            res = res * a % M;
        a = a * a % M;
        b >>= 1;
    }
    return res;
}
 
// Function to find the first and last
// M digits from N^K
void findFirstAndLastM(ll N, ll K, ll M)
{
    // Calculate Last M digits
    ll lastM
        = modPower(N, K, (1LL) * pow(10, M));
 
    // Calculate First M digits
    ll firstM;
 
    double y = (double)K * log10(N * 1.0);
 
    // Extract the number after decimal
    y = y - (ll)y;
 
    // Find 10 ^ y
    double temp = pow(10.0, y);
 
    // Move the Decimal Point M - 1 digits forward
    firstM = temp * (1LL) * pow(10, M - 1);
 
    // Print the result
    cout << firstM << " " << lastM << endl;
}

int main()
{
    int t;
    cin >> t;
    while(t--) {
        ll N, K, M;
        cin >> N >> K >> M;
 
        findFirstAndLastM(N, K, M);
    }
    return 0;
}