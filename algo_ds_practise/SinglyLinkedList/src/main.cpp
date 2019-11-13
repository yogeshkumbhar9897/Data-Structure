/*
 * main.cpp
 *
 *  Created on: 29-Sep-2019
 *      Author: yogesh
 */
#include <iostream>
using namespace std;
#include <iomanip>
#include "list1.h"




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
				cout<<"Enter the position Where you want to insert elemment :";
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
				cout<<"Enter the position Where you want to insert elemment :";
				cin>>position;
				l1.delete_node_at_specific_position(position);
				break;

			case 7:
					l1.display_list();
				break;

			case 8:
				break;

			case 9:
				break;
			}



		}

return 0;
}


