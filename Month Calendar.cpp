#include<iostream>
#include<string>
#include<cstdio>
using namespace std;


short ReadYear()
{
	string Num;

	do
	{
		cout << "Enter a year: ";
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
		cout << "\nPlease enter a Month? ";
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
		cout << "\nPlease enter a day? ";
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


string MonthName(short MonthOfYear)
{

	string arrDays[] = { "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec" };

	return arrDays[MonthOfYear - 1];
}


short CalculateDayOrder(short Year, short Month, short Day = 1)
{

	short a = (14 - Month) / 12;
	short y = Year - a;
	short m = Month + (12 * a) - 2;

	// Gregorian Way:
	return (Day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
}
string DayName(short DayOfWeek)
{

	string arrDays[] = { "Sun", "Mon", "Tue", "Wen", "Thur", "Fri",  "Sat" };

	return arrDays[DayOfWeek];

}


void PrintMonthCalendar(short Year, short Month)
{

	short FirstDayInMonth = CalculateDayOrder(Year, Month);
	short DayesOfWeek = NumberOfDaysInMonth(Year, Month);


	cout << "\n  _______________" << MonthName(Month) << "_______________\n\n";

	printf("  Sun  Mon  Tue  Wen  Thu  Fri  Sat\n");


	short i;
	for (i = 0; i < FirstDayInMonth; i++)
		printf("     ");

	for (short j = 1; j < DayesOfWeek; j++)
	{
		printf("%5d", j);

		if (++i == 7)
		{
			i = 0;
			cout << endl;
		}
	}
	cout << "\n  _________________________________\n";
}


int main()
{
	short Year = 0, Month = 0, Day = 0;

	Year = ReadYear();
	Month = ReadMonthInYear();


	PrintMonthCalendar(Year, Month);


	system("pause>0");

	return 0;
}