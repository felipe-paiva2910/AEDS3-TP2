#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<sys/resource.h>
#include <sys/time.h>
#include "file.h"
#include "grid.h"

File *readFILE(char *in)
{
    FILE *fp = fopen(in, "r");
    if (fp == NULL)
    {
        printf("Erro ao abrir o arquivo %s\n", in);
        exit(1);
    }
    File *input = (File *)malloc(sizeof(File));                         //abre o arquivo e aloca o espaço para ele

    fscanf(fp, "%d", &input->n_casos);
    input->casos = (Matriz *)malloc(input->n_casos * sizeof(Matriz)); //aloca espaço para o numero correspondente de casos pedidos pelo usuário

    for (int i = 0; i < input->n_casos; i++)
    {
        int R, C;
        fscanf(fp, "%d %d", &R, &C);                                 //le os valores das dimensoes das matrizes para cada caso,
        Matriz *grid = cria_Matriz(R, C);                               //criando e alocando espaço para cada matriz

        for (int j = 0; j < R; j++)
        {
            for (int k = 0; k < C; k++)
            {
                fscanf(fp, "%d", &grid->matriz[j][k]);               //le os valores de cada posicao da matriz
            }
        }
        input->casos[i] = *grid;                                        //guarda cada matriz em um indice diferente de acordo com o caso
    }
    fclose(fp);
    return input;
}

void CriaSaida(int *energia, int n_casos)
{

    FILE *saida = fopen("saida.txt", "a");                              //abre o arquivo de saida ou cria um se esse não existir
    if (saida == NULL)
    {
        printf("Erro ao abrir o arquivo\n");
        exit(1);
    }
    for (int i = 0; i < n_casos; i++)
    {
        fprintf(saida, "%d\n", energia[i]);                                //imprime o resultado de cada caso no arquivo de saida
    }
    fclose(saida);
}
void FileTempos(int tam_entrada, double rusage_s, double rusage_u, double gettimeofday)
{

    FILE *tempos = fopen("tempos.csv", "w");                              //abre o arquivo de saida ou cria um se esse não existir
    if (tempos == NULL)
    {
        printf("Erro ao abrir o arquivo\n");
        exit(1);
    }
        fprintf(tempos, "%d; %lf; %lf; %lf;\n",tam_entrada,rusage_s,rusage_s,gettimeofday);                                //imprime o resultado de cada caso no arquivo de saida

    fclose(tempos);
}

void freeFILE(File *input)
{
    if (input->casos != NULL)
    {
        for (int i = 0; i < input->n_casos; i++)
        {
            free(input->casos[i].matriz);                               //libera a memoria para cada matriz alocada em cada caso
        }
        free(input->casos);
    }                                                                   //libera a memoria alocada para o arquivo de entrada
    free(input);
}
