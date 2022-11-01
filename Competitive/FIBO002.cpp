#include<iostream>
using namespace std;
void fibonacci(int n, long long &res) {
    long long prePrev{0}, prev{1}, curr{1};
    while(true) {
        prePrev = prev;
        prev = curr;
        curr = prePrev + prev;

        if(curr % 2 == 0 && curr <= n) {
            res += curr;
        }
        if(curr > n) {
            break;
        }
    }
}
int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        long long res{0};
        fibonacci(n, res);
        cout << res << endl;
    }
}