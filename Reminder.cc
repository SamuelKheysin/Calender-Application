#include "Reminder.hh"

Reminder::Reminder(string _desc)
{
	desc = _desc;
}
string Reminder::toString()
{
	return "Reminder - " + desc + "\n";
}
string Reminder::getDesc()
{
	return desc;
}
void Reminder::setDesc(string _desc)
{
	desc = _desc;
}

