#include<iostream>
#include<string>
using namespace std;


short ReadNumber()
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

bool CheckLeapYearOrNot(short Year)
{
	return (Year % 400) == 0 || (Year % 4) == 0 && (Year % 100) != 0;
}

short NumberOfDaysInYear(short Year)
{
	return (CheckLeapYearOrNot(Year)) ? 366 : 365;
}

short NumberOfHoursInYear(short Year)
{

	return NumberOfDaysInYear(Year) * 24;

}

int NumberOfMinutesInYear(short Year)
{

	return NumberOfHoursInYear(Year) * 60;

}

int NumberOfSecondsInYear(short Year)
{

	return NumberOfMinutesInYear(Year) * 60;

}


int main()
{

	short Year = ReadNumber();


	printf("\nNumber Of Days    in Year [%d] is %d ", Year, NumberOfDaysInYear(Year));
	printf("\nNumber Of Hours   in Year [%d] is %d ", Year, NumberOfHoursInYear(Year));
	printf("\nNumber Of Minutes in Year [%d] is %d ", Year, NumberOfMinutesInYear(Year));
	printf("\nNumber Of Seconds in Year [%d] is %d\n", Year, NumberOfSecondsInYear(Year));
	
	system("pause>0");

	return 0;
}