#include <iostream>
#include <string>
#include "OrderList_Linkedlist.h"
#include "OrderList_Structure.h"

using namespace std;

void runAssignment()
{
	cout << endl;
	cout << "--- Welcome to Purchasing Order System ---" << endl;

	
	
	OrderList order;
	int n = 0;
	//asking for number of orders will be inserted at once
	cout << "How many orders? " << endl;
	cin >> n;
	cin.ignore(numeric_limits <streamsize> ::max(), '\n');

	for (int i = 0; i < n; ++i)
	{
		string oID, name, email, date, total, shipping, item, quantity;
		cout << "\n--- ENTER ORDER ID #" << (i + 1) << "---" << endl << endl;
		cout << "Order ID= ";
		getline(cin, oID);
		cout << "Buyer Name= ";
		getline(cin, name);
		cout << "Buyer Email= ";
		getline(cin, email);
		cout << "Order Date (eg. 2022/05/20)= ";
		getline(cin, date);
		cout << "Total= RM";
		getline(cin, total);
		cout << "Shipping Address= ";
		getline(cin, shipping);
		cout << "Item ID= ";
		getline(cin, item);
		cout << "Quantity= ";
		getline(cin, quantity);

		order.insertNew(stoi(oID), name, email, date, stod(total), shipping, stoi(item), stoi(quantity));
	}

	//show
	//order.showAll();
	cout << endl;
	char next = 'n';

	do {
		//show
		order.showAll();
		cout << endl;
		int opt = -1;
		cout << "\n--- ORDER LISTS ---" << endl;
		cout << "1) Delete First Order" << endl;
		cout << "2) Delete Last Last" << endl;
		cout << "3) Delete Order by Index" << endl;
		cout << "4) Delete Order by ID" << endl;
		cout << "5) Sort by ID ascending" << endl;
		cout << "6) Sort by ID descending" << endl;
		cout << "7) Sort by Total ascending" << endl;
		cout << "8) Sort by Total descending" << endl;
		cout << "9) Sort by Order Date ascending" << endl;
		cout << "10) Sort by Order Date descending" << endl;
		cout << "11) Sort by Quantity ascending" << endl;
		cout << "12) Sort by Quantity descending" << endl;

		cout << "\nChoice? " << endl;
		cin >> opt;
		cout << endl;
		switch (opt)
		{
		case 1:
		{
			order.deleteFirst();
		}
		break;
		case 2:
		{
			order.deleteLast();
		}
		break;
		case 3:
		{
			int i = -1;
			cout << "Enter index? " << endl;
			cin >> i;
			order.deleteItemAt(i);
		}
		break;
		case 4:
		{
			cout << "--- DELETE ORDER BY ID ---" << endl;
			int uid = -1;
			cout << "Enter Order ID? " << endl;
			cin >> uid;
			order.remove(uid);
			cout << "LOG:  Order ID#" << uid << " is deleted..." << endl;
		}
		break;
		case 5:
		{
			cout << "--- SORT ORDER BY ID ---" << endl;
			cout << "1) Ascending" << endl;
			cout << "2) Descending" << endl;
			cin >> opt;
			cout << endl;
			switch (opt)
			{
				case 1:
				{
					cout << "--- SORT ORDER BY ID ASCENDING---" << endl;
					order.sortIDAsc();
				}
				break;
				case 2:
				{
					cout << "--- SORT ORDER BY ID DESCENDING---" << endl;
					order.sortIDDesc();
				}
				break;
				default:
					cout << "LOG: Invalid option!" << endl;
					break;
			}
		}
		break;
		case 6:
		{
			cout << "--- SORT ORDER BY TOTAL ---" << endl;
			cout << "1) Ascending" << endl;
			cout << "2) Descending" << endl;
			cin >> opt;
			cout << endl;
			switch (opt)
			{
			case 1:
			{
				cout << "--- SORT ORDER BY TOTAL ASCENDING---" << endl;
				order.sortTotalAsc();
			}
			break;
			case 2:
			{
				cout << "--- SORT ORDER BY TOTAL DESCENDING---" << endl;
				order.sortTotalDesc();
			}
			break;
			default:
				cout << "LOG: Invalid option!" << endl;
				break;
			}
			
		}
		break;
		case 7:
		{
			cout << "--- SORT ORDER BY ORDER DATE ---" << endl;
			cout << "1) Ascending" << endl;
			cout << "2) Descending" << endl;
			cin >> opt;
			cout << endl;
			switch (opt)
			{
			case 1:
			{
				cout << "--- SORT ORDER BY ORDER DATE ASCENDING---" << endl;
				order.sortOrderDateAsc();
			}
			break;
			case 2:
			{
				cout << "--- SORT ORDER BY ORDER DATE DESCENDING---" << endl;
				order.sortOrderDateDesc();
			}
			break;
			default:
				cout << "LOG: Invalid option!" << endl;
				break;
			}
		}
		break;
		default:
			cout << "LOG: Invalid option!" << endl;
			break;
		}
		//show
		order.showAll();
		cout << endl;

		do {
			cout << "Do you want to continue? (y/n)." << endl;
			cin >> next;
		} while (next != 'y' && next != 'n');

	} while (next == 'y');


	cout << endl;
	cout << "============================================================" << endl;
}

int main()
{
	runAssignment();
}