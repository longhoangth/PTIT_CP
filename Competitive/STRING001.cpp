#include <bits/stdc++.h>
using namespace std;
#define MAX 1000001

void tach(string str, string &child, string &parent) {
    for(int i=0; i < str.length(); i++) {
        if(str[i] == '"') {
            i++;
            while(str[i] != '"') {
                child += char(str[i]);
                i++;
            }
        }
        if(str[i] == '"')   break;
    }
    int j = str.length()-2;
    while(str[j] != '"') {
        parent += char(str[j]);
        j--;
    }
    int n = parent.length();
 
    for (int i = 0; i < n / 2; i++)
        swap(parent[i], parent[n - i - 1]);
}
int subStr(string child, string parent) {
    if(child.length() == 0 || parent.length() == 0) return 0;
    if(child.length() > parent.length())    return -1;

    int M = child.length();
    int N = parent.length();
 
    /* A loop to slide pat[] one by one */
    for (int i = 0; i <= N - M; i++) {
        int j;
 
        /* For current index i, check for
 pattern match */
        for (j = 0; j < M; j++)
            if (parent[i + j] != child[j])
                break;
 
        if (j == M)
            return i;
    }
 
    return -1;
}
int main() {
    int t;
    cin >> t;
    while(t--) {
        string str;
        cin.ignore();
        getline(cin,str);
        string child{""}, parent{""};
        tach(str, child, parent);
        cout << subStr(child, parent) << endl;
    }
    return 0;
}