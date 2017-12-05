All: gg.o hoofd.o
	g++ -Wall -o getallen gg.o hoofd.o
gg.o: gg.cc gg.h
	g++ -Wall -c gg.cc
hoofd.o: hoofd.cc gg.h
	g++ -Wall -c hoofd.cc
