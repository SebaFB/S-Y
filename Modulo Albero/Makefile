eseguibile-albero : main_albero.o albero.o stringa.o 
	g++ -Wall -o eseguibile-albero main_albero.o albero.o stringa.o

main_albero.o : main_albero.cpp albero.h stringa.h
	g++ -Wall -c main_albero.cpp

albero.o : albero.cpp albero.h stringa.h
	g++ -Wall -c albero.cpp

stringa.o: stringa.cpp stringa.h
	g++ -Wall -c stringa.cpp

	