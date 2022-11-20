// given n and l
// input array has N-1 elements from L to L+N
// find the missing number in that array

#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n, l;
        vector<int> vt;
        vector<int> mark;
        cin >> n >> l;

        for(int i=0; i < n-1; i++)
        {
            int tmp;
            cin >> tmp;
            vt.push_back(tmp);
        }
        sort(vt.begin(), vt.end());
        // for(int i=l; i < l + n; i++)
        // {
        //     mark.push_back(i);
        // }

        // while(!vt.empty())
        // {
        //     if(vt.front() == mark.front())
        //     {
        //         vt.erase(vt.begin());
        //         mark.erase(mark.begin());
        //     } 
        //     else break;
        // }

        // cout << mark.front() << endl;
        if(vt.front() != l)  cout << l << endl;
        else if (vt.back() != l+n-1)
        {
            cout << l+n-1 << endl;
        }
        else {
            for(int i=1; i < vt.size(); i++)
            {
                if(vt[i]-1 != vt[i-1])
                {
                    cout << vt[i] - 1 << endl;
                }
            }
        }
    }
}
