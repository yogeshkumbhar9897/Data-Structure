//============================================================================
// Name        : graph.cpp
// Author      : yogesh kumbhar
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include<iostream>
using namespace std;
#include<vector>
#include<list>
#include<iterator>
#include<iomanip>

class edge
{
private:
		int v;//to point
		int w;//weight

public:
		edge(int v=0 , int w=0)
		{
			this->v = v;
			this->w = w;
		}

		friend ostream& operator<<(ostream& out , edge& other)
		{
			out<<other.v<< ":" <<other.w ;
			return out;
		}
};

class graph
{
private:
	vector < list<edge> > gr;
	int vtx_cnt;
	int edge_cnt;

public:
	graph(void)
	{
		this->vtx_cnt = 0;
		this->edge_cnt = 0;
	}

	void AcceptGraph()
	{
		cout<<"Enter total Vertices :"<<endl;
		cin>>vtx_cnt;
		cout<<"Enter total Edges :"<<endl;
		cin>>edge_cnt;

		for( int i = 0 ; i < vtx_cnt ; ++i )
		{
			list<edge> empty_list;
			gr.push_back(empty_list);
		}

		for(int i = 0 ; i<edge_cnt ; ++i)
		{
			int to, from, weight;
			cout<<"Enter From, To and Weight"<<endl;
			cin>> from >> to >> weight;

			edge ed1(to, weight);
			gr[from].push_back(ed1);

			edge ed2(from,weight);
			gr[to].push_back(ed2);
		}

	}

	void DisplayGraph()
	{
		cout<<"Vertex count :"<<vtx_cnt<<endl;
		cout<<"Edge count :"<<edge_cnt<<endl;
		cout<<"Input Graph :";

		list<edge>::iterator itr;

		for(int i=0 ; i < vtx_cnt ; i++)
		{
			cout<<"[" <<i<< "]";
			for(itr = gr[i].begin() ; itr != gr[i].end() ; itr++)
			{
				cout<< *itr <<"->";

			}cout<<"NULL"<<endl;
		}cout<<endl;
	}

};

int main()
{
	graph g1;

	g1.AcceptGraph();
	g1.DisplayGraph();

	return 0;

}
