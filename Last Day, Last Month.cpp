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

		if (Day > 31 || Day < 1)
		{
			cout << "\nPlease enter a rigth Day.\n";
		}

	} while (Day > 31 || Day < 1);

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


// Check Last Day In Month
bool CheckLeapYearOrNot(short Year)
{
	return (Year % 400) == 0 || (Year % 4) == 0 && (Year % 100) != 0;
}
short NumberOfDaysInMonth(short Year, short Month)
{

	short arrDays[13] = { 0, 31, 28, 31, 30, 31, 30, 31 , 31, 30, 31, 30, 31 };

	return (Month == 2) ? (CheckLeapYearOrNot(Year) ? 29 : 28) : arrDays[Month];

}
bool IsLastDayInMonth(stDate Date)
{
	return (NumberOfDaysInMonth(Date.Year, Date.Month) == Date.Day);
}
void PrintIsLastDayInMonth(stDate Date)
{

	if (IsLastDayInMonth(Date))
	{
		cout << "\n\nYes, Day is last Day in Month.\n";
	}
	else
	{
		cout << "\n\No, Day is  Not last Day in Month.\n";
	}
}


// Check Last Month In Year
bool IsLastMonthInYear(stDate Date)
{
	return (Date.Month == 12);
}
void PrintIsLastMonthInYear(stDate Date)
{
	if (IsLastMonthInYear(Date))
	{
		cout << "Yes, Month is last Month in Year.\n";
	}
	else
	{
		cout << "No, Month is Not last Month in Year.\n";
	}
}



int main()
{
	cout << "Date:" << endl;
	stDate Date = FillDate();


	PrintIsLastDayInMonth(Date);

	PrintIsLastMonthInYear(Date);




	system("pause>0");

	return 0;
}