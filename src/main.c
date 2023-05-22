#include "file.h"
#include<stdio.h>
#include<stdlib.h>
#include<sys/resource.h>
#include<sys/time.h>

int main(int argc, char **argv)
{
    struct rusage time;
    struct timeval start,end;

    gettimeofday(&start,NULL);

    if (argc != 3)
    {
        printf("ENTRADA INVALIDA\n");
        return 0;
    }
    int estrategia;
    sscanf(argv[1], "%d", &estrategia);         //le a estrategia solicitada pelo usuario
    File *input = readFILE(argv[2]);

    int *energia = (int *)malloc(input->n_casos * sizeof(int));     //aloca memoria para a energia de cada caso

    for (int i = 0; i < input->n_casos; i++)
    {
        energia[i] = Calcula_Energia(&input->casos[i]/*,int estrategia*/);             //calcula a energia de cada caso baseado na estrategia solicitada
    }

    CriaSaida(energia, input->n_casos);
    int tam_entrada = input->n_casos;         //cria o arquivo de saida com as respectivas energias minimas de cada caso
    freeFILE(input);
    free(energia);                                 //libera o espaço do arquivo e da energia

getrusage(RUSAGE_SELF,&time);
gettimeofday(&end,NULL);

double rusage_system = (double)1e-6*(time.ru_stime.tv_sec + time.ru_stime.tv_usec);
double rusage_user = (double)1e-6*(time.ru_utime.tv_sec + time.ru_utime.tv_usec);
double gettimeofday = (end.tv_sec-start.tv_sec)+ 1e-6 *(end.tv_usec-start.tv_usec);

FileTempos(tam_entrada, rusage_system,rusage_user,gettimeofday);

    return 0;
}
