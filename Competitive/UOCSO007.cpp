#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        long long int n, m, count{0};
        cin >> n >> m;
        if(m % n != 0)
        {
            count += n;
            for(int i=2; i <= sqrt(n); i++)
            {
                if(n%i==0)
                {
                    if(m % i != 0)
                        count += i;
                    if(i != n/i)
                    {
                        if(m % (n/i) != 0)
                            count += n/i;
                    }
                }
            }
        }
        cout << count << endl;
    }
}