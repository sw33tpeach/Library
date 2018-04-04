#include <iomanip>
#include <iostream>
#include <string>
#include "Publication.h"
#include "Books.h"
#include "Music.h"
#include "Person.h"
#include "Videos.h"
using namespace std;

//Count initialization
int Person::count = 0;
int Books::count = 0;

//Function Prototypes
int menu();
void displaySubscribers();
void displayBooks();
//void displayMusic();
//void displayVideos();
void checkInOut();

//Global variables
Person people[3]; //create subscribers
Books lbooks[3];// create book library
int main()
{
	bool check = false;


	people[0] = { "Sophie", "Speach@gmail.com" };
	people[1] = { "Kevin", "Monstar@me.mail" };
	people[2] = { "Katherine", "CaptainSmartie@voy.ager" };

	lbooks[0] = new Books ("Diana Jones", 336, 1, "Howl's Moving Castle", 2);
	lbooks[1] = new Books ("Patrick Rothfuss", 662, 1, "Name of The Wind", 3);
	lbooks[2] = new Books ("Mark Lawrence", 384, 2, "Prince of Thorns", 1);

	while (check == false)
	{
		int op = menu();

		switch (op)
		{
		case 1: displaySubscribers();
			break;
		case 2: displayBooks();
			break;
		//case 3: displayMusic();
		//	break;
		//case 4: displayVideos();
		//	break;
		case 5: checkInOut();
			break;
		case 0: check = true;
			break;
		}

	}

    return 0;
}

int menu()
{
	int menu;
	while (true)
	{
		cout << "What would you like to do? \n";
		cout << "1:    Display subscribers \n";
		cout << "2:    Display books \n";
		cout << "3:    Display Music \n";
		cout << "4:    Display Videos \n";
		cout << "5:    Check in/out a publication \n";
		cout << "0:    Quit the program \n\n";
		cout << "Please enter option number: ";
		cin >> menu;

		 if (cin.fail())
		{
			cout << "Invalid: not a number. Try again \a\n";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		else if (menu > 5 || menu < 0)
		{
			cout << endl;
			cout << "Incorrect entry, please use a number between 0-3 \a\n\n";
		}
		else
		{
			break;
		}
	}
	cout << endl;

	return menu;
}

void displaySubscribers()
{
	//Subscriber output
	cout << "================================================= \n \n";
	cout << "ID  Subscriber    Email \n";
	cout << "--  ----------    ------------------------------- \n";
	for (int i = 0; i < Person::count; i++)
	{
		cout << setw(2) << right << people[i].getNumber() << "  "
			<< setw(14) << left << people[i].getName() << people[i].getEmail() << endl;
	}

	cout << endl;
}

void displayBooks()
{
	cout << endl;
	cout << "===================================================== \n \n";
	cout << "Book Title              Author            Copies  Out \n";
	cout << "--------------------    ----------------  ------  --- \n";
	for (int i = 0; i < Books::count; i++)
	{
		cout << setw(24) << left << lbooks[i].getTitle() << setw(23) << lbooks[i].getAuthor() 
			 << setw(3) << lbooks[i].getCopies() << "  " << left << lbooks[i].getCOut() << endl;
	}

	cout << endl;
}

void checkInOut()
{
	int pID;
	int bID;
	int choice;

	cout << "Which type of publication in particular? \n";
	cout << "Book ID: ";
	cin >> bID;
	bID--;
	cout << endl;

	cout << "Title: " << lbooks[bID].getTitle() << endl;
	cout << "Copies: " << lbooks[bID].getCopies() << endl;
	cout << "Checked out: " << lbooks[bID].getCOut() << endl << endl;
	cout << "-------------------------------------------- \n";
	lbooks[bID].getBorrower();

	cout << "Checking in or out?" << endl << "1: Check out \n" << "2: Check in \n" << "0: Exit \n";
	while (true)
	{
		cout << "Choice: ";
		cin >> choice;
		if (cin.fail())//check if number
		{
			cout << "Invalid: not a number. Try again \a\n";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		else if (choice < 0 || choice > 2) //check if in range
		{
			cout << "Error: incorrect choice. Try again \a\n";
		}
		else
		{
			break;
		}
	}


		if (choice == 1)//check out
		{

			cout << "Person ID: ";
			cin >> pID;
			pID--; //conform to vector

			cout << endl;
			cout << "-------------------------------------------- \n";
			if (lbooks[bID].checkOut(people[pID]) == true)//check if copies available
			{
				lbooks[bID].getBorrower();
			}
			else
			{
				cout << "I'm sorry, all copies of this publication \n" "have been checked out by: \a\n\n";
				lbooks[bID].getBorrower();
			}

			cout << "-------------------------------------------- \n\n";
		}
		else if (choice == 2)//check in
		{
			cout << endl << "Which borrower is returning this publication? \n";
			cout << "No.: ";
			cin >> pID;
			pID--; //conform to vector

			cout << endl;
			cout << "-------------------------------------------- \n";
			if (lbooks[bID].checkIn(pID) == true)//check if any borrowed
			{
				cout << "Title: " << lbooks[bID].getTitle() << endl << endl;
				cout << "Book has been checked in. Remaining borrowers are: \n";
				lbooks[bID].getBorrower();
			}
			else
			{
				cout << "All copies of this publication have already been returned \a\n";
			}

			cout << "-------------------------------------------- \n\n";
		}
}
