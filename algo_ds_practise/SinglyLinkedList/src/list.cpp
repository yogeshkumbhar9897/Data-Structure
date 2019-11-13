/*
 * list.cpp
 *
 *  Created on: 29-Sep-2019
 *      Author: sunbeam
 */
/*#include<iostream>
using namespace std;
#include<iomanip>
#include"list.h"
#include<cstdlib>

list::list()
{
	this->head=NULL;
	this->cnt=0;
}

bool list::is_list_empty(void)
{
	return (this->head == NULL);
}

int list::cnt_nodes(void)
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
			this->cnt;

		}
}
void list::add_node_at_specific_position(int data,int position)
{
	if(position == 1)//pos is the first pos
	{
		add_node_at_first_position(data);
	}else
		if(position == get_cnt())//pos is the last position
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
			head == NULL; //delete the node and make head as NULL & cnt as 0
			this->cnt=0;
		}
		else//if list contains more than one nodes
		{
			node *trav = head;//start traversal from first node


			while(trav->next->next == NULL)//traverse the list till second last node
				trav = trav->next;

	//delete the last node
			delete trav->next;
			trav->next = NULL;
			this->cnt--;
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
		cout<<"NULL";
	}
	else
		cout<<"List is Empty";

}


*/
