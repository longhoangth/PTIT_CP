#include<iostream>
#include<math.h>

using namespace std;

bool checkSquare(long long n)
{
    long long sqr = sqrt(n);

    return (sqr * sqr == n) ? true : false;
}
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        long long l, r, sqr_l, sqr_r;
        cin >> l >> r;

        if(checkSquare(l) && checkSquare(r))
        {
            cout << sqrt(r) - sqrt(l) + 1 << endl;
        } else if(checkSquare(l))
        {
            sqr_l = sqrt(l);
            sqr_r = floor(sqrt(r));
            cout << sqr_r - sqr_l + 1 << endl;
        } else if (checkSquare(r)){
            sqr_l = ceil(sqrt(l));
            sqr_r = sqrt(r);
            cout << sqr_r - sqr_l + 1 << endl;
        } else 
        {
            sqr_l = ceil(sqrt(l));
            sqr_r = floor(sqrt(r));
            cout << sqr_r - sqr_l + 1 << endl;
        }

    }
}