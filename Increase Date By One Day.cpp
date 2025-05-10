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

		if (Day > 31 || Day < 1)
		{
			cout << "\nPlease enter a rigth Day.\n";
		}

	} while (Day > 31 || Day < 1);

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


bool CheckLeapYearOrNot(short Year)
{
	return (Year % 400) == 0 || (Year % 4) == 0 && (Year % 100) != 0;
}
short NumberOfDaysInMonth(short Year, short Month)
{

	short arrDays[13] = { 0, 31, 28, 31, 30, 31, 30, 31 , 31, 30, 31, 30, 31 };

	return (Month == 2) ? (CheckLeapYearOrNot(Year) ? 29 : 28) : arrDays[Month];

}


stDate IncreaseDateByOneDay(stDate Date)
{
	//short OneDay = 1;
	while (true)
	{
		if (Date.Day < NumberOfDaysInMonth(Date.Year, Date.Month))
		{
			Date.Day++;
			break;
		}


		if (Date.Month == 12)
		{
			Date.Day = 1;
			Date.Month = 1;
			Date.Year++;
			break;
		}


		if (Date.Day == NumberOfDaysInMonth(Date.Year, Date.Month))
		{
			Date.Day = 1;
			Date.Month++;
			break;
		}
		

		cout << "\nYou entered wrong date!\n";
		break;
	}

	return Date;
}



int main()
{
	cout << "Date:" << endl;
	stDate Date = FillDate();


	Date = IncreaseDateByOneDay(Date);

	cout << "\nDate after adding one day is: " 
		<< Date.Day << "/" << Date.Month << "/" << Date.Year << endl;




	system("pause>0");

	return 0;
}