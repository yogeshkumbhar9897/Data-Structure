//============================================================================
// Name        : BST.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
#include<iomanip>
#include<stack>
#include<queue>

class bst;
class node
{
int data;
node *left;
node *right;

public:

		node(int data)
		{
		this->data=data;
		this->left=NULL;
		this->right=NULL;
		}

		friend class bst;
};

class bst
{
private:
	node *root;
public:
	bst(void)
{
		this->root=NULL;
}
	bool is_empty()
	{
		return (this->root == NULL);
	}
	void add_node(int data)
	{
		node *newnode = new node(data);
		if(is_empty())
		{
			root = newnode;
		}
		else
		{
			node *trav=root;
			while(1)
			{
				if(data < trav->data)
				{
					if(trav->left == NULL)
					{
						trav->left = newnode;
						break;

					}
					else
						trav=trav->left;

				}
				else
				{
					if(trav->right == NULL)
					{
						trav->right=newnode;
						break;
					}
					else
						trav=trav->right;
				}
			}//end of while

		}//end else
	}//end add_node

	void preorder(void)//Wrapper Function
	{
		if(!is_empty())
		{
			cout<<"PREORDER : ";
			preorder(root);
			cout<<endl;
		}
		else
			cout<<"Empty...";

	}

		void preorder(node *trav)
		{
			if(trav == NULL)
			return;

			cout<<setw(4)<<left<<trav->data;
			preorder(trav->left);
			preorder(trav->right);

		}

		void postorder(void)
		{
			if(!is_empty())
			{
				cout<<"POSTORDER : ";
				postorder(root);
				cout<<endl;
			}
			else
				cout<<"Empty...";
		}

		void postorder(node *trav)
		{
			if(trav == NULL)
				return;

			postorder(trav->left);
			postorder(trav->right);
			cout<<setw(4)<<left<<trav->data;
		}

		void inorder(void)
		{
			if(!is_empty())
			{
				cout<<"INORDER : ";
				inorder(root);
				cout<<endl;

			}
			else
				cout<<"Empty...";
		}

		void inorder(node *trav)
		{
			if(trav == NULL)
				return;

			inorder(trav->left);
			cout<<setw(4)<<left<<trav->data;
			inorder(trav->right);
		}

void dfs_traversal()
{
	if(is_empty())
		return;

	stack<node *> s;
	//step1: push root node into the stack
	s.push(root);
	cout<<"DFS : ";
	while(!s.empty())
	{
	//step2: pop the node from the stack and visit it
		node *trav = s.top(); s.pop();
		cout<<setw(4)<<left<<trav->data;
	//step3: if the cur node having right child push it into the stack
		if(trav->right != NULL)
			s.push(trav->right);
	//step4: if the cur node having left child push it into the stack
		if(trav->left != NULL)
			s.push(trav->left);
	//step5: repeat step2, step3 & step4 till stack not becomes empty
	}cout<<endl;
}

void bfs_traversal()
{
	if(is_empty())
		return;

	queue<node *> q;
	//step1: push root node into the stack
	q.push(root);
	cout<<"BFS : ";
	while(!q.empty())
	{
	//step2: pop the node from the stack and visit it
		node *trav = q.front(); q.pop();
		cout<<setw(4)<<left<<trav->data;
	//step3: if the cur node having right child push it into the stack
		if(trav->left != NULL)
			q.push(trav->left);
	//step4: if the cur node having left child push it into the stack
		if(trav->right != NULL)
			q.push(trav->right);
	//step5: repeat step2, step3 & step4 till stack not becomes empty
	}cout<<endl;
}


};//end of class

int main()
{
	bst b;

	b.add_node(50);
	b.add_node(20);
	b.add_node(90);
	b.add_node(85);
	b.add_node(10);
	b.add_node(45);
	b.add_node(30);
	b.add_node(100);
	b.add_node(15);
	b.add_node(75);
	b.add_node(95);
	b.add_node(120);
	b.add_node(5);
	b.add_node(50);

	b.preorder();
	b.postorder();
	b.inorder();

	b.bfs_traversal();
	b.dfs_traversal();

return 0;
}


