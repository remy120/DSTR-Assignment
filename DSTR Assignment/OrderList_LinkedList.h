#ifndef ORDERLIST_LINKED_LIST_H_
#define ORDERLIST_LINKED_LIST_H_

#include "OrderList_Structure.h"
#include <iostream>		// cin cout
#include <algorithm>	// sort
#include <sstream>		// stringstream
#include <tuple>		//tuple, make_tuple, get
#include <iomanip>

using namespace std;
//using std::cout;
//using std::cin;

inline void generateHardCodedOrder(hardCodedOrder* hardCodedOrder) {
	hardCodedOrder[0].horderID = 1;
	hardCodedOrder[0].hbuyerName = "Hayden Emmett";
	hardCodedOrder[0].hbuyerEmail = "haydenE@mail.com";
	hardCodedOrder[0].horderDate = "2021/04/09";
	hardCodedOrder[0].htotal = 394.80;
	hardCodedOrder[0].hshippingAddss = "G 36A Jln Penrissen Batu 7 Kuching";
	hardCodedOrder[0].hitemID = 1;
	//hardCodedOrder[0].hitemID.push_back(5);
	//hardCodedOrder[0].hitemID.push_back(7);
	hardCodedOrder[0].hquantity =3;
	//hardCodedOrder[0].hquantity.push_back(5);
	//hardCodedOrder[0].hquantity.push_back(2);
	hardCodedOrder[0].hstatus = "Completed";

	hardCodedOrder[1].horderID = 3;
	hardCodedOrder[1].hbuyerName = "Ira Prudence";
	hardCodedOrder[1].hbuyerEmail = "iraP@mail.com";
	hardCodedOrder[1].horderDate = "2021/08/04";
	hardCodedOrder[1].htotal = 373.70;
	hardCodedOrder[1].hshippingAddss = "Sek Memandu Kenderaan Darat Jln Au3/1";
	hardCodedOrder[1].hitemID = 2;
	//hardCodedOrder[1].hitemID.push_back(4);
	//hardCodedOrder[1].hitemID.push_back(6);
	hardCodedOrder[1].hquantity = 4;
	//hardCodedOrder[1].hquantity.push_back(8);
	//hardCodedOrder[1].hquantity.push_back(6);
	hardCodedOrder[1].hstatus = "Completed";

	hardCodedOrder[2].horderID = 5;
	hardCodedOrder[2].hbuyerName = "Michael Zandra";
	hardCodedOrder[2].hbuyerEmail = "michelleZ@mail.com";
	hardCodedOrder[2].horderDate = "2022/01/16";
	hardCodedOrder[2].htotal = 57;
	hardCodedOrder[2].hshippingAddss = "No.87, Medan Sepadu";
	hardCodedOrder[2].hitemID = 9;
	//hardCodedOrder[2].hitemID.push_back(10);
	//hardCodedOrder[2].hitemID.push_back(3);
	hardCodedOrder[2].hquantity = 1;
	//hardCodedOrder[2].hquantity.push_back(2);
	//hardCodedOrder[2].hquantity.push_back(2);
	hardCodedOrder[2].hstatus = "Completed";

	hardCodedOrder[3].horderID = 6;
	hardCodedOrder[3].hbuyerName = "Ethelyn Jane";
	hardCodedOrder[3].hbuyerEmail = "haydenE@mail.com";
	hardCodedOrder[3].horderDate = "2022/04/08";
	hardCodedOrder[3].htotal = 394.80;
	hardCodedOrder[3].hshippingAddss = "G 36A Jln Penrissen Batu 7 Kuching";
	hardCodedOrder[3].hitemID = 1;
	//hardCodedOrder[3].hitemID.push_back(5);
	//hardCodedOrder[3].hitemID.push_back(7);
	hardCodedOrder[3].hquantity = 3;
	//hardCodedOrder[3].hquantity.push_back(5);
	//hardCodedOrder[3].hquantity.push_back(2);
	hardCodedOrder[3].hstatus = "Cancelled";

	hardCodedOrder[4].horderID = 2;
	hardCodedOrder[4].hbuyerName = "Darnell Axel";
	hardCodedOrder[4].hbuyerEmail = "iraP@mail.com";
	hardCodedOrder[4].horderDate = "2021/07/04";
	hardCodedOrder[4].htotal = 373.70;
	hardCodedOrder[4].hshippingAddss = "Sek Memandu Kenderaan Darat Jln Au3/1";
	hardCodedOrder[4].hitemID = 2;
	//hardCodedOrder[4].hitemID.push_back(4);
	//hardCodedOrder[4].hitemID.push_back(6);
	hardCodedOrder[4].hquantity = 4;
	//hardCodedOrder[4].hquantity.push_back(8);
	//hardCodedOrder[4].hquantity.push_back(6);
	hardCodedOrder[4].hstatus = "Shipping";

	hardCodedOrder[5].horderID = 7;
	hardCodedOrder[5].hbuyerName = "Lavena Ping";
	hardCodedOrder[5].hbuyerEmail = "michelleZ@mail.com";
	hardCodedOrder[5].horderDate = "2022/05/25";
	hardCodedOrder[5].htotal = 57;
	hardCodedOrder[5].hshippingAddss = "No.87, Medan Sepadu";
	hardCodedOrder[5].hitemID = 9;
	//hardCodedOrder[5].hitemID.push_back(10);
	//hardCodedOrder[5].hitemID.push_back(3);
	hardCodedOrder[5].hquantity = 1;
	//hardCodedOrder[5].hquantity.push_back(2);
	//hardCodedOrder[5].hquantity.push_back(2);
	hardCodedOrder[5].hstatus = "New";

	hardCodedOrder[6].horderID = 4;
	hardCodedOrder[6].hbuyerName = "Marlee Sherri";
	hardCodedOrder[6].hbuyerEmail = "iraP@mail.com";
	hardCodedOrder[6].horderDate = "2021/08/04";
	hardCodedOrder[6].htotal = 373.70;
	hardCodedOrder[6].hshippingAddss = "Sek Memandu Kenderaan Darat Jln Au3/1";
	hardCodedOrder[6].hitemID = 2;
	//hardCodedOrder[6].hitemID.push_back(4);
	//hardCodedOrder[6].hitemID.push_back(6);
	hardCodedOrder[6].hquantity = 4;
	//hardCodedOrder[6].hquantity.push_back(8);
	//hardCodedOrder[6].hquantity.push_back(6);
	hardCodedOrder[6].hstatus = "Shipping";

	hardCodedOrder[7].horderID = 8;
	hardCodedOrder[7].hbuyerName = "Drea Polly";
	hardCodedOrder[7].hbuyerEmail = "michelleZ@mail.com";
	hardCodedOrder[7].horderDate = "2022/05/27";
	hardCodedOrder[7].htotal = 57;
	hardCodedOrder[7].hshippingAddss = "No.87, Medan Sepadu";
	hardCodedOrder[7].hitemID = 9;
	//hardCodedOrder[7].hitemID.push_back(10);
	//hardCodedOrder[7].hitemID.push_back(3);
	hardCodedOrder[7].hquantity = 1;
	//hardCodedOrder[7].hquantity.push_back(2);
	//hardCodedOrder[7].hquantity.push_back(2);
	hardCodedOrder[7].hstatus = "New";
}

