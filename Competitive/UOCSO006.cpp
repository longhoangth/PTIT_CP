// Friend pair number

#include<iostream>
#include<math.h>
using namespace std;

void cal(long long a, long long b) {
    long long uoc = 0;
    for(int i=1; i <= sqrt(a); i++) {
        if(a % i ==0) {
            uoc += i;
            uoc += a/i;
        }
    }
    uoc -= a;
    int can = sqrt(a);
    if(can * can == a) {
        uoc -= can;
    }
    if(uoc == b) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}
int main() {
    int t;
    cin >> t;
    while(t--) {
        long long a, b;
        cin >> a >> b;
        if(a > b) {
            cal(a, b);
        } else cal(b,a);
    }
}