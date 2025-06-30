simulazioneEsame: main.o compito.o liste.o tipo.o
	g++ -Wall main.o compito.o liste.o tipo.o -o simulazioneEsame

main.o: main.cc compito.h liste.h
	g++ -Wall -c main.cc

compito.o: compito.cc compito.h liste.h tipo.h
	g++ -Wall -c compito.cc

liste.o: liste.cc liste.h tipo.h
	g++ -Wall -c liste.cc

tipo.o: tipo.cc tipo.h
	g++ -Wall -c tipo.cc