/*
    Author: Long Hoang Thanh
    Date: 27/10/2022
*/
// square of a number that contains n number '1'

#include <iostream>
#include <string>
using namespace std;
const string num = "123456790", repeat = "098765432";
string s{""};
int t, n;

string solve(int n) 
{
    int n1 = (n-1)/9, n2 = n - 9*n1;
         
    // middle
    for (int i=1; i<=n2; i++)
    {
        s.insert(s.length(), 1, (char)(i + '0'));
    }
    for (int i=n2-1; i>0; i--)
    {
        s.insert(s.length(), 1, (char)(i + '0'));
    }
    // if n is greater than 10
    if (n>9)
    {
        //starting
        for (int i=0; i<n1; i++)
        {
            s.insert(0, num);
        }
        //ending
        for (int i=0; i<n1; i++)
        {
            s.insert(s.length()-1, repeat);
        }
    }
    return s;
}
int main()
{
    cin >> t;
    while(t--) 
    {
        cin >> n;
        cout << solve(n) << endl;
        s = "";
    }
    return 0;
}