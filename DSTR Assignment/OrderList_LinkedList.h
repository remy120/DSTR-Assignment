#ifndef ORDERLIST_LINKED_LIST_H_
#define ORDERLIST_LINKED_LIST_H_

#include "OrderList_Structure.h"
#include <iostream>		// cin cout
#include <algorithm>	// sort
#include <sstream>		// stringstream
#include <tuple>		//tuple, make_tuple, get
#include <iomanip>
#include <string>

using namespace std;

//check if choice input is integer
inline int checkChoiceInt() {
	string checkint;
	int count=0;
	do {
		cout << "\nChoice?" << endl;
		cin >> checkint;
		cout << endl;

		for (int i = 0; i < checkint.length(); i++)
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
			return stoi(checkint);
		}
		else
		{
			cout << "Invalid input!" << endl;
		}

	} while (count != 0);
}

inline void generateHardCodedOrder(Order* hardCodedOrder) {
	hardCodedOrder[0].orderID = 1;
	hardCodedOrder[0].buyerName = "Hayden Emmett";
	hardCodedOrder[0].buyerEmail = "haydenE@mail.com";
	hardCodedOrder[0].orderDate = "2021/04/09";
	hardCodedOrder[0].total = 394.80;
	hardCodedOrder[0].shippingAddss = "Penrissen Batu 7 Kuching";
	hardCodedOrder[0].itemID = 1;
	//hardCodedOrder[0].hitemID.push_back(5);
	//hardCodedOrder[0].hitemID.push_back(7);
	hardCodedOrder[0].quantity =3;
	//hardCodedOrder[0].hquantity.push_back(5);
	//hardCodedOrder[0].hquantity.push_back(2);
	hardCodedOrder[0].status = "Completed";

	hardCodedOrder[1].orderID = 3;
	hardCodedOrder[1].buyerName = "Ira Prudence";
	hardCodedOrder[1].buyerEmail = "prudenceI@mail.com";
	hardCodedOrder[1].orderDate = "2021/08/04";
	hardCodedOrder[1].total = 373.70;
	hardCodedOrder[1].shippingAddss = "Sek Memandu Kenderaan";
	hardCodedOrder[1].itemID = 2;
	//hardCodedOrder[1].hitemID.push_back(4);
	//hardCodedOrder[1].hitemID.push_back(6);
	hardCodedOrder[1].quantity = 4;
	//hardCodedOrder[1].hquantity.push_back(8);
	//hardCodedOrder[1].hquantity.push_back(6);
	hardCodedOrder[1].status = "Completed";

	hardCodedOrder[2].orderID = 5;
	hardCodedOrder[2].buyerName = "Michael Zandra";
	hardCodedOrder[2].buyerEmail = "michelleZ@mail.com";
	hardCodedOrder[2].orderDate = "2022/01/16";
	hardCodedOrder[2].total = 57;
	hardCodedOrder[2].shippingAddss = "No.87, Medan Sepadu";
	hardCodedOrder[2].itemID = 9;
	//hardCodedOrder[2].hitemID.push_back(10);
	//hardCodedOrder[2].hitemID.push_back(3);
	hardCodedOrder[2].quantity = 1;
	//hardCodedOrder[2].hquantity.push_back(2);
	//hardCodedOrder[2].hquantity.push_back(2);
	hardCodedOrder[2].status = "Completed";

	hardCodedOrder[3].orderID = 6;
	hardCodedOrder[3].buyerName = "Ethelyn Jane";
	hardCodedOrder[3].buyerEmail = "ethelynJ@mail.com";
	hardCodedOrder[3].orderDate = "2022/04/08";
	hardCodedOrder[3].total = 394.80;
	hardCodedOrder[3].shippingAddss = "OUG Parklane Block D";
	hardCodedOrder[3].itemID = 1;
	//hardCodedOrder[3].hitemID.push_back(5);
	//hardCodedOrder[3].hitemID.push_back(7);
	hardCodedOrder[3].quantity = 3;
	//hardCodedOrder[3].hquantity.push_back(5);
	//hardCodedOrder[3].hquantity.push_back(2);
	hardCodedOrder[3].status = "Cancelled";

	hardCodedOrder[4].orderID = 2;
	hardCodedOrder[4].buyerName = "Darnell Axel";
	hardCodedOrder[4].buyerEmail = "darnellA@mail.com";
	hardCodedOrder[4].orderDate = "2021/07/04";
	hardCodedOrder[4].total = 373.70;
	hardCodedOrder[4].shippingAddss = "Pavillion Bukit Jalil";
	hardCodedOrder[4].itemID = 2;
	//hardCodedOrder[4].hitemID.push_back(4);
	//hardCodedOrder[4].hitemID.push_back(6);
	hardCodedOrder[4].quantity = 4;
	//hardCodedOrder[4].hquantity.push_back(8);
	//hardCodedOrder[4].hquantity.push_back(6);
	hardCodedOrder[4].status = "Pending";

	hardCodedOrder[5].orderID = 7;
	hardCodedOrder[5].buyerName = "Lavena Ping";
	hardCodedOrder[5].buyerEmail = "lavenaP@mail.com";
	hardCodedOrder[5].orderDate = "2022/05/25";
	hardCodedOrder[5].total = 57;
	hardCodedOrder[5].shippingAddss = "Taman Teknologi Malaysia";
	hardCodedOrder[5].itemID = 9;
	//hardCodedOrder[5].hitemID.push_back(10);
	//hardCodedOrder[5].hitemID.push_back(3);
	hardCodedOrder[5].quantity = 1;
	//hardCodedOrder[5].hquantity.push_back(2);
	//hardCodedOrder[5].hquantity.push_back(2);
	hardCodedOrder[5].status = "Pending";

	hardCodedOrder[6].orderID = 4;
	hardCodedOrder[6].buyerName = "Marlee Sherri";
	hardCodedOrder[6].buyerEmail = "marleeS@mail.com";
	hardCodedOrder[6].orderDate = "2021/08/04";
	hardCodedOrder[6].total = 373.70;
	hardCodedOrder[6].shippingAddss = "Taman Bukit Damansara";
	hardCodedOrder[6].itemID = 2;
	//hardCodedOrder[6].hitemID.push_back(4);
	//hardCodedOrder[6].hitemID.push_back(6);
	hardCodedOrder[6].quantity = 4;
	//hardCodedOrder[6].hquantity.push_back(8);
	//hardCodedOrder[6].hquantity.push_back(6);
	hardCodedOrder[6].status = "Pending";

	hardCodedOrder[7].orderID = 8;
	hardCodedOrder[7].buyerName = "Drea Polly";
	hardCodedOrder[7].buyerEmail = "dreaP@mail.com";
	hardCodedOrder[7].orderDate = "2022/05/27";
	hardCodedOrder[7].total = 57;
	hardCodedOrder[7].shippingAddss = "D-24 Muasang King Farm";
	hardCodedOrder[7].itemID = 9;
	//hardCodedOrder[7].hitemID.push_back(10);
	//hardCodedOrder[7].hitemID.push_back(3);
	hardCodedOrder[7].quantity = 1;
	//hardCodedOrder[7].hquantity.push_back(2);
	//hardCodedOrder[7].hquantity.push_back(2);
	hardCodedOrder[7].status = "Pending";
}

