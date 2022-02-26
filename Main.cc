/*
Author: Samuel Kheysin
*/
#include<iostream>
#include <ctime>
//#include<conio.h>
#include<string.h>
using namespace std;

#include "Calendar.hh"       

int main()
{

	int choice1, choice2, days = 0, startingDay = 1;
	string title;

	cout << "Welcome to CSE240 Calendar\n";
	cout <<"\n1. Build a new Calendar";
	cout <<"\n2. Exit\n";
	
	while(!(cin >> choice1) || choice1 < 1 || choice1 > 2)
	{
		cin.clear();
		cin.ignore();		
		cout << "\nError, Unrecognized option # please select 1 or 2\n";
		
	}

	if (choice1 == 1)
	{
		cout << "\nBuilding a new calendar.\n";  //build calender
	}
	if (choice1 == 2)
	{
		cout << "\nExiting program...";
		exit(0);
		return 0;
	}
	//int x;
	//cin>>x;
	cout << "Give your calendar a title: ";  //name of the calender
	getline(cin>>ws, title);
	//cin >> title;

	cout <<"\nHow many days should this calendar have?: ";
	while(!(cin >> days) || days < 1)
	{
		cin.clear();
		cin.ignore();		
		cout << "\nError, please set positive number of days\n";
		cout <<"\nHow many days should this calendar have?: ";
	}
	

	cout << "\nWhat day does your calendar start on?:\n";
	cout << "1.Monday\n";
	cout << "2.Tuesday\n";
	cout << "3.Wednesday\n";
	cout << "4.Thursday\n";
	cout << "5.Friday\n";
	cout << "6.Saturday\n";
	cout << "7.Sunday\n";
	cout << "Selection>> ";

	while(!(cin >> startingDay) || startingDay < 1 || startingDay > 7)  //between 1 and 7 days
	{
		cin.clear();
		cin.ignore();		
		cout << "\nError, please set the according starting day\n";		
	}
	
	Calendar* test = new Calendar(title, days, startingDay - 1);
	cout << "\nYour Calendar has been created.\n";
	do
	{
		cout << "\nWhat would you like to do?"
			"\n1. Display Whole Calendar"
			"\n2. Display a Single Day"
			"\n3. Add an Errand"
			"\n4. Delete an Errand"
			"\n5. Save to a file"
			"\n0. Exit\n";

		cin >> choice2;
		cout << "Option: " << choice2 << " selected\n";  

		switch (choice2)  //switch statement for output
		{
			case 1:
				test->displayEntire();
				break;
			case 2:
				cout << "Select which day to display:\n ";
				cout << "Day (1" << " - " << days << ")  (0 - Back to main menu): ";

				int day_index;
				while(!(cin >> day_index) || day_index < 0 || day_index > days)
				{
					cin.clear();
					cin.ignore();		
					cout << "\nError, Unrecognized option\n";
				}
				
				if(day_index == 0)
					break;
				test->displayDay(day_index);
				break;

			case 3:
				{
					cout << "Add an Errand\nSelect which day you want to add an Errand to :\nDay(1 - " << days << "): ";
					int day_index;
					while(!(cin >> day_index) || day_index < 0 || day_index > days)
					{
						cin.clear();
						cin.ignore();		
						cout << "\nError, Unrecognized option\n";
					}
					
					if(day_index == 0)
						break;
					Day *d = test->fetchDay(day_index-1);
					cout << "What type of Errand ?\n";
					cout << "1. Reminder\n";
					cout << "2. Appointment\n";
					cout << "0. Back to main menu\n";
					int nsubmenu;
					while(!(cin >> nsubmenu) || nsubmenu < 0 || nsubmenu > 2)
					{
						cin.clear();
						cin.ignore();		
						cout << "\nError, Unrecognized option # please select 1 or 2\n";
					}					
					if (nsubmenu == 0)
						break;
					if (nsubmenu == 1)
					{
						string txt;
						cout << "Enter reminder text: ";
						cin >> txt;
						d->addReminder(txt);
						getline(cin>>ws, title);  //to display more than one word

					}
					else
					{
						int beginh, beginm, endh, endm;   //appointments
						string txt;
						cout << "Enter start time hour(24 - hour clock) : ";
						cin >> beginh;
						cout << "Enter start time minutes : ";
						cin >> beginm;
						cout << "Enter end time hours(24 - hour clock) : ";
						cin >> endh;
						cout << "Enter end time minutes : ";
						cin >> endm;
						cout << "Enter reminder text : ";
						cin >> txt;
					}
				}				
				break;
			case 4:
				{
					cout << "Remove an Errand\nSelect which day you want to delete an Errand to :\nDay(1 - " << days << "): "; //remove errand
					int day_index;
					while(!(cin >> day_index) || day_index < 0 || day_index > days)
					{
						cin.clear();
						cin.ignore();		
						cout << "\nError, Unrecognized option\n";
					}
					
					if(day_index == 0)
						break;
					
					cout << "You have chosen "  ;
					test->displayDay(day_index);
					cout << "Errands:"<<endl;
					Day* d1 = test->fetchDay(day_index-1);
					cout << d1->toString();
					cout << "0. Back to main menu"<<endl;
					cout << "Which would you like to delete?\n>> " ;
					int errand_index;
					while(!(cin >> errand_index) || errand_index < 0 || errand_index > d1->getSizeErrand())
					{
						cin.clear();
						cin.ignore();		
						cout << "\nError, Unrecognized option\n";
					}
					if(errand_index == 0)   
						break;
					Reminder* r = d1->removeReminder(errand_index -1);
					cout<< r->toString() << " Deleted"<<endl;
				}				
				break;
			case 5:
				{
					cout << "Please enter the fliename to store to: ";
					string filename1;
					cin >> filename1;
					test->daytoFile(filename1);
				}	
				break;			
			default:
				cout << "That is not a choice\n";
				break;

		}

	} while (choice2 != 0);

	cout << "\nExiting program..." << endl; //to exit calender program

	system("PAUSE");

	return 0;
}