class OrderList
{
public:
	Order* head;
	int size;

	OrderList()
	{
		this->size = 0;
		this->head = nullptr;
	}

public:

	void getOrdrFromArray(hardCodedOrder hardCodedOrder[]) {
		for (int i = 0; i < sizeof(hardCodedOrder); i++) {
			Order* newNode = new Order;
			newNode->orderID = hardCodedOrder[i].horderID;
			newNode->buyerName = hardCodedOrder[i].hbuyerName;
			newNode->buyerEmail = hardCodedOrder[i].hbuyerEmail;
			newNode->orderDate = hardCodedOrder[i].horderDate;
			newNode->total = hardCodedOrder[i].htotal;
			newNode->shippingAddss = hardCodedOrder[i].hshippingAddss;
			newNode->itemID = hardCodedOrder[i].horderID;
			newNode->quantity = hardCodedOrder[i].hquantity;
			newNode->status = hardCodedOrder[i].hstatus;
			//for (int x = 0; x < sizeof(hardCodedOrder[i].horderID); x++) {
			//	newNode->itemID.push_back(hardCodedOrder[i].horderID);
			//};

			newNode->next = nullptr;

			if (head == nullptr) {
				head = newNode;
			}
			else {
				Order* last = head;
				while (last->next != nullptr)
					last = last->next;
				last->next = newNode;
			}
			size++;
		};
	}

