#include "management.h"

vector<customerManagement> manage;
fstream Customer_File;
int numOfCus;
int option{0};
bool warning_flag{false};

int main()
{
    while(option != 7)
    {
        OptionDisplay();
        cin >> option;
        //Load data from file
        if(option == 1)
        {
            LoadData();
        }
        
        //Add new Customer
        if(option == 2)
        {
            AddNewCustomer();
        }

        //Find A Customer
        if(option == 3)
        {
           FindCustomer();
        }

        //Modify A Customer
        if(option == 4)
        {
            ModifyCustomer();
        }

        //Delete A Customer
        if(option == 5)
        {
            DeleteCustomer();
        }

        // Update Every Change
        if(option == 6)
        {
            UpdateEverything();
        }
    }
    cout << "Log out\n";
    return 0;
}
