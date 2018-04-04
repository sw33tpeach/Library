#ifndef PUBLICATION_H
#define PUBLICATION_H
#include <iostream>
#include <iomanip>
#include "Person.h"
#include <string>
#include <vector>
using namespace std;

class Publication
{
private:
	int copies;
	string title;
	bool status;
	int out;
	string format;
	vector<Person> borrower;
public:
	Publication()
	{
		title = " ";
		copies = 0;
		out = 0;
	}

	Publication(string t, int c)
	{
		title = t;
		copies = c;
		out = 0;
	}

	int getCopies()
	{
		return copies;
	}

	int getCOut()
	{
		return out;
	}

	string getTitle()
	{
		return title;
	}

	bool checkOut(Person p)
	{
		if (out < copies)
		{
			out++;
			borrower.push_back(p);
			return true;
		}
		else
			return false;
	}

	bool checkIn(int p)
	{
		if (out > 0)
		{
			out--;
			borrower.erase(borrower.begin()+p);
			return true;
		}
		else
			return false;
	}

	void getBorrower()
	{
		int howbig = borrower.size();
		cout << "No.  Borrower           Email" << endl;
		cout << "===  ========  =======================" << endl;
		for (int i = 0; i < howbig; i++)
		{
			cout << setw(5) << left << i+1 << setw(10) << borrower.at(i).getName() << borrower.at(i).getEmail() << endl;
		}

		cout << endl;
	}
};
#endif