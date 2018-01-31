CC = g++
CFLAGS = -g

default: mercury

mercury: functions.o main.o
	$(CC) $(CFLAGS) -o mercury functions.o main.o 

functions.o: functions.cpp fun.h
	$(CC) $(CFLAGS) -c functions.cpp 

main.o: main.cpp fun.h
	$(CC) $(CFLAGS) -c main.cpp

clean:
	$(RM) count *.o *~
