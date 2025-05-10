#include<iostream>
#include<cstdio>
#include "ReadDate.h"
using namespace std;



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
// Increase Date By Ten days
ReadDate::stDate IncreaseDateByXdays(short Day, ReadDate::stDate Date)
{
	for (short i = 1; i <= Day; i++)
	{
		Date = IncreaseDateByOneDay(Date);
	}
	return Date;
}



// Increase Date By One Week
ReadDate::stDate IncreaseDateByOneWeek(ReadDate::stDate Date)
{
	for (short i = 1; i <= 7; i++)
	{
		Date = IncreaseDateByOneDay(Date);
	}
	return Date;
}
// Increase Date By Ten Weeks
ReadDate::stDate IncreaseDateByXWeeks(short Week, ReadDate::stDate Date)
{
	for (short i = 1; i <= Week; i++)
	{
		Date = IncreaseDateByOneWeek(Date);
	}
	return Date;
}



// Increase Date By One Month
ReadDate::stDate IncreaseDateByOneMonth(ReadDate::stDate Date)
{
	if (Date.Month == 12)
	{
		Date.Month = 1;
		Date.Year++;
	}
	else
	{
		Date.Month++;
	}

	short NumberOfDaysInCurrentMonth = NumberOfDaysInMonth(Date.Year, Date.Month);

	if (Date.Month > NumberOfDaysInCurrentMonth)
	{
		Date.Month = NumberOfDaysInCurrentMonth;
	}

	return Date;
}
// Increase Date By X Months
ReadDate::stDate IncreaseDateByXMonths(short Months, ReadDate::stDate Date)
{

	for (short i = 1; i <= Months; i++)
	{
		Date = IncreaseDateByOneMonth(Date);
	}
	return Date;
}



// Increase Date By One Year
ReadDate::stDate IncreaseDateByOneYear(ReadDate::stDate Date)
{
	Date.Year++;
	return Date;
}
// Increase Date By X Years
ReadDate::stDate IncreaseDateByXYears(short Years, ReadDate::stDate Date)
{
	for (short i = 1; i <= Years; i++)
	{
		Date = IncreaseDateByOneYear(Date);
	}
	return Date;
}
// Increase Date By X Years (Faster)
ReadDate::stDate IncreaseDateByXYearsFaster(short Years, ReadDate::stDate Date)
{
	Date.Year += Years;
	return Date;
}



// Increase Date By One Decade
ReadDate::stDate IncreaseDateByOneDecade(ReadDate::stDate Date)
{
	Date.Year += 10;
	return Date;
}
// Increase Date By X Decades
ReadDate::stDate IncreaseDateByXDecades(short Decades, ReadDate::stDate Date)
{
	for (short i = 1; i <= Decades; i++)
	{
		Date = IncreaseDateByOneDecade(Date);
	}
	return Date;
}
// Increase Date By X Decades Faster
ReadDate::stDate IncreaseDateByXDecadesFaster(short Decades, ReadDate::stDate Date)
{
	Date.Year += (10 * Decades);
	return Date;
}


// Increase Date By One Century
ReadDate::stDate IncreaseDateByOneCentury(ReadDate::stDate Date)
{
	Date.Year += 100;
	return Date;
}



// Increase Date By One Millennium
ReadDate::stDate IncreaseDateByOneMillennium(ReadDate::stDate Date)
{
	Date.Year += 1000;
	return Date;
}



int main()

{
	
	ReadDate::stDate Date = ReadDate::FillDate();

	
	cout << "\n\nDate After:\n\n";


	Date = IncreaseDateByOneDay(Date);
	printf("%02d-Adding One Day is: %d/%d/%d\n",1 ,Date.Day, Date.Month, Date.Year);
	
	Date = IncreaseDateByXdays(10, Date);
	printf("%02d-Adding %d Day is: %d/%d/%d\n", 2, 10, Date.Day, Date.Month, Date.Year);



	Date = IncreaseDateByOneWeek(Date);
	printf("%02d-Adding One Week is: %d/%d/%d\n", 3, Date.Day, Date.Month, Date.Year);

	Date = IncreaseDateByXWeeks(10, Date);
	printf("%02d-Adding %d Weeks is: %d/%d/%d\n", 4, 10, Date.Day, Date.Month, Date.Year);



	Date = IncreaseDateByOneMonth(Date);
	printf("%02d-Adding One Month is: %d/%d/%d\n", 5, Date.Day, Date.Month, Date.Year);

	Date = IncreaseDateByXMonths(5, Date);
	printf("%02d-Adding %d Months is: %d/%d/%d\n", 6, 5, Date.Day, Date.Month, Date.Year);



	Date = IncreaseDateByOneYear(Date);
	printf("%02d-Adding One Year is: %d/%d/%d\n", 7, Date.Day, Date.Month, Date.Year);

	Date = IncreaseDateByXYears(10, Date);
	printf("%02d-Adding %d Years is: %d/%d/%d\n", 8, 10, Date.Day, Date.Month, Date.Year);

	Date = IncreaseDateByXYearsFaster(10, Date);
	printf("%02d-Adding %d Years (Faster) is: %d/%d/%d\n", 9, 10, Date.Day, Date.Month, Date.Year);



	Date = IncreaseDateByOneDecade(Date);
	printf("%02d-Adding One Decade is: %d/%d/%d\n", 10, Date.Day, Date.Month, Date.Year);

	Date = IncreaseDateByXDecades(10, Date);
	printf("%02d-Adding %d Decades is: %d/%d/%d\n", 11, 10, Date.Day, Date.Month, Date.Year);

	Date = IncreaseDateByXDecadesFaster(10, Date);
	printf("%02d-Adding %d Decades (Faster) is: %d/%d/%d\n", 12, 10, Date.Day, Date.Month, Date.Year);



	Date = IncreaseDateByOneCentury(Date);
	printf("%02d-Adding One Century is: %d/%d/%d\n", 13, Date.Day, Date.Month, Date.Year);



	Date = IncreaseDateByOneMillennium(Date);
	printf("%02d-Adding One Millennium is: %d/%d/%d\n", 14, Date.Day, Date.Month, Date.Year);




	system("pause>0");

	return 0;
}