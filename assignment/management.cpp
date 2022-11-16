#include "management.h"

void Warning()
{
    if(manage.size() == 0)
    {
        warning_flag = true;
        cout << "\nThere are not any customers in database.\n";
        cout << "PLEASE LOAD DATA FROM FILE OR ADD NEW CUSTOMER FIRST!\n";
    }
}

vector<string> Tokenize(string s, string del)
{
    vector<string> wordInLine;
	int start, end = -1*del.size();
	do {
		start = end + del.size();
		end = s.find(del, start);
		wordInLine.push_back(s.substr(start, end - start));
	} while (end != -1);
    return wordInLine;
}

void LoadData()
{
    Customer_File.open("data.txt", ios::in);
    if(Customer_File.fail())
    {
        cout << "\nFail to open this file.\n"
             << "Please check your file and try again later.\n";
    }
    /*
        Read file line by line and split each word using character '$'
    */
    if(Customer_File.is_open())
    {
        string line, word;
        while(getline(Customer_File, line))
        {
            vector<string> wordInLine;
            wordInLine = Tokenize(line, "$");

            customerManagement tmp;

            tmp.id = wordInLine[0];
            tmp.name = wordInLine[1];
            tmp.email = wordInLine[2];
            tmp.phone = wordInLine[3];
            tmp.balance = wordInLine[4];
            
            manage.push_back(tmp);

            wordInLine.clear();

            numOfCus+=1;
        }
    }
    cout << "\nLoading data successfully.\n";
    Customer_File.close();
}

void OptionDisplay()
{
    cout << "\nAvailable operations: \n"
         << "1. Load Data.\n"
         << "2. Add New Customer.\n"
         << "3. Find Customer.\n"
         << "4. Modify A Customer.\n"
         << "5. Delete A Customer.\n"
         << "6. Update Everything.\n"
         << "7. Exit\n"
         << "Current Number Of Customers: " << numOfCus << '\n'
         << "Enter option: ";
}

void FindingOptionDisplay()
{
    Warning();
    if(option == 3 || option == 5 )
    {
        cout << "\n1. By ID.\n"
             << "2. By Name.\n"
             << "3. By Email.\n"
             << "4. By Phone Number.\nEnter your choice: ";
    }
    else if (option == 4 )
    {
        cout << "\n1. Name.\n"
             << "2. Email.\n"
             << "3. Phone Number.\n"
             << "4. Balance.\nEnter your choice: ";
    }
}

bool Valid_id(string data)
{
    if(manage.size() == 0)  return true;
    for(int i=0; i < manage.size(); i++)
    {
        if(data == manage[i].id)
        {
            return false;
        }
    }
    return true;
}

bool Valid_email(string data)
{
     // Regular expression definition
    const regex pattern("(\\w+)(\\.|_)?(\\w*)@(\\w+)(\\.(\\w+))+");
  
    // Match the string pattern
    // with regular expression
    return regex_match(data, pattern);
}

bool Valid_phone(string data)
{
    if(data[0] != '0' || data.size() != 10)    
        return false;

    return true;
}

int IsSubstring(string s1, string s2)
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

void UpdateEverything()
{
    Customer_File.open("data.txt", ios::out);
    for(int i=0; i < manage.size(); i++)
    {
        Customer_File << manage[i].id << "$";
        Customer_File << manage[i].name << "$";
        Customer_File << manage[i].email << "$";
        Customer_File << manage[i].phone << "$";
        Customer_File << manage[i].balance;
        Customer_File << '\n';
    }
    cout << "\nUpdating successfully.\n";
    Customer_File.close();
}

void AddNewCustomer()
{
    string data;
    customerManagement newCus;

addNewCusID:
    cout << "Enter ID: ";
    cin >> data;
    if(Valid_id(data)) {newCus.id = data;}
    else 
    {
        cout << "INVALID ID!\n";
        goto addNewCusID;
    }

    cout << "Enter Name: \n";
    cin.ignore();
    getline(cin, data);       
    newCus.name = data;

addNewCusEmail:
    cout << "Enter Email Address: ";
    cin >> data;
    if(Valid_email(data)) {newCus.email = data;}
    else
    {
        cout << "INVALID EMAIL ADDRESS!\n";
        goto addNewCusEmail;
    }

addNewCusPhone:
    cout << "Enter Phone Number: ";
    cin >> data;
    if(Valid_phone(data)) {newCus.phone = data;}
    else
    {
        cout << "INVALID PHONE NUMBER!\n";
        goto addNewCusPhone;
    }

    cout << "Enter Balance (NUMBER ONLY): ";
    cin >> data;
    newCus.balance = data;

    manage.push_back(newCus);
    numOfCus+=1;
}

