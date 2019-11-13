/*
 * node.h
 *
 *  Created on: 30-Sep-2019
 *      Author: sunbeam
 */

#ifndef NODE_H_
#define NODE_H_


class list;

class node
{
	int data;
	node *next;
public:

  node(int data);

friend class list;
};



#endif /* NODE_H_ */
