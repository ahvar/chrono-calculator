CFLAGS = -g -Wall -std=c++0x

trader: analyzer.o stock.o portfolio.o location.o

location.o: location.h