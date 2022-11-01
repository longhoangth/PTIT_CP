#include<iostream>

using namespace std;

int fibonacci(int n) {
    if(n <= 3)	return 4;
    int prePrev{0}, prev{1}, curr{1};
    while(true) {
        prePrev = prev;
        prev = curr;
        curr = prePrev + prev;
        
        if(curr == n || curr == n+1) {
            return curr+1;
        }
        if(n < curr) {
            return n+1;
        }
    }
}
int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        cout << fibonacci(n) << endl;
    }
}