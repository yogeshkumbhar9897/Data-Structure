//============================================================================
// Name        : scll.cpp
// Author      : yogesh kumbhar
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
#include<iomanip>
#include<cstdlib>

class list;

class node
{
int data;
node *next;

public:

	node(int data)
	{
		this->data=data;
		this->next=NULL;
	}
friend class list;
};

class list
{
node *head;
int cnt;

public:

	list(void)
	{
		this->head=NULL;
		this->cnt = 0;
	}
		bool is_list_empty(void)
		{
			return (this->head == NULL);

		}

		int get_cnt(void)
		{
			return cnt;
		}

		void add_node_at_first_position(int data)
		{
				node *newnode = new node(data);
			if( is_list_empty() )
			{
				head = newnode;
				newnode->next = head;
				this->cnt++;
			}
			else
			{
				newnode->next = head;
				head = newnode;
				this->cnt++;
			}

		}	
		void add_node_at_last_position(int data)
		{
			node *newnode = new node(data);
			if( is_list_empty() )
			{
				head = newnode;
				newnode->next=head;
				this->cnt++;
			}
			else
			{
				node *trav = head;
				while(trav->next != head )
				{
					trav = trav->next;
				}
				trav->next = newnode;
				newnode->next=head;
				this->cnt++;
			}
		}

		void add_node_at_specific_position(int data , int position)
		{
			if(position == 1)
				add_node_at_first_position(data);
			else if(position == get_cnt() + 1)
					add_node_at_last_position(data);
			else
			{
				node *newnode = new node(data);
				node *trav = head;
				int i=1;
				while( i < position -1)
				{
					i++;
					trav=trav->next;
				}
				newnode->next = trav->next;
				trav->next = newnode;
				this->cnt++;

			}

		}
		void delete_node_at_first_position()
		{
			if(!is_list_empty())
			{
					if( head == head->next )
					{
						delete head;
						head = NULL;
						this->cnt=0;

					}
					else
					{
						node *temp = head;
						head=head->next;
						delete temp;
						temp = NULL;
						this->cnt--;

					/*	node *trav = head;
						while(trav->next != head)
						{
							trav = trav->next;
						}
						head = head->next;
						 delete trav->next;
						 trav->next =  head;
						 this->cnt--;*/

					}
			}

		}
		void delete_node_at_last_position()
		{
			if(! is_list_empty())
			 {
				if(head == head->next)
				 {
					delete head;
					head = NULL;
					this->cnt=0;
				 }
				else
				 {
					node *trav = head;
					while(trav->next->next != head)
					{
						trav= trav->next;
					}
					delete trav->next;
					trav->next = head;
					this->cnt--;
				 }
			}
			else
				cout<<"List is Empty...!!!";

		}
		void delete_node_at_specific_position(int position)
		{
			if(position == 1)
				delete_node_at_first_position();
			else if( position == get_cnt() )
					delete_node_at_last_position();
			else
			{
				node *trav = head;
				int i=1;
				while(i<position-1)
				{
					i++;
					trav = trav->next;
				}
				node *temp = trav->next;
				trav->next = trav->next->next;
				delete temp;
				temp = NULL;
				this->cnt--;
			}
		}
		void display_list(void)
		{
			if( ! is_list_empty())
			{
					node *trav = head;
					cout<<"head -> ";
					do
					{
						cout<<trav->data;
						cout<<"-> ";
						trav = trav->next;
					}while(trav != head);
					cout<<"NULL"<<endl;
			}
			else
				cout<<"List is Empty...!!!";
		}
			~list(void)
			{
				if(!is_list_empty())
					free_list();
				return;
			}

			void free_list()
			{
				while(is_list_empty())
					delete_node_at_first_position();
				cout<<"List Freed Successfully...!!!"<<endl;
			}

};



int menu(void)
{
	int choice;

	cout << "0. EXIT" << endl;
	cout << "1. ADDLAST" << endl;
	cout << "2. ADDFIRST" << endl;
	cout << "3. ADDATPOS" << endl;
	cout << "4. DELFIRST" << endl;
	cout << "5. DELLAST" << endl;
	cout << "6. DELATPOS" << endl;
	cout << "7. DISPLAY" << endl;
	cout << "ENTER THE CHOICE: ";
	cin >> choice;

	return choice;
}

int main(void)
	{
	list l1;
	int choice,data,position;

		while(1)
		{
			choice = menu();
			switch(choice)
			{
			case 0:
					l1.~list();
				break;
			case 1:
					cout<<"Enter the data :";
					cin>>data;
					l1.add_node_at_last_position(data);
				break;

			case 2:
				cout<<"Enter the data :";
				cin>>data;
				l1.add_node_at_first_position(data);

				break;

			case 3:
				cout<<"Enter the data :";
				cin>>data;
				cout<<"Enter the position Where you want to insert element :";
				cin>>position;
				l1.add_node_at_specific_position(data,position);

				break;

			case 4:
					l1.delete_node_at_first_position();
				break;

			case 5:
				l1.delete_node_at_last_position();
				break;

			case 6:
				cout<<"Enter the position from Where you want to delete element :";
				cin>>position;
				l1.delete_node_at_specific_position(position);
				break;

			case 7:
					l1.display_list();
				break;

			}



		}

		return 0;
}

