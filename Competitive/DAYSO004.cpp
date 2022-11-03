//the longest increasing sub array
/*
    Author: Long Hoang Thanh 
    Date: 3/11/2022
*/
#include <iostream>
using namespace std;

const int MAX = 100000;

int t, n, arr[MAX];

int lenOfLongestSubArray(int arr[], int n)
{
    int longestLength[MAX];
    int max{1}, len;
    for(int i=0; i < n; i++)
    {
        len = 0;
        for(int j=0; j < i; j++)
        {
            if(arr[i] > arr[j])
            {
                if(longestLength[j] > len)
                {
                    len = longestLength[j];
                }
            }
        }
        longestLength[i] = len + 1; 
        if(max < longestLength[i])
        {
            max = longestLength[i];
        }
    }
    return max;
}

int main()
{
	cin >> t;
    while(t--)
    {
        cin >> n;
        for(int i=0; i < n; i++)
        {
            cin >> arr[i];
        }
        cout << lenOfLongestSubArray(arr, n) << endl;
    }
}

