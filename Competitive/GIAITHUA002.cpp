/*
    Author: Long Hoang Thanh
    Date: 20/11/2022
*/
// find the smallest number whose fraction has the last n 0 number

#include <bits/stdc++.h>

using namespace std;

int five(long long res)
{
    if (res == 0)   return 0;
    int count{0};
    while(res % 5 == 0)
    {
        count += 1;
        res /= 5;
    }
    return count;
}
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n, m{0};
        cin >> n;
        long long res = 0;
        while(m < n) {
            m += five(res);
            if(m < n) 
                res += 5;
        }
        cout << res << endl;
    }
}