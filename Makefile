objects = portfolio.o security.o location.o analyzer.o
CFLAGS = -std=c++0x -Wall
VPATH = fin:util

investor: $(objects)
	g++ $(CFLAGS) -o investor $(objects)
	
analyzer.o: analyzer.h
	g++ $(CFLAGS) -c $@ $^
portfolio.o: portfolio.h security.h
	g++ $(CFLAGS) -c $@ $^
security.o: security.h
	g++ $(CFLAGS) -c $@ $^
location.o: location.h
	g++ $(CFLAGS) -c $@ $^
.PHONY: clean

clean:
	rm investor $(objects)