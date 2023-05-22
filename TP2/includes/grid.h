#ifndef GRID_H
#define GRID_H

typedef struct
{
    int R, C;
    int **matriz;
} Matriz;

Matriz *cria_Matriz(int R, int C);
void libera_Matriz(Matriz *matriz);
int Calcula_Energia(Matriz *matriz);

#endif