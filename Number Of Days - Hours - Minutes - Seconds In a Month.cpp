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
			cout << "\nPlease enter a year truly!\n";
		}

	} while (Num.length() > 4 || Num.length() < 4);

	return stoi(Num);
}
short ReadMonthInYear()
{
	short Month;
	do
	{
		cout << "\nPlease enter a Month to ckeck? ";
		cin >> Month;

		if (Month > 12 || Month < 1)
		{
			cout << "\nPlease enter true Month.\n";
		}

	} while (Month > 12 || Month < 1);

	return Month;
}

bool CheckLeapYearOrNot(short Year)
{
	return (Year % 400) == 0 || (Year % 4) == 0 && (Year % 100) != 0;
}

short NumberOfDaysInMonth(short Year, short Month)
{
	
	if (Month == 2)
	{
		return CheckLeapYearOrNot(Year) ? 29 : 28;
	}
	

	short arr31Days[7] = {1, 3, 5, 7, 8, 10, 12};

	for (short i = 0; i < 7; i++)
	{
		if (arr31Days[i] == Month)
		{
			return 31;
		} 
	}

	// if you reach here then it's 30 days.
	return 30;
}

short NumberOfHoursInMonth(short Year, short Month)
{

	return NumberOfDaysInMonth(Year, Month) * 24;

}

int NumberOfMinutesInMonth(short Year, short Month)
{

	return NumberOfHoursInMonth(Year, Month) * 60;

}

int NumberOfSecondsInMonth(short Year, short Month)
{

	return NumberOfMinutesInMonth(Year, Month) * 60;

}


int main()
{

	short Year = ReadYear();
	short Month = ReadMonthInYear();

	printf("\nNumber Of Days    in Year [%d] is %d ", Month, NumberOfDaysInMonth(Year, Month));
	printf("\nNumber Of Hours   in Year [%d] is %d ", Month, NumberOfHoursInMonth(Year, Month));
	printf("\nNumber Of Minutes in Year [%d] is %d ", Month, NumberOfMinutesInMonth(Year, Month));
	printf("\nNumber Of Seconds in Year [%d] is %d\n", Month, NumberOfSecondsInMonth(Year, Month));

	system("pause>0");

	return 0;
}