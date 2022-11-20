/*
    Find the remainder of a^N / modulo
*/

#include<iostream>
#include <math.h>
using namespace std;
#define ll long long
const int mod = pow(10,9) + 7;

ll res(int a, int n) {
    if(n == 0)  return 1;
    if(a == 1)  return 1;
    if(n == 1)  return a;
    if(n%2 == 0){
        ll tmp = res(a,n/2);
        return (tmp*tmp)%mod;
    }
    else{
        ll tmp = res(a,n/2);
        return ((a*tmp)%mod*tmp)%mod;
    }
}
int main() {
    int t;
    cin >> t;
    while(t--) {
        int a, n;
        cin >> a >> n;
        cout << res(a, n) << endl;       
    }
}