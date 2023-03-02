#include<iostream>
#include<fstream>
#include<cstring>
#include<sstream>
#include<ctime>
#include<limits>
#include<vector>
#include<chrono>
#include "encrypter.h"
#include <Windows.h>
#include "date.h"
#pragma warning(disable: 4996)

string GlobalUserName;
//using namespace std;
using std::cout;
using std::cin;
using std::string;
class login_signup
{
	
public:
	string user_name;
	bool admin();
	bool user();
	string name()
	{
		return user_name;
	}
};

bool login_signup::user()
{
	bool password_valid = false;
	char ch;
	string signup_name, signup_password;
	string encrypt_name, encrypt_password;
	cout << "Do you have an account (y/n) ?: " << std::endl;
	cin >> ch;
	if (ch == 'y')
	{

		std::vector<std::string> row;
		std::string line, word, temp;

		std::string nameU, passwordU;
		std::fstream user_login;

		std::string check_name, check_password;
		cin.ignore();
		cout << "--------------Login--------------\n" << endl;
		cout << "Enter your name: " << std::endl;
		getline(cin, nameU);
		cout << "Enter the password: " << std::endl;
		getline(cin, passwordU);
	    user_name = nameU;
		GlobalUserName = nameU;
		check_name = encrypt::entry(nameU);
		check_password = encrypt::entry(passwordU);
		user_login.open("users/users.txt", std::ios::in);
		if (user_login.is_open())
		{
			string store;
			int i = 0;
			while (getline(user_login, store))
			{
				if (store == check_name)
					i = 2;
				
				if (i == 1)
					if (store == check_password)
						password_valid = true;

				if (i == 2)
					i--;
			}
		}
		else
		{
			cout << "Error login" << std::endl;
		}
		user_login.close();

	}
	else if (ch == 'n')
	{
		cout << "Please ask admin to create an account: " << std::endl;

	}
	else
		cout << "Invalid input " << std::endl;

	return password_valid;
}

bool login_signup::admin()
{    
	bool password_valid = false;
	char ch;
	string signup_name, signup_password;
	string encrypt_name, encrypt_password;
	cout << "Do you have an account (y/n) ?: " << std::endl;
	cin >> ch;
	if (ch == 'y')
	{     

	login:  
		ch = 'y'; 
		std::vector<std::string> row;
		std::string line, word, temp;

		std::string name, password;
		std::fstream admin_login;
                                  
		std::string check_name, check_password;
		cin.ignore();
		cout << "--------------Login--------------\n" << endl;
		cout << "Enter your name: " << std::endl;
		getline(cin,name);
		cout << "Enter the password: " << std::endl;
		getline(cin,password);
		check_name = encrypt::entry(name);
		check_password = encrypt::entry(password);
		admin_login.open("LoginSignup/admin_login_signup.txt", std::ios::in);
		if (admin_login.is_open())
		{
			string store;
			int i = 0;
			while (getline(admin_login, store))
			{
				if (store == check_name)
				{   
					//cout << store << check_name;
					i = 2;
				}
				if (i == 1)
				{
					i = 0;
					if (store == check_password)
					{   
						//cout << store << check_password;
						password_valid = true;
						
					}
				}
				if (i == 2)
				{
					i--;
				}
			}
		}
		else
		{
			cout << "Error login" << std::endl;
		}
	}
	else if(ch == 'n')
	{ 
	signup: 
		cin.ignore();
		cout << "--------------Create Account--------------\n" << std::endl;
		cout << "Enter your name: " << std::endl;
		getline(cin,signup_name);
		cout << "Enter your password: " << std::endl;
		getline(cin,signup_password);

		encrypt_name = encrypt::entry(signup_name);
		encrypt_password = encrypt::entry(signup_password);
        
		//cout << encrypt_name << "   " << encrypt_password << std::endl; // check if error occur :)

		fstream check_account;
		bool account_found = false;
		check_account.open("LoginSignup/admin_login_signup.txt", std::ios::in);
		if (check_account.is_open())
		{
			cout << "Admin account had already been created: " << std::endl;
			account_found = true;
			goto login;
		}
		check_account.close();


		if (account_found == false)
		{
			fstream signup;
			signup.open("LoginSignup/admin_login_signup.txt", ios::in | ios::out | ios::app);
			if (signup.is_open())
			{
				signup << encrypt_name << std::endl;
				signup << encrypt_password << std::endl;
				goto login;

			}
			else
				cout << "Error Creating account: " << std::endl;
			signup.close();

		}
		
	}
	else
	{
	cout << "Error login/signup" << endl;
	}



	return password_valid;
}
int intro()
{
	login_signup ls;
	int ch;
	bool check = false;
	cin.ignore();
	label:
	cout << "1. Admin" << std::endl;
	cout << "2. User" << std::endl;
	cout << "Enter the choice: " << std::endl;
	cin >> ch;
	if (ch == 1)
	{
		check = ls.admin();
	}

	else if (ch == 2)
	{
		check = ls.user();
	}
	else
	{
		cout << "choose either 1 or 2: " << std::endl;
		goto label;
	}

	if (ch == 1 && check == true)
		return 1;
	if (ch == 2 && check == true)
		return 2;
	else
		return 0;

}

class user_main_menu
{
public:
	
	void take_book();
	void pending_books();
	void return_books();
	void returned_books();
};

