#include <bits/stdc++.h>
using std::cin;
using std::cout;

void reverseStr(std::string& str)
{
    int n = str.length();
    for (int i = 0; i < n / 2; i++)
        std::swap(str[i], str[n - i - 1]);
}
std::string toHex(unsigned long long n) {
    if(n < 10)  return std::to_string(n);
    std::string ans;
    while(n) {
        unsigned long long tmp = n%16;
        switch (tmp)
        {
            case 10:
                ans += 'A';
                break;
            case 11:
                ans += 'B';
                break;
            case 12:
                ans += 'C';
                break;
            case 13:
                ans += 'D';
                break;
            case 14:
                ans += 'E';
                break;
            case 15:
                ans += 'F';
                break;
            default:
                ans += tmp +'0';
                break;
        }
        n/=16;
    }
    reverseStr(ans);
    return ans;
}
int main() {
    int t;
    cin >> t;
    while(t--) {
        unsigned long long n;
        cin >> n;
        cout << toHex(n) << '\n';
    }
}