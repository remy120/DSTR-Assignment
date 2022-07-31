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
inline int validateUser(vector<user> userD, int& id) {
	char next = 'n';
	do {
		bool flag = true;
		string emailAddress, pass;
		cout << "Enter email: ";
		cin >> emailAddress;
		cout << "Enter password: ";
		cin >> pass;

		for (user data: userD)
		{
			if (get<2>(data) == emailAddress && get<3>(data) == pass)
			{
				cout << "Login successfull. Welcome " << get<1>(data);
				flag = false;
				next = 'n';
				id = get<0>(data);
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

//show user
inline void showUser(user userD) {
	string position = "";
	user data = userD;
	//user data = userD.back();
	cout << "==========USER INFO==========" << endl;
	cout << "ID: " << get<0>(data) << endl;
	cout << "Name: " << get<1>(data) << endl;
	cout << "Email: " << get<2>(data) << endl;
	if (get<4>(data) == 1) {
		position = "Admin";
	}
	else if (get<4>(data) == 2) {
		position = "Sales";
	}
	else {
		position = "Invalid/Unknown";
	}
	cout << "Position: " << position << endl;
	cout << "=============================" << endl;
}

//show all users
inline void showAllUsers(vector<user> userD) {
	for (user data : userD)
	{
		showUser(data);
	}
}

//delete user
inline void delUsers(vector<user>& userD, int id) {
	int theID = 0, count = 0;
	bool del = false, found = false;
	for (user data : userD)
	{
		if (get<0>(data) != id) {
			showUser(data);
		}
	}
	do {
		cout << "Please input the UserID that you wanted to delete: ";
		cin >> theID;
		while (cin.fail())
		{
			cout << "Please input valid ID!" << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Please input the UserID that you wanted to delete: ";
			cin >> theID;
		}
		if (id == theID) {
			cout << "Cannot delete your own account!" << endl;
			del = false;
		}
		else {
			del = true;
		}
		if (del == true) {
			for (user data : userD)
			{
				if (get<0>(data) == theID) {
					found = true;
					break;
				}
				else {
					found = false;
				}
			}
			if (found) {
				for (user& data : userD)
				{
					if (get<0>(data) == theID) {
						userD.erase(userD.begin() + count);
						cout << "Account deleted!";
					}
					count++;
				}
			}
			else {
				cout << "Account not found!" << endl;
			}
		}
			
	} while (del == false || found == false);
}

//user change password
inline void changePassword(vector<user>& userD, int id) {
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	string currP, newP, confirmP = "";
	bool corrP = false, corrN = false;
	do {
		cout << "Current password: ";
		getline(cin, currP);
		for (user data : userD)
		{
			if (get<0>(data) == id) {
				corrP = true;
				if (get<3>(data) != currP) {
					cout << "Incorrect current password" << endl;
					corrP = false;
				}
			}
		}
	} while (corrP == false);
	do {
		cout << "New password: ";
		getline(cin, newP);
		cout << "Confirm new password: ";
		getline(cin, confirmP);
		if (newP == confirmP) {
			corrN = true;
			for (user& data : userD)
			{
				if (get<0>(data) == id) {
					get<3>(data) = confirmP;
					cout << "Password changed successfully!" << endl;
				}
			}
		}
		else {
			cout << "New password and confirm password not match!" << endl;
			corrN = false;
		}
	} while (corrN == false);
	
}

//add new user
inline void addNewUser(vector<user>& userD) {
	int id, pos = 0;
	string name, email = "";
	bool correctPos, validID = true;

	do {
		validID = true;
		cout << "ID (Number only): ";
		cin >> id;
		while (cin.fail())
		{
			cout << "Please input digits only!";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "ID (Number only): ";
			cin >> id;
		}
		for (user data : userD)
		{
			if (get<0>(data) == id)
			{
				cout << "User ID already exist!" << endl;
				validID = false;
			}
		}
	} while (validID == false);
	cin.ignore(numeric_limits <streamsize> ::max(), '\n');
	cout << "Name: ";
	getline(cin, name);
	cout << "Email: ";
	getline(cin, email);
	do {
		correctPos = true;
		cout << "Position (1=Admin, 2=Sales): ";
		cin >> pos;
		while (cin.fail())
		{
			cout << "Please input digits only!";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Position (1=Admin, 2=Sales): ";
			cin >> pos;
		}
		if (pos != 1 && pos != 2) {
			cout << "Please input 1 or 2 only!";
			correctPos = false;
		}
	} while (correctPos == false);
	cin.ignore(numeric_limits <streamsize> ::max(), '\n');
	userD.push_back(user(id, name, email, "1234", pos));

	cout << "\nNEW USER INFO" << endl;
	showUser(userD.back());
	cout << "Default password for new account is '1234'" << endl;
}