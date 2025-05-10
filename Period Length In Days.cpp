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


struct stPeriod
{
	stDate StartDate;
	stDate EndDate;
};
stPeriod FillPeriod()
{
	stPeriod Period;

	cout << "Enter Start Date:\n";
	Period.StartDate = FillDate();

	cout << "\nEnter End Date:\n";
	Period.EndDate = FillDate();

	return Period;
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


bool IsDate1BeforDate2(stDate Date1, stDate Date2)
{
	return (Date1.Year < Date2.Year) ? true : (Date1.Month < Date2.Month) ? true : (Date1.Day < Date2.Day) ? true : false;
}


// Check Last Day In Month
bool IsLastDayInMonth(stDate Date)
{
	return (NumberOfDaysInMonth(Date.Year, Date.Month) == Date.Day);
}
// Check Last Month In Year
bool IsLastMonthInYear(stDate Date)
{
	return (Date.Month == 12);
}
// Increase Date By One day
stDate IncreaseDateByOneDay(stDate Date)
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

int GetDifferenceInDays(stDate Date1, stDate Date2, bool IncludeEndDay = false)
{

	int Days = 0;

	while (IsDate1BeforDate2(Date1, Date2))
	{
		Days++;

		Date1 = IncreaseDateByOneDay(Date1);
	}

	return IncludeEndDay ? ++Days : Days;
}


short PeriodLengthInDays(stPeriod Period1, bool AddEndDay = false)
{
	return GetDifferenceInDays(Period1.StartDate, Period1.EndDate, AddEndDay);
}


int main()
{
	stPeriod Period;

	cout << "Enter Period 1:\n\n";
	Period = FillPeriod();


	cout << "\n\nPeriod Length is: " << PeriodLengthInDays(Period) << endl;
	cout << "Period Length (Includeing End Date) is: " << PeriodLengthInDays(Period, true) << endl;


	return 0;

}