//============================================================================
// Name        : DynamicStack.cpp
// Author      : yogesh kumbhar
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
#include<cstdlib>
#include<stack>
int menu(void)
{
int choice;

	cout<<"0.Exit "<<endl;
	cout<<"1.push "<<endl;
	cout<<"2.pop "<<endl;
	cout<<"3.peek "<<endl;
	cout<<"Enter your choice :"<<endl;
	cin>>choice;
return choice;
}

int main()
{
	stack<int> s;
	int choice,element;

	while(1)
	{
		choice = menu();

		switch(choice)
		{
		case 0 :
				exit(0);
				break;

		case 1 :

					cout<<"Enter element to add in Stack :"<<endl;
					cin>>element;
					s.push(element);
					cout<<element<<"inserted into Stack successfully..."<<endl;

					break;

		case 2:
				if(!s.empty())
				{
					element = s.top();
					s.pop();
					cout<<element<<"Deleted from stack successfully..."<<endl;
				}
				else
				cout<<"Stack is empty..."<<endl;
				break;
		case 3:
				if(! s.empty())
				{
				cout<<"Topmost element is :"<<s.top()<<endl;
				}
				else
					cout<<"Stack is Empty"<<endl;
				break;
		}
	}


	return 0;
}
