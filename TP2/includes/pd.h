#ifndef PD_H
#define PD_H

#include "grid.h"

typedef struct{
    int R,C;
    int **grid;
}TabelaPD;

TabelaPD *cria_Tabela(Matriz *grid);
void libera_Tabela(TabelaPD *tab);
int PDinamica(Matriz *grid);
int max(int a,int b);

#endif