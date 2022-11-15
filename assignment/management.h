#pragma once

#ifndef _MANAGEMENT_H_
#define _MANAGEMENT_H_

#include<iostream>
#include<fstream>
#include<vector>
#include<regex>
#include<sstream>
#include<string>

using namespace std;

class customerManagement
{
    public:
        string id, name, email, phone, balance;
};

extern vector<customerManagement> manage;
extern fstream Customer_File;
extern int numOfCus;
extern int option;
extern bool warning_flag;

void OptionDisplay();
void FindingOptionDisplay();
vector<string> Tokenize(string s, string del);
void LoadData();

bool Valid_id(string data);
bool Valid_email(string data);
bool Valid_phone(string data);
int IsSubstring(string s1, string s2);

void Warning();
void UpdateEverything();
void AddNewCustomer();
string newCustomerNameInput();

void FindCustomer();
vector<customerManagement> FindCustomer_Handler(int finding, string data);

void ModifyCustomer();
void ModifyCustomer_Handler(int finding, string id_find, string data);

void DeleteCustomer();
void DeleteWarning();
void DeleteCustomer_Handler(vector<customerManagement> resultFinding);

#endif
