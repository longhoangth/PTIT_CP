#include <iostream>
#include <string.h>

using std::cin, std::cout, std::string;

void getInputStr(string s, string &h, string &m) {
    char pos1{0}, pos2{0};
    for(int i = 0; i < s.size(); i++) {
        //find the start of time string
        if(s[i] == '"') {
            pos1=i;
            continue;
        }
        //find the ':' between hour and minute
        if(s[i] == ':') {
            pos2 = i;
            break;
        }
    }
    //insert hour to string h
    for(int i=pos1+1; i <= pos1+2; i++) {
        h += s[i];
    }
    //insert minute to string m
    for(int i=pos2+1; i < s.size()-1; i++) {
        m += s[i];
    }
    /*
        h = h[0]h[1]
        m = m[0]m[1]
    */
}
void maxTime(string &h, string &m) {
    if(h[0] == '?' && h[1] == '?') {
        h[0] = '2';
        h[1] = '3';
    } else {
        if(h[0] == '?') {
            if(h[1] >= '4') {
                h[0] = '1';
            } else h[0] = '2';
        }
        if(h[1] == '?') {
            if(h[0] == '2') {
                h[1] = '3';
            } else h[1] = '9';
        }
    }
    //max minute
    if(m[0] == '?')   m[0] = '5';
    if(m[1] == '?')   m[1] = '9';

    //display maxTime
    cout << char(34) << h << ':' << m << char(34) << "\n";
}
int main() {
    int t;
    cin >> t;
    while(t--) {
        string s{""},h{""},m{""};
        cin.ignore();
        getline(cin, s);
        getInputStr(s,h,m);
        maxTime(h,m);  
        fflush(stdin);
    }
}