// count the number of the last consecutive ZERO number in N! 

#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll n;
int main()
{

    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int t; cin >>t;
    while(t--){
        cin >>n;
        ll ans = 0;
        int k = 1;
        while(pow(5,k) <= n){
            ans += n/(pow(5,k));
            k++;
        }
        cout <<ans<<'\n';
    }
   return 0;
}