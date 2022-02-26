CC=g++
CFLAGS=-g

main: Main.o Calendar.o Day.o Appointment.o Reminder.o 
	g++ -g -o main Main.o Calendar.o Day.o Appointment.o Reminder.o		
	
Main.o: Main.cc Calendar.hh 
	g++ -g -c Main.cc	  
Calendar.o: Calendar.cc Day.hh 
	$(CC) $(CFLAGS) -c Calendar.cc	
Day.o: Day.cc Appointment.hh 
	$(CC) $(CFLAGS) -c Day.cc	
Appointment.o: Appointment.cc Reminder.hh
	$(CC) $(CFLAGS) -c Appointment.cc	
Reminder.o: Reminder.cc Reminder.hh 
	$(CC) $(CFLAGS) -c Reminder.cc	
clean:
	rm edit Main.o Calendar.o Day.o Appointment.o Reminder.o	

