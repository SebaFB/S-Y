eseguibile-gioco : main_gioco.o liste.o compito.o tipo.o
	g++ -Wall -o eseguibile-gioco main_gioco.o tipo.o liste.o compito.o 

main_gioco.o : main_gioco.cpp compito.h 
	g++ -Wall -c main_gioco.cpp

compito.o : compito.cc compito.h
	g++ -Wall -c compito.cc

tipo.o: tipo.cc tipo.h
	g++ -Wall -c tipo.cc

liste.o : liste.cc liste.h tipo.h
	g++ -Wall -c liste.cc


