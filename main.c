#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#include "funcoes.h"
#ifndef TAM
    #define TAM 10000
#endif //TAM

//Função principal:

int main(void){
    setlocale(LC_ALL, "portuguese");
    srand((unsigned)time(NULL));
    int vetor[TAM];
    adiciona_aleatorios(vetor);
    int *aux_1 = vetor, *aux_2 = vetor, *aux_3 = vetor, *aux_4 = vetor, *aux_5 = vetor, *aux_6 = vetor;
    if(!vetor || !aux_1 || !aux_2 || !aux_3 || !aux_4 || !aux_5 || !aux_6){
        printf("Memória insuficiente!\n");
    }else{
        clock_t inicio, fim;
        inicio = clock();
        bubble_sort(vetor, TAM);
        fim = clock();
        double a = (double)(fim - inicio) / CLOCKS_PER_SEC;
        inicio = clock();
        heap_sort(aux_1);
        fim = clock();
        double b = (double)(fim - inicio) / CLOCKS_PER_SEC;
        inicio = clock();
        insert_sort(aux_2, TAM);
        fim = clock();
        double c = (double)(fim - inicio) / CLOCKS_PER_SEC;
        inicio = clock();
        merge_sort(aux_3, 0, TAM - 1);
        fim = clock();
        double d = (double)(fim - inicio) / CLOCKS_PER_SEC;
        inicio = clock();
        quick_sort(aux_4, TAM);
        fim = clock();
        double e = (double)(fim - inicio) / CLOCKS_PER_SEC;
        inicio = clock();
        select_sort(aux_5, TAM);
        fim = clock();
        double f = (double)(fim - inicio) / CLOCKS_PER_SEC;
        inicio = clock();
        shell_sort(aux_6, TAM);
        fim = clock();
        double g = (double)(fim - inicio) / CLOCKS_PER_SEC;
        printf("Tempo de execução em segundos de cada algoritmo:\n\n");
        printf("Bubble sort: %lf segundos;\n", a);
        printf("Heap sort: %lf segundos;\n", b);
        printf("Insert sort: %lf segundos;\n", c);
        printf("Merge sort: %lf segundos;\n", d);
        printf("Quick sort: %lf segundos;\n", e);
        printf("Select sort: %lf segundos;\n", f);
        printf("Shell sort: %lf segundos.\n", g);
    }
    return 0;
}