class OrderList
{
public:
	Order* head;
	int size;
	string value[10];

	OrderList()
	{
		this->size = 0;
		this->head = nullptr;
	}

public:

	// length of the string  
	//Reference from https://www.javatpoint.com/how-to-split-strings-in-cpp
	inline int len(string str)
	{
		int length = 0;
		for (int i = 0; str[i] != '\0'; i++)
		{
			length++;
		}
		return length;
	}

	//create custom split() function  
	//Reference from https://www.javatpoint.com/how-to-split-strings-in-cpp
	inline void split(string str, char seperator)
	{
		int currIndex = 0, i = 0;
		int startIndex = 0, endIndex = 0;
		while (i <= len(str))
		{
			if (str[i] == seperator || i == len(str))
			{
				endIndex = i;
				string subStr = "";
				subStr.append(str, startIndex, endIndex - startIndex);
				value[currIndex] = subStr;
				currIndex += 1;
				startIndex = endIndex + 1;
			}
			i++;
		}
	}

	void getOrdrFromArray(Order hardCodedOrder[]) {
		for (int i = 0; i < sizeof(hardCodedOrder); i++) {
			Order* newNode = new Order;
			newNode->orderID = hardCodedOrder[i].orderID;
			newNode->buyerName = hardCodedOrder[i].buyerName;
			newNode->buyerEmail = hardCodedOrder[i].buyerEmail;
			newNode->orderDate = hardCodedOrder[i].orderDate;
			newNode->total = hardCodedOrder[i].total;
			newNode->shippingAddss = hardCodedOrder[i].shippingAddss;
			newNode->itemID = hardCodedOrder[i].orderID;
			newNode->quantity = hardCodedOrder[i].quantity;
			newNode->status = hardCodedOrder[i].status;
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
		newNode->status = "Pending";

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
			cout << "First order is deleted..." << endl;
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
			cout << "Last order is deleted..." << endl;
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
	int searchOrderID(int id)
	{
		Order* current = head;
		int position = -1;
		while (current != nullptr)
		{
			++position;
			if (current->orderID == id)
				return position;
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

	void generateReport(int statusId)
	{
		Order* curr = head;
		double sum = 0;
		
		if (head == nullptr) {
			cout << "List is empty" << endl;
			return;
		}

		// Completed Status
		if (statusId == 1) {
			cout << "ID	|Buyer		|Order Date	|Total		|ItemID	|Quantity	|Status" << endl;
			while (curr != nullptr)
			{
				if (curr->status == "Completed") {
					cout << "" << curr->orderID << "	 " << curr->buyerName << "	 " << curr->orderDate << "	 RM" << setprecision(2) << fixed << curr->total << "	 " << curr->itemID << "	 " << curr->quantity << "		 " << curr->status << endl;
					curr = curr->next;
				}
				else {
					curr = curr->next;
				}
			}
		}

		if (statusId == 2) {
			cout << "ID	|Buyer		|Order Date	|Total		|ItemID	|Quantity	|Status" << endl;
			while (curr != nullptr)
			{
				if (curr->status == "Pending") {
					cout << "" << curr->orderID << "	 " << curr->buyerName << "	 " << curr->orderDate << "	 RM" << setprecision(2) << fixed << curr->total << "	 " << curr->itemID << "	 " << curr->quantity << "		 " << curr->status << endl;
					curr = curr->next;
				}
				else {
					curr = curr->next;
				}
			}
		}

		if (statusId == 3) {
			cout << "ID	|Buyer		|Order Date	|Total		|ItemID	|Quantity	|Status" << endl;
			while (curr != nullptr)
			{
				if (curr->status == "Cancelled") {
					cout << "" << curr->orderID << "	 " << curr->buyerName << "	 " << curr->orderDate << "	 RM" << setprecision(2) << fixed << curr->total << "	 " << curr->itemID << "	 " << curr->quantity << "		 " << curr->status << endl;
					curr = curr->next;
				}
				else {
					curr = curr->next;
				}
			}
		}

		if (statusId == 4) {
			int year;
			cout << "Input a year (eg. 2022)";
			year = checkChoiceInt();

			cout << "--- " << year << " ORDERS --- " << endl;
			cout << "ID	|Buyer		|Order Date	|Total		|ItemID	|Quantity	|Status" << endl;
			while (curr != nullptr)
			{
				char seperator = '/'; 
				split(curr->orderDate, seperator);

				if (value[0] == to_string(year) && curr->status != "Cancelled") {
					cout << "" << curr->orderID << "	 " << curr->buyerName << "	 " << curr->orderDate << "	 RM" << setprecision(2) << fixed << curr->total << "	 " << curr->itemID << "	 " << curr->quantity << "		 " << curr->status << endl;

					sum += curr->total;
					curr = curr->next;
				}
				else {
					curr = curr->next;
				}
			}

			cout << "Total Revenue is RM" << sum << endl;
		}
	}

	//insert new order
	void insertNewOrder()
	{
		int amount = 0;
		//asking for number of orders will be inserted at once
		cout << "How many orders? " << endl;
		if (amount = checkChoiceInt()) {
			cin.ignore(numeric_limits <streamsize> ::max(), '\n');

			for (int i = 0; i < amount; ++i)
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
	}

	//show linkedlist
	void showSpecific(int index)
	{
		Order* curr = head;
		cout << "ID	|Buyer		|Email			|Order Date	|Total		|Address		|ItemID	|Quantity|Status" << endl;
		if (index < size)
		{
			for (int i = 0; i < index; ++i)
			{
				curr = curr->next;
			}
			cout << "" << curr->orderID << "	 " << curr->buyerName << "	 " << curr->buyerEmail << "	 " << curr->orderDate << "	 RM" << setprecision(2) << fixed << curr->total << "	 " << curr->shippingAddss << "	 " << curr->itemID << "	 " << curr->quantity << "	  " << curr->status << endl;
		}
	}

	void editData(int chosenID, int chosenCol, string newData)
	{
		Order* curr = head, * index = nullptr;

		if (head == nullptr) {
			return;
		}
		else {
			for (int i = 0; i < searchOrderID(chosenID); ++i)
			{
				curr = curr->next;
			}

			switch (chosenCol)
			{
				case 1:
				{
					if (stoi(newData)) {
						curr->orderID = stoi(newData);
					}
					else {
						cout << "New data is invalid";
					}
				}
				break; 
				case 2:
				{
					curr->buyerName = newData;
				}
				break;
				case 3:
				{
					curr->buyerEmail = newData;
				}
				break;
				case 4:
				{
					curr->orderDate = newData;
				}
				break;
				case 5:
				{
					if (stoi(newData)) {
						curr->total = stod(newData);
					}
					else {
						cout << "New data is invalid";
					}
					
				}
				break;
				case 6:
				{
					curr->shippingAddss = newData;
				}
				break;
				case 7:
				{
					if (stoi(newData)) {
						curr->itemID = stoi(newData);
					}
					else {
						cout << "New data is invalid";
					}
				}
				break;
				case 8:
				{
					if (stoi(newData)) {
						curr->quantity = stoi(newData);
					}
					else {
						cout << "New data is invalid";
					}
				}
				break;
				case 9:
				{
					curr->status = newData;
				}
				break;
				default:
				{
					cout << "Invalid option!" << endl;
				}
				break;
			}
		}
	}

	//sort by ID
	void sortByID()
	{
		cout << "--- SORT ORDER BY ID ---" << endl;
		cout << "1) Ascending" << endl;
		cout << "2) Descending" << endl;

		switch (checkChoiceInt())
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
		cout << "--- SORT ORDER BY TOTAL ---" << endl;
		cout << "1) Ascending" << endl;
		cout << "2) Descending" << endl;

		switch (checkChoiceInt())
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
		cout << "--- SORT ORDER BY ORDER DATE ---" << endl;
		cout << "1) Ascending" << endl;
		cout << "2) Descending" << endl;
		switch (checkChoiceInt())
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

	//sort by quantity
	void sortByQuantity()
	{
		cout << "--- SORT ORDER BY QUANTITY ---" << endl;
		cout << "1) Ascending" << endl;
		cout << "2) Descending" << endl;

		switch (checkChoiceInt())
		{
		case 1:
		{
			cout << "--- SORT ORDER BY QUANTITY ASCENDING---" << endl;
			sortQuantityAsc();
			showAll();
		}
		break;
		case 2:
		{
			cout << "--- SORT ORDER BY QUANTITY DESCENDING---" << endl;
			sortQuantityDesc();
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

	//sort order based on quantity ascending
	void sortQuantityAsc()
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
					if (curr->quantity > index->quantity)
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

	//sort order based on quantity descending
	void sortQuantityDesc()
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
					if (curr->quantity < index->quantity)
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

	void sortReportByNewest()
	{
		cout << "--- SORT REPORT BY NEWEST ---" << endl;
		cout << "1) Completed" << endl;
		cout << "2) Pending" << endl;
		cout << "3) Cancelled" << endl;

		switch (checkChoiceInt())
		{
		case 1:
		{
			cout << "--- SORT COMPLETED REPORT BY NEWEST ---" << endl;
			sortOrderDateDesc();
			generateReport(1);
		}
		break;
		case 2:
		{
			cout << "--- SORT PENDING REPORT BY NEWEST ---" << endl;
			sortOrderDateDesc();
			generateReport(2);
		}
		break;
		case 3:
		{
			cout << "--- SORT CANCELLED REPORT BY NEWEST ---" << endl;
			sortOrderDateDesc();
			generateReport(3);
		}
		break;
		default:
			cout << "LOG: Invalid option!" << endl;
			break;
		}
	}

	void sortReportByOldest()
	{
		cout << "--- SORT REPORT BY OLDEST ---" << endl;
		cout << "1) Completed" << endl;
		cout << "2) Pending" << endl;
		cout << "3) Cancelled" << endl;

		switch (checkChoiceInt())
		{
		case 1:
		{
			cout << "--- SORT COMPLETED REPORT BY OLDEST ---" << endl;
			sortOrderDateAsc();
			generateReport(1);
		}
		break;
		case 2:
		{
			cout << "--- SORT PENDING REPORT BY OLDEST ---" << endl;
			sortOrderDateAsc();
			generateReport(2);
		}
		break;
		case 3:
		{
			cout << "--- SORT CANCELLED REPORT BY OLDEST ---" << endl;
			sortOrderDateAsc();
			generateReport(3);
		}
		break;
		default:
			cout << "LOG: Invalid option!" << endl;
			break;
		}
	}

};

#endif /* ORDERLIST_LINKED_LIST_H_ */