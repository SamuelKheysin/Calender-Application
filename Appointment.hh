#pragma once
#include "Reminder.hh"
class Appointment :public Reminder
{
private:
	int beginTimeHour;
	int beginTimemin;
	int endTimeHour;
	int endTimeMin;
public:
	Appointment(int beginH, int _beginM, int endH, int endM, string txt);
	string toString();
	int getBeginTimeHour();
	int getBeginTimeMin();
	void setBeginTimeHour(int);
	void setBeginTimeMin(int);
	int getEndTimeHour();
	int getEndTimeMin();
	void setEndTimeHour(int);
	void setEndTimeMin(int);
};