void user_main_menu::take_book()
{    
	//cout << user_name;
	string name, Taken_book_store;
	//string store_id_taken_book;
	int book_id;
	string encrypt_name;
	bool valid_user = false, found_repeat = false, insert_id = false;
	bool taken_book = false;
	string delete_book, book_no;
	name = GlobalUserName;
	//cout << "hello, " << GlobalUserName;
	encrypt_name = encrypt::entry(name);
	fstream namecheck;
	namecheck.open("users/users.txt", ios::in);
	if (namecheck.is_open())
	{
		int i = 0;
		string check;
		while (getline(namecheck, check))
		{

			if (encrypt_name == check)
			{
				if (i % 2 == 0)
					valid_user = true;

			}
			i++;



		}
	}
	else
		cout << "Error taking book " << std::endl;
	namecheck.close();

	fstream check_pending;
	check_pending.open("users/users_pending.txt", ios::in);
	if (check_pending.is_open())
	{
		string users;
		while (getline(check_pending, users))
		{
			if (name == users)
			{
				cout << "Please return the previos book: " << endl;
				valid_user = false;
				return;
			}
		}

	}



	if (valid_user == true)
	{
		cout << "Enter the book ID: " << std::endl;
		cin >> book_id;

		string Book_id = to_string(book_id);
		fstream book;
		fstream check_repeat;
		check_repeat.open("books/RepeatID.txt", ios::in | ios::out | ios::app);
		if (check_repeat.is_open()) {

			string store;
			while (getline(check_repeat, store))
			{
				if (store == Book_id)
				{
					found_repeat = true;
				}
			}
		}
		else
			cout << "Error " << endl;
		check_repeat.close();
		if (found_repeat == true)
		{
			cout << "The book has already been taken: " << endl;
			return;
		}


		fstream copy_of_available_books; 
		copy_of_available_books.open("books/CheckBooks.txt", ios::in | ios::out | ios::app);
		book.open("books/available_books.txt", ios::in | ios::out | ios::app);
		if (book.is_open())
		{
			int i = 1;
			bool check_id = false, update_check = false, if_not_found = false;
			string store_book;
			int store_book_id;
			while (getline(book, store_book, '*'))
			{
				//cout << store_book << endl;;


				if (check_id == true)
				{
					cout << "Seleceted book is: " << store_book << endl;
					delete_book = "*" + book_no + "*" + store_book;
					check_id = false;
				}


				if (i % 2 == 0)
				{

					string copy_book = store_book;
					store_book_id = stoi(store_book);
					if (store_book_id == book_id) {
						book_no = to_string(store_book_id);
						check_id = true;
						if_not_found = true;
						insert_id = true;
						copy_of_available_books << "*" << book_no << "*" << endl;

					}
					copy_book.erase(std::remove(copy_book.begin(), copy_book.end(), ' '), copy_book.end());
					copy_of_available_books << "*" << copy_book << "*";
				}
				else
					copy_of_available_books << store_book;


				i++;



			}

			if (if_not_found == false) {
				cout << "Book not found: " << endl;
				return;
			}





		}
		else
			cout << "Error taking book" << std::endl;
		if (insert_id == true)
		{
			fstream file;
			file.open("books/RepeatID.txt", ios::in | ios::out | ios::app);
			if (file.is_open())
			{
				file << book_no << endl;
			}
			else
			{
				cout << "Error ";
				return;
			}
			file.close();
		}
		else
		{
			cout << "Error";
			return;
		}

		book.close();
		copy_of_available_books.close();
		check_repeat.close();
		std::remove("books/available_books.txt");

		fstream rename_book;
		fstream update;
		update.open("books/updated.txt", ios::in | ios::out | ios::app);
		//delete_book.erase(remove(delete_book.begin(), delete_book.end(), ' '),delete_book.end());
		delete_book.erase(std::remove(delete_book.begin(), delete_book.end(), '\n'), delete_book.end());
		delete_book.erase(std::remove(delete_book.begin(), delete_book.end(), ','), delete_book.end());
		rename_book.open("books/CheckBooks.txt", ios::in | ios::out | ios::app);
		Taken_book_store = delete_book;
		if (rename_book.is_open())
		{
			string store_, Rename;
			Rename = delete_book;
			cin.ignore(); // clear buffer
			cin.get();
			int i = 0;
			const char* f;
			while (getline(rename_book, store_))
			{

				//store_.erase(remove(store_.begin(), store_.end(), ' '), store_.end());
				store_.erase(std::remove(store_.begin(), store_.end(), '\n'), store_.end());
				store_.erase(std::remove(store_.begin(), store_.end(), ','), store_.end());

				if (Rename != store_)
				{
					taken_book = true;
					update << store_ << endl;

				}

			}



		}
		else
			cout << "Error taking book: " << endl;

		rename_book.close();
		update.close();
		std::remove("books/Checkbooks.txt");
		std::rename("books/updated.txt", "books/available_books.txt");


		if (taken_book == true)
		{
			auto start = std::chrono::system_clock::now();
			auto legacyStart = std::chrono::system_clock::to_time_t(start);
			char tmBuff[30];
			ctime_s(tmBuff, sizeof(tmBuff), &legacyStart);
			std::cout << tmBuff << '\n';

			string date = tmBuff;
			date;
			fstream taken, users_pending;
			users_pending.open("users/users_pending.txt", ios::in | ios::out | ios::app);
			if (users_pending.is_open())
			{
				users_pending << name << endl;
			}
			else
				cout << "Error taking books" << endl;
			users_pending.close();
			taken.open("books/TakenBooks.csv", ios::in | ios::out | ios::app);
			if (taken.is_open())
			{
				taken << ",Name      : " << name << ',' << "Taken Book: " << Taken_book_store << ',' << "Taken Date: " << date;
			}
			else
				cout << "Error taking books" << endl;
			taken.close();

			fstream pending;
			pending.open("books/Pendingbooks.txt", ios::in | ios::out | ios::app);
			if (pending.is_open())
			{
				string duedate = TodayDate::InputDate();
				pending << name << endl << Taken_book_store << endl << duedate << endl;
			}
			else
				cout << "Error taking book" << endl;

			pending.close();
		}

	}
	else
		cout << "User not found" << std::endl;
}

