#pragma once
#include <string>
#include <vector>
#include <iostream>
using namespace std;
#include "Day.hh"

class Calendar
{
private:
	string title;
	int numOfDays;
	int startingDay;
	vector<Day*> Daylst;
public:
	Calendar(string, int, int);
	Calendar();
	void setDays(int dayn, int sday);
	void displayDay(int);
	void displayEntire();
	void daytoFile(string);
	Day* fetchDay(int);
	Day* removeday(int);
	int getStartingDay();
	int getNumOfDays();
	

};

