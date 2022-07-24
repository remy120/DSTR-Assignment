#ifndef ORDERLIST_LINKED_LIST_H_
#define ORDERLIST_LINKED_LIST_H_

#include "OrderList_Structure.h"
#include <iostream>		// std::cout
#include <algorithm>	// std::sort
#include <sstream>		// stringstream
#include <cassert>
#include <string>
#include <cstdlib>
#include <cstring>
#include <time.h>
#include <stdio.h>
#include <vector>

using namespace std;

//class OrderList_LinkedList
//{
//};

class OrderList
{
public:
	Order* head;
	int size;

	OrderList()
	{
		cout << "--- Constructing the LinkedList object ---" << endl;
		this->size = 0;
		this->head = nullptr;
	}

public:

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
	void deleteItemAt(int index)
	{
		if (index < size)
		{
			cout << "--- DELETE ORDER BY INDEX ---" << endl;
			if (index == 0)
				deleteFirst();
			else {
				Order* prev = nullptr;
				Order* toDelete = head;
				for (int i = 0; i < index; ++i)
				{
					prev = toDelete;
					toDelete = toDelete->next;
				}
				prev->next = toDelete->next;
				delete toDelete;
				size--;
				cout << "LOG:  Order #" << index << " is deleted..." << endl;
			}

		}//if
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
		}//if
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
		cout << "ID	|Buyer	|Order Date	|Total	|Quantity	|Status" << endl;
		if (head == nullptr)
		{
			cout << "List is empty" << endl;
			return;
		}
		while (curr != nullptr)
		{
			cout << "" << curr->orderID << "	 " << curr->buyerName << "	 " << curr->orderDate << "	 RM" << curr->total << "	 RM" << curr->quantity << "		 " << curr->status  << endl;
			curr = curr->next;
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