#include<iostream>
#include<string>
#include<cstdio>
#include<cmath>
using namespace std;


short ReadYear()
{
	string Num;

	do
	{
		cout << "Please enter a year? ";
		cin >> Num;

		if (Num.length() > 4 || Num.length() < 4)
		{
			cout << "\nPlease enter a right year!\n";
		}

	} while (Num.length() > 4 || Num.length() < 4);

	return stoi(Num);
}
short ReadMonthInYear()
{
	short Month;
	do
	{
		cout << "Please enter a Month? ";
		cin >> Month;

		if (Month > 12 || Month < 1)
		{
			cout << "\nPlease enter a right Month.\n";
		}

	} while (Month > 12 || Month < 1);

	return Month;
}
short ReadDay()
{
	short Day;
	do
	{
		cout << "Please enter a day? ";
		cin >> Day;

		if (Day > 30 || Day < 1)
		{
			cout << "\nPlease enter a rigth Day.\n";
		}

	} while (Day > 30 || Day < 1);

	return Day;
}

bool CheckLeapYearOrNot(short Year)
{
	return (Year % 400) == 0 || (Year % 4) == 0 && (Year % 100) != 0;
}
short NumberOfDaysInMonth(short Year, short Month)
{

	short arr31Days[13] = { 0, 31, 28, 31, 30, 31, 30, 31 , 31, 30, 31, 30, 31 };

	return (Month == 2) ? (CheckLeapYearOrNot(Year) ? 29 : 28) : arr31Days[Month];

}

// This Function Calculate Days of same this year not anouther year
short NumberOfDaysFromTheBeginingOfTheYear(short Year, short Month, short Day)
{
	short TotalDays = 0;

	for (short i = 1; i < Month; i++)
	{

		TotalDays += NumberOfDaysInMonth(Year, i);
	}

	return TotalDays += Day;
}



int main()
{
	short Year = 0, Month = 0, Day = 0;


	// Date 1
	Day = ReadDay();
	Month = ReadMonthInYear();
	Year = ReadYear();

	short Date1 = NumberOfDaysFromTheBeginingOfTheYear(Year, Month, Day);

	cout << "\n\n";

	// Date 2
	Day = ReadDay();
	Month = ReadMonthInYear();
	Year = ReadYear();
	
	short Date2 = NumberOfDaysFromTheBeginingOfTheYear(Year, Month, Day);


	if (Date1 < Date2)
	{
		cout << "\nYes, Date1 is Less than Date2.\n";
	}
	else
	{
		cout << "\nNo, Date1 is not Less than Date2.\n";
	}


	system("pause>0");

	return 0;
}