#include "management.h"

vector<customerManagement> manage;
fstream Customer_File;
int numOfCus;
int option{0};

int main()
{
    string data;
    loadData();
    while(option != 6)
    {
        optionDisplay();
        cin >> option;
        //Add new Customer
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

        //Find A Customer
        if(option == 2)
        {
            warning();
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
                cout << "Enter A Email Address: ";
                cin >> data;
                if(!valid_email(data)) {goto notMatchingCriteria;}
                break;

            case 4:
                cout << "Enter A Phone Number: ";
                cin >> data;
                if(!valid_phone(data)) {goto notMatchingCriteria;}
                break;
            
            notMatchingCriteria:
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

        // Update Every Change
        if(option == 5)
        {
            updateEverything();
        }
    }
}
