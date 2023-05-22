#include "grid.h"
#include "file.h"
#include <stdio.h>
#include <stdlib.h>

Matriz *cria_Matriz(int R, int C)
{
    Matriz *m = (Matriz *)malloc(sizeof(Matriz));
    m->R = R;
    m->C = C;
    m->matriz = (int **)malloc(m->R * sizeof(int *)); // aloca espaço para a matriz
    {
        for (int i = 0; i < m->R; i++) // aloca espaço para cada linha da matriz
            m->matriz[i] = (int *)malloc(m->C * sizeof(int));
    }
    return m;
}

void libera_Matriz(Matriz *Matriz)
{
    if (Matriz->matriz != NULL)
    {
        for (int i = 0; i < Matriz->R; i++)
        { // libera o espaço alocado para cada linha e para a própria matriz em si
            free(Matriz->matriz[i]);
        }
        free(Matriz->matriz);
    }
    free(Matriz);
}

int Calcula_Energia(Matriz *Matriz)  //estratgia 1 -> Algoritmo Guloso
{                                               
    int i = 0;
    int j = 0; // Inicia da posição [0][0] com a energia gasta = 0
    int energia = 0;
    int n_R = Matriz->R;
    int n_C = Matriz->C;

    while (i != n_R - 1 || j != n_C - 1)
    {                                              // loop que vai até a ultima posição da matriz
        energia += Matriz->matriz[i][j]; // Ex; n_a matriz 3x3 ele vai até [2][2]

        // escolhe o movimento que diminui menos energia
        if (i == n_R - 1)
            j++;                // se estiver na ultima linha, se direciona para a direita (próxima coluna)
        else if (j == n_C - 1) // se estiver na ultima coluna, se direciona para baixo (proxima linha)
            i++;
        else if (Matriz->matriz[i + 1][j] > Matriz->matriz[i][j + 1]) // caso contrario verifica qual direção possui menor
            i++;                                                                     // perda de energia e segue nesse caminho
        else                                                                              // considerando que só se move para a direita e para baixo
            j++;
    }

    if (energia + Matriz->matriz[i][j] < 0)
    {                                                           // se a energia no final for menor que zero
        return -(energia + Matriz->matriz[i][j]) + 1; // retorna o mesmo número com sinal trocado + 1 ( se retornasse só o n_ero positivo, a energia ainda seria 0 no final)
    }                                                           // mostrando a energia que seria necessário começar
    else
    {                                                       
        return 1; // caso contrário retorna apenas 1 que é a energia minima
    }
}