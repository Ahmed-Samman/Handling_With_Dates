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

struct stDate
{
	short Day;
	short Month;
	short Year;
};
stDate FillDate()
{
	stDate Date;

	Date.Day = ReadDay();
	Date.Month = ReadMonthInYear();
	Date.Year = ReadYear();

	return Date;
}

bool IsDate1EqualDate2(stDate Date1, stDate Date2)
{
	return (Date1.Year == Date2.Year) ? ((Date1.Month == Date2.Month)? ((Date1.Day == Date2.Day)? true : false) : false) : false;
}



int main()
{
	cout << "Date1:" << endl;
	stDate Date1 = FillDate();

	cout << "\n\nDate2:" << endl;
	stDate Date2 = FillDate();


	if (IsDate1EqualDate2(Date1, Date2))
	{
		cout << "\n\nYes, Date1 is Equal Date2.\n";
	}
	else
	{
		cout << "\n\nNo, Date1 is Not Equal Date2.\n";
	}


	system("pause>0");

	return 0;
}