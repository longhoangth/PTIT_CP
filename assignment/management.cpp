#include "management.h"

void warning()
{
    if(manage.size() == 0)
    {
        cout << "There are not any customers in database.\n";
        cout << "PLEASE LOAD DATA FROM FILE OR ADD NEW CUSTOMER FIRST!\n";
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
         << "1. Load Data.\n"
         << "2. Add New Customer.\n"
         << "3. Find Customer.\n"
         << "4. Modify A Customer.\n"
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

bool valid_id(string data)
{
    if(manage.size() == 0)  return false;
    for(int i=0; i < manage.size(); i++)
    {
        if(data == manage[i].id)
        {
            return false;
        }
    }
    return true;
}

bool valid_email(string data)
{
     // Regular expression definition
    const regex pattern("(\\w+)(\\.|_)?(\\w*)@(\\w+)(\\.(\\w+))+");
  
    // Match the string pattern
    // with regular expression
    return regex_match(data, pattern);
}

bool valid_phone(string data)
{
    if(data[0] != '0' || data.size() != 10)    
        return false;

    return true;
}

void findingOperation(int finding, string data)
{
    bool flag = false;
    vector<customerManagement> resultFinding;
    for(int i=0; i < manage.size(); i++)
    {
        switch (finding)
        {
        case 1:
            if(data == manage[i].id)
            {
                resultFinding.push_back(manage[i]);
                flag = true;
            }
            break;
        
        case 2:
            if(isSubstring(data, manage[i].name) != -1)
            {
                resultFinding.push_back(manage[i]);
            }
            break;
        
        case 3:
            if(data == manage[i].email)
            {
                resultFinding.push_back(manage[i]);
                flag = true;
            }
            break;
        
        case 4:
            if(data == manage[i].phone)
            {
                resultFinding.push_back(manage[i]);
                flag = true;
            }
            break;
        }
        if(flag)
        {
            break;
        }
    }
    if(resultFinding.size() == 0)
    {
        cout << "There are any customers who have " << data << endl;
        return;
    }
    for(int i=0; i < resultFinding.size(); i++)
    {
        cout << "Result " << i + 1 << endl;
        cout << "ID: " << resultFinding[i].id << endl;
        cout << "NAME: " << resultFinding[i].name << endl;
        cout << "Email Address: " << resultFinding[i].email << endl;
        cout << "Phone Number: " << resultFinding[i].phone << endl;
        cout << "Bill: " << resultFinding[i].bill << " VND" << endl;
    }
}

int isSubstring(string s1, string s2)
{
    int M = s1.length();
    int N = s2.length();
 
    /* A loop to slide pat[] one by one */
    for (int i = 0; i <= N - M; i++) {
        int j;
 
        /* For current index i, check for
 pattern match */
        for (j = 0; j < M; j++)
            if (s2[i + j] != s1[j])
                break;
 
        if (j == M)
            return i;
    }
 
    return -1;
}

void updateEverything()
{
    Customer_File.open("data.txt", ios::out);
    for(int i=0; i < manage.size(); i++)
    {
        Customer_File << manage[i].id << " ";
        Customer_File << manage[i].name << " ";
        Customer_File << manage[i].email << " ";
        Customer_File << manage[i].phone << " ";
        Customer_File << manage[i].bill << endl;
    }
}

void addNewCustomer()
{
    string data;
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

void findACustomer()
{
    string data;
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