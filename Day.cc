#include "Day.hh"

Day::Day(int dayn, int dayweek)
{
	dayNumber = dayn;
	dayofWeek = dayweek;
}
string Day::toString()
{
	string display = "";
	for (size_t i = 0; i < reminderlst.size(); i++)
	{
		display += to_string(i+1) + ". " + reminderlst.at(i)->toString();
	}
	return display;
}
void Day::addAppointment(int beginH, int beginM, int endH, int endM, string txt)
{
	Appointment* app = new Appointment(beginH, beginM, endH, endM, txt);
	reminderlst.push_back(app);
}
void Day::addReminder(string txt)
{
	Reminder *rem = new Reminder(txt);
	reminderlst.push_back(rem);
}
Reminder * Day::removeReminder(int index)  
{
	Reminder *r = reminderlst.at(index);
	reminderlst.erase(reminderlst.begin() + index);
	return r;
}
string Day::daytoName()
{	
	string str = "";
	switch (dayofWeek)
	{
	case 0:
		str = "Monday";
		break;
	case 1:
		str = "Tuesday";
		break;
	case 2:
		str = "Wednesday";
		break;
	case 3:
		str = "Thursday";
		break;
	case 4:
		str = "Friday";
		break;
	case 5:
		str = "Saturday";
		break;
	case 6:
		str = "Sunday";
		break;
	}
	return str;
}
int Day::getDayNumber()
{
	return dayNumber;
}
int Day::getDayWeek()
{
	return dayofWeek;
}
int Day::getSizeErrand()
{
	return reminderlst.size();
}