void user_main_menu::pending_books()
{
	string name, store_date, store_book; // , compare_date;
	char* seperate;
	char* compare_seperate;
	int i = 0;
	
	name = GlobalUserName;

	string todaydate = TodayDate::DateGive();

	bool book_found = false;
	fstream collect_date;
	collect_date.open("books/Pendingbooks.txt", ios::in | ios::out | ios::app);
	if (collect_date.is_open())
	{
		string store;
		while (getline(collect_date, store))
		{
			if (name == store)
			{
				i = 3;

			}
			if (i == 1)
			{
				store_date = store;
				book_found = true;
				break;
			}
			if (i == 2)
			{
				store_book = store;
				i--;
			}

			if (i == 3)
			{
				i--;
			}

		}



	}
	else
		cout << "Error" << endl;
	collect_date.close();

	if (book_found == true)
	{


		string day, month, year;
		string str_obj(todaydate);
		seperate = &str_obj[0];
		day += seperate[0];
		day += seperate[1];

		month += seperate[2];
		month += seperate[3];

		year += seperate[4];
		year += seperate[5];
		year += seperate[6];
		year += seperate[7];


		int dayint, monthint, yearint;


		dayint = stoi(day);
		monthint = stoi(month);
		yearint = stoi(year);



		//compare_date = TodayDate::DateGive();
		string cday, cmonth, cyear;       // cday -> compareday
		string str_obj1(store_date);
		compare_seperate = &str_obj1[0];
		cday += compare_seperate[0];
		cday += compare_seperate[1];

		cmonth += compare_seperate[2];
		cmonth += compare_seperate[3];

		cyear += compare_seperate[4];
		cyear += compare_seperate[5];
		cyear += compare_seperate[6];
		cyear += compare_seperate[7];

		int cdayint, cmonthint, cyearint;

		cdayint = stoi(cday);
		cmonthint = stoi(cmonth);
		cyearint = stoi(cyear);

		cout << "Book is:  [ " << store_book << " ]" << endl;
		cout << "\nReturn on or before : " << cday << "/ " << cmonth << "/ " << cyear << "\n\n" << endl;

		if (yearint > cyearint)
		{
			cout << "Failed to return the book: " << endl;

		}
		else if (yearint == cyearint)
		{
			if (monthint > cmonthint)
			{
				cout << "Failed to return the book: " << endl;

			}
			else if (monthint == cmonthint)
			{
				if (dayint > cdayint)
				{
					cout << "Failed to return the book: " << endl;
				}
				else if (dayint == cdayint)
				{
					cout << "Today is the last date: " << endl;
				}
				else
					cout << "No books to return: " << endl;

			}
			else
				cout << "No books to return: " << endl;
		}
		else
			cout << "No book pending" << endl;




	}
	else
		cout << "User/Book not found: " << endl;
}

void user_main_menu::return_books()
{

	bool check_book = false, return_success = false, All_success = false;
	string name, storebook, storedate;
    
	name = GlobalUserName;
	fstream return_books, firsthalf, secondhalf, joint;

	firsthalf.open("books/first.txt", ios::in | ios::out | ios::app);
	secondhalf.open("books/second.txt", ios::in | ios::out | ios::app);
	return_books.open("books/Pendingbooks.txt", ios::in | ios::out | ios::app);
	if (return_books.is_open())
	{
		int i = 0;
		string store;
		while (getline(return_books, store))
		{

			if (store == name)
			{
				i = 3;
			}
			if (i == 1)
			{

				storedate = store;
				check_book = true;
				break;
			}
			if (i == 2)
			{

				storebook = store;
				i--;
			}
			if (i == 3)
			{
				i--;
			}
		}

	}
	else {
		cout << "Error " << endl;
		return;
	}
	return_books.close();

	char* sep;
	bool check = false;
	int  j = 0, k = 0;
	string str_obj(storebook);
	sep = &str_obj[0];

	for (int i = 0; i <= storebook.length(); i++)
	{
		if (sep[i] == '*' && check == false)
		{
			j = i + 1;
			check = true;

		}
		if (sep[i + 1] == '*' && check == true)
		{
			k = i;
			break;
		}

	}
	string sep_store = "", sep_store_with;
	if (j != k)
	{
		for (int i = j; i <= k; i++)
			sep_store += sep[i];
	}
	else
		sep_store = sep[j];

	sep_store_with = "*" + sep_store + "*";

	if (check_book == true)
	{
		int i = 0;
		fstream book;
		book.open("books/available_books.txt", ios::in | ios::out | ios::app);
		if (book.is_open())
		{

			string store;
			while (getline(book, store))
			{
				if (store != sep_store_with)
				{
					firsthalf << store << endl;
				}
				else
					break;
			}
			firsthalf << storebook << endl;


		}
		else
		{
			cout << "User not found/ No books to return/ Error " << endl;
			return;
		}
		book.close();
		firsthalf.close();
		fstream books;
		books.open("books/available_books.txt", ios::in | ios::out | ios::app);
		if (books.is_open())
		{
			int i = 0;
			string store;
			while (getline(books, store))
			{
				if (store == sep_store_with)
				{
					i = 2;
				}
				if (i == 1)
					secondhalf << store << endl;
				if (i == 2)
				{
					i = 1;
				}
			}

		}

		secondhalf.close();
		books.close();


	}
	else
	{
		cout << "User not found/ No books to return/ Error " << endl;
		return;
	}

	if (check_book == true)
	{
		fstream first, second;
		first.open("books/first.txt", ios::in | ios::out | ios::app);
		second.open("books/second.txt", ios::in | ios::out | ios::app);
		if (second.is_open())
		{
			string store;
			while (getline(second, store))
			{
				first << store << endl;
			}
			return_success = true;
		}
		else
			cout << "Error " << endl;
		first.close();
		second.close();

		std::remove("books/second.txt");
		std::remove("books/available_books.txt");
		std::rename("books/first.txt", "books/available_books.txt");

	}
	else
	{
		cout << "User not found/ No books to return/ Error " << endl;
		return;
	}

	if (return_success == true)
	{
		int i = 0;
		fstream file, renamePB, userP, renamePU;
		renamePU.open("users/newfile.txt", ios::in | ios::out | ios::app);
		userP.open("users/users_pending.txt", ios::in | ios::out | ios::app);
		if (userP.is_open() && renamePU.is_open())
		{
			string store;
			while (getline(userP, store))
			{
				if (store != name)
					renamePU << store << endl;
			}
		}
		else
		{
			cout << "Error " << endl;
			return;
		}
		renamePU.close();
		userP.close();
		std::remove("users/users_pending.txt");
		std::rename("users/newfile.txt", "users/users_pending.txt");



		renamePB.open("books/file.txt", ios::in | ios::out | ios::app);
		file.open("books/Pendingbooks.txt", ios::in | ios::out | ios::app);
		if (file.is_open() && renamePB.is_open())
		{
			int i = 0;
			string store;
			while (getline(file, store))
			{
				if (store == name)
					i = 3;
				if (i > 0)
					i--;
				else
					renamePB << store << endl;

			}

			All_success = true;
		}
		else
		{
			cout << "Error " << endl;
			return;
		}
		renamePB.close();
		file.close();
		std::remove("books/Pendingbooks.txt");
		std::rename("books/file.txt", "books/Pendingbooks.txt");


		fstream delete_checkid;
		fstream new_chekid;
		new_chekid.open("books/newcheckid.txt", ios::in | ios::out | ios::app);
		delete_checkid.open("books/RepeatID.txt", ios::in | ios::out | ios::app);
		if (delete_checkid.is_open())
		{
			string store;
			while (getline(delete_checkid, store))
			{
				if (store != sep_store)
					new_chekid << store << endl;
			}
		}
		else
			cout << "Error" << endl;
		new_chekid.close();
		delete_checkid.close();
		std::remove("books/RepeatID.txt");
		cin.ignore();
		std::rename("books/newcheckid.txt", "books/RepeatID.txt");


		fstream return_book_history;
		auto start = std::chrono::system_clock::now();
		auto legacyStart = std::chrono::system_clock::to_time_t(start);
		char tmBuff[30];
		ctime_s(tmBuff, sizeof(tmBuff), &legacyStart);
		string date = tmBuff;
		return_book_history.open("books/ReturnedBooks.csv", ios::in | ios::out | ios::app);
		if (return_book_history.is_open())
		{
			return_book_history << ",Name      : " << name << ',' << "Taken Book: " << storebook << ',' << "Taken Date: " << date;
		}
		else
		{
			cout << "Error" << endl;
			return;
		}
		return_book_history.close();

	}
	else
		cout << "User not found/ No books to return/ Error " << endl;


	if (All_success == true)
	{
		cout << "The Book: [" << storebook << "]" << endl;
		cout << "\n\n                              S U C C E S S F U L L Y      R E T U R N E D \n\n" << endl;
		cin.ignore();
		system("cls");
	}

}
void user_main_menu::returned_books()
{
	fstream show_returned_books;
	show_returned_books.open("books/ReturnedBooks.csv", ios::in);
	if (show_returned_books.is_open())
	{
		string store;
		cout << "____________________________________________" << endl;
		while (getline(show_returned_books, store, ','))
		{
			cout << "|      " << store << endl;
		}
		cout << "____________________________________________" << endl;
	}
	else
		cout << "Error " << endl;
	show_returned_books.close();
}

