objects = security.o portfolio.o analyzer.o location.o
CFLAGS = -std=c++0x -Wall
VPATH = util:fin

investor: $(objects)	
	g++ $(CFLAGS) $(objects) -o investor

analyzer.o: analyzer.cpp analyzer.h portfolio.h security.h location.h
	g++ -c $(CFLAGS) $< -o $@
	
portfolio.o: portfolio.cpp portfolio.h security.h
	g++ -c $(CFLAGS) $< -o $@

security.o: security.cpp security.h
	g++ -c $(CFLAGS) $< -o $@

location.o: location.cpp location.h
	g++ -c $(CFLAGS) $< -o $@

.PHONY: clean

clean:
	rm analyzer $(objects)