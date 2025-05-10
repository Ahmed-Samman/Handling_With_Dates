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
		cout << "\nPlease enter a year? ";
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

short NumberOfDaysFromTheBeginingOfTheYear(short Year, short Month, short Day)
{
	short TotalDays = 0;

	for (short i = 1; i < Month; i++)
	{

		TotalDays += NumberOfDaysInMonth(Year, i);
	}

	return TotalDays += Day;
}


struct stDate
{
	short Day;
	short Month;
	short Year;
};
stDate DayFromDayOrderInYear(short DaysOrder, short Year)
{
	stDate Date;

	short RemainingDays = DaysOrder;
	short DaysInMonth = 0;

	Date.Year = Year;
	Date.Month = 1;

	while (true)
	{
		DaysInMonth = NumberOfDaysInMonth(Year, Date.Month);

		if (RemainingDays > DaysInMonth)
		{
			RemainingDays -= DaysInMonth;
			Date.Month++;
		}
		else
		{
			Date.Day = RemainingDays;
			break;
		}
	}
	return Date;
}


int main()
{
	short Year = 0, Month = 0, Day = 0;

	Day = ReadDay();
	Month = ReadMonthInYear();
	Year = ReadYear();


	short NumOfDays = NumberOfDaysFromTheBeginingOfTheYear(Year, Month, Day);

	printf("\nNumber Of Days from the begining of the year is : %d\n", NumOfDays);



	stDate Date = DayFromDayOrderInYear(NumOfDays, Year);

	cout << "\nDate for [" << NumOfDays << "] is: " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;




	system("pause>0");

	return 0;
}