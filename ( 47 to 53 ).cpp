#pragma warning (disable : 4996)
#include<iostream>
#include<string>
#include<ctime>
#include"ReadDate.h"
using namespace std;


short CalculateDayOrder(short Year, short Month, short Day)
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

ReadDate::stDate GetSystemDate()
{
	ReadDate::stDate Date;

	time_t t = time(0);
	tm* now = localtime(&t);

	Date.Day = now->tm_mday;
	Date.Month = now->tm_mon + 1;
	Date.Year = now->tm_year + 1900;

	return Date;
}

bool IsEndOfWeek(string NameDay)
{
	return (NameDay == "Sat");
}
void PrintIsEndOfWeek(string NameDay)
{
	cout << "Is it End of Week?\n";

	if (IsEndOfWeek(NameDay))
	{
		cout << "Yes, it is end of week.\n\n";
	}
	else
	{
		cout << "No, it is Not end of week.\n\n";
	}

}


bool IsWeekEnd(string NameDay)
{
	return (NameDay == "Fri" || NameDay == "Sat");
}
void PrintIsWeekEnd(string NameDay)
{
	cout << "Is it WeekEnd?\n";
	if (IsWeekEnd(NameDay))
	{
		cout << "Yes, it is a week end.\n\n";
	}
	else
	{
		cout << "No, it is Not a week end.\n\n";
	}
}


bool IsBusinessDay(string NameDay)
{
	return (!IsWeekEnd(NameDay));
}
void PrintIsBusinessDay(string NameDay)
{
	cout << "Is it Business Day?\n";
	if (IsBusinessDay(NameDay))
	{
		cout << "Yes, it is a business day.\n\n";
	}
	else
	{
		cout << "No, it is Not a business day.\n\n";
	}
}


short DaysUntilTheEndOfWeek(short DayOfWeek)
{
	return 6 - DayOfWeek;
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
short DaysUntilTheEndOfMonth(ReadDate::stDate Date)
{
	short DaysOfMonth = NumberOfDaysInMonth(Date.Year, Date.Month);
	return DaysOfMonth - Date.Day;
}


short NumberOfDaysToTheEndingOfTheYear(short Year, short Month, short Day)
{
	short TotalDays = 0;

	for (short i = Month + 1; i <= 12; i++)
	{

		TotalDays += NumberOfDaysInMonth(Year, i);
	}

	return TotalDays += NumberOfDaysInMonth(Year, Month) - Day;
}
short DaysUntilTheEndOfYear(ReadDate::stDate Date)
{
	return NumberOfDaysToTheEndingOfTheYear(Date.Year, Date.Month, Date.Day);
}



int main()
{

	ReadDate::stDate Date = GetSystemDate();


	short DayOfWeek = CalculateDayOrder(Date.Year, Date.Month, Date.Day);
	string NameDay = DayName(DayOfWeek);

	cout << "Today is " << NameDay << " , " << Date.Day << "/" << Date.Month << "/" << Date.Year << "\n\n";
	

	// End Of Week
	PrintIsEndOfWeek(NameDay);

	// Week End
	PrintIsWeekEnd(NameDay);

	// Business Day
	PrintIsBusinessDay(NameDay);


	cout << "Days until end of week  : " << DaysUntilTheEndOfWeek(DayOfWeek) << " Day(s).\n";

	cout << "Days until end of month : " << DaysUntilTheEndOfMonth(Date) << " Day(s).\n";

	cout << "Days until end of year  : " << DaysUntilTheEndOfYear(Date) << " Day(s).\n";



	system("pause>0");

	return 0;

}