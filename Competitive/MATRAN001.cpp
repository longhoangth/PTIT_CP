// find max sum path from line 1 to line n
// each line has m elements
/*
    Author: Long Hoang Thanh
    Date: 19/10/2022
*/


#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll t, m, n, dp[105][105], a[105][105];
int main() {
  cin >> t;
  while(t--){
    cin >> n >> m;
    for(int i=1; i <= n; i++) {
         for(int j=1; j <= m; j++) {
            cin >> a[i][j];
        }
    }
    for(int i=1; i <= n; i++) {
        dp[i][0] = INT_MIN;
        dp[i][m+1] = INT_MIN;
    }
    for(int i=1; i <= m; i++) {
        dp[1][i] = a[1][i];
    }
    for(int i=2; i <= n; i++) {
        for(int j=1; j <= m; j++) {
        dp[i][j]=max(max(dp[i-1][j-1], dp[i-1][j]), dp[i-1][j+1]) + a[i][j];
      }
    }
    ll ans=INT_MIN;
    for(int i = 1; i <= m; i++) ans = max(ans, dp[n][i]);
    cout << ans << '\n';
  }
return 0;
}