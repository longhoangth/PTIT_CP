// Next Permutation
/*
    Author: Long Hoang Thanh
    Date: 23/11/2022
*/
#include <algorithm>
#include <iostream>
using namespace std;

#define MAX 103 

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n, arr[MAX];
        cin >> n;
        for(int i=0; i < n; i++)
        {
            cin >> arr[i];
        }

        if(next_permutation(arr, arr+n))
        {
            for(int i=0; i < n; i++)
            {
                cout << arr[i] << " ";
            }
        } else 
        {
            for(int i=0; i < n; i++)
            {
                cout << arr[i] << " ";
            }
        }
        cout << "\n";
    }    
}
