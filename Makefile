objects = filereader.o market.o security.o transaction.o portfolio.o stockList.o analyzer.o location.o bank.o date.o
CFLAGS = -std=c++14 -Wall
VPATH = util:fin

modeler: $(objects)	
	g++ $(CFLAGS) $(objects) -o modeler

filereader.o: filereader.cpp filereader.h market.h analyzer.h transaction.h bank.h portfolio.h stockList.h security.h location.h bank.h date.h
	g++ -c $(CFLAGS) $< -o $@

market.o: market.cpp market.h analyzer.h transaction.h bank.h portfolio.h stockList.h security.h location.h date.h 
	g++ -c $(CFLAGS) $< -o $@

analyzer.o: analyzer.cpp analyzer.h transaction.h bank.h portfolio.h stockList.h security.h location.h date.h 
	g++ -c $(CFLAGS) $< -o $@

transaction.o: transaction.cpp transaction.h bank.h portfolio.h stockList.h security.h location.h date.h
	g++ -c $(CFLAGS) $< -o $@

bank.o: bank.cpp bank.h portfolio.h stockList.h security.h location.h date.h
	g++ -c $(CFLAGS) $< -o $@
	
portfolio.o: portfolio.cpp portfolio.h stockList.h security.h location.h date.h
	g++ -c $(CFLAGS) $< -o $@

stockList.o: stockList.cpp stockList.h security.h location.h date.h
	g++ -c $(CFLAGS) $< -o $@

security.o: security.cpp security.h location.h date.h
	g++ -c $(CFLAGS) $< -o $@

location.o: location.cpp location.h date.h
	g++ -c $(CFLAGS) $< -o $@

date.o: date.cpp date.h
	g++ -c $(CFLAGS) $< -o $@

.PHONY: clean

clean:
	rm modeler $(objects) *.*~ fin/*.*~ util/*.*~