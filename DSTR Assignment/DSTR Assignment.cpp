#include <iostream>
#include <string>
#include "OrderList_Linkedlist.h"
#include "OrderList_Structure.h"
#include "login.cpp"

using namespace std;
using std::cout;
using std::cin;

void runPOSystem()
{
	cout << endl;
	cout << "--- Welcome to Purchasing Order System ---" << endl;

	OrderList order;

	cout << endl;
	char next = 'y';

	do {
		int opt = -1;
		int i, count;
		string checkint;

		cout << "\n--- CHOICES OF FUNCTIONS ---" << endl;
		cout << "1) Insert new order" << endl;
		cout << "2) Search Order" << endl;
		cout << "3) Sort Order" << endl;
		cout << "4) Edit Order" << endl;
		cout << "5) Delete Order" << endl;

		cout << "77) Add hardcoded orders" << endl;
		cout << "88) Show current orders" << endl;
		cout << "99) Logout and Exit" << endl;

		//check if input is integer
		do {
			cout << "\nChoice? ";
			cin >> checkint;
			cout << endl;

			for (i = 0; i < checkint.length(); i++)
			{
				if (isdigit(checkint[i]) == false)
				{
					count = 1;
					break;
				}
				else
					count = 0;
			}

			if (count == 0)
			{
				opt = stoi(checkint);
			}
			else
				cout << "Invalid input!" << endl;

		} while (count !=0);

		switch (opt)
		{
			case 1:
			{
				order.insertNewOrder();
			}
			break;
			case 2:
			{
				int searchopt = -1;
				cout << "1) Search order by id" << endl;
				cout << "2) Search order by position in linked list" << endl;

				cout << "\nChoice? ";
				cin >> searchopt;
				switch (searchopt)
				{
				case 1:
				{
					int oid;
					cout << "--- SEARCH ORDER BY ID ---" << endl;
					cout << "OrderID: ";
					cin >> oid;
					order.showSpecific(order.searchOrderID(oid));
				}
				break;
				case 2:
				{
					int pos;
					cout << "--- SEARCH ORDER BY POSITION ---" << endl;
					cout << "Position: ";
					cin >> pos;
					order.showSpecific(pos);
				}
				break;
				default:
				{
					cout << "Invalid option!" << endl;
				}
				break;
				}
			}
			break;
			case 3:
			{
				int sortopt = -1;
				cout << "1) Sort by ID" << endl;
				cout << "2) Sort by Total" << endl;
				cout << "3) Sort by Order Date" << endl;
				cout << "4) Sort by Quantity" << endl;

				cout << "\nChoice? ";
				cin >> sortopt;
				switch (sortopt)
				{
				case 1:
				{
					order.sortByID();
				}
				break;
				case 2:
				{
					order.sortByTotal();
				}
				break;
				case 3:
				{
					order.sortByDate();
				}
				break;
				case 4:
				{
					order.sortByQuantity();
				}
				break;
				default:
				{
					cout << "Invalid option!" << endl;
				}
				break;
				}
			}
			break; 
			case 4:
			{
				int chosenID, chosenCol = -1;
				string newData;
				order.showAll();
				cout << "Provide order ID of the order that wanted to edit: ";
				cin >> chosenID;
				order.showSpecific(order.searchOrderID(chosenID));
				cout << "Which column do you want to edit (One column each time)? ";
				cin >> chosenCol;
				cin.ignore(numeric_limits <streamsize> ::max(), '\n');
				cout << "Insert new data: ";
				getline(cin, newData);

				order.editData(chosenID, chosenCol, newData);
			}
			break;
			case 5:
			{
				int delopt = -1;
				cout << "1) Delete First Order" << endl;
				cout << "2) Delete Last Order" << endl;
				cout << "3) Delete Order by Position" << endl;
				cout << "4) Delete Order by ID" << endl;

				cout << "\nChoice? ";
				cin >> delopt;
				switch (delopt)
				{
					case 1:
					{
						order.deleteFirst();
						order.showAll();
					}
					break;
					case 2:
					{
						order.deleteLast();
						order.showAll();
					}
					break;
					case 3:
					{
						int i = -1;
						cout << "Enter position: ";
						cin >> i;
						order.deleteItemAt(i);
						order.showAll();
					}
					break;
					case 4:
					{
						cout << "--- DELETE ORDER BY ID ---" << endl;
						int uid = -1;
						cout << "Enter Order ID: ";
						cin >> uid;
						order.remove(uid);
						cout << "Order ID#" << uid << " is deleted..." << endl;
						order.showAll();
					}
					break;
					default:
					{
						cout << "Invalid option!" << endl;
					}
					break;
				}
				
			}
			break;
			case 77:
			{
				cout << "--- ADDING HARDCODED(ONLINE) ORDERS ---" << endl;
				hardCodedOrder hardOrder[8];
				generateHardCodedOrder(hardOrder);
				order.getOrdrFromArray(hardOrder);
				order.showAll();
			}
			break;
			case 88:
			{
				//show
				order.showAll();
				cout << endl;
			}
			break;
			case 99:
			{
				next = 'n';
			}
			break;
			default:
			{
				cout << "LOG: Invalid option!" << endl;
			}
				break;
		}

	} while (next == 'y');

	cout << "\nLogging out...Thank you!" << endl;
	cout << "============================================================" << endl;
}

int main()
{
	user user[3];
	userData(user);

	if (validateUser(user) != -1) {
		runPOSystem();
	}
	
}