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

	cout << "Please enter a Month? ";
	cin >> Month;

	return Month;
}
short ReadDay()
{
	short Day;

	cout << "Please enter a day? ";
	cin >> Day;

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


bool IsLastMonthInYear(stDate Date)
{
	return (Date.Month <= 12 && Date.Month >= 1);
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
	short Days  = NumberOfDaysInMonth(Date.Year, Date.Month);

	return (Date.Day <= Days && Date.Day >= 1);
}


bool ValidateDate(stDate Date)
{
	

	return IsLastMonthInYear(Date) && IsLastDayInMonth(Date);

	
}


int main()
{
	
	cout << "Enter Date:\n";
	stDate Date = FillDate();



	if (ValidateDate(Date))
		cout << "\n\nYes, Date is a valide date.\n\n";
	
	else
		cout << "\n\nNo, Date is Not a valide date.\n\n";
	


	return 0;
}