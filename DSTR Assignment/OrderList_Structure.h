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
	string type;
	string status;

	Order* next;
};

//tuple declaration for order
typedef tuple<int, string, string, string, double, string, int, int, string, string> order;

#endif /* ORDERLIST_STRUCTURE_H_ */