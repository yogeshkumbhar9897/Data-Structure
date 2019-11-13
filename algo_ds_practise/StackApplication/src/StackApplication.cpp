//============================================================================
// Name        : StackApplication.cpp
// Author      : yogesh kumbhar
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include<iostream>
#include<stack>
using namespace std;
#include<iomanip>
#include<cstring>

void infix_to_postfix(char *in ,char *post);

int main(void)
{
	char infix[64] = "(a*b)*(c+d)/e*f-g*h";
	char postfix[64]= " ";

	cout<<"Infix Expression is :"<<infix<<endl;

		infix_to_postfix(infix , postfix);
		cout<<"Postfix Expression is :"<<postfix<<endl;

return 0;
}

void infix_to_postfix(char *in ,char *post)
{
	stack<int> s;

	int j=0;

	for(int i=0; i != '\0'; i++)
	{

		;
	}

}
