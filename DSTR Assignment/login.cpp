#include <iostream>
#include <string>

using namespace std;

struct user {
	int userID;
	string name;
	string email;
	string password;
	int role;
};

inline void userData(user* user) {
	user[0].userID = 001;
	user[0].name = "Remy";
	user[0].email = "remy@mail.com";
	user[0].password = "1234";
	user[0].role = 1;

	user[1].userID = 002;
	user[1].name = "Hanns";
	user[1].email = "hanns@mail.com";
	user[1].password = "1234";
	user[1].role = 2;

	user[2].userID = 003;
	user[2].name = "Aya";
	user[2].email = "aya@mail.com";
	user[2].password = "1234";
	user[2].role = 2;
}

inline int validateUser(user user[]) {
	char next = 'n';
	do {
		string emailAddress;
		string pass;
		bool flag = true;
		cout << "Enter email: ";
		cin >> emailAddress;

		cout << "Enter password: ";
		cin >> pass;

		for (int i = 0; i < 3; ++i)
		{
			if (user[i].email == emailAddress && user[i].password == pass)
			{
				cout << "Login successfull. Welcome " << user[i].name;
				flag = false;
				next = 'n';
				return user[i].role;
			}
		}

		if (flag) {
			cout << "Login unsuccessfull." << endl;
			do {
				cout << "Do you want to continue? (y/n)." << endl;
				cin >> next;
			} while (next != 'y' && next != 'n');
		}
	} while (next == 'y');
	exit(0);
}