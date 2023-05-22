#ifndef FILE_H
#define FILE_H

#include "grid.h"

typedef struct
{
    int estrategia;
    Matriz *casos;
    int n_casos;
} File;

File *readFILE(char *input);
    void CriaSaida(int *energia, int n_casos);
    void freeFILE(File * input);
    void FileTempos(int tam_entrada,double rusage_s, double rusage_u, double gettimeofday);
    
#endif