class Main_menu
{
public:
	void books();
	void add_user();
	void display_users();
	void take_book();
	void taken_books();
	void pending_books();
	void return_book();
	void returned_books();
	void search();
	void add_book();
	void delete_book();
	void delete_user();

};


void Main_menu::search()
{   
	system("cls");
	fstream file;
	string book, book_space;
	bool found = false;
	cin.ignore();
	cout << "Search: " << endl;
	getline(cin, book);
	book_space = book;
	book.erase(remove(book.begin(), book.end(), ' '), book.end());
	book.erase(remove(book.begin(), book.end(), ','), book.end());
	book.erase(remove(book.begin(), book.end(), '\n'), book.end());
	book.erase(remove(book.begin(), book.end(), '"'), book.end());
	book.erase(remove(book.begin(), book.end(), '\''), book.end());
	

	vector<char>ch;
	vector<char>ch1;



	for (int i = 0; i < book.length(); i++) {

		// convert str[i] to lowercase
		ch.push_back( std::tolower(book[i]));
		
	}
	string cmp(ch.begin(), ch.end());






	file.open("books/available_books.txt", ios::in | ios::out | ios::app);
	if (file.is_open())
	{
		string store, id, storebook;
		int i = 1;
		while (getline(file, store, '*'))
		{

			if (i % 2 != 0)
			{
				ch1.clear();
				store.erase(remove(store.begin(), store.end(), ' '), store.end());
				store.erase(remove(store.begin(), store.end(), ','), store.end());
				store.erase(remove(store.begin(), store.end(), '\n'), store.end());
				store.erase(remove(store.begin(), store.end(), '"'), store.end());
				store.erase(remove(store.begin(), store.end(), '\''), store.end());

				for (int j = 0; j < store.length(); j++) {

					// convert str[i] to lowercase
					ch1.push_back(std::tolower(store[j]));

				}
				string cmp1(ch1.begin(), ch1.end());

				if (cmp1 == cmp)
				{
					found = true;
					break;
				}

			}
			else
				id = store;
			i++;
		     
		}

		if (found == true)
			cout <<endl<< "Book id: [ " << id <<" ]"<< endl << "Book   : [ " << book_space << " ]" << endl;
		else
			cout << "No search results " << endl;


	}
	else
		cout << "Error " << endl;


}


void Main_menu::add_book()
{
	fstream books, id, idupdate;
	bool check = false;
	string bookname, idupdated;
	int Bookid;
	id.open("books/createid.txt", ios::in | ios::out | ios::app);
	if (id.is_open())
	{
		string bookid;
		string store;
		while (getline(id, store))
		{
			bookid = store;
		}

		Bookid = stoi(bookid);
		Bookid = Bookid + 1;
		idupdated = to_string(Bookid);
	}

	else
	{
		cout << "Error adding book " << endl;
		return;
	}
     
	id.close();

	idupdate.open("books/createid.txt", ios::out);
	if (idupdate.is_open())
	{

		idupdate << idupdated << endl;
		
	}
	else
	{
		cout << "Error adding book " << endl;
		return;
	}
	idupdate.close();

	cin.ignore();
	cout << "Book name: " << endl;
	getline(cin, bookname);
	bookname.erase(std::remove(bookname.begin(), bookname.end(), '\n'), bookname.end());
	bookname.erase(std::remove(bookname.begin(), bookname.end(), ','), bookname.end());
	books.open("books/available_books.txt", ios::in | ios::out | ios::app);
	if (books.is_open())
	{
		string inputid = idupdated;
		
		books << "*"<<inputid <<"*"<< " " << bookname << endl;
		check = true;
	}
	else
		cout << "Error adding book " << endl;
	books.close();

	if (check == true)
	{
		cout << "S U C C E S F U L L" << endl;
	}
}

