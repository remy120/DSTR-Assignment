#ifndef ORDERLIST_STRUCTURE_H_
#define ORDERLIST_STRUCTURE_H_

# include <iostream>
# include <vector>

using namespace std;

struct Order {
	int orderID;
	string buyerName;
	string buyerEmail;
	string orderDate;
	double total;
	string shippingAddss;
	int itemID;
	int quantity;
	string status;

	Order* next;
};

struct hardCodedOrder {
	int horderID;
	string hbuyerName;
	string hbuyerEmail;
	string horderDate;
	double htotal;
	string hshippingAddss;
	int hitemID;
	int hquantity;
	string hstatus;
};

#endif /* ORDERLIST_STRUCTURE_H_ */