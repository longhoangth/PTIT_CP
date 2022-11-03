#include<iostream>
#include<fstream>
using namespace std;
int main()
{
    int pos;
    fstream file_ob;
    file_ob.open("data.txt", ios::app);
    pos = file_ob.tellp();
    file_ob.seekp(3, ios::beg);
    file_ob << "testagain";
    cout << pos << endl;
    file_ob.close();
}