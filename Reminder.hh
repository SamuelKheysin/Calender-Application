#pragma once
#include <string>

using namespace std;
class Reminder
{
private:
	string desc;
public:
	Reminder(string _desc);
	string toString();
	string getDesc();
	void setDesc(string);
};

