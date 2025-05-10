#include<iostream>
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

	string arrDays[] = { "Sun", "Mon", "Tue", "Wed", "Thu", "Fri",  "Sat" };

	return arrDays[DayOfWeek];

}


bool CheckLeapYearOrNot(short Year)
{
	return (Year % 400) == 0 || (Year % 4) == 0 && (Year % 100) != 0;
}
short NumberOfDaysInMonth(short Year, short Month)
{

	short arrDays[13] = { 0, 31, 28, 31, 30, 31, 30, 31 , 31, 30, 31, 30, 31 };

	return (Month == 2) ? (CheckLeapYearOrNot(Year) ? 29 : 28) : arrDays[Month];

}


bool IsDate1BeforDate2(ReadDate::stDate Date1, ReadDate::stDate Date2)
{
	return (Date1.Year < Date2.Year) ? true : (Date1.Month < Date2.Month) ? true : (Date1.Day < Date2.Day) ? true : false;
}
// Check Last Day In Month
bool IsLastDayInMonth(ReadDate::stDate Date)
{
	return (NumberOfDaysInMonth(Date.Year, Date.Month) == Date.Day);
}
// Check Last Month In Year
bool IsLastMonthInYear(ReadDate::stDate Date)
{
	return (Date.Month == 12);
}
// Increase Date By One day
ReadDate::stDate IncreaseDateByOneDay(ReadDate::stDate Date)
{
	if (IsLastDayInMonth(Date))
	{
		if (IsLastMonthInYear(Date))
		{

			Date.Day = 1;
			Date.Month = 1;
			Date.Year++;
		}
		else
		{
			Date.Day = 1;
			Date.Month++;
		}
	}
	else
	{
		Date.Day++;
	}

	return Date;
}

// All Days From Date1 To Date2
int GetDifferenceInDays(ReadDate::stDate Date1, ReadDate::stDate Date2, bool IncludeEndDay = false)
{

	int Days = 0;

	while (IsDate1BeforDate2(Date1, Date2))
	{
		Days++;

		Date1 = IncreaseDateByOneDay(Date1);
	}

	return IncludeEndDay ? ++Days : Days;
}


bool IsWeekEnd(string NameDay)
{
	return (NameDay == "Fri" || NameDay == "Sat");
}
short CalculateVacationDays(ReadDate::stDate Date1 , ReadDate::stDate Date2)
{
	short Vacations = 0;
	int AllDays = GetDifferenceInDays(Date1, Date2);

	for (short i = Date1.Day; i <= AllDays; i++)
	{

		short DayOrder = CalculateDayOrder(Date2.Year, Date2.Month, i);
		string Day = DayName(DayOrder);

		if (!IsWeekEnd(Day))
		{
			Vacations++;
		}
	}
	return Vacations;
}




int main()
{

	cout << "Vacation Starts:\n";
	ReadDate::stDate DateFrom = ReadDate::FillDate();


	cout << "\n\nVacation Ends:\n";
	ReadDate::stDate DateTo = ReadDate::FillDate();


	short DayOrder1 = CalculateDayOrder(DateFrom.Year, DateFrom.Month, DateFrom.Day);
	string Day1 = DayName(DayOrder1);
	cout << "\n\nVacation From: " << Day1 << " , " << DateFrom.Day << "/" << DateFrom.Month << "/" << DateFrom.Year;


	short DayOrder2 = CalculateDayOrder(DateTo.Year, DateTo.Month, DateTo.Day);
	string Day2 = DayName(DayOrder2);
	cout << "\nVacation To: " << Day2 << " , " << DateTo.Day << "/" << DateTo.Month << "/" << DateTo.Year;


	short VacatinDays = CalculateVacationDays(DateFrom, DateTo);

	cout << "\n\nActucal Vacation Days is: " << VacatinDays << endl;




	system("pause>0");

	return 0;
}