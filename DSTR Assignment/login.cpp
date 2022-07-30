#include <iostream>
#include <string>
#include <vector>
#include <tuple>

using namespace std;

//tuple declaration for user
typedef tuple<int, string, string, string, int> user;

//add hard coded users
inline void addUser(vector<user>& userD) {
	userD.push_back(user(001, "Administrator", "admin@mail.com", "1234", 1));
	userD.push_back(user(002, "Sales Person", "sales@mail.com", "1234", 2));
}

//validate user
inline int validateUser(vector<user> userD) {
	char next = 'n';
	do {
		bool flag = true;
		string emailAddress, pass;
		cout << "Enter email: ";
		cin >> emailAddress;
		cout << "Enter password: ";
		cin >> pass;

		// Declaring iterator to a vector
		vector<user>::iterator ptr;

		for (user data: userD)
		{
			if (get<2>(data) == emailAddress && get<3>(data) == pass)
			{
				cout << "Login successfull. Welcome " << get<1>(data);
				flag = false;
				next = 'n';
				return get<4>(data);
			}
		}

		if (flag) {
			cout << "Login unsuccessfull." << endl;
			do {
				cout << "Try again? (y/n)." << endl;
				cin >> next;
			} while (next != 'y' && next != 'n');

		}

	} while (next == 'y');
	exit(0);
}