void Main_menu::books()
{   
	system("cls");
	fstream books;
	books.open("books/available_books.txt", ios::in);
	if (books.is_open())
	{
		int j = 0;
		string Available_books;
		cout << "\t Welcome to picsolet library!\n\n" << "\t ***AVAILABLE BOOKS***\n" << endl;
		cout << "*********************************************" << endl;
		cout << "          P R E S S   E N T E R  " << endl << endl;

		system("pause");
		while (getline(books, Available_books))
		{

			//cout << endl << "\t|_______________________________________________________________________________________" << endl;
			//cout << "\t|                                                                                                 |" << endl;
			cout << "\t |  " << Available_books <<endl;
			//cout << "\t|_______________________________________________________________________________________|" << endl << endl;
			j++;

		}
	}
	else
		cout << "Error: " << std::endl;

}

void  Main_menu::pending_books() {

	string name, store_date, store_book; // , compare_date;
	char* seperate;
	char* compare_seperate;
	int i = 0;
	cin.ignore();
	cout << "Enter your name: " << endl;
	getline(cin, name);

	string todaydate = TodayDate::DateGive();

	bool book_found = false;
	fstream collect_date;
	collect_date.open("books/Pendingbooks.txt", ios::in | ios::out | ios::app);
	if (collect_date.is_open())
	{
		string store;
		while (getline(collect_date, store))
		{
			if (name == store)
			{
				i = 3;

			}
			if (i == 1)
			{
				store_date = store;
				book_found = true;
				break;
			}
			if (i == 2)
			{
				store_book = store;
				i--;
			}

			if (i == 3)
			{
				i--;
			}

		}



	}
	else
		cout << "Error" << endl;
	collect_date.close();

	if (book_found == true)
	{
		

		string day, month, year;
		string str_obj(todaydate);
		seperate = &str_obj[0];
		day += seperate[0];
		day += seperate[1];

		month += seperate[2];
		month += seperate[3];

		year += seperate[4];
		year += seperate[5];
		year += seperate[6];
		year += seperate[7];


		int dayint, monthint, yearint;


		dayint = stoi(day);
		monthint = stoi(month);
		yearint = stoi(year);



		//compare_date = TodayDate::DateGive();
		string cday, cmonth, cyear;       // cday -> compareday
		string str_obj1(store_date);
		compare_seperate = &str_obj1[0];
		cday += compare_seperate[0];
		cday += compare_seperate[1];

		cmonth += compare_seperate[2];
		cmonth += compare_seperate[3];

		cyear += compare_seperate[4];
		cyear += compare_seperate[5];
		cyear += compare_seperate[6];
		cyear += compare_seperate[7];

		int cdayint, cmonthint, cyearint;

		cdayint = stoi(cday);
		cmonthint = stoi(cmonth);
		cyearint = stoi(cyear);

		cout << "Book is:  [ " << store_book << " ]" << endl;
		cout << "\nReturn on or before : " << cday << "/ " << cmonth << "/ " << cyear << "\n\n"<<endl;

		if (yearint > cyearint)
		{
			cout << "Failed to return the book: " << endl;

		}
		else if (yearint == cyearint)
		{
			if (monthint > cmonthint)
			{
				cout << "Failed to return the book: " << endl;

			}
			else if (monthint == cmonthint)
			{
				if (dayint > cdayint)
				{
					cout << "Failed to return the book: " << endl;
				}
				else if (dayint == cdayint)
				{
					cout << "Today is the last date: " << endl;
				}
				else
					cout << "No books to return: " << endl;

			}
			else
				cout << "No books to return: " << endl;
		}
		else
			cout << "No book pending" << endl;

		

      
	}
	else
		cout << "User/Book not found: " << endl;
}

void Main_menu::taken_books()
{
	fstream show_taken_books;
	show_taken_books.open("books/TakenBooks.csv", ios::in);
	if (show_taken_books.is_open())
	{
		string store;
		cout << "____________________________________________" << endl;
		while (getline(show_taken_books, store, ','))
		{
			cout <<"|      "<< store << endl;
		}
		cout << "____________________________________________" << endl;
	}
	else
		cout << "Error " << endl;

}

