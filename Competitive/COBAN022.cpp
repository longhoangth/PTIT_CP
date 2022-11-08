// create a triangle from an array
// this triangle has n rows 
// i-th row is sum of two consecutive elements in (i-1)-th
/* Example:
[1 2 3 4 5]
[3 5 7 9]
[8 12 16]
[20 28]
[48]
*/

/*
    Author: Long Hoang Thanh 
    Date: 8/11/2022
*/

#include<iostream>
#include<vector>

using namespace std;

void solve(vector<int> vt_starting, int n);
void printRes(vector<vector<int> > triangle);

int main()
{
    int t;
    cin >> t;
    while(t--) 
    {
        int n;
        cin >> n;
        vector<int> vt_starting;
        for(int i=0; i < n; i++)
        {
            int tmp;
            cin >> tmp;
            vt_starting.push_back(tmp);
        }
        solve(vt_starting, n-1);
    }
}

void solve(vector<int> vt_starting, int n) 
{
    vector<vector<int> > triangle;
    vector<int> tmp;
    triangle.push_back(vt_starting);

    for(int i=0; i < n; i++)
    {
        for(int j = 1; j < triangle[i].size(); j++)
        {
            int sum_tmp;
            sum_tmp = triangle[i][j] + triangle[i][j-1];
            tmp.push_back(sum_tmp);
        }
        triangle.push_back(tmp);
        tmp.clear();
    }
    printRes(triangle);
}
void printRes(vector<vector<int> > triangle)
{
    //print result
    for(int i=0; i < triangle.size(); i++)
    {
        cout << '[';
        for(int j = 0; j < triangle[i].size(); j++)
        {
            cout << triangle[i][j];
            if(j != triangle[i].size() - 1)
            {
                cout << " ";
            }
        }
        cout << ']' << endl;       
    }
}