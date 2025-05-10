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

enum enCompareDate { Before = -1, Equal = 0, After = 1 };

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
bool IsDate1EqualDate2(stDate Date1, stDate Date2)
{
	return (Date1.Year == Date2.Year) ? ((Date1.Month == Date2.Month) ? ((Date1.Day == Date2.Day) ? true : false) : false) : false;
}

enCompareDate CompareDate1AndDate2(stDate Date1, stDate Date2)
{

	if (IsDate1BeforDate2(Date1, Date2))
		return enCompareDate::Before;

	if (IsDate1EqualDate2(Date1, Date2))
		return enCompareDate::Equal;


	return enCompareDate::After;

}


bool IsOverlapPeriod(stPeriod Period1, stDate DateCheck)
{

	return CompareDate1AndDate2(DateCheck, Period1.StartDate) == enCompareDate::After
		&& CompareDate1AndDate2(DateCheck, Period1.EndDate) == enCompareDate::Before;

}

bool IsDateWithinPeriod(stPeriod Period1, stDate DateCheck)
{
	return IsOverlapPeriod(Period1, DateCheck);
}


int main()
{
	stPeriod Period1;

	cout << "Enter Period:\n\n";
	Period1 = FillPeriod();


	cout << "\n\nEnter Date to check:\n\n";
	stDate DateCheck = FillDate();
	

	if (IsDateWithinPeriod(Period1, DateCheck))
	{
		cout << "\n\nYes, Date is Within period.\n\n";
	}
	else
	{
		cout << "\n\nNo, Date is not Within period.\n\n";
	}


	return 0;

}