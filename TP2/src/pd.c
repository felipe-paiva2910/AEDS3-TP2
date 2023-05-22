#include <stdio.h>
#include <stdlib.h>
#include "pd.h"

TabelaPD *cria_Tabela(Matriz *grid)
{
    TabelaPD *tab = (TabelaPD *)malloc(sizeof(TabelaPD));
    tab->R = grid->R;
    tab->C = grid->C;
    tab->grid = (int **)malloc(tab->R * sizeof(int *)); // aloca espaço para a TabelaPD
    {
        for (int i = 0; i < tab->R; i++) // aloca espaço para cada linha da TabelaPD
            tab->grid[i] = (int *)malloc(tab->C * sizeof(int));
    }
    return tab;
}

void libera_Tabela(TabelaPD *TabelaPD)
{
    if (TabelaPD->grid != NULL)
    {
        for (int i = 0; i < TabelaPD->R; i++)
        { // libera o espaço alocado para cada linha e para a própria TabelaPD em si
            free(TabelaPD->grid[i]);
        }
        free(TabelaPD->grid);
    }
    free(TabelaPD);
}

int PDinamica(Matriz *grid)
{
    TabelaPD *tab = cria_Tabela(grid);

    int i = 0;
    int j = 0;

    for (int i = 0; i < tab->R - 1; i++)
    {
        for (int j = 0; j < tab->C - 1; j++)
        {
            if (i == 0 && j == 0)
            {
                tab->grid[i][j] = grid->matriz[i][j];
                i++;
                j++;
            }
            else if (i == 0 && j != 0)
            {
                tab->grid[i][j] = tab->grid[i][j - 1] + grid->matriz[i][j];
                j++;
            }
            else if (i != 0 && j == 0)
            {
                tab->grid[i][j] = tab->grid[i - 1][j] + grid->matriz[i][j];
                i++;
            }
            else
            {
                tab->grid[i][j] = max(tab->grid[i - 1][j], tab->grid[i][j - 1]) + grid->matriz[i][j];
            }
        }
    }
    int energia = tab->grid[i][j];
    libera_Tabela(tab);
    if(energia < 0){
    return -(energia)+1;
    }else{
        return 1;
    }
}

int max(int a,int b){
    return a >= b ? a:b;
}