// the largest k-th power of 2
// find k

#include<iostream>

#define ll long long int

using namespace std;

ll two(ll n)
{
    if(n == 2)  return 1;

    ll count{0};
    while(n%2==0)
    {
        count++;
        n/=2;    
    }
    return count;
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        ll n;
        cin >> n;
        if(n <= 1) 
        {
            cout << 0 << endl;
            continue;
        }
        ll count{0};
        for(int i=2; i <= n; i+=2)
        {
            count += two(i);
        }
        cout << count << endl;
    } 
}