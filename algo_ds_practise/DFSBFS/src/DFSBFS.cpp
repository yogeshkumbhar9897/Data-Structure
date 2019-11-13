//============================================================================
// Name        : DFSBFS.cpp
// Author      : yogesh kumbhar
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
#include<iomanip>
#include<cstring>
#include<stack>
#include<queue>
#define MAX 10
class graph
{
private:
	int mat[MAX][MAX];
	int ver_cnt;
	int edge_cnt;

public:
		graph(void)
		{
			this->ver_cnt = 0;
			this->edge_cnt = 0;

			memset(mat,0,sizeof(mat));
		}

		void accept(void)
		{
			cout<<"enter total vertex :"<<endl;
			cin>>ver_cnt;
			cout<<"enter total edges :"<<endl;
			cin>>edge_cnt;

			for(int i = 0 ; i < edge_cnt ; ++i)
			{
				int to , from ;
				cout<<"Enter From to To :"<<endl;
				cin >>from >> to ;

				mat[from][to] = 1;
				mat[to][from] = 1;

			}
		}
		void display()
		{
			cout<<"Total Vertex :"<<ver_cnt<<endl;

			cout<<"Total Edge :"<<edge_cnt<<endl;


			for(int i = 0; i<ver_cnt ; i++)
			{
				for(int j = 0 ; j < ver_cnt ; j++)
				{
					cout<<setw(4)<<left<<mat[i][j];
				}
				cout<<endl;
			}
			cout<<endl;
		}
		void dfs_trav(int start)
		{
			stack<int> s;
			bool mark[MAX];
			cout<<"DFS Traversal :"<<endl;
			for(int v=0; v<ver_cnt ; v++)
				mark[v]=false;

			//step1: push the starting vertex into the stack and mark it
			s.push(start);
			mark[start] = true;

			while(!s.empty())
			{

			//step2: pop the vertex from the stack and visit it
			int trav = s.top();
				s.pop();

				cout<<setw(4)<<left<<trav;
			//	step3: push all its adjacent but unmarked vertices into the stack and mark them
				for(int v=0; v<ver_cnt ; v++)
				{

					if(mat[trav][v] != 0 && mark[v] == false)
					{
						s.push(v);
						mark[v]=true;
					}


				}//	step4: repeat step2 & step3 till stack not becomes empty.
		}
			cout<<endl;
	}

		void bfs_trav(int start)
				{
					queue<int> q;
					bool mark[MAX];
					cout<<"BFS Traversal :"<<endl;
					for(int v=0; v<ver_cnt ; v++)
						mark[v]=false;

					//step1: push the starting vertex into the queue and mark it
					q.push(start);
					mark[start] = true;

					while(!q.empty())
					{

					//step2: pop the vertex from the queue and visit it
					int trav = q.front();
						q.pop();

						cout<<setw(4)<<left<<trav;
					//	step3: push all its adjacent but unmarked vertices into the queue and mark them
						for(int v=0; v<ver_cnt ; v++)
						{

							if(mat[trav][v] != 0 && mark[v] == false)
							{
								q.push(v);
								mark[v]=true;
							}


						}//	step4: repeat step2 & step3 till queue not becomes empty.
				}
			}
};

int main(void)
{
	graph g1;
	g1.accept();
	g1.display();

	int start;
	cout<<"Enter Start to travers :"<<endl;
	cin>>start;

	g1.dfs_trav(start);
	g1.bfs_trav(start);


return 0;
}
