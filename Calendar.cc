#include "Calendar.hh"
#include <fstream>
#include <iostream>

Calendar::Calendar(string _title, int _dayn, int _dayw)
{
	this->title = _title;
	this->numOfDays = _dayn;
	this->startingDay = _dayw;  
	setDays(_dayn, _dayw);
}
Calendar::Calendar()
{
	this->title = "Calendar";
	this->numOfDays = 30;
	this->startingDay = 0;
	setDays(30, 1);
}
void Calendar::setDays(int dayn, int sday)
{
	for (int i = 0; i < dayn; i++)
	{
		Day* d = new Day(sday, sday % 7);
		sday++;
		Daylst.push_back(d);
	}
}
void Calendar::displayDay(int index)
{
	Day *d = fetchDay(index-1);
	cout << index<< " - " << d->daytoName() << ":\n";
	cout<<"       " <<d->toString() << endl;
}
void Calendar::displayEntire()
{
	cout << "Calendar " << title << endl;
	for (size_t i = 0; i < Daylst.size(); i++)
	{
		Day *d = fetchDay(i);
		cout << i + 1 << " - " << d->daytoName() << ": ";
		if (d->getSizeErrand() == 0)
			cout << "No";
		else
			cout << d->getSizeErrand();
		cout<< " Errands"<<endl;
	}
}
void Calendar::daytoFile(string filename)
{
	string input;
	ofstream out(filename);
	for (size_t i = 0; i < Daylst.size(); i++)
	{
		Day *d = fetchDay(i);
		out << i + 1 << " - " << d->daytoName() << ": ";
		if (d->getSizeErrand() == 0)
			out << "No";
		else
			out << d->getSizeErrand();
		out << " Errands" << endl;
		out << d->toString();
	}	
	out.close();
}
Day* Calendar::fetchDay(int index)
{
	return Daylst.at(index);
}
Day* Calendar::removeday(int nday)
{
	Day* d = fetchDay(nday);
	Daylst.erase(Daylst.begin() + nday);
	return d;

}
int Calendar::getStartingDay()
{
	return startingDay;
}
int Calendar::getNumOfDays()
{
	return numOfDays;
}

