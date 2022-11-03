#include<iostream>
#include<fstream>
using namespace std;
int main()
{
    fstream file_ob;
    file_ob.open("data.txt", ios::in | ios::out);
    while(!file_ob.eof())
    {
        string data;
        file_ob >> data;
        cout << data << endl;
    }
    file_ob.seekg(ios::beg);
    while(!file_ob.eof())
    {
        string data;
        file_ob >> data;
        if(data == "2")
        {
            file_ob.seekp(ios::cur + 2);
            file_ob << "test";
        } else {
            file_ob << data<< endl;
        }
    }
    file_ob.close();
}