void FindCustomer()
{
    string data;
    Warning();
    if(warning_flag)    {return;}

    int finding;
    FindingOptionDisplay();
    cin >> finding;
tryFindAgain:
    switch (finding)
    {
    case 1:
        cout << "Enter ID: ";
        cin >> data;
        break;
            
    case 2:
        cout << "Enter Name: \n";
        cin.ignore();
        getline(cin, data);
        break;

    case 3:
        cout << "Enter A Email Address: ";
        cin >> data;
        if(!Valid_email(data)) {goto notMatchingCriteria;}
        break;

    case 4:
        cout << "Enter A Phone Number: ";
        cin >> data;
        if(!Valid_phone(data)) {goto notMatchingCriteria;}
        break;
            
notMatchingCriteria:
    default:
        int again;
        cout << "\nDo you want to continue?\n"
             << "1. YES\n"
             << "2. NO\nEnter your choice: ";
        cin >> again;
        if(again == 1)
        {
            goto tryFindAgain;
        } else break;
    }
    vector<customerManagement> resultFinding = FindCustomer_Handler(finding, data);
    if(resultFinding.size() == 0)
    {
        cout << "There are any customers who have ";
        switch (finding)
        {
        case 1:
            cout << "ID: ";
            break;
        case 2: 
            cout << "name: ";
            break;
        case 3: 
            cout << "email: ";
            break;
        case 4:
            cout << "phone number: ";
        }
        cout << data << endl;
        return;
    }
    for(int i=0; i < resultFinding.size(); i++)
    {
        cout << "Result " << i + 1 << endl;
        cout << "ID: " << resultFinding[i].id << endl;
        cout << "NAME: " << resultFinding[i].name << endl;
        cout << "Email Address: " << resultFinding[i].email << endl;
        cout << "Phone Number: " << resultFinding[i].phone << endl;
        cout << "Balance: " << resultFinding[i].balance << " VND" << endl;
    }

    if(option == 5 && resultFinding.size() != 0)
    {
        DeleteCustomer_Handler(resultFinding);
    }
}

vector<customerManagement> FindCustomer_Handler(int finding, string data)
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
            if(IsSubstring(data, manage[i].name) != -1)
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
    cout << "\nFinding successfully!\n";
    return resultFinding;
}

void ModifyCustomer()
{
    if(manage.size() == 0)
    {
        Warning();
        return;
    }
    int finding;
    string id, data;
tryEnterIDAgain:
    cout << "\nPlease enter ID: ";
    cin.ignore();
    cin >> id;
    if(Valid_id(id))
    {
        cout << "Invalid ID.\n";
        goto tryEnterIDAgain;
    }
    FindingOptionDisplay();
    cin >> finding;
tryModifyAgain:
    switch (finding)
    {
    case 1:
        cout << "Enter Name: \n";
        cin.ignore();
        getline(cin, data);
        break;

    case 2:
        cout << "Enter A Email Address: ";
        cin >> data;
        if(!Valid_email(data)) {goto notMatchingCriteria;}
        break;

    case 3:
        cout << "Enter A Phone Number: ";
        cin >> data;
        if(!Valid_phone(data)) {goto notMatchingCriteria;}
        break;

    case 4:
        cout << "Enter Balance Value: ";
        cin >> data;
        break;

notMatchingCriteria:
    default:
        int again;
        cout << "Do you want to continue?\n"
             << "1. YES\n"
             << "2. NO\nEnter your choice: ";
        cin >> again;
        if(again == 1)
        {
            goto tryModifyAgain;
        } else break;
    }

    ModifyCustomer_Handler(finding, id, data);
}

void ModifyCustomer_Handler(int finding, string id_find, string data)
{
    for(int i=0; i < manage.size(); i++)
    {
        if(id_find == manage[i].id)
        {
            switch (finding)
            {
            case 1:
                manage[i].name = data;
                break;
            case 2:
                manage[i].email = data;
                break;
            case 3:
                manage[i].phone = data;
                break;
            case 4:
                manage[i].balance = data;
                break;
            }
            break;
        }
    }
    cout << "\nModifying successfully.\n";
}

void DeleteCustomer()
{
    cout << "Delete Customer Option\n";
    FindCustomer();
}

void DeleteWarning()
{
    cout << "\nAre you sure you want to delete this customer?\n"
         << "1. YES\n"
         << "2. NO\n";
}

void DeleteCustomer_Handler(vector<customerManagement> resultFinding)
{
    if(resultFinding.size() == 1)
    {
        DeleteWarning();
        int optionDelete;
        cin >> optionDelete;
        if(optionDelete == 1)
        {
            for(int i=0; i < manage.size(); i++) 
            {
                if(resultFinding[0].id == manage[i].id)
                {
                    manage.erase(manage.begin() + i);
                    cout << "Deleting Customer successfully.\n";
                    break;
                } 
            }
        } else return;
    }

    if(resultFinding.size() != 1) 
    {
        cout << "Which customer do you want to delete?\n"
            << "Enter the number reference with finding result above:\n";
        int optionDelete;
        cin >> optionDelete;
        for(int i=0; i < manage.size(); i++)
        {
            if(resultFinding[optionDelete-1].id == manage[i].id)
            {
                manage.erase(manage.begin() + i);
                cout << "Deleting Customer successfully.\n";
                break;
            } 
        }
    }
}
