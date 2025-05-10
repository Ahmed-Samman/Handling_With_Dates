#include<iostream>
#include<string>
using namespace std;


short ReadYear()
{
	string Num;

	do
	{
		cout << "Enter a year: ";
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

	string arrDays[] = { "Sun", "Mon", "Tue", "Wen", "Thur", "Fri",  "Sat" };

	return arrDays[DayOfWeek];

}



int main()
{
	short Year = 0, Month = 0, Day = 0;

	Year = ReadYear();
	Month = ReadMonthInYear();
	Day = ReadDay();

	cout << "\n\n";

	cout << "Date      : " << Day << "/" << Month << "/" << Year << endl;
	cout << "Day Order : " << CalculateDayOrder(Year, Month, Day) << endl;
	cout << "Day Name  : " << DayName(CalculateDayOrder(Year, Month, Day)) << endl;



	system("pause>0");

	return 0;

}