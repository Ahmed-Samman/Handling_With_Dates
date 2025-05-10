#include<iostream>
#include<cstdio>
#include "ReadDate.h"
using namespace std;


bool CheckLeapYearOrNot(short Year)
{
	return (Year % 400) == 0 || (Year % 4) == 0 && (Year % 100) != 0;
}
// Check Last Day In Month
short NumberOfDaysInMonth(short Year, short Month)
{

	short arrDays[13] = { 0, 31, 28, 31, 30, 31, 30, 31 , 31, 30, 31, 30, 31 };

	return (Month == 2) ? (CheckLeapYearOrNot(Year) ? 29 : 28) : arrDays[Month];

}


// Decrease Date By One Day
ReadDate::stDate DecreaseDateByOneDay(ReadDate::stDate Date)
{

	if (Date.Day == 1)
	{
		if (Date.Month == 1)
		{
			Date.Day = 31;
			Date.Month = 12;
			Date.Year--;
		}
		else
		{
			Date.Month--;
			Date.Day = NumberOfDaysInMonth(Date.Year, Date.Month);
		}
	}
	else
	{
		Date.Day--;
	}

	return Date;
}
// Decrease Date By X Days
ReadDate::stDate DecreaseDateByXDays(short Days, ReadDate::stDate Date)
{

	for (short i = 1; i <= Days; i++)
	{
		Date = DecreaseDateByOneDay(Date);
	}

	return Date;
}


// Decrease Date By One Week
ReadDate::stDate DecreaseDateByOneWeek(ReadDate::stDate Date)
{

	for (short i = 1; i <= 7; i++)
	{
		Date = DecreaseDateByOneDay(Date);
	}
	return Date;
}
// Decrease Date By X Weeks
ReadDate::stDate DecreaseDateByXWeeks(short Weeks, ReadDate::stDate Date)
{

	for (short i = 1; i <= Weeks; i++)
	{
		Date = DecreaseDateByOneWeek(Date);
	}
	return Date;
}


// Decrease Date By One Month
ReadDate::stDate DecreaseDateByOneMonth(ReadDate::stDate Date)
{

	if (Date.Month == 1)
	{
		Date.Month = 12;
		Date.Year--;
	}
	else
	{
		Date.Month--;
	}


	short DaysOfMonth = NumberOfDaysInMonth(Date.Year, Date.Month);
	if (Date.Day > DaysOfMonth)
	{
		Date.Day = DaysOfMonth;
	}
	return Date;
}
// Decrease Date By X Month
ReadDate::stDate DecreaseDateByXMonths(short Months, ReadDate::stDate Date)
{

	for (short i = 1; i <= Months; i++)
	{
		Date = DecreaseDateByOneMonth(Date);
	}
	return Date;
}


// Decrease Date By One Year
ReadDate::stDate DecreaseDateByOneYear(ReadDate::stDate Date)
{
	Date.Year--;

	short DaysOfMonth = NumberOfDaysInMonth(Date.Year, Date.Month);

	if (Date.Day > DaysOfMonth)
	{
		Date.Day = DaysOfMonth;
	}
	return Date;
}
// Decrease Date By X Years
ReadDate::stDate DecreaseDateByXYears(short Years, ReadDate::stDate Date)
{
	for (short i = 1; i <= Years; i++)
	{
		Date = DecreaseDateByOneYear(Date);
	}
	return Date;
}
// Decrease Date By X Years (Faster)
ReadDate::stDate DecreaseDateByXYearsFaster(short Years, ReadDate::stDate Date)
{
	Date.Year -= Years;
	return Date;
}


// Decrease Date By One Decade
ReadDate::stDate DecreaseDateByOneDecade(ReadDate::stDate Date)
{
	Date.Year -= 10;
	return Date;
}
// Decrease Date By X Decades
ReadDate::stDate DecreaseDateByXDecades(short Decades, ReadDate::stDate Date)
{
	for (short i = 1; i <= Decades; i++)
	{
		Date = DecreaseDateByOneDecade(Date);
	}
	return Date;
}
// Decrease Date By X Decades (Faster)
ReadDate::stDate DecreaseDateByXDecadesFaster(short Decades, ReadDate::stDate Date)
{
	Date.Year -= (10 * Decades);
	return Date;
}


// Decrease Date By One Century
ReadDate::stDate DecreaseDateByOneCentury(ReadDate::stDate Date)
{
	Date.Year -= 100;
	return Date;
}


// Decrease Date By One Millennium
ReadDate::stDate DecreaseDateByOneMillennium(ReadDate::stDate Date)
{
	Date.Year -= 1000;
	return Date;
}




int main()
{

	ReadDate::stDate Date = ReadDate::FillDate();

	cout << "\n\nDate After:\n\n";


	// Days
	Date = DecreaseDateByOneDay(Date);
	printf("%02d-Subtracting One Day is: %d/%d/%d\n", 1, Date.Day, Date.Month, Date.Year);
	Date = DecreaseDateByXDays(10, Date);
	printf("%02d-Subtracting %d Days is: %d/%d/%d\n", 2, 10, Date.Day, Date.Month, Date.Year);


	// Weeks
	Date = DecreaseDateByOneWeek(Date);
	printf("%02d-Subtracting One Week is: %d/%d/%d\n", 3, Date.Day, Date.Month, Date.Year);
	Date = DecreaseDateByXWeeks(10, Date);
	printf("%02d-Subtracting %d Weeks is: %d/%d/%d\n", 4, 10, Date.Day, Date.Month, Date.Year);


	// Months
	Date = DecreaseDateByOneMonth(Date);
	printf("%02d-Subtracting One Month is: %d/%d/%d\n", 5, Date.Day, Date.Month, Date.Year);
	Date = DecreaseDateByXMonths(5, Date);
	printf("%02d-Subtracting %d Months is: %d/%d/%d\n", 6, 5, Date.Day, Date.Month, Date.Year);


	// Years
	Date = DecreaseDateByOneYear(Date);
	printf("%02d-Subtracting One Year is: %d/%d/%d\n", 7, Date.Day, Date.Month, Date.Year);
	Date = DecreaseDateByXYears(10, Date);
	printf("%02d-Subtracting %d Years is: %d/%d/%d\n", 8, 10, Date.Day, Date.Month, Date.Year);
	Date = DecreaseDateByXYearsFaster(10, Date);
	printf("%02d-Subtracting %d Years (Faster) is: %d/%d/%d\n", 9, 10, Date.Day, Date.Month, Date.Year);


	// Decades
	Date = DecreaseDateByOneDecade(Date);
	printf("%02d-Subtracting One Decade is: %d/%d/%d\n", 10, Date.Day, Date.Month, Date.Year);
	Date = DecreaseDateByXDecades(10, Date);
	printf("%02d-Subtracting %d Decades is: %d/%d/%d\n", 11, 10, Date.Day, Date.Month, Date.Year);
	Date = DecreaseDateByXDecadesFaster(10, Date);
	printf("%02d-Subtracting %d Decades (Faster) is: %d/%d/%d\n", 12, 10, Date.Day, Date.Month, Date.Year);


	// Century
	Date = DecreaseDateByOneCentury(Date);
	printf("%02d-Subtracting One Century is: %d/%d/%d\n", 13, Date.Day, Date.Month, Date.Year);


	// Millennium
	Date = DecreaseDateByOneMillennium(Date);
	printf("%02d-Subtracting One Millennium is: %d/%d/%d\n", 14, Date.Day, Date.Month, Date.Year);



	
	system("pause>0");

	return 0;
}