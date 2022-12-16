// the smallest prime divisor has the largest exponent
/*
    Author: Long Hoang Thanh 
    Date: 3/11/2022
*/

#include <bits/stdc++.h>
using namespace std;

bool checkPrime(long long n)
{
    if(n==0 || n == 1) return false;
    if(n == 2)  return true;

    int i = 2;
    while(i * i <= n)
    {
        if(n % i == 0)  
            return false;
        
        i += 1;
    }
    return true;
}

void solve(long long n)
{
    if(checkPrime(n))
    {
        cout << n << " " << 1 << endl;
        return;
    }
    int the_smallest_prime_divisor;
    int the_exponent{0};
    int dem;
    for(int i = 2; i <= n; i++){
        dem = 0;
        while(n % i == 0){
            ++dem;
            n /= i;
        }
        if(dem > the_exponent)
        {
            the_smallest_prime_divisor = i;
            the_exponent = dem;
        }
        if(n == 0)
            break;
    }   
    cout << the_smallest_prime_divisor << " " << the_exponent << endl;
}

int main()
{
    int t;
	cin >> t;
    while(t--)
    {
        long long n;
        cin >> n;

        solve(n);
    }
    return 0;
}
