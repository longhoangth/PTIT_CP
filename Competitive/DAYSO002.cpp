// find the number of k-elements sub-array having sum exactly equal to S

#include <bits/stdc++.h>
#define MAX 25 
using namespace std;

int solve(int arr[], int n, int k, int s)
{
    int res{0};
    // Calculate all sub-arrays
    for (int i = 0; i < n-k; i++)
    {
        int sum = 0;
        for (int j = i; j < i+k; j++)
        {
            // Calculate required sum
            sum += arr[j];
            // Check if sum is equal to required sum
        }
        if(sum == s)
            res++;
    }
    return res;
}
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n, k, s, arr[MAX];
        cin >> n >> k >> s;

        for(int i=0; i < n; i++)
        {
            cin >> arr[i];
        }
        
        cout << solve(arr,n,k,s) << endl;
    }
}

