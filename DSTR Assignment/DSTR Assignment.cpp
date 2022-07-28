#include <iostream>
#include <string>
#include "OrderList_Linkedlist.h"
#include "OrderList_Structure.h"
#include "login.cpp"

using std::cout;
using std::cin;

void runPOSystem(int role)
{
	cout << endl;
	cout << "--- Welcome to Purchasing Order System ---" << endl;

	OrderList order;

	cout << endl;
	char next = 'y';
	bool added = false;

	do {
		cout << "\n--- CHOICES OF FUNCTIONS ---" << endl;
		cout << "1) Insert new order" << endl;
		cout << "2) Search Order" << endl;
		cout << "3) Sort Order" << endl;
		cout << "4) Edit Order" << endl;
		cout << "5) Delete Order" << endl;
		cout << "6) View Pending orders" << endl;
		
		if (role == 1) {
			cout << "7) Generate Report" << endl;
			cout << "8) Sort Report" << endl;
		}
		cout << endl;

		if (!added) {
			cout << "66) Add hardcoded orders" << endl;
		}
		cout << "88) Show current orders" << endl;
		cout << "99) Logout and Exit" << endl;

		switch (checkChoiceInt())
		{
			case 1:
			{
				order.insertNewOrder();
			}
			break;
			case 2:
			{
				cout << "1) Search order by id" << endl;
				cout << "2) Search order by position in linked list" << endl;

				switch (checkChoiceInt())
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
				cout << "1) Sort by ID" << endl;
				cout << "2) Sort by Total" << endl;
				cout << "3) Sort by Order Date" << endl;
				cout << "4) Sort by Quantity" << endl;

				switch (checkChoiceInt())
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
				int chosenID, chosenCol = 0;
				string newData;
				order.showAll();
				cout << "Provide order ID of the order that wanted to edit: ";
				cin >> chosenID;
				while (cin.fail()) {
					cout << "Please input order ID only" << std::endl;
					cin.clear();
					cin.ignore(numeric_limits <streamsize> ::max(), '\n');
					cin >> chosenID;
				}
				order.showSpecific(order.searchOrderID(chosenID));
				cout << "Which column do you want to edit (Column number eg. 2)? ";
				cin >> chosenCol;
				while (cin.fail()) {
					cout << "Please input column number only" << std::endl;
					cin.clear();
					cin.ignore(numeric_limits <streamsize> ::max(), '\n');
					cin >> chosenCol;
				}
				cin.ignore(numeric_limits <streamsize> ::max(), '\n');
				cout << "Insert new data: ";
				getline(cin, newData);

				order.editData(chosenID, chosenCol, newData);
			}
			break;
			case 5:
			{
				cout << "1) Delete First Order" << endl;
				cout << "2) Delete Last Order" << endl;
				cout << "3) Delete Order by Position" << endl;
				cout << "4) Delete Order by ID" << endl;

				switch (checkChoiceInt())
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
			case 6:
			{
				char decision;
				int chosenID, chosenCol = 0;
				string newType;
				order.generateReport(2);

				do {
					cout << "Modify Pending Order Type? (y/n)" << endl;
					cin >> decision;

					if (decision == 'y') {
						cout << "Please provide order ID: ";
						cin >> chosenID;
						while (cin.fail()) {
							cout << "Please input order ID only" << std::endl;
							cin.clear();
							cin.ignore(numeric_limits <streamsize> ::max(), '\n');
							cin >> chosenID;
						}
						order.searchOrderID(chosenID);
						cin.ignore(numeric_limits <streamsize> ::max(), '\n');
						cout << "New Type: ";
						getline(cin, newType);
						order.editData(chosenID, 9, newType);
					}
				} while (decision != 'y' && decision != 'n');
			}
			break;
			case 7:
			{
				cout << "1) View completed orders" << endl;
				cout << "2) View pending orders" << endl;
				cout << "3) View canceled orders" << endl;
				cout << "4) Total Revenue" << endl;

				switch (checkChoiceInt()) {
				case 1:
				{
					order.generateReport(1);
				}
				break;

				case 2:
				{
					order.generateReport(2);
				}
				break;

				case 3:
				{
					order.generateReport(3);
				}
				break;

				case 4:
				{
					order.generateReport(4);
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
			case 8:
			{
				cout << "1) Report for newest orders" << endl;
				cout << "2) Report for oldest orders" << endl;

				switch (checkChoiceInt())
				{
					case 1:
					{
						order.sortReportByNewest();
					}
					break;
					case 2:
					{
						order.sortReportByOldest();
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
			case 66:
			{
				cout << "--- ADDING HARDCODED(ONLINE) ORDERS ---" << endl;
				Order hardOrder[8];
				generateHardCodedOrder(hardOrder);
				order.getOrdrFromArray(hardOrder);
				order.showAll();
				added = true;
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
	user users[5];
	userData(users);

	runPOSystem(validateUser(users));
}