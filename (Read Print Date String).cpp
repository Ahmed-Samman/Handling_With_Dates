#include<iostream>
#include<vector>
#include<string>
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



string DateToString(stDate sDate)
{

	string StringOfDate = to_string(sDate.Day) + "/" + to_string(sDate.Month) + "/" + to_string(sDate.Year);

	return StringOfDate;
}



int main()
{
	string ReadStringDate = ReadDateOfString();
	stDate Date = StringToDate(ReadStringDate);


	cout << "\n\nDay: " << Date.Day << endl;
	cout << "Month: " << Date.Month << endl;
	cout << "Year: " << Date.Year << endl;


	cout << "\n\nYour Entered: " << DateToString(Date) << endl;



	return 0;
}
