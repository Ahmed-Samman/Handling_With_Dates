#include<iostream>
#include<string>
using namespace std;


short ReadNumber()
{
	string Num;
	
	do
	{
		cout << "Enter a year: ";
		cin >> Num;

		if (Num.length() > 4 || Num.length() < 4)
		{
			cout << "\nPlease enter a year truly!\n";
		}

	} while (Num.length() > 4 || Num.length() < 4);

	return stoi(Num);
}

bool CheckLeapYearOrNot(short Year)
{

	return (Year % 400) == 0 ? true : (Year % 4) == 0 && (Year % 100) != 0 ? true : false;

	// OR
	 
	// Optimization for Solution
	return (Year % 400) == 0 || (Year % 4) == 0 && (Year % 100) != 0;
}



int main()
{

	short Year = ReadNumber();

	if (CheckLeapYearOrNot(Year))
	{
		cout << "\nYear [ " << Year << " ] is Leap Year!" << endl;
	}
	else
	{
		cout << "\nYear [ " << Year << " ] is Not Leap Year!" << endl;
	}


	return 0;
}