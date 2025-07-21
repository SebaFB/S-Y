#ifndef __IMPIANTO_H__
#define __IMPIANTO_H__

typedef struct {
    int id; /**< Identificativo numerico del nodo */
    char tipo; /**< "O" oppure "D" */
    char stato;  /**< "P" o "A" oppure "R" o "G" */
} tipo_inf;

//TODO Implement compare (1 if tipo_inf is equivalent to tipo_inf)
int compare(tipo_inf,tipo_inf);

void print(tipo_inf);
//TODO Implement copy from tipo_inf to tipo_inf*
void copy(tipo_inf*, tipo_inf);


//TODO Implement sanity check of data from tipo_inf
// (type == O -> status = {P,A} | type == D -> status = {R,G})
int sanity_check(tipo_inf);




#endif /* __IMPIANTO_H__ */
