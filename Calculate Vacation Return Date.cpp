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

bool IsWeekEnd(ReadDate::stDate Date1)
{
	short DayOfWeek = CalculateDayOrder(Date1.Year, Date1.Month, Date1.Day);
	string Day = DayName(DayOfWeek);

	return (Day == "Fri" || Day == "Sat");
}
ReadDate::stDate CalculateVacationReturnDate(short VacationDays, ReadDate::stDate Date1)
{

	while (VacationDays > 0)
	{

		if (!IsWeekEnd(Date1))
		{
			VacationDays--;
		}
		Date1 = IncreaseDateByOneDay(Date1);

	}
	return Date1;
}

short Check_Positive_Num(string Message)
{
	short Num = 0;
	do
	{
		cout << Message;
		cin >> Num;

		if (Num <= 0)
			cout << "Number must be > 0:\n";

	} while (Num <= 0);

	return Num;
}



int main()
{

	cout << "Vacation Starts:\n";
	ReadDate::stDate DateFrom = ReadDate::FillDate();

	short DayOrderFrom = CalculateDayOrder(DateFrom.Year, DateFrom.Month, DateFrom.Day);
	string DayFrom = DayName(DayOrderFrom);
	cout << "\n\nVacation From: " << DayFrom << " , " << DateFrom.Day << "/" << DateFrom.Month << "/" << DateFrom.Year;


	short Vacations = Check_Positive_Num("\n\nPlease enter vacation days? ");


	ReadDate::stDate DateTo = CalculateVacationReturnDate(Vacations, DateFrom);

	short DayOrderTo = CalculateDayOrder(DateTo.Year, DateTo.Month, DateTo.Day);
	string DayTo = DayName(DayOrderTo);
	cout << "\n\nReturn Date: " << DayTo << " , " << DateTo.Day << "/" << DateTo.Month << "/" << DateTo.Year << endl;



	system("pause>0");

	return 0;
}