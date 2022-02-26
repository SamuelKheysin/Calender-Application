#include "Appointment.hh"
Appointment::Appointment(int beginH, int beginM, int endH, int endM, string txt):Reminder(txt)
{
	beginTimeHour = beginH;
	beginTimemin = beginM;
	endTimeHour = endH;
	endTimeMin = endM;
}
string Appointment::toString()
{
	string displaytxt = "Appointment - ";
	if (beginTimeHour < 10)
		displaytxt += "0";
	displaytxt += to_string(beginTimeHour) + ":";

	if (beginTimemin < 10)
		displaytxt += "0";
	displaytxt += to_string(beginTimemin) + " - ";

	if (endTimeHour < 10)
		displaytxt += "0";
	displaytxt += to_string(endTimeHour) + ":";

	if (endTimeMin < 10)
		displaytxt += "0";
	displaytxt += to_string(endTimeMin) + " - " + this->getDesc();

	return displaytxt;
}
int Appointment::getBeginTimeHour()
{
	return beginTimeHour;
}
int Appointment::getBeginTimeMin()
{
	return beginTimemin;
}
void Appointment::setBeginTimeHour(int _hour)
{
	beginTimeHour = _hour;
}
void Appointment::setBeginTimeMin(int _min)
{
	beginTimemin = _min;
}
int Appointment::getEndTimeHour()
{
	return endTimeHour;
}
int Appointment::getEndTimeMin()
{
	return endTimeMin;
}
void Appointment::setEndTimeHour(int _hour)
{
	endTimeHour = _hour;
}
void Appointment::setEndTimeMin(int _min)
{
	endTimeMin = _min;
}