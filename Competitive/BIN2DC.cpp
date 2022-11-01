#include<iostream>
#include<bitset>
using std::cin;
using std::cout;

// std::string toDec(std::string bin, int i = 0) {
//     std::string ans;
//     int n=bin.length();
//     if(i==n-1) {
//         ans += bin[i] - '0';
//     }
//     ans += (((bin[i] - '0') << (n-i-1)) + toDec(bin, i+1));

//     return ans;
// }
int main() {
    int t;
    cin >> t;
    while(t--) {
        std::string bin;
        cin >> bin;
        unsigned long long value = std::stoull(bin,0,2);
        cout << value << '\n';
    }
}