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

//check if choice input is integer after asking for choice
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
	return 0;
}

//add hard coded order
inline vector<order> generateHardCodedOrder() {
	vector <order> hardOrder;
	hardOrder.push_back(order(1, "Hayden Emmett", "haydenE@mail.com", "2021/04/09", 394.80, "Penrissen 7 Kuching", 1, 3, "Urgent", "Completed"));
	hardOrder.push_back(order(3, "Ira Prudence", "prudenceI@mail.com", "2021/08/04", 373.70, "Sek Memandu Kenderaan", 2, 4, "Normal", "Completed"));
	hardOrder.push_back(order(5, "Michael Zandra", "michelleZ@mail.com", "2022/01/16", 57, "No.87, Medan Sepadu", 9, 1, "Normal", "Completed"));
	hardOrder.push_back(order(6, "Ethelyn Jane", "ethelynJ@mail.com", "2022/04/08", 394.80, "OUG Parklane Block D", 1, 3, "Normal", "Cancelled"));
	hardOrder.push_back(order(2, "Darnell Axel", "darnellA@mail.com", "2021/07/04", 373.7, "Pavillion Bukit Jalil", 2, 4, "Urgent", "Pending"));
	hardOrder.push_back(order(7, "Lavena Ping", "lavenaP@mail.com", "2022/05/25", 57, "Taman Teknologi Malaysia", 9, 1, "Normal", "Pending"));
	hardOrder.push_back(order(4, "Marlee Sherri", "marleeS@mail.com", "2021/08/04", 373.70, "Taman Bukit Damansara", 2, 4, "Urgent", "Pending"));
	hardOrder.push_back(order(8, "Hayden Emmett", "haydenE@mail.com", "2022/05/27", 57, "D-24 Muasang King", 9, 1, "Normal", "Pending"));

	return hardOrder;
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

	string value[10];
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

	//swap node (for sorting)
	void swap(Order* curr, Order* index) {
		int tempID, tempItem, tempQuantity;
		string tempName, tempEmail, tempDate, tempShipping, tempType, tempStatus;
		double tempTotal;

		tempID = curr->orderID;
		tempName = curr->buyerName;
		tempEmail = curr->buyerEmail;
		tempDate = curr->orderDate;
		tempTotal = curr->total;
		tempShipping = curr->shippingAddss;
		tempItem = curr->itemID;
		tempQuantity = curr->quantity;
		tempType = curr->type;
		tempStatus = curr->status;

		curr->orderID = index->orderID;
		curr->buyerName = index->buyerName;
		curr->buyerEmail = index->buyerEmail;
		curr->orderDate = index->orderDate;
		curr->total = index->total;
		curr->shippingAddss = index->shippingAddss;
		curr->itemID = index->itemID;
		curr->quantity = index->quantity;
		curr->type = index->type;
		curr->status = index->status;

		index->orderID = tempID;
		index->buyerName = tempName;
		index->buyerEmail = tempEmail;
		index->orderDate = tempDate;
		index->total = tempTotal;
		index->shippingAddss = tempShipping;
		index->itemID = tempItem;
		index->quantity = tempQuantity;
		index->type = tempType;
		index->status = tempStatus;
	}

	//display individual order based on current node
	void displayInd(Order* current) {
		cout << "=========================================" << endl;
		cout << "Order ID: " << current->orderID << endl;
		cout << "Buyer Name: " << current->buyerName << endl;
		cout << "Buyer Email: " << current->buyerEmail << endl;
		cout << "Order Date: " << current->orderDate << endl;
		cout << "Total: RM" << current->total << endl;
		cout << "Shipping Address: " << current->shippingAddss << endl;
		cout << "Item ID: " << current->itemID << endl;
		cout << "Quantity: " << current->quantity << endl;
		cout << "Type: " << current->type << endl;
		cout << "Status: " << current->status << endl;
		cout << "=========================================" << endl;
	}

	//display line of order
	void displayLine(Order* curr)
	{
		cout << "" << curr->orderID << "	 " << curr->buyerName << "	 " << curr->orderDate << "	 RM" << setprecision(2) << fixed << curr->total << "	 " << curr->type << "	 " << curr->status << endl;
	}

	//display header
	void displayOrderHeader() {
		cout << "ID	|Buyer		|Order Date	|Total		|Type	|Status" << endl;
	}

	//Insert hardcoded orders
	void getOrdrFromArray(vector<order> orderD) {
		for (order data : orderD) {
			Order* newNode = new Order;
			newNode->orderID = get<0>(data);
			newNode->buyerName = get<1>(data);
			newNode->buyerEmail = get<2>(data);
			newNode->orderDate = get<3>(data);
			newNode->total = get<4>(data);
			newNode->shippingAddss = get<5>(data);
			newNode->itemID = get<6>(data);
			newNode->quantity = get<7>(data);
			newNode->type = get<8>(data);
			newNode->status = get<9>(data);

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
		newNode->type = "Normal";
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
		sort(1);
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

	//search order by name
	int searchOrderbyName(string bName)
	{
		Order* current = head;
		bool found = false;
		while (current != nullptr)
		{
			if (current->buyerName == bName) {
				found = true;
				displayInd(current);
			}
			current = current->next;
		}
		if (found == false) {
			cout << "Order does not exist!" << endl;
		}
		return 0;
	}

	//search order by email
	int searchOrderbyEmail(string email)
	{
		Order* current = head;
		bool found = false;
		while (current != nullptr)
		{
			if (current->buyerEmail == email) {
				found = true;
				displayInd(current);
			}
			current = current->next;
		}
		if (found == false) {
			cout << "Order does not exist!" << endl;
		}
		return 0;
	}

	//search order by date
	int searchOrderbyDate(string oDate)
	{
		Order* current = head;
		bool found = false;
		while (current != nullptr)
		{
			if (current->orderDate == oDate) {
				found = true;
				displayInd(current);
			}
			current = current->next;
		}
		if (found == false) {
			cout << "Order does not exist!" << endl;
		}
		return 0;
	}

	//search order by year
	int searchOrderbyYear(string oYear)
	{
		Order* current = head;
		bool found = false;
		while (current != nullptr)
		{
			char seperator = '/';
			split(current->orderDate, seperator);
			if (value[0] == oYear) {
				found = true;
				displayInd(current);
			}
			current = current->next;
		}
		if (found == false) {
			cout << "Order does not exist!" << endl;
		}
		return 0;
	}

	//search order by month and year
	int searchOrderbyMonthYear(string oYear, string oMonth)
	{
		Order* current = head;
		bool found = false;
		while (current != nullptr)
		{
			char seperator = '/';
			split(current->orderDate, seperator);
			if (value[0] == oYear && value[1] == oMonth) {
				found = true;
				displayInd(current);
			}
			current = current->next;
		}
		if (found == false) {
			cout << "Order does not exist!" << endl;
		}
		return 0;
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
		cout << "Order does not exist!"<<endl;
		return -1;
	}

	//get linkedlist size
	int getSize()
	{
		return size;
	}

	//show whole order list
	void showAll()
	{
		Order* curr = head;
		cout << "\n--- TOTAL ORDERS = " << size << " ---" << endl;
		displayOrderHeader();
		if (head == nullptr)
		{
			cout << "List is empty" << endl;
			return;
		}
		while (curr != nullptr)
		{
			displayLine(curr); 
			curr = curr->next;
		}
	}

	//generate report
	void generateReport(int statusId)
	{
		Order* curr = head;
		double sum = 0;
		int count = 0;
		
		if (head == nullptr) {
			cout << "List is empty" << endl;
			return;
		}

		// Completed Status
		if (statusId == 1) {
			displayOrderHeader();
			while (curr != nullptr)
			{
				if (curr->status == "Completed") {
					displayLine(curr);
					curr = curr->next;
					count++;
				}
				else {
					curr = curr->next;
				}
			}
			cout << "Total completed order:" << count << endl;
		}

		//pending and urgent
		if (statusId == 2) {
			displayOrderHeader();
			while (curr != nullptr)
			{
				if (curr->status == "Pending" && curr->type == "Urgent") {
					displayLine(curr); 
					curr = curr->next;
					count++;
				}
				else {
					curr = curr->next;
				}
			}
			Order* curr = head;
			while (curr != nullptr)
			{
				if (curr->status == "Pending" && curr->type == "Normal") {
					displayLine(curr); 
					curr = curr->next;
					count++;
				}
				else {
					curr = curr->next;
				}
			}
			cout << "Total pending order:" << count << endl;
		}

		//cancelled
		if (statusId == 3) {
			displayOrderHeader();
			while (curr != nullptr)
			{
				if (curr->status == "Cancelled") {
					displayLine(curr); 
					curr = curr->next;
					count++;
				}
				else {
					curr = curr->next;
				}
			}
			cout << "Total cancelled order:" << count << endl;
		}

		//year with completed
		if (statusId == 4) {
			int year;
			cout << "Input a year (eg. 2022)";
			year = checkChoiceInt();

			cout << "--- " << year << " ORDERS --- " << endl;
			displayOrderHeader();
			while (curr != nullptr)
			{
				char seperator = '/'; 
				split(curr->orderDate, seperator);

				if (value[0] == to_string(year) && curr->status == "Completed") {
					displayLine(curr);

					sum += curr->total;
					count++;
					curr = curr->next;
				}
				else {
					curr = curr->next;
				}
			}
			cout << "Total Revenue is RM" << sum << " from " << count << " orders" << endl;
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
				bool validID = true, validItem = true, validQuantity = true, validTotal = true, validType = true;
				string oID, name, email, date, total, shipping, item, quantity;
				double tempTotal;
				int tempID, tempItem, tempQuantity;
				cout << "\n--- ENTER ORDER ID #" << (i + 1) << "---" << endl << endl;
				do {
					Order* curr = head;
					cout << "Order ID= ";
					getline(cin, oID);
					try {
						tempID = stoi(oID);
						while (curr != nullptr)
						{
							try {
								if (curr->orderID == stoi(oID)) {
									cout << "Order ID exist, please insert other order ID" << endl;
									validID = false;
									break;
								}
								else {
									validID = true;
								}
							}
							catch (...) {
								cout << "Order ID must be integer!" << endl;
								validID = false;
								break;
							}
							curr = curr->next;
						}
					}
					catch (...) {
						cout << "Order ID must be integer!" << endl;
						validID = false;
					}
				} while (validID == false);
				cout << "Buyer Name= ";
				getline(cin, name);
				cout << "Buyer Email= ";
				getline(cin, email);
				cout << "Order Date (eg. 2022/05/20)= ";
				getline(cin, date);
				do {
					cout << "Total= RM";
					getline(cin, total);
					try {
						tempTotal = stod(total);
						validTotal = true;
					}
					catch (...) {
						cout << "Total must be integer/double!" << endl;
						validTotal = false;
					}
				} while (validTotal == false);
				cout << "Shipping Address= ";
				getline(cin, shipping);
				do {
					cout << "Item ID= ";
					getline(cin, item);
					try {
						tempItem = stoi(item);
						validItem = true;
					}
					catch (...) {
						cout << "Item ID must be integer!" << endl;
						validItem = false;
					}
				} while (validItem == false);
				do {
					cout << "Quantity= ";
					getline(cin, quantity);
					try {
						tempQuantity = stoi(quantity);
						validQuantity = true;
					}
					catch (...) {
						cout << "Quantity must be integer!" << endl;
						validQuantity = false;
					}
				} while (validQuantity == false);

				insertNew(stoi(oID), name, email, date, tempTotal, shipping, tempItem, tempQuantity);
			}
			showAll();
		}
	}

	//show specific order
	bool showSpecific(int index)
	{
		if (index != -1) {
			Order* curr = head;
			if (index < size)
			{
				for (int i = 0; i < index; ++i)
				{
					curr = curr->next;
				}
				displayInd(curr);
				return true;
			}
		}
		else {
			return false;
		}
	}

	//update order detail
	void updateData(int chosenID, int chosenCol, string newData) {
		Order* curr = head, * index = nullptr;

		if (head == nullptr) {
			return;
		}
		else {
			if (searchOrderID(chosenID) != -1) {
				for (int i = 0; i < searchOrderID(chosenID); ++i)
				{
					curr = curr->next;
				}

				switch (chosenCol)
				{
				case 1:
				{
					try {
						bool can = true;
						Order* curr = head;
						while (curr != nullptr)
						{
							if (curr->orderID == stoi(newData)) {
								cout << "Order ID already exist, please try again with other order ID" << endl;
								can = false;
								break;
							}
							curr = curr->next;
						}
						if (can == true) {
							curr->orderID = stoi(newData);
						}
					}
					catch (...) {
						cout << "New data is invalid" << endl;
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
					try {
						curr->total = stod(newData);
					}
					catch (...) {
						cout << "New data is invalid" << endl;
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
					try {
						curr->itemID = stoi(newData);
					}
					catch (...) {
						cout << "New data is invalid" << endl;
					}
				}
				break;
				case 8:
				{
					try {
						curr->quantity = stoi(newData);
					}
					catch (...) {
						cout << "New data is invalid" << endl;
					}
				}
				break;
				case 9:
				{
					curr->type = newData;
				}
				break;
				case 10:
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
	}

	//edit order detail
	void editData()
	{
		int chosenID, chosenCol = 0;
		string newData;
		bool validID = true, validCol = true;
		showAll();

		do {
			cout << "Provide order ID of the order that wanted to edit: ";
			cin >> chosenID;
			validID = true;
			if (cin.fail()) {
				cout << "Please input order ID only" << endl;
				cin.clear();
				cin.ignore(numeric_limits <streamsize> ::max(), '\n');
				validID = false;
			}
		} while (validID == false);
		
		
		do {
			cout << "Which column do you want to edit (Column number eg. 2)? ";
			cin >> chosenCol;
			validCol = true;
			if (cin.fail()) {
				cout << "Please input column number only" << endl;
				cin.clear();
				cin.ignore(numeric_limits <streamsize> ::max(), '\n');
				validCol = false;
			}
			cin.ignore(numeric_limits <streamsize> ::max(), '\n');
		} while (validCol == false);

		cout << "Insert new data: ";
		getline(cin, newData);

		updateData(chosenID, chosenCol, newData);

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
			sort(1);
			showAll();
		}
		break;
		case 2:
		{
			cout << "--- SORT ORDER BY ID DESCENDING---" << endl;
			sort(2);
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
			sort(3);
			showAll();
		}
		break;
		case 2:
		{
			cout << "--- SORT ORDER BY TOTAL DESCENDING---" << endl;
			sort(4);
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
			sortDate(1);
			showAll();
		}
		break;
		case 2:
		{
			cout << "--- SORT ORDER BY ORDER DATE DESCENDING---" << endl;
			sortDate(2);
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
			sort(5);
			showAll();
		}
		break;
		case 2:
		{
			cout << "--- SORT ORDER BY QUANTITY DESCENDING---" << endl;
			sort(6);
			showAll();
		}
		break;
		default:
			cout << "LOG: Invalid option!" << endl;
			break;
		}
	}

	//sort order based on ID, total, quantity (ASC,DESC)
	void sort(int direction)
	{
		Order* curr = head, * index = nullptr;

		if (head == nullptr) {
			return;
		}
		else {
			while (curr != nullptr)
			{
				index = curr->next;
				while (index != nullptr)
				{
					switch (direction)
					{
						case 1: {
							if (curr->orderID > index->orderID)
							{
								swap(curr, index);
							}
						}
							break;
						case 2: {
							if (curr->orderID < index->orderID)
							{
								swap(curr, index);
							}
						}
							break;
						case 3: {
							if (curr->total > index->total)
							{
								swap(curr, index);
							}
						}
							  break;
						case 4: {
							if (curr->total < index->total)
							{
								swap(curr, index);
							}
						}
							  break;
						case 5: {
							if (curr->quantity > index->quantity)
							{
								swap(curr, index);
							}
						}
							  break;
						case 6: {
							if (curr->quantity < index->quantity)
							{
								swap(curr, index);
							}
						}
							  break;
						default: {
							cout << "Error";
						}
							  break;
					}
					
					index = index->next;
				}
				curr = curr->next;
			}
		}
	}

	//sort by date
	void sortDate(int direction) {
		Order* curr = head, * index = nullptr;

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

					switch (direction)
					{
					case 1:
					{
						if (result == 1)
						{
							swap(curr, index);
						}
					}
					break;
					case 2:
					{
						if (result == -1)
						{
							swap(curr, index);
						}
					}
					break;
					default:
					{
						cout << "ERROR" << endl;
					}
					break;
					}
					
					index = index->next;
				}
				curr = curr->next;
			}
		}
	}

	//sort and generate report by newest
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
			sortDate(2);
			generateReport(1);
		}
		break;
		case 2:
		{
			cout << "--- SORT PENDING REPORT BY NEWEST ---" << endl;
			sortDate(2);
			generateReport(2);
		}
		break;
		case 3:
		{
			cout << "--- SORT CANCELLED REPORT BY NEWEST ---" << endl;
			sortDate(2);
			generateReport(3);
		}
		break;
		default:
			cout << "LOG: Invalid option!" << endl;
			break;
		}
	}

	//sort and generate report by oldest
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
			sortDate(1);
			generateReport(1);
		}
		break;
		case 2:
		{
			cout << "--- SORT PENDING REPORT BY OLDEST ---" << endl;
			sortDate(1);
			generateReport(2);
		}
		break;
		case 3:
		{
			cout << "--- SORT CANCELLED REPORT BY OLDEST ---" << endl;
			sortDate(1);
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