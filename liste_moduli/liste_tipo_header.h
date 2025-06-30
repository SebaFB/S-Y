/*HEADER FILE DEL MODULO CHE DEFINISCE LE FUNZIONI SULLE LISTE CHE RITORNANO UN TIPO DIVERSO DA LISTA*/




struct elem
{
    char inf[51];
    elem* prev;
    elem* pun;
};

typedef elem* lista;

char* head(lista);

elem* new_elem(char*);

elem* search(lista, char*);