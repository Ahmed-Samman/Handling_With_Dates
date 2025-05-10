#include<iostream>
#include<string>
#include<cstdio>
#include<cmath>
#include<vector>
using namespace std;

string ReadDateString()
{
	string SDate = "";
	cout << "Please Enter Date dd/mm/yyyy? ";
	cin >> SDate;
	return SDate;
}

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

struct stDate
{
	short Day;
	short Month;
	short Year;
};
vector<stDate> StringToDate(vector<string> vStringDate)
{
	vector<stDate> vDate;
	stDate Date;
	
	Date.Day = stoi(vStringDate.at(0));
	Date.Month = stoi(vStringDate.at(1));
	Date.Year = stoi(vStringDate.at(2));

	vDate.push_back(Date);

	return vDate;
}
void PrintStringToDate(vector<stDate> vDate)
{
	for (stDate& Date : vDate)
	{
		cout << "\n\nDay: " << Date.Day << endl;
		cout << "Month: " << Date.Month << endl;
		cout << "Year: " << Date.Year << endl;
	}
}


string DateToString(vector<stDate> vSplitWords, string delim)
{
	string Str = "";
	for (stDate& Date : vSplitWords)
	{
		Str = Str + to_string(Date.Day) + delim;
		Str = Str + to_string(Date.Month) + delim;
		Str = Str + to_string(Date.Year);
	}
	return Str.substr(0, Str.length());
}



int main()
{
	string ReadStringDate;
	vector<string> vSplitStringDate;
	vector<stDate> vDate;


	ReadStringDate = ReadDateString();
	vSplitStringDate = SplitString(ReadStringDate, "/");
	vDate = StringToDate(vSplitStringDate);


	PrintStringToDate(vDate);

	
	cout << "\nYou Entered: " << DateToString(vDate, "/") << endl;


	return 0;
}