//============================================================================
// Name        : empsort.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
#include<iomanip>
#include<cstdlib>

class list;
class node;
class employee
{
private:
		int empid;
		string name;
		float salary;

public:
		employee(void)
		{
			this->empid=0;
			this->name=" ";
			this->salary=0.0;

		}
		employee(employee& other)
		{
			this->empid=other.empid;
			this->name=other.name;
			this->salary=other.salary;
		}

		friend istream& operator>>(istream& in , employee& emp )
		{
			cout<<"Enter Employee id:";
			cin>>emp.empid;

			cout<<"Enter Name:";
			cin>>emp.name;

			cout<<"Enter Salary:";
			cin>>emp.salary;

			return in;
		}

		friend ostream& operator<<(ostream& out ,const  employee& emp )
		{
			cout<<emp.empid<<"\t";

			cout<<emp.name<<"\t";

			cout<<emp.salary<<endl;

			return out;
				}
		friend class node;
		friend class list;

};

class node
{
private:
	employee data;
	node *prev;
	node *next;

public:
	node(employee &data)
	{
		this->data=data;
		this->prev=NULL;
		this->next=NULL;
	}
friend class list;

};

class list
{
private:
	node *head;
	int cnt;
public:
	list(void)
	{
		this->head = NULL;
		this->cnt = 0;
	}

	bool is_list_empty(void)
	{
		return ( this->head == NULL );
	}

	int get_cnt(void)const
	{
		return ( this->cnt );
	}

	void add_node_at_last_position(employee data)
	{
		node *newnode = new node(data);
		if( is_list_empty() )
		{
			head = newnode;
			newnode->next = newnode;
			newnode->prev = head;
			this->cnt++;
		}
		else
		{

			newnode->next = head;
			newnode->prev = head->prev;
			head->prev->next = newnode;
			head->prev = newnode;
			this->cnt++;
		}
	}

	void add_node_at_first_position(employee data)
		{
			node *newnode = new node(data);
			if( is_list_empty() )
			{
				head = newnode;
				newnode->next = newnode;
				newnode->prev = head;
				this->cnt++;
			}
			else
			{
				newnode->next = head;
				newnode->prev = head->prev;
				head->prev = newnode;
				head = newnode;
				head->prev->next = head;
				this->cnt++;
			}
		}


	void display_list(void)
	{
		if( !is_list_empty() )
		{
			node *trav = head;
			cout << "\tEmpid\tName\tSalary"<<endl;
			do{
				cout <<"\t"<<trav->data<<"  ";
				trav = trav->next;
			}while( trav != head );


		}
		else
			cout << "list is empty !!!" << endl;
	}

	void delete_node_at_last_position(void)
	{

		if( !is_list_empty())
		{
			if( head == head->next )
			{
				delete head;
				head = NULL;
				this->cnt = 0;
			}
			else
			{
				head->prev = head->prev->prev;
				delete head->prev->next;
				head->prev->next = head;
				this->cnt--;
			}
		}
		else
			cout << "list is empty !!!" << endl;
	}
	~list(void)
	{
		if( !is_list_empty() )
			free_list();
		else
			cout << "list is empty !!!" << endl;
	}

	void sort(void) // wrapper function
	{
		if(!is_list_empty())
		{
			sort(head);
		}
		else
		cout<<"list is empty";
	}

	void sort(node *trav)
	{
		cout<<"sorting";


		for(node *trav1 = trav; trav1 != trav->prev; trav1 = trav1->next )
		{
			for(node *trav2 = trav1->next ; trav2 != trav ; trav2 = trav2->next)
			{
				if(trav1->data.empid > trav2->data.empid)
				{
					employee temp;
					temp= trav1->data;
					trav1->data= trav2->data;
					trav2->data = temp;
				}

			}

		}




	}
private:
	void free_list(void)
	{
		while( !is_list_empty())
			delete_node_at_last_position();
		cout << "list freed successfully..." << endl;
	}


};

int menu(void)
{
	int choice;
	cout<<"\n";
	cout << "0. EXIT" << endl;
	cout << "1. ADD EMPLOYEE AT LAST POSITION" << endl;
	cout << "2. ADD EMPLOYEE AT FIRST POSITION" << endl;
	cout << "3. DELETE LAST EMPLOYEE" << endl;
	cout << "4. DISPLAY LIST" << endl;
	cout << "5. SORT RECORD"  << endl;
	cout << "ENTER THE CHOICE: "<<endl;
	cin >> choice;

	return choice;
}

int main(void)
{
	list l1;
	employee emp;

	while(1)
	{
		int choice = menu();
		switch(choice)
		{
		case 0:
			l1.~list();
			exit(0);
		case 1:
			cin >>emp;
			l1.add_node_at_last_position(emp);
			break;

		case 2:
			cin>>emp;
			l1.add_node_at_first_position(emp);
			break;

		case 3:
			l1.delete_node_at_last_position();
			break;

		case 4:
			l1.display_list();
			break;

		case 5:
			l1.sort();

			break;

		}//end of switch control block

	}//end of while loop

	return 0;
}//end of main