	//insert new order
	void insertNew(int id, string buyer, string email, string date, double total, string shipping, int item, int quantity)
	{
		Order* newNode = new Order;
		newNode->orderID = id;
		newNode->buyerName = buyer;
		newNode->buyerEmail = email;
		newNode->orderDate = date;
		newNode->total = total;
		newNode->shippingAddss = shipping;
		newNode->itemID = item;
		newNode->quantity = quantity;
		newNode->status = "New";

		newNode->next = nullptr;

		if (head == nullptr) {
			head = newNode;
		}
		else {
			Order* last = head;
			while (last->next != nullptr)
				last = last->next;
			last->next = newNode;
		}
		size++;
	}

	//insert new order and sort
	void insertAndSorted(int id, string buyer, string email, string date, double total, string shipping, int item, int quantity)
	{
		insertNew(id, buyer, email, date, total, shipping, item, quantity);
		sortIDAsc();
	}

	//delete first order in the list
	void deleteFirst()
	{
		if (size > 0)
		{
			cout << "--- DELETE FIRST ORDER ---" << endl;
			Order* toBeDeleted = head; //pointer refers to head which is the 1st node
			head = head->next; //move the head pointer to the 2nd node
			delete toBeDeleted;
			size--;
			cout << "LOG:  First order is deleted..." << endl;
		}
	}

	//delete last order in the list
	void deleteLast()
	{
		if (size > 0)
		{
			cout << "--- DELETE LAST ORDER ---" << endl;
			if (size == 1) {
				delete head;
				head = nullptr;
			}
			else {
				Order* beforeLast = head;
				while (beforeLast->next->next != nullptr)
					beforeLast = beforeLast->next;
				delete beforeLast->next;
				beforeLast->next = nullptr;
			}
			size--;
			cout << "LOG:  Last order is deleted..." << endl;
		}
	}

	//delete specific item based on index
	void deleteItemAt(int position)
	{
		if (position < size)
		{
			cout << "--- DELETE ORDER BY INDEX ---" << endl;
			if (position == 0)
				deleteFirst();
			else {
				Order* prev = nullptr;
				Order* toDelete = head;
				for (int i = 0; i < position; ++i)
				{
					prev = toDelete;
					toDelete = toDelete->next;
				}
				prev->next = toDelete->next;
				delete toDelete;
				size--;
				cout << "Order at position #" << position << " is deleted..." << endl;
			}
		}
	}

	//remove specific order based on orderID
	void remove(int id)
	{
		int index = -1;
		if (size > 0)
		{
			Order* curr = head;
			while (curr != nullptr)
			{
				++index;
				if (curr->orderID != id)
					curr = curr->next;
				else
					deleteItemAt(index);
			}
		}
	}

	//search for order based on ID
	void searchOrderID(int id)
	{
		Order* current = head;
		int position = -1;
		while (current != nullptr)
		{
			++position;
			if (current->orderID == id)
				showSpecific(position);
			current = current->next;
		}
	}


	//get linkedlist size
	int getSize()
	{
		return size;
	}

	//show linkedlist
	void showAll()
	{
		Order* curr = head;
		cout << "\n--- TOTAL ORDERS = " << size << " ---" << endl;
		cout << "ID	|Buyer		|Order Date	|Total		|ItemID	|Quantity	|Status" << endl;
		if (head == nullptr)
		{
			cout << "List is empty" << endl;
			return;
		}
		while (curr != nullptr)
		{
			cout << "" << curr->orderID << "	 " << curr->buyerName << "	 " << curr->orderDate << "	 RM" << setprecision(2) << fixed << curr->total << "	 " << curr->itemID << "	 " << curr->quantity << "		 " << curr->status << endl;
			curr = curr->next;
		}
	}

