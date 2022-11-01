#include<iostream>
#include<fstream>
#include<vector>

using namespace std;

class customerManagement
{
    public:
        string id, name, email, phone, bill;
};

vector<customerManagement> manage;
fstream Customer_File;
int numOfCus;
int option{0};

void optionDisplay();
void findingOptionDisplay();
void loadData();

bool valid_id(string data);
bool valid_email(string data);
bool valid_phone(string data);

void findingOperation(int finding, string data);

int main()
{
    string data;
    loadData();
    while(option != 6)
    {
        optionDisplay();
        cin >> option;
        if(option == 1)
        {
        addNewCusID:
            customerManagement newCus;
            cout << "Enter ID: ";
            cin >> data;
            if(valid_id(data)) {newCus.id = data;}
            else 
            {
                cout << "INVALID ID!\n";
                goto addNewCusID;
            }
            
            cout << "Enter Name: ";
            cin >> data;
            newCus.name = data;

        addNewCusEmail:
            cout << "Enter Email Address: ";
            cin >> data;
            if(valid_email(data)) {newCus.email = data;}
            else
            {
                cout << "INVALID EMAIL ADDRESS!\n";
                goto addNewCusEmail;
            }

        addNewCusPhone:
            cout << "Enter Phone Number: ";
            cin >> data;
            if(valid_phone(data)) {newCus.phone = data;}
            else
            {
                cout << "INVALID PHONE NUMBER!\n";
                goto addNewCusPhone;
            }

            cout << "Enter Bill (NUMBER ONLY): ";
            cin >> data;
            newCus.bill = data;

            manage.push_back(newCus);
            numOfCus+=1;
        }

        if(option == 2)
        {
        tryFindAgain:
            int finding;
            findingOptionDisplay();
            cin >> finding;
            switch (finding)
            {
            case 1:
                cout << "Enter ID: ";
                cin >> data;
                break;
            
            case 2:
                cout << "Enter Name: ";
                cin >> data;
                break;

            case 3:
                cout << "Enter A Valid Email Address: ";
                cin >> data;
                break;

            case 4:
                cout << "Enter A Valid Phone Number: ";
                cin >> data;
                break;
            default:
                int again;
                cout << "Do you want to continue finding?\n"
                     << "1. YES\n"
                     << "2. NO\nEnter your choice: ";
                cin >> again;
                if(again == 1)
                {
                    goto tryFindAgain;
                }
                break;
            }
            findingOperation(finding, data);
        }

        if(option == 3)
        {

        }

        if(option == 4)
        {

        }

        if(option == 5)
        {

        }
    }
}

void loadData()
{
    Customer_File.open("data.txt", ios::in);
    while(!Customer_File.eof())
    {
        customerManagement tmp;
        Customer_File >> tmp.id;
        Customer_File >> tmp.name;
        Customer_File >> tmp.email;
        Customer_File >> tmp.phone;
        Customer_File >> tmp.bill;
        manage.push_back(tmp);
        numOfCus++;
    }
    Customer_File.close();
}

void optionDisplay()
{
    cout << "Available operations: \n"
         << "1. Add New Customer.\n"
         << "2. Find Customer.\n"
         << "3. Modify A Customer.\n"
         << "4. Display Bill Value.\n"
         << "5. Update Everything.\n"
         << "6. Exit\nEnter option: ";
}

void findingOptionDisplay()
{
    cout << "1. By ID.\n"
         << "2. By Name.\n"
         << "3. By Email.\n"
         << "4. By Phone Number.\nEnter your choice: ";
}

bool valid_id(string data);
bool valid_email(string data);
bool valid_phone(string data);
