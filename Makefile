CFLAGS = -Wall -std=c++0x

planner: planner.o date.o
	
planner.o: date.h

clean:
	-rm -f *.o
	-rm -f planner