void Main_menu::add_user()
{
	string name;
	string password;
	string age;
	int updated_no = 0;
	int reg_no = 0;
	string reg_no_;
	string encrypt_name, encrypt_password;

	auto start = std::chrono::system_clock::now();
	auto legacyStart = std::chrono::system_clock::to_time_t(start);
	char tmBuff[30];
	ctime_s(tmBuff, sizeof(tmBuff), &legacyStart);
	string date = tmBuff;
	date += ",";
	fstream regno;

	regno.open("users/registerno.txt", ios::in | ios::out | ios::app); //if error occur create this txt file and give 0 as value
	if (regno.is_open())
	{


		while (getline(regno, reg_no_));
		reg_no = stoi(reg_no_);
		updated_no = reg_no + 1;

	}
	regno.close();
	fstream regno_update;
	regno_update.open("users/registerno.txt", ios::out);
	if (regno_update.is_open())
		regno_update << updated_no;
	regno_update.close();



signup:
	cin.ignore();
	cin.get();
	cout << "--------------Create Account--------------\n" << std::endl;
	cout << "Enter your name: " << std::endl;
	getline(cin, name);
	cout << "Enter your password: " << std::endl;
	getline(cin, password);
   
	fstream just_name;
	just_name.open("users/user.txt", ios::in | ios::out | ios::app);
	if (just_name.is_open())
	{
		just_name << name<<endl;
	}
	else
		cout << "Error creating account " << std::endl;

	encrypt_name = encrypt::entry(name);
	encrypt_password = encrypt::entry(password);

	//cout << encrypt_name << "   " << encrypt_password << std::endl; // check if error occur :)

	fstream check_account;
	bool account_found = false;
	check_account.open("users/users.txt", std::ios::in);
	if (check_account.is_open())
	{
		string store;
		//int i = 0;
		while (getline(check_account, store))
		{
			if (store == encrypt_name)
			{
				account_found = true;
			}

		}

	}
	check_account.close();


	if (account_found == false)
	{
		fstream signup;
		signup.open("users/users.txt", ios::in | ios::out | ios::app);
		if (signup.is_open())
		{
			signup << encrypt_name << std::endl;
			signup << encrypt_password << std::endl;


		}
		else
			cout << "Error Creating account: " << std::endl;
		signup.close();

	}
	else
	{
		cout << "Already have an account of this name: " << endl;
		cout << "Try another name: " << endl;
		system("pause");
		goto signup;
	}

	fstream user_data;
	cout << "Enter your age: " << endl;
	cin >> age;
	user_data.open("users/user_data.csv", ios::in | ios::out | ios::app);
	if (user_data.is_open())
	{
		user_data << "register no:        " << reg_no_ << ',' << "Name:               " << name << ',' << "Age:                " << age << ',' << "Account created on: " << date;
	}
	user_data.close();
}
void Main_menu::display_users()
{
	fstream user_data;
	vector<string>data;
	user_data.open("users/user_data.csv", ios::in);
	if (user_data.is_open())
	{    
		int i = 0;
		string datas;
		cout << "____________________________________________________" << endl;
		while (getline(user_data, datas, ',')) {
			data.push_back(datas);
			cout <<"|       "<< data[i] << endl;
			i++;
		}
		cout << "____________________________________________________" << endl;
		
		
	}
	user_data.close();
	
	//for (int i = 0; i < 5; i++)
		//cout << data[i] <<endl;

}
void Main_menu::take_book()
{
	string name,Taken_book_store;
	//string store_id_taken_book;
	int book_id;
	string encrypt_name;
	bool valid_user = false, found_repeat = false, insert_id = false;
	bool taken_book = false;
	cin.ignore();
	string delete_book,book_no;
	cout << "Enter your name: " << std::endl;
	getline(cin, name);
	encrypt_name = encrypt::entry(name);
	fstream namecheck;
	namecheck.open("users/users.txt", ios::in);
	if (namecheck.is_open())
	{   
		int i = 0;
		string check;
		while (getline(namecheck, check))
		{
			
			if (encrypt_name == check)
			{
				if (i % 2 == 0)
					valid_user = true;
				
			}
			i++;
			


		}
	}
	else
		cout << "Error taking book " << std::endl;
	namecheck.close();

	fstream check_pending;
	check_pending.open("users/users_pending.txt", ios::in);
	if(check_pending.is_open())
	{
		string users;
		while (getline(check_pending, users))
		{
			if (name == users)
			{   
				cout << "Please return the previos book: " << endl;
				valid_user = false;
				return;
			}
		}
		
	}


	
	if (valid_user == true)
	{
		cout << "Enter the book ID: " << std::endl;
		cin >> book_id;

		string Book_id = to_string(book_id);
		fstream book;
		fstream check_repeat;
		check_repeat.open("books/RepeatID.txt", ios::in | ios::out | ios::app);
		if (check_repeat.is_open()) {

			string store;
			while (getline(check_repeat, store))
			{
				if (store == Book_id)
				{
					found_repeat = true;
				}
			}
		}
		else
			cout << "Error " << endl;
		check_repeat.close();
		if (found_repeat == true)
		{
			cout << "The book has already been taken: " << endl;
			return;
		}

		
		fstream copy_of_available_books; // , firsthalf, secondhalf;

		//firsthalf.open("bookfirsthalf.txt", ios::in | ios::out | ios::app);
		//secondhalf.open("booksecondhalf.txt", ios::in | ios::out | ios::app);
		copy_of_available_books.open("books/CheckBooks.txt", ios::in | ios::out | ios::app);
		book.open("books/available_books.txt", ios::in | ios::out | ios::app);
		if (book.is_open())
		{  
			int i = 1 ;
			bool check_id = false, update_check = false, if_not_found = false;
			string store_book;
			int store_book_id;
			while (getline(book, store_book, '*'))
			{   
				//cout << store_book << endl;;

				
				if (check_id == true)
				{
					cout << "Seleceted book is: "<< store_book << endl;
					delete_book = "*" + book_no + "*" + store_book;
					check_id = false;
					
				}

				
				if (i % 2 == 0)
				{

					string copy_book = store_book;
					store_book_id = stoi(store_book);
					if (store_book_id == book_id) {
						book_no = to_string(store_book_id);
						check_id = true;
						if_not_found = true;
						insert_id = true;
						copy_of_available_books <<"*"<<book_no <<"*"<< endl;

					}
					copy_book.erase(std::remove(copy_book.begin(), copy_book.end(), ' '), copy_book.end());
					copy_of_available_books << "*"<<copy_book<<"*";
				}
				else
					 copy_of_available_books<<store_book;
				

				i++;

				
				
			}
			
			if (if_not_found == false) {
				cout << "Book not found: " << endl;
				return;
			}
			
			

		
			
		}
		else
			cout << "Error taking book" << std::endl;
		if (insert_id == true)
		{
			fstream file;
			file.open("books/RepeatID.txt", ios::in | ios::out | ios::app);
			if (file.is_open())
			{
				file << book_no << endl;
			}
			else
			{
				cout << "Error ";
				return;
			}
			file.close();
		}
		else
		{
			cout << "Error";
			return;
		}
		
		book.close();
		copy_of_available_books.close();
		check_repeat.close();
		std::remove("books/available_books.txt");
		
		fstream rename_book;
		fstream update;
		update.open("books/updated.txt", ios::in | ios::out | ios::app);
		//delete_book.erase(remove(delete_book.begin(), delete_book.end(), ' '),delete_book.end());
		delete_book.erase(std::remove(delete_book.begin(), delete_book.end(), '\n'), delete_book.end());
		delete_book.erase(std::remove(delete_book.begin(), delete_book.end(), ','), delete_book.end());
		rename_book.open("books/CheckBooks.txt", ios::in | ios::out | ios::app);
		Taken_book_store = delete_book;
		if (rename_book.is_open())
		{
			string store_, Rename;
			Rename = delete_book;
			cin.ignore(); // clear buffer
			//cin.get();
			int i = 0;
			while (getline(rename_book, store_))
			{

				//store_.erase(remove(store_.begin(), store_.end(), ' '), store_.end());
				store_.erase(std::remove(store_.begin(), store_.end(), '\n'), store_.end());
				store_.erase(std::remove(store_.begin(), store_.end(), ','), store_.end());

				if (Rename != store_)
				{
					taken_book = true;
					update << store_ << endl;
					
				}
				
			}



		}
		else
			cout << "Error taking book: " << endl;
		
		rename_book.close();
		update.close();
		std::remove("books/Checkbooks.txt");
		std::rename("books/updated.txt", "books/available_books.txt");
		
		
		if (taken_book == true)
		{
			auto start = std::chrono::system_clock::now();
			auto legacyStart = std::chrono::system_clock::to_time_t(start);
			char tmBuff[30];
			ctime_s(tmBuff, sizeof(tmBuff), &legacyStart);
			std::cout << tmBuff << '\n';

			string date = tmBuff;
			date;
			fstream taken, users_pending;
			users_pending.open("users/users_pending.txt", ios::in | ios::out | ios::app);
			if (users_pending.is_open())
			{
				users_pending << name << endl;
			}
			else
				cout << "Error taking books" << endl;
			users_pending.close();
			taken.open("books/TakenBooks.csv", ios::in | ios::out | ios::app);
			if (taken.is_open())
			{
				taken << ",Name      : " << name << ',' << "Taken Book: "<<Taken_book_store << ',' << "Taken Date: "<<date;
			}
			else
				cout << "Error taking books" << endl;
			taken.close();

			fstream pending;
			pending.open("books/Pendingbooks.txt", ios::in | ios::out | ios::app);
			if (pending.is_open())
			{
				string duedate = TodayDate::InputDate();
				pending << name << endl << Taken_book_store << endl << duedate << endl;
			}
			else
				cout << "Error taking book" << endl;

			pending.close();
		}
		
	}
	else
		cout << "User not found" << std::endl;
}
void Main_menu::return_book()
{
	
	bool check_book = false, return_success = false, All_success=false;
	string name, storebook, storedate;
	cin.ignore();
	cout << "Enter your name: " << endl;
	getline(cin,name);
	fstream return_books, firsthalf, secondhalf, joint;

	firsthalf.open("books/first.txt", ios::in | ios::out | ios::app);
	secondhalf.open("books/second.txt", ios::in | ios::out | ios::app);
	return_books.open("books/Pendingbooks.txt", ios::in | ios::out | ios::app);
	if (return_books.is_open())
	{
		int i = 0;
		string store;
		while (getline(return_books, store))
		{   
			
			if (store == name)
			{
				i = 3;
			}
			if (i == 1)
			{
				
				storedate = store;
				check_book = true;
				break;
			}
			if (i == 2)
			{
				
				storebook = store;
				i--;
			}
			if (i == 3)
			{
				i--;
			}
		}

	}
	else {
		cout << "Error " << endl;
		return;
	    }
	return_books.close();

	char* sep;
	bool check = false;
	int  j = 0, k = 0;
	string str_obj(storebook);
	sep = &str_obj[0];
	
	for (int i = 0; i <= storebook.length(); i++)
	{
		if (sep[i] == '*' && check == false)
		{
			j = i + 1;
			check = true;
			
		}
		if (sep[i+1] == '*' && check == true)
		{
			k = i;
			break;
		}

	}
	string sep_store = "", sep_store_with;
	if (j != k)
	{
		for (int i = j; i <= k; i++)
			sep_store += sep[i];
	}
	else
		sep_store = sep[j];

	sep_store_with = "*" + sep_store + "*";

	if (check_book == true)
	{
		int i = 0;
		fstream book;
		book.open("books/available_books.txt", ios::in | ios::out | ios::app);
		if (book.is_open())
		{

			string store;
			while (getline(book, store))
			{
				if (store != sep_store_with)
				{
					firsthalf << store << endl;
				}
				else
					break;
			}
			firsthalf << storebook << endl;


		}
		else
		{
			cout << "User not found/ No books to return/ Error " << endl;
			return;
		}
		book.close();
		firsthalf.close();
		fstream books;
		books.open("books/available_books.txt", ios::in | ios::out | ios::app);
		if (books.is_open())
		{
			int i = 0;
			string store;
			while (getline(books, store))
			{
				if (store == sep_store_with)
				{
					i = 2;
				}
				if (i == 1)
					secondhalf << store << endl;
				if (i == 2)
				{
					i = 1;
				}
			}

		}

		secondhalf.close();
		books.close();


	}
	else
	{
		cout << "User not found/ No books to return/ Error " << endl;
		return;
	}

	if (check_book == true)
	{
		fstream first, second;
		first.open("books/first.txt", ios::in | ios::out | ios::app);
		second.open("books/second.txt", ios::in | ios::out | ios::app);
		if (second.is_open())
		{
			string store;
			while (getline(second, store))
			{
				first << store << endl;
			}
			return_success = true;
		}
		else
			cout << "Error " << endl;
		first.close();
		second.close();

		std::remove("books/second.txt");
		std::remove("books/available_books.txt");
		std::rename("books/first.txt", "books/available_books.txt");

	}
	else
	{
		cout << "User not found/ No books to return/ Error " << endl;
		return;
	}

	if (return_success == true)
	{
		int i = 0;
		fstream file, renamePB, userP, renamePU;
		renamePU.open("users/newfile.txt", ios::in | ios::out | ios::app);
		userP.open("users/users_pending.txt", ios::in | ios::out | ios::app);
		if (userP.is_open() && renamePU.is_open())
		{
			string store;
			while (getline(userP, store))
			{
				if (store != name)
					renamePU << store << endl;
			}
		}
		else
		{
			cout << "Error " << endl;
			return;
		}
		renamePU.close();
		userP.close();
		std::remove("users/users_pending.txt");
		std::rename("users/newfile.txt", "users/users_pending.txt");

		

		renamePB.open("books/file.txt", ios::in | ios::out | ios::app);
		file.open("books/Pendingbooks.txt", ios::in | ios::out | ios::app);
		if (file.is_open() && renamePB.is_open())
		{
			int i = 0;
			string store;
			while (getline(file, store))
			{
				if (store == name)
					i = 3;
				if (i > 0)
					i--;
				else
					renamePB << store << endl;

			}

			All_success = true;
		}
		else
		{
			cout << "Error " << endl;
			return;
		}
		renamePB.close();
		file.close();
		std::remove("books/Pendingbooks.txt");
		std::rename("books/file.txt", "books/Pendingbooks.txt");


		fstream delete_checkid;
		fstream new_chekid;
		new_chekid.open("books/newcheckid.txt", ios::in | ios::out | ios::app);
		delete_checkid.open("books/RepeatID.txt", ios::in | ios::out | ios::app);
		if (delete_checkid.is_open())
		{
			string store;
			while (getline(delete_checkid, store))
			{
				if (store != sep_store)
					new_chekid << store << endl;
			}
		}
		else
			cout << "Error" << endl;
		new_chekid.close();
		delete_checkid.close();
		std::remove("books/RepeatID.txt");
		cin.ignore();
		std::rename("books/newcheckid.txt", "books/RepeatID.txt");



		fstream return_book_history;
		auto start = std::chrono::system_clock::now();
		auto legacyStart = std::chrono::system_clock::to_time_t(start);
		char tmBuff[30];
		ctime_s(tmBuff, sizeof(tmBuff), &legacyStart);
		string date = tmBuff;
		return_book_history.open("books/ReturnedBooks.csv", ios::in | ios::out | ios::app);
		if (return_book_history.is_open())
		{
			return_book_history << ",Name      : " << name << ',' << "Taken Book: " << storebook << ',' << "Taken Date: " << date;
		}
		else
		{
			cout << "Error" << endl;
			return;
		}
		return_book_history.close();
		
	}
	else
		cout << "User not found/ No books to return/ Error " << endl;

	
 if(All_success == true)
 {
	 cout << "The Book: [" << storebook << "]" << endl;
	 cout << "\n\n                              S U C C E S S F U L L Y      R E T U R N E D \n\n" << endl;
	 cin.ignore();
	 system("cls");
 }

}
void Main_menu::returned_books()
{
	fstream show_returned_books;
	show_returned_books.open("books/ReturnedBooks.csv", ios::in);
	if (show_returned_books.is_open())
	{
		string store;
		cout << "____________________________________________" << endl;
		while (getline(show_returned_books, store, ','))
		{
			cout << "|      " << store << endl;
		}
		cout << "____________________________________________" << endl;
	}
	else
		cout << "Error " << endl;
	show_returned_books.close();
}
void main_menu_user()
{
	system("color 60");
	Main_menu menu;
	user_main_menu M;
	int ch;
	do
	{
		cout << "                 _____________________________W E L C O M E_____________________________                 " << endl;
		cout << "                 0. E X I T                                                             | " << endl;
		cout << "                 1. Books                                                               | " << endl;
		cout << "                 2. Take books                                                          | " << endl;
		cout << "                 3. pending books                                                       | " << endl;
		cout << "                 4. Return books                                                        | " << endl;
		cout << "                 5. Search books                                                        | " << endl;
		cout << "                 6. Returned books history                                              | " << endl;
		cin >> ch;
		switch (ch)
		{
		case 1: menu.books();
			break;
		case 2:M.take_book();
			break;
		case 3:M.pending_books();
			break;
		case 4:M.return_books();
			break;
		case 5:menu.search();
			break;
		case 6:M.returned_books();
			break;
		default:cout << " " << endl;
		}
	} while (ch != 0);

}
void main_menu()
{   
	system("color 60");
	Main_menu menu;
	int ch;
	
	do
	{
		cout << "                 _____________________________W E L C O M E_____________________________                 " << endl;
		cout << "                 0. E X I T                                                             | " << endl;
		cout << "                 1. Add User                                                            | " << endl;
		cout << "                 2. Display Users                                                       | " << endl;
		cout << "                 3. Display Available Books                                             | " << endl;
		cout << "                 4. Take Books                                                          | " << endl;
		cout << "                 5. Taken Books History                                                 | " << endl;
		cout << "                 6. Pending Books                                                       | " << endl;
		cout << "                 7. Return Books                                                        | " << endl;
		cout << "                 8. Add Book                                                            | " << endl;
		cout << "                 9. Search book                                                         | " << endl;
		cout << "                 10.Returned Books History                                              | " << endl;
		cin >> ch;
		switch (ch)
		{
		case 1:menu.add_user();
			break;
		case 2:menu.display_users();
			break;
		case 3:menu.books();
			break;
		case 4:menu.take_book();
			break;
		case 5:menu.taken_books();
			break;
		case 6:menu.pending_books();
			break;
		case 7:menu.return_book();
			break;
		case 8:menu.add_book();
			break;
		case 9:menu.search();
			break;
		case 10:menu.returned_books();
			break;
		default:cout << " " << endl;
		}
	} while (ch != 0);
	
}
int main()
{   
	//Main_menu m;
	CONSOLE_FONT_INFOEX cfi;
	cfi.cbSize = sizeof(cfi);
	cfi.nFont = 0;
	cfi.dwFontSize.X = 14;                   // Width of each character in the font
	cfi.dwFontSize.Y = 24;                  // Height
	cfi.FontFamily = FF_DONTCARE;
	cfi.FontWeight = FW_HEAVY;
	
	std::wcscpy(cfi.FaceName, L"FUTURA"); // Choose your font
	SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);

	std::cout << "                                       Linkid in: Srithin A V \n";
	//m.add_user();
	system("color 60");
	//system("color 2E");




	int r = 0;

	r  = intro();
	if (r == 1)
	{
		system("color 62");
		cout << "Login successfull: " << endl;
		cin.ignore();
		system("cls");
		main_menu();
	}
	else if (r == 2)
	{
		system("color 62");
		cout << "Login successfull: " << endl;
		cin.ignore();
		system("cls");
		main_menu_user();
	}
	
	else {
		system("color E4");
		cout << "Error login/signup: " << endl;
	}
	system("pause");
	return 0;

}

int main_() // for testing 
{
	login_signup m;
	m.user();
	return 0;
}
