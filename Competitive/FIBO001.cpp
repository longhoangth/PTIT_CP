#include<iostream>

using namespace std;

long long non_fibo(int n) {
    int a{1}, b{2}, c{3};
    while(n > 0) {
        a = b;
        b = c;
        c = a+b;
        n -= (a-1);
    }
    n += (a-1);
    return (n+b);
}
int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        cout << non_fibo(n) << endl;
    }
}