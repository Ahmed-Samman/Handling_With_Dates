#include<iostream>
#include<string>
#include<cstdio>
#include<cmath>
using namespace std;

enum enCompareDate {Before = -1, Equal = 0, After = 1};

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

bool IsDate1BeforDate2(stDate Date1, stDate Date2)
{
	return (Date1.Year < Date2.Year) ? true : (Date1.Month < Date2.Month) ? true : (Date1.Day < Date2.Day) ? true : false;
}
bool IsDate1EqualDate2(stDate Date1, stDate Date2)
{
	return (Date1.Year == Date2.Year) ? ((Date1.Month == Date2.Month) ? ((Date1.Day == Date2.Day) ? true : false) : false) : false;
}


enCompareDate CampareDate1AndDate2(stDate Date1, stDate Date2)
{

	if (IsDate1BeforDate2(Date1, Date2))
		return enCompareDate::Before;
	
	if (IsDate1EqualDate2(Date1, Date2))
		return enCompareDate::Equal;
	

	return enCompareDate::After;
	
}



int main()
{
	cout << "Date1:" << endl;
	stDate Date1 = FillDate();

	cout << "\n\nDate2:" << endl;
	stDate Date2 = FillDate();


	cout << "\n\nCampare Result = " << CampareDate1AndDate2(Date1, Date2) << endl;


	return 0;
}


