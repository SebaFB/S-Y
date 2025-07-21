eseguibile-grafi2: compito.o grafo.o impianto.o
	g++ -Wall -o eseguibile-grafi2 compito.o grafo.o impianto.o

compito.o : compito.cc  grafo.h impianto.h
	g++ -Wall -c compito.cc

impianto.o : impianto.cc impianto.h
	g++ -Wall -c impianto.cc

grafo.o: grafo.cc grafo.h impianto.h
	g++ -Wall -c grafo.cc

