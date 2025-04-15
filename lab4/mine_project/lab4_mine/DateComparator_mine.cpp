#include "DateComparator_mine.h"

using namespace std;

DateComparator::DateComparator():
	year1(2000),  month1(1), day1(1),
	year2(2023), month2(12), day2(31),
	difference(0) {}
void DateComparator::readFile(const char *fileName) {
   vector<string> ds;
    in.open(fileName,ios::in);

    if (!in.is_open()) {
        cout << "Failed to open file.\n";
    }
    string s;
    while (getline(in, s)) {
        ds.push_back(s);
    }
    for(int i = 0;i < ds.size();i++){
        difference = 0;
        string tmp_year1 = "",tmp_month1 = "",tmp_day1 = "";
        string tmp_year2 = "",tmp_month2 = "",tmp_day2 = "";
        for(int j = 0;j < 4;j++) tmp_year1 += ds[i][j];
        for(int j = 5;j < 7;j++) tmp_month1 += ds[i][j];
        for(int j = 8;j < 10;j++) tmp_day1 += ds[i][j];
        for(int j = 11;j < 15;j++) tmp_year2 += ds[i][j];
        for(int j = 16;j < 18;j++) tmp_month2 += ds[i][j];
        for(int j = 19;j < 21;j++) tmp_day2 += ds[i][j];
        year1 = atoi(tmp_year1.c_str());
        month1 = atoi(tmp_month1.c_str());
        day1 = atoi(tmp_day1.c_str());
        year2 = atoi(tmp_year2.c_str());
        month2 = atoi(tmp_month2.c_str());
        day2 = atoi(tmp_day2.c_str());
         setOrder();
         setDifference();
         print();
    }

	//TODO:
	//Read the data from the txt file.
	//
	//Hint: You can use get() to get a character in ifstream.
	//      You can use getline() to get one line in the txt file.
	//      You can use stoi() to change variable type from string to int
}
void DateComparator::setOrder()
{
    if(year1 > year2){
      swap(year1,year2);
      swap(month1,month2);
      swap(day1,day2);
    }else if(year1 == year2){
       if(month1 > month2){
          swap(month1,month2);
          swap(day1,day2);
       }else if(month1 == month2){
           if(day1 > day2) swap(day1,day2);
       }
    }
	//TODO:
	//Compare the order of the two dates.
	//Set the earlier date as {year1, month1, day1} and the later one as {year2, month2, day2}.
}

void DateComparator::setDifference()
{
    vector<int> ds = {31,28,31,30,31,30,31,31,30,31,30,31};
    vector<int> ds_leap = {31,29,31,30,31,30,31,31,30,31,30,31};
    if(year1 == year2){
        if(month1 == month2) difference = day2 - day1;
        else{
           for(int i = month1;i < month2;i++){
               if(!isLeapYear(year1)) difference += ds[i - 1];
               else difference += ds_leap[i - 1];
           }
           difference += day2 - day1;
        }
    }else{
        int tmp_year = year1,tmp_month = month1;
        while(tmp_year < year2){

            if(!isLeapYear(tmp_year)) difference += ds[tmp_month - 1];
            else difference += ds_leap[tmp_month - 1];
            tmp_month++;
             if(tmp_month == 13){
               tmp_year++;
               tmp_month = 1;
            }
        }
        for(int i = tmp_month;i < month2;i++){
               if(!isLeapYear(year2)) difference += ds[i - 1];
               else difference += ds_leap[i - 1];
           }
           difference += day2 - day1;
    }
    //complete;
	//TODO:
	//Calculate the number of days between the two dates.
}

bool DateComparator::isLeapYear(int year_)
{
    if((year_ % 4 == 0 && year_ % 100 != 0) || year_ % 400 == 0) return true;
    return false;
    //complete;
	//TODO:
	//Determine whether year_ is a leap year.
}

void DateComparator::print()
{
    cout << "the order of two dates: [" << year1 << "/";
    if(month1 < 10) cout << '0' << month1 << "/";
    else cout << month1 << "/";
    if(day1 < 10) cout << '0' << day1 << " ";
    else cout << day1 << " ";
    cout << year2 << "/";
    if(month2 < 10) cout << '0' << month2 << "/";
    else cout << month2 << "/";
    if(day2 < 10) cout << '0' << day2;
    else cout << day2;
    cout << "]" << endl;
    cout << "the number of days between two dates: " << difference <<  endl;
	//TODO:
	//The function output the result on the screen.
	//Hint: You can use setw() to set the length of the number.
	//      You can use setfill('c') to fill 'c' to the empty space.
	//      Two functions of above is in iomanip header file.
}
