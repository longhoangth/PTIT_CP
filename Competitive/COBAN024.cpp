// swap k times each number in a specific number
// to create the largest possible number
/*
    Author: Long Hoang Thanh
    Date: 8/11/2022
*/
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

void solve(int k, string s)
{
    vector<char> element;
    for(int i=0; i < s.size(); i++)
    {
        element.push_back(s[i]);
    }  

    sort(element.begin(), element.end());

    for(int i=0; i < s.size(); i++)
    {
        if(k)
        {
            if(element.back() != s[i])
            {
                char tmp = s[i];
                s[i] = element.back();
                for(int j=s.size()-1; j > i; j--)
                {
                    if(s[j] == element.back())
                    {
                        s[j] = tmp;
                        break;
                    }
                }
                element.pop_back();
                k--;
            } else {
                element.pop_back();
            }
        }
    }
    cout << s << endl;
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int k;
        string s;
        cin >> k >> s;
        solve(k, s);
    }
}