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

inline void userData(user* users) {
	users[0] = { 001,"Remy","remy@mail.com","1234",1 };
	users[1] = { 002,"Hanns","hanns@mail.com","1234",2 };
	users[2] = { 003,"Aya","aya@mail.com","1234",2 };
}

//struct user users[5]
//	= { {001,"Remy","remy@mail.com","1234",1},
//		{002,"Hanns","hanns@mail.com","1234",2},
//		{003,"Aya","aya@mail.com","1234",2} };

//inline void userData(user* users) {
//	users[0].userID = 001;
//	users[0].name = "Remy";
//	users[0].email = "remy@mail.com";
//	users[0].password = "1234";
//	users[0].role = 1;
//
//	users[1].userID = 002;
//	users[1].name = "Hanns";
//	users[1].email = "hanns@mail.com";
//	users[1].password = "1234";
//	users[1].role = 2;
//
//	users[2].userID = 003;
//	users[2].name = "Aya";
//	users[2].email = "aya@mail.com";
//	users[2].password = "1234";
//	users[2].role = 2;
//}

inline int validateUser(user users[]) {
	char next = 'n';
	do {
		bool flag = true;
		string emailAddress, pass;
		cout << "Enter email: ";
		cin >> emailAddress;
		cout << "Enter password: ";
		cin >> pass;

		for (int i = 0; i < 5; ++i)
		{
			if (users[i].email == emailAddress && users[i].password == pass)
			{
				cout << "Login successfull. Welcome " << users[i].name;
				flag = false;
				next = 'n';
				return users[i].role;
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