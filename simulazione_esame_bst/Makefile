eseguibile-bst : compito.o bst.o hotel.o
	g++ -Wall -o eseguibile-gioco compito.o hotel.o bst.o 

compito.o : compito.cc bst.h
	g++ -Wall -c compito.cc

bst.o: bst.cc bst.h
	g++ -Wall -c bst.cc

hotel.o : hotel.cc hotel.h
	g++ -Wall -c hotel.cc