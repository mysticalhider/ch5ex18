/*
File Name: ch5ex18.cpp
programer: Perrin Dalgleish
requirements: 
	read the file "people.txt" and make a bar graph of the populaton of each year
	All user input should be validated.
This program should have at least 3 modules ( including the main module) and should be repeatable.
Each module should have a brief comment on what the module is intended to do.

file contains only population data
year starts at 1900 and ends at 2000
"2000	4000	5000	9000	14000	18000"
*/

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;


//int getinfo()
string getfilename();
fstream getfilehandle(string fileName);


//void calulate()


//void displayresults();
void displayline(double value, int year);
bool getrepeat();


string const pathName = R"(C:\Users\pjd6878\Documents\)";


int main()
{
	bool repeat = true;
	string fileName;
	fstream handle;
	int year = 1900;
	double value;

	while (repeat)
	{
		fileName = getfilename();
		fileName = pathName + fileName;
		handle = getfilehandle(fileName);
		if (!handle == NULL)
		{
			while (handle >> value)
			{
				displayline(value, year);
				year += 20;
			}
		}
	
		repeat = getrepeat();

	}

}

string getfilename()
{
	string fileName;
	cout << "Enter the name of the file you want to open: ";
	cin >> fileName;
	return fileName;
}

fstream getfilehandle(string fileName)
{
	fstream handle;
	handle.open(fileName);
	if (handle.fail())
	{
		cout << "Error opening file. Please try again." << endl;
	}
	else
	{
		cout << "File opened successfully." << endl;
	}
	return handle;
}

void displayline(double pop, int year)
{
	int thousands = pop / 1000;
	cout << year;
	for (int count = 0; count < thousands; count++)
		cout << "*";
	cout << endl;
}

bool getrepeat()
{
	char repeat;
	cout << "Do you want to repeat the program? (y/n): ";
	cin >> repeat;
	if (repeat == 'y' || repeat == 'Y')
	{
		return true;
	}
	else
	{
		return false;
	}
}