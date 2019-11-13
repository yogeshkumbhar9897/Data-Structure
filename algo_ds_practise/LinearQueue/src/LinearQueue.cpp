//============================================================================
// Name        : LinearQueue.cpp
// Author      : yogesh kumbhar
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
#include<iomanip>
#include<cstdlib>

#define size 5

class queue
{
int arr[size];
int rear;
int front;

public:
	queue(void)
	{
		this->rear=-1;
		this->front=-1;
	}

	bool is_queue_empty()
	{
		return (  this->rear == -1 || this->front > this->rear);
	}

	bool is_queue_full()
	{
		return ( this->rear == size-1  );
	}

	void enqueue(int data)
	{
		this->rear++;
		this->arr[this->rear] = data;
		if(front == -1)
			front = 0;
	}

	void dequeue(void)
	{
		this->front++;
	}

	int get_front(void)
	{
		return this->arr[this->front];
	}



};

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
	queue q;
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
				if(!q.is_queue_full())
				{
					cout<<"Enter element to add in queue :"<<endl;
					cin>>element;
					q.enqueue(element);
					cout<<element<<"inserted into queue successfully..."<<endl;
				}
				else
					cout<<"Queue is full..."<<endl;
					break;

		case 2:
				if(!q.is_queue_empty())
				{
					element = q.get_front();
					q.dequeue();
					cout<<element<<"Deleted from queue successfully..."<<endl;
				}
				else
				cout<<"Queue is empty..."<<endl;
				break;
		}
	}


	return 0;
}
