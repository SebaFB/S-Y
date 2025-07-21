eseguibile-grafi2: compito.o grafo.o impianto.o
	g++ -Wall -o eseguibile-grafi2 compito.o grafo.o impianto.o

compito.o : compito.cc impianto.h grafo.h
	g++ -Wall -c compito.cc

grafo.o: grafo.cc grafo.h
	g++ -Wall -c grafo.cc

impianto.o : impianto.cc impianto.h
	g++ -Wall -c impianto.cc