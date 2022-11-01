// knapsack problem
/*
    Author: Long Hoang Thanh
    Date: 13/10/2022
*/

#include<bits/stdc++.h>
#define MAX 26
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        //set up input
        int n, w;
        cin >> n >> w;
        int value[MAX], weight[MAX], dp[n+1][w+1];
        for(int i=1; i <= n; i++) {
            cin >> weight[i];
        }
        for(int i=1; i <= n; i++) {
            cin >> value[i];
        }
        
        // set up table to find
        memset(dp, 0, sizeof(dp));


        for(int i=1 ; i <= n; i++) {
            for(int j=1; j <= w; j++) {

                // assume that can not put the i-th object into bag
                dp[i][j] = dp[i-1][j];

                // put the i-th object into bag if can
                if(j >= weight[i]) {
                    dp[i][j] = max(dp[i][j], dp[i-1][j-weight[i]] + value[i]);
                }
            }
        }
        cout << dp[n][w] << endl;
    }
}