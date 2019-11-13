//============================================================================
// Name        : slll.cpp
// Author      : yogesh kumbhar
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
#include <iomanip>
#include<cstdlib>

class list;

class node
{
	int data;
	node *next;
public:

  node(int data);

friend class list;
};
class list
{
private:
	node *head;
	int cnt;

public:
	list(void);
	bool is_list_empty(void);
	int get_cnt(void);
	void add_node_at_first_position(int data);
	void add_node_at_last_position(int data);
	void add_node_at_specific_position(int data , int position);
	void delete_node_at_first_position();
	void delete_node_at_last_position();
	void delete_node_at_specific_position(int position);
	void display_reverse(node *trav);
	void display_reverse(void);
	void reverse_list(void);
	void display_list(void);
	~list(void);

private:

		void free_list(void);

};

node::node(int data)
{
	this->data = data;
	this->next = NULL;
}

list::list()
{
	this->head=NULL;
	this->cnt=0;
}

bool list::is_list_empty(void)
{
	return (this->head == NULL);
}

int list::get_cnt(void)
{
	return (this->cnt);
}

void list::add_node_at_last_position(int data)
{
		//create a newnode - allocate memory dynamically for node & initialize its members
		node *newnode = new node(data);
		//if list is empty -- then attach newly created node to the head
		if( is_list_empty() )
		{
				//store the addr of newly created node into the head
			head=newnode;
			this->cnt++;
		}
		else		//if list is not empty
		{
			//start traversal of list from first node
			node *trav = head;

			//traverse the list till last node
			while(trav->next != NULL)

			//move trav pointer to its next node
				trav=trav->next;

				//attach newly created node to the last node
				//i.e. store the addr of newly created node into the next part of last node
				trav->next =newnode;
				this->cnt++;

		}
	}
void list::add_node_at_first_position(int data)
{
	//create a newnode - allocate memory dynamically for node & initialize its members
		node *newnode = new node(data);

	//if list is empty -- then attach newly created node to the head
		if( is_list_empty() )
		{
				//store the addr of newly created node into the head
			head  = newnode;
			this->cnt++;
				}
		else//if list is not empty
		{
				//store the addr cur first node into the next part of newly created node
			newnode->next = head;
				//attach newly created node to the head i.e. store the addr of newly
				//created node into the head
			head = newnode;
			this->cnt++;

		}
}
void list::add_node_at_specific_position(int data,int position)
{
	if(position == 1)//pos is the first pos
	{
		add_node_at_first_position(data);
	}else
		if(position == get_cnt()+1 ) //pos is the last position
		{
			add_node_at_last_position(data);
		}
		else//pos is in between position
		{
	//create a newnode
			node *newnode = new node(data);
			node *trav = head;//start traversal from the first node
			int i = 1;
			while( i < position - 1 )//traverse list till (pos-1)th node
			{
				i++;
				trav = trav->next;

			}

	//store the addr of cur (pos)th node into the next part of newly created node
			newnode->next=trav->next;
//store the addr of newly created node into the next part of (pos-1)th node
			trav->next=newnode;
			this->cnt++;
		}
}
void list::delete_node_at_first_position()
{
	//if list is not empty
	if( ! is_list_empty() )
	{
		//if list contains only one node
		if( head->next == NULL )
		{

			delete head;	//delete the node and make head as NULL & cnt as 0
			head = NULL;
			this->cnt =0;
		}
			else	//if list contains more than one nodes
			{

				//store the addr of first node into a temp
				node *temp = head;
				//store the addr of cur second node into the head
				head = head->next;

				//delete the node
				delete temp;
				temp=NULL;
				this->cnt--;

		}
	}
		else
			cout<<"List is Empty...!!!";


}
void list::delete_node_at_last_position()
{
	//if list is not empty
	if(! is_list_empty() )
	{
		if( head->next == NULL)//if list contains only one node
		{
			delete head;
			head = NULL; //delete the node and make head as NULL & cnt as 0
			this->cnt=0;
		}
		else//if list contains more than one nodes
		{
			node *trav = head;//start traversal from first node


			while(trav->next->next != NULL)//traverse the list till second last node
			{
				trav = trav->next;
			}
			delete trav->next;
						trav->next = NULL;
						this->cnt--;

	//delete the last node

	//make next part second last node as NULL
		}
	}
	else
		cout<<"list is Empty...!!!";

}
void list::delete_node_at_specific_position(int position)
{
	if(position == 1)
	{
		delete_node_at_first_position();
	}
	else
		if( position == get_cnt())
		{
			delete_node_at_last_position();
		}
		else
		{
			node *trav =head;
			int i=1;
			while(i < position - 1)
			{
				i++;
				trav=trav->next;
			}

			node *temp = trav->next;
			trav->next = trav->next->next;
			delete temp;
			temp = NULL;
			this->cnt--;
		}
}

void list::display_list()
{
	if( !is_list_empty() )
	{
		node *trav = head;
		cout<<"Total Nodes are :"<<get_cnt()<<endl;
		cout<<"Head -> ";
		while ( trav != NULL)
		{
			cout<<trav->data<<"-> ";
			trav = trav->next;

		}
		cout<<"NULL"<<endl;
	}
	else
		cout<<"List is Empty";

}

void list::display_reverse(node *trav)
{

	if(trav == NULL)
		return;
	display_reverse(trav->next);
	cout<<trav->data;
}

void list::display_reverse(void)
{
	if( !is_list_empty() )
		{
		cout<<"Reverse list is :";
		display_reverse(this->head);
		cout<<endl;
		}
	else
		cout<<"List is Empty";

}

list::~list(void)
{
	if( !is_list_empty() )
	free_list();
	else
		cout<<"List is Empty"<<endl;

}

void list::free_list(void)
{
	while( ! is_list_empty() )
		delete_node_at_last_position();
	cout<<"List Freed Successfully...!!!"<<endl;
}

void list::reverse_list()
{
	if( !is_list_empty() )
	{
		node *t1=head;
		node *t2 = t1->next;
		t1->next = NULL;

		while(t2 != NULL)
		{
			node *t3 = t2->next;
			t2->next = t1;
			t1 = t2;
			t2 = t3;

		}
		head = t1;

	}

}

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
	cout << "8. DISPREV" << endl;
	cout << "9. REVERSE" << endl;
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

			case 8:
					l1.reverse_list();
				break;

			case 9:
					l1.reverse_list();
				break;
			}



		}

		return 0;
}
