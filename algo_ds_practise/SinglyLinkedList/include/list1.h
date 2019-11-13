/*
 * list.h
 *
 *  Created on: 29-Sep-2019
 *      Author: sunbeam
 */

#ifndef LIST1_H_
#define LIST1_H_
#include "node.h"

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
	int cnt_nodes(void);
	~list(void);

/*private:

		void free_list(void);*/

};


#endif /* LIST_H1_ */

