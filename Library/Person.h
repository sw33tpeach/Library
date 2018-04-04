#ifndef PERSON_H
#define PERSON_H
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class Person
{
private:
	int number; //Subscriber ID number
	string name;
	string email;
public:
	static int count; //Number of subscribers

	Person()
	{
		name = " ";
		number = 0;
		email = " ";
	}

	Person(string na, string em)
	{
		name = na;
		email = em;
		count++;
		number = count;
	}

	string getName()
	{
		return name;
	}

	string getEmail()
	{
		return email;
	}

	int getNumber()
	{
		return number;
	}
};
#endif