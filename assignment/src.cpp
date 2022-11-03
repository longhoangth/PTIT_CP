#include "management.h"

vector<customerManagement> manage;
fstream Customer_File;
int numOfCus;
int option{0};
bool warning_flag{false};

int main()
{
    while(option != 6)
    {
        optionDisplay();
        cin >> option;
        //Load data from file
        if(option == 1)
        {
            loadData();
        }
        
        //Add new Customer
        if(option == 2)
        {
            addNewCustomer();
        }

        //Find A Customer
        if(option == 3)
        {
           findCustomer();
        }

        //Modify A Customer
        if(option == 4)
        {
            findCustomer();
        }

        // Update Every Change
        if(option == 5)
        {
            updateEverything();
        }
    }
}
