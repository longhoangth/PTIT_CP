#include <bits/stdc++.h>

using namespace std;

int n, x[105], k, used[105]={}, init[105];
bool check = false;
void init_array()
{
    for(int i=1; i <= n; i++)
    {
        init[i] = i;
    }
}

bool test(){
    for(int i = 1; i <= n; i++)
    {
        if(abs(x[i] - init[i]) != k)
        {
            return false;
        }
    }
    return true;
}
void Try(int i){
    for(int j = 1; j <= n; ++j){
        if(used[j] == 0){
            used[j] = 1;
            x[i] = j;
        }
        else continue;
        if(i == n)
        {
            if(test())
            {
                check = true;
                break;
            }
        }
        if(i < n)  Try(i + 1);
        used[j] = 0;
    }
}

int main()
{
    int t; 
    cin >> t;
    while(t--){
        cin >> n;
        init_array();
        Try(1);
        if(check)
        {
            for(int i=1; i <= n; i++)
            {
                cout << x[i] << (i < n ? " " : "\n");
            }
        }else cout << -1 << endl;
    }
}