	//insert new order
	void insertNewOrder()
	{
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

			insertNew(stoi(oID), name, email, date, stod(total), shipping, stoi(item), stoi(quantity));
		}
		showAll();
	}

	//show linkedlist
	void showSpecific(int index)
	{
		Order* curr = head;
		cout << "ID	|Buyer		|Order Date	|Total		|ItemID	|Quantity	|Status" << endl;
		if (index < size)
		{
			for (int i = 0; i < index; ++i)
			{
				curr = curr->next;
			}
			cout << "" << curr->orderID << "	 " << curr->buyerName << "	 " << curr->orderDate << "	 RM" << setprecision(2) << fixed << curr->total << "	 " << curr->itemID << "	 " << curr->quantity << "		 " << curr->status << endl;
		}
	}

	//sort by ID
	void sortByID()
	{
		int sortIDopt = -1;
		cout << "--- SORT ORDER BY ID ---" << endl;
		cout << "1) Ascending" << endl;
		cout << "2) Descending" << endl;
		cin >> sortIDopt;
		cout << endl;
		switch (sortIDopt)
		{
		case 1:
		{
			cout << "--- SORT ORDER BY ID ASCENDING---" << endl;
			sortIDAsc();
			showAll();
		}
		break;
		case 2:
		{
			cout << "--- SORT ORDER BY ID DESCENDING---" << endl;
			sortIDDesc();
			showAll();
		}
		break;
		default:
			cout << "Invalid option!" << endl;
			break;
		}
	}

	//sort by total
	void sortByTotal()
	{
		int sortTotalopt = -1;
		cout << "--- SORT ORDER BY TOTAL ---" << endl;
		cout << "1) Ascending" << endl;
		cout << "2) Descending" << endl;
		cin >> sortTotalopt;
		cout << endl;
		switch (sortTotalopt)
		{
		case 1:
		{
			cout << "--- SORT ORDER BY TOTAL ASCENDING---" << endl;
			sortTotalAsc();
			showAll();
		}
		break;
		case 2:
		{
			cout << "--- SORT ORDER BY TOTAL DESCENDING---" << endl;
			sortTotalDesc();
			showAll();
		}
		break;
		default:
			cout << "Invalid option!" << endl;
			break;
		}
	}

	//sort by date
	void sortByDate()
	{
		int sortDateopt = -1;
		cout << "--- SORT ORDER BY ORDER DATE ---" << endl;
		cout << "1) Ascending" << endl;
		cout << "2) Descending" << endl;
		cin >> sortDateopt;
		cout << endl;
		switch (sortDateopt)
		{
		case 1:
		{
			cout << "--- SORT ORDER BY ORDER DATE ASCENDING---" << endl;
			sortOrderDateAsc();
			showAll();
		}
		break;
		case 2:
		{
			cout << "--- SORT ORDER BY ORDER DATE DESCENDING---" << endl;
			sortOrderDateDesc();
			showAll();
		}
		break;
		default:
			cout << "LOG: Invalid option!" << endl;
			break;
		}
	}

	//sort order based on ID ascending
	void sortIDAsc()
	{
		Order* curr = head, * index = nullptr;
		int tempID, tempItem, tempQuantity;
		string tempName, tempEmail, tempDate, tempShipping, tempStatus;
		double tempTotal;

		if (head == nullptr) {
			return;
		}
		else {
			while (curr != nullptr)
			{
				index = curr->next;
				while (index != nullptr)
				{
					if (curr->orderID > index->orderID)
					{
						tempID = curr->orderID;
						tempName = curr->buyerName;
						tempEmail = curr->buyerEmail;
						tempDate = curr->orderDate;
						tempTotal = curr->total;
						tempShipping = curr->shippingAddss;
						tempItem = curr->itemID;
						tempQuantity = curr->quantity;
						tempStatus = curr->status;

						curr->orderID = index->orderID;
						curr->buyerName = index->buyerName;
						curr->buyerEmail = index->buyerEmail;
						curr->orderDate = index->orderDate;
						curr->total = index->total;
						curr->shippingAddss = index->shippingAddss;
						curr->itemID = index->itemID;
						curr->quantity = index->quantity;
						curr->status = index->status;

						index->orderID = tempID;
						index->buyerName = tempName;
						index->buyerEmail = tempEmail;
						index->orderDate = tempDate;
						index->total = tempTotal;
						index->shippingAddss = tempShipping;
						index->itemID = tempItem;
						index->quantity = tempQuantity;
						index->status = tempStatus;
					}
					index = index->next;
				}
				curr = curr->next;
			}
		}
	}

	//sort order based on ID descending
	void sortIDDesc()
	{
		Order* curr = head, * index = nullptr;
		int tempID, tempItem, tempQuantity;
		string tempName, tempEmail, tempDate, tempShipping, tempStatus;
		double tempTotal;

		if (head == nullptr) {
			return;
		}
		else {
			while (curr != nullptr)
			{
				index = curr->next;
				while (index != nullptr)
				{
					if (curr->orderID < index->orderID)
					{
						tempID = curr->orderID;
						tempName = curr->buyerName;
						tempEmail = curr->buyerEmail;
						tempDate = curr->orderDate;
						tempTotal = curr->total;
						tempShipping = curr->shippingAddss;
						tempItem = curr->itemID;
						tempQuantity = curr->quantity;
						tempStatus = curr->status;

						curr->orderID = index->orderID;
						curr->buyerName = index->buyerName;
						curr->buyerEmail = index->buyerEmail;
						curr->orderDate = index->orderDate;
						curr->total = index->total;
						curr->shippingAddss = index->shippingAddss;
						curr->itemID = index->itemID;
						curr->quantity = index->quantity;
						curr->status = index->status;

						index->orderID = tempID;
						index->buyerName = tempName;
						index->buyerEmail = tempEmail;
						index->orderDate = tempDate;
						index->total = tempTotal;
						index->shippingAddss = tempShipping;
						index->itemID = tempItem;
						index->quantity = tempQuantity;
						index->status = tempStatus;
					}
					index = index->next;
				}
				curr = curr->next;
			}
		}
	}

	//sort order based on total ascending
	void sortTotalAsc()
	{
		Order* curr = head, * index = nullptr;
		int tempID, tempItem, tempQuantity;
		string tempName, tempEmail, tempDate, tempShipping, tempStatus;
		double tempTotal;

		if (head == nullptr) {
			return;
		}
		else {
			while (curr != nullptr)
			{
				index = curr->next;
				while (index != nullptr)
				{
					if (curr->total > index->total)
					{
						tempID = curr->orderID;
						tempName = curr->buyerName;
						tempEmail = curr->buyerEmail;
						tempDate = curr->orderDate;
						tempTotal = curr->total;
						tempShipping = curr->shippingAddss;
						tempItem = curr->itemID;
						tempQuantity = curr->quantity;
						tempStatus = curr->status;

						curr->orderID = index->orderID;
						curr->buyerName = index->buyerName;
						curr->buyerEmail = index->buyerEmail;
						curr->orderDate = index->orderDate;
						curr->total = index->total;
						curr->shippingAddss = index->shippingAddss;
						curr->itemID = index->itemID;
						curr->quantity = index->quantity;
						curr->status = index->status;

						index->orderID = tempID;
						index->buyerName = tempName;
						index->buyerEmail = tempEmail;
						index->orderDate = tempDate;
						index->total = tempTotal;
						index->shippingAddss = tempShipping;
						index->itemID = tempItem;
						index->quantity = tempQuantity;
						index->status = tempStatus;
					}
					index = index->next;
				}
				curr = curr->next;
			}
		}
	}

	//sort order based on total descending
	void sortTotalDesc()
	{
		Order* curr = head, * index = nullptr;
		int tempID, tempItem, tempQuantity;
		string tempName, tempEmail, tempDate, tempShipping, tempStatus;
		double tempTotal;

		if (head == nullptr) {
			return;
		}
		else {
			while (curr != nullptr)
			{
				index = curr->next;
				while (index != nullptr)
				{
					if (curr->total < index->total)
					{
						tempID = curr->orderID;
						tempName = curr->buyerName;
						tempEmail = curr->buyerEmail;
						tempDate = curr->orderDate;
						tempTotal = curr->total;
						tempShipping = curr->shippingAddss;
						tempItem = curr->itemID;
						tempQuantity = curr->quantity;
						tempStatus = curr->status;

						curr->orderID = index->orderID;
						curr->buyerName = index->buyerName;
						curr->buyerEmail = index->buyerEmail;
						curr->orderDate = index->orderDate;
						curr->total = index->total;
						curr->shippingAddss = index->shippingAddss;
						curr->itemID = index->itemID;
						curr->quantity = index->quantity;
						curr->status = index->status;

						index->orderID = tempID;
						index->buyerName = tempName;
						index->buyerEmail = tempEmail;
						index->orderDate = tempDate;
						index->total = tempTotal;
						index->shippingAddss = tempShipping;
						index->itemID = tempItem;
						index->quantity = tempQuantity;
						index->status = tempStatus;
					}
					index = index->next;
				}
				curr = curr->next;
			}
		}
	}

	//sort order based on order date ascending
	void sortOrderDateAsc()
	{
		Order* curr = head, * index = nullptr;
		int tempID, tempItem, tempQuantity;
		string tempName, tempEmail, tempDate, tempShipping, tempStatus;
		double tempTotal;

		if (head == nullptr) {
			return;
		}
		else {
			while (curr != nullptr)
			{
				index = curr->next;
				while (index != nullptr)
				{
					//convert current orderDate from string to char
					string currDate = curr->orderDate;
					char charCurrDate[1024];
					strcpy_s(charCurrDate, currDate.c_str());

					//convert index orderDate from string to char
					string nextDate = index->orderDate;
					char charNextDate[1024];
					strcpy_s(charNextDate, nextDate.c_str());

					//compare date (result is -1 if smaller, 1 if bigger)
					int result = strcmp(charCurrDate, charNextDate);

					if (result == 1)
					{
						tempID = curr->orderID;
						tempName = curr->buyerName;
						tempEmail = curr->buyerEmail;
						tempDate = curr->orderDate;
						tempTotal = curr->total;
						tempShipping = curr->shippingAddss;
						tempItem = curr->itemID;
						tempQuantity = curr->quantity;
						tempStatus = curr->status;

						curr->orderID = index->orderID;
						curr->buyerName = index->buyerName;
						curr->buyerEmail = index->buyerEmail;
						curr->orderDate = index->orderDate;
						curr->total = index->total;
						curr->shippingAddss = index->shippingAddss;
						curr->itemID = index->itemID;
						curr->quantity = index->quantity;
						curr->status = index->status;

						index->orderID = tempID;
						index->buyerName = tempName;
						index->buyerEmail = tempEmail;
						index->orderDate = tempDate;
						index->total = tempTotal;
						index->shippingAddss = tempShipping;
						index->itemID = tempItem;
						index->quantity = tempQuantity;
						index->status = tempStatus;
					}
					index = index->next;
				}
				curr = curr->next;
			}
		}
	}

	//sort order based on order date descending
	void sortOrderDateDesc()
	{
		Order* curr = head, * index = nullptr;
		int tempID, tempItem, tempQuantity;
		string tempName, tempEmail, tempDate, tempShipping, tempStatus;
		double tempTotal;

		if (head == nullptr) {
			return;
		}
		else {
			while (curr != nullptr)
			{
				index = curr->next;
				while (index != nullptr)
				{
					//convert current orderDate from string to char
					string currDate = curr->orderDate;
					char charCurrDate[1024];
					strcpy_s(charCurrDate, currDate.c_str());

					//convert index orderDate from string to char
					string nextDate = index->orderDate;
					char charNextDate[1024];
					strcpy_s(charNextDate, nextDate.c_str());

					//compare date (result is -1 if smaller, 1 if bigger)
					int result = strcmp(charCurrDate, charNextDate);

					if (result == -1)
					{
						tempID = curr->orderID;
						tempName = curr->buyerName;
						tempEmail = curr->buyerEmail;
						tempDate = curr->orderDate;
						tempTotal = curr->total;
						tempShipping = curr->shippingAddss;
						tempItem = curr->itemID;
						tempQuantity = curr->quantity;
						tempStatus = curr->status;

						curr->orderID = index->orderID;
						curr->buyerName = index->buyerName;
						curr->buyerEmail = index->buyerEmail;
						curr->orderDate = index->orderDate;
						curr->total = index->total;
						curr->shippingAddss = index->shippingAddss;
						curr->itemID = index->itemID;
						curr->quantity = index->quantity;
						curr->status = index->status;

						index->orderID = tempID;
						index->buyerName = tempName;
						index->buyerEmail = tempEmail;
						index->orderDate = tempDate;
						index->total = tempTotal;
						index->shippingAddss = tempShipping;
						index->itemID = tempItem;
						index->quantity = tempQuantity;
						index->status = tempStatus;
					}
					index = index->next;
				}
				curr = curr->next;
			}
		}
	}



};

#endif /* ORDERLIST_LINKED_LIST_H_ */