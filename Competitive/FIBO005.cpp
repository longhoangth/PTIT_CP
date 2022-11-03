// express number N equal to sum of fibonacci numbers without repetition
/*
    Author: Long Hoang
    Date: 13/10/2022
*/

#include <bits/stdc++.h>
#include<math.h>

using namespace std;

long long fib[110], dp1[110], dp2[110], v[110];

void fibonacci() {
    // two first fibonacci number
    fib[1] = 1;
    fib[2] = 2;

    for(int i=3; i <= 87; i++) {
        fib[i] = fib[i-1] + fib[i-2];
    }
}

int find(int num) {
    int cnt = 0;
 
    // Generate the Canonical form of given number
    for (int i = 87; i > 0; i--) {
        if (num >= fib[i]) {
            v[cnt++] = i;
            num -= fib[i];
        }
    }
 
    // Reverse the number
    reverse(v, v + cnt);
 
    // Base condition of dp1 and dp2
    dp1[0] = 1;
    dp2[0] = (v[0] - 1) / 2;
 
    // Iterate from 1 to cnt
    for (int i = 1; i < cnt; i++) {
 
        // Calculate dp1[]
        dp1[i] = dp1[i - 1] + dp2[i - 1];
 
        // Calculate dp2[]
        dp2[i] = ((v[i] - v[i - 1]) / 2) * dp2[i - 1] + ((v[i] - v[i - 1] - 1) / 2) * dp1[i - 1];
    }
 
    // Return final ans
    return (dp1[cnt - 1] + dp2[cnt - 1]);
}

int main() {
    int t;
    cin >> t;
    // generate fibonacci number
    fibonacci();
    while(t--) {
        int n;
        cin >> n;
        cout << find(n) << endl;
    }
    return 0;
}