eseguibile-liste : main_liste.o liste_tipo.o liste_header.o fun_liste.o
	g++ -Wall -o eseguibile-liste main_liste.o liste_tipo.o liste_header.o fun_liste.o

main_liste.o : main_liste.cpp fun_liste.h
	g++ -Wall -c main_liste.cpp

liste_tipo.o : liste_tipo.cpp liste_tipo_header.h 
	g++ -Wall -c liste_tipo.cpp

liste_header.o : liste_header.cpp liste_header.h
	g++ -Wall -c liste_header.cpp

fun_liste.o :fun_liste.cpp fun_liste.h 
	g++ -Wall -c fun_liste.cpp