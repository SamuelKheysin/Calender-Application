#pragma once
#include <string>
#include <vector>
using namespace std;
#include "Appointment.hh"

class Day
{
private:
	int dayNumber;
	int dayofWeek;
	vector<Reminder*> reminderlst;
public:
	Day(int, int);
	string toString();
	void addAppointment(int beginH, int beginM, int endH, int endM, string txt);  
	void addReminder(string txt);
	Reminder* removeReminder(int index);
	string daytoName();
	int getDayNumber();
	int getDayWeek();
	int getSizeErrand();
};
