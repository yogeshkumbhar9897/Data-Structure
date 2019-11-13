//============================================================================
// Name        : DynamicQueue.cpp
// Author      : yogesh kumbhar
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
#include<cstdlib>
#include<queue>


int menu(void)
{
int choice;

	cout<<"0.Exit "<<endl;
	cout<<"1.Enqueue "<<endl;
	cout<<"2.Dequeue "<<endl;
	cout<<"Enter your choice :"<<endl;
	cin>>choice;
return choice;
}

int main()
{
		cout<<"Dynamic Queue "<<endl;
	queue <int> q;
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
					cout<<"Enter element to add in queue :"<<endl;
					cin>>element;
					q.push(element);
					cout<<element<<" is inserted into queue successfully..."<<endl;

					break;

		case 2:
				if(!q.empty())
				{
					element = q.front();
					q.pop();
					cout<<element<<" is Deleted from queue successfully..."<<endl;
				}
				else
				cout<<"Queue is empty..."<<endl;
				break;
		}
	}


	return 0;
}
