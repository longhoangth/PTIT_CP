#pragma once

#ifndef _MANAGEMENT_H_
#define _MANAGEMENT_H_

#include<iostream>
#include<fstream>
#include<vector>
#include<regex>

using namespace std;

class customerManagement
{
    public:
        string id, name, email, phone, bill;
};

extern vector<customerManagement> manage;
extern fstream Customer_File;
extern int numOfCus;
extern int option;

void optionDisplay();
void findingOptionDisplay();
void loadData();

bool valid_id(string data);
bool valid_email(string data);
bool valid_phone(string data);
int isSubstring(string s1, string s2);
void findingOperation(int finding, string data);
void warning();
void updateEverything();
void addNewCustomer();
void findACustomer();

#endif
