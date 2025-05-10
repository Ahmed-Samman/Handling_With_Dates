#include<iostream>
#include<vector>
#include<string>
#include<cstdio>
using namespace std;

string ReadDateOfString()
{
	string Date = "";

	cout << "Please Enter Date dd/mm/yyyy? ";
	getline(cin >> ws, Date);

	return Date;
}


struct stDate
{
	short Day;
	short Month;
	short Year;
};
vector<string> SplitString(string Str, string delim)
{
	vector <string> vSplitWords;

	string sWord; // define a string variable
	short Pos = 0;

	// use find() function to get the position of the delimiter
	while ((Pos = Str.find(delim)) != std::string::npos) // true
	{
		sWord = Str.substr(0, Pos); // store the word
		if (sWord != " ")
		{
			vSplitWords.push_back(sWord);
		}
		Str.erase(0, Pos + delim.length()); // erase() until position and move to next word. 
	}
	if (Str != " ")
	{
		vSplitWords.push_back(Str);
	}
	return vSplitWords;
}
stDate StringToDate(string sDate)
{
	vector <string> vDate = SplitString(sDate, "/");

	stDate Date;
	Date.Day = stoi(vDate[0]);
	Date.Month = stoi(vDate[1]);
	Date.Year = stoi(vDate[2]);

	return Date;
}



void DateToString(short Day, short Month, short Year, const char delim[] = "", const char sDay[] = "", const char sMonth[] = "", const char sYear[] = "")
{

	printf("\n%s%d%s%s%d%s%s%d\n", sDay,Day,delim, sMonth,Month,delim, sYear,Year);

}



int main()
{
	string ReadStringDate = ReadDateOfString();
	stDate Date = StringToDate(ReadStringDate);


	DateToString(Date.Day, Date.Month, Date.Year, "/");

	DateToString(Date.Year, Date.Day, Date.Month, "/");

	DateToString(Date.Month, Date.Day, Date.Year, "/");

	DateToString(Date.Month, Date.Day, Date.Year, "-");

	DateToString(Date.Day, Date.Month, Date.Year, "-");

	DateToString(Date.Day, Date.Month, Date.Year, ", ", "Day:", "Month:", "Year:");




	return 0;
}
