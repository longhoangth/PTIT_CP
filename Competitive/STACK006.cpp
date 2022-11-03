// postfix to infix conversion
/*
    Author: Long Hoang Thanh 
    Date: 3/11/2022
*/
#include<iostream>
#include<stack>
using namespace std;
int t;

// function to check if character is operator or not
bool isOperator(char x)
{
	switch (x) {
	case '+':
	case '-':
	case '/':
	case '*':
		return true;
	}
	return false;
}

string postfix2InfixConversion(string postfix_exp)
{
    stack<string> s;
    int length = postfix_exp.length();
    for(int i=0; i < length; i++)
    {
        if(isOperator(postfix_exp[i]))
        {
            string operand1 = s.top();
            s.pop();
            string operand2 = s.top();
            s.pop();
            string temp = "(" + operand2 + postfix_exp[i] + operand1 + ")";

            s.push(temp);
        } else {
            s.push(string(1, postfix_exp[i]));
        }
    }

    return s.top();
}

int main()
{
    cin >> t;
    while(t--)
    {
        string postfix_exp;
        cin >> postfix_exp;
        cout << postfix2InfixConversion(postfix_exp) << endl;
    }
}