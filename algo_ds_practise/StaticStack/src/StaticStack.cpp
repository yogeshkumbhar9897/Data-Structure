//============================================================================
// Name        : StaticStack.cpp
// Author      : yogesh kumbhar
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
#define size 5
#include<cstdlib>

class stack
{
private :
	int arr[size];
	int top;

public:
	stack(void)
	{
		this->top=-1;
	}

	bool is_stack_empty()
	{
		return ( this->top == -1 );
	}

    bool is_stack_full()
    {
    	return ( this->top == size - 1 );

    }

    void push(int data)
    {
    	this->top++;
    	this->arr[this->top] = data;


    }
    void pop()
    {
    	this->top--;
    }

    int peek()
    {
    	return ( this->arr[this->top] );
    }
};
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
	stack s;
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
				if(!s.is_stack_full())
				{
					cout<<"Enter element to add in Stack :"<<endl;
					cin>>element;
					s.push(element);
					cout<<element<<"inserted into Stack successfully..."<<endl;
				}
				else
					cout<<"Stack is full..."<<endl;
					break;

		case 2:
				if(!s.is_stack_empty())
				{
					element = s.peek();
					s.pop();
					cout<<element<<"Deleted from stack successfully..."<<endl;
				}
				else
				cout<<"Stack is empty..."<<endl;
				break;
		case 3:
				if(! s.is_stack_empty())
				{
				cout<<"Topmost element is :"<<s.peek()<<endl;
				}
				else
					cout<<"Stack is Empty"<<endl;
				break;
		}
	}


	return 0;
}
