// fibonacci string
/*

    G(1) = A,
    G(2) = B,
    G(n) = G(n-2) + G(n-1)
    '+': connect two string
*/ 
// find i-th character of n-th fibonacci string

#include<iostream>
#include<vector>
#include<string>
#define MAX 93
using namespace std;
vector<string> fibo_string;
void generating_fibo_string()
{
    string str1{"A"}, str2{"B"};
    fibo_string.push_back(str1);
    fibo_string.push_back(str2);
    for(int i=2; i < MAX; i++)
    {
        string tmp{""};
        tmp = fibo_string[i-2] + fibo_string[i-1];
        fibo_string.push_back(tmp);
    }
}
int main()
{
    generating_fibo_string();
    int t;
    cin >> t;
    while(t--)
    {
        int n, i;
        cin >> n >> i;
        cout << fibo_string[n-1][i-1] << endl;
    }
}