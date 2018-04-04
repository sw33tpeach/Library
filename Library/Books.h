#ifndef BOOKS_H
#define BOOKS_H
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
using namespace std;

class Books : public Publication
{
private:
	string author;
	int pages;
public:
	static int count;
	enum Format { Nformat, hardcover, softcover, digital };
	Format pformat;

	Books()
	{
		author = " ";
		pages = 0;
		pformat = (Format)0;
		count++;
	}

	Books(string a, int p, int f, string t, int c) : Publication(t, c)
	{
		author = a;
		pages = p;
		pformat = (Format)f;
		count++;
	}

	string getAuthor()
	{
		return author;
	}

	int GetPages()
	{
		return pages;
	}

	void SetPages(int p)
	{

			pages = p;
	}
};
#endif
