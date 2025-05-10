#include<iostream>
#include<string>
using namespace std;




#pragma once
namespace ReadDate
{
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


}
