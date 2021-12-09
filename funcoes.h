/*Arquivo destinado às funções que
serão utilizadas nesse projeto.*/

//Definição da variável TAM para esse arquivo:

#ifndef TAM
    #define TAM 10000
#endif //TAM

//Função que adiciona valores aleatórios ao vetor:

void adiciona_aleatorios(int *vetor){
    for(int i = 0; i < TAM; i++){
        vetor[i] = rand() % TAM;
    }
}

//Função que implementa o bubble sort:

void bubble_sort(int *vet, int tam){
    int aux;
    for(int i = 1; i < tam;i++){
        for(int j = 0; j < (tam - 1); j++){
            if(vet[j] > vet[j + 1]){
                aux = vet[j];
                vet[j] = vet[j + 1];
                vet[j + 1] = aux;
            }
        }
    }
}

//Método heap:

void heap(int *vetor, int inicio, int fim){
    int pai = vetor[inicio];
    int filho = (inicio * 2) + 1;
    while(filho <= fim){
        if(filho < fim){
            if(vetor[filho] < vetor[filho + 1]){
                filho = filho + 1;
            }
        }
        if(pai < vetor[filho]){
            vetor[inicio] = vetor[filho];
            inicio = filho;
            filho = (2 * inicio) + 1;
        }else{
            filho = fim + 1;
        }
    }
    vetor[inicio] = pai;
}

//Função que implementa o heap sort:

void heap_sort(int *vetor){
    int aux, meio = (TAM - 1) / 2;
    for(int i = meio; i >= 0; i--){
        heap(vetor, i, TAM - 1);
    }
    for(int j = TAM - 1; j >= 1; j--){
        aux = vetor[0];
        vetor[0] = vetor[j];
        vetor[j] = aux;
        heap(vetor, 0, j - 1);
    }
}

//Função que implementa o insert sort:

void insert_sort(int *vet, int tam){
    int aux, proximo;
    for(int i = 1; i < tam; i++){
        proximo = i;
        while(proximo != 0 && vet[proximo] < vet[proximo - 1]){
            aux = vet[proximo];
            vet[proximo] = vet[proximo - 1];
            vet[proximo - 1] = aux;
            proximo--;
        }
    }
}

//Método merge:

void merge_method(int *vetor, int inicio_1, int fim_1, int inicio_2, int fim_2){
    int aux[TAM], i = inicio_1, j = inicio_2, k = 0;
    while(i <= fim_1 && j <= fim_2){
        if(vetor[i] < vetor[j]){
            aux[k++] = vetor[i++];
        }else{
            aux[k++] = vetor[j++];
        }
    }
    while(i <= fim_1){
        aux[k++] = vetor[i++];
    }
    while(j <= fim_2){
        aux[k++] = vetor[j++];
    }
    for(i = inicio_1, j = 0; i <= fim_2; i++, j++){
        vetor[i] = aux[j];
    }
}

//Função que implementa o merge sort:

void merge_sort(int *vetor, int inicio, int fim){
    if(inicio < fim){
        int meio = (inicio + fim) / 2;
        merge_sort(vetor, inicio, meio);
        merge_sort(vetor, meio + 1, fim);
        merge_method(vetor, inicio, meio, meio + 1, fim);
    }
}

//Função que implementa o quick sort:

void quick_sort(int *vetor, int tam){
    int i, j, aux, troca;
    if(tam < 2){
        return;
    }else{
        aux = vetor[tam / 2];
    }
    for(i = 0, j = tam - 1;; i++, j--){
        while(vetor[i] < aux){
            i++;
        }
        while(aux < vetor[j]){
            j--;
        }
        if(i >= j){
            break;
        }else{
            troca = vetor[i];
            vetor[i] = vetor[j];
            vetor[j] = troca;
        }
    }
    quick_sort(vetor, i);
    quick_sort(vetor + i, tam - i);
}

//Função que implementa o select sort:

void select_sort(int *vet, int tam){
    int menor, aux;
    for(int j = 0; j < (tam - 1); j++){
        menor = j;
        for(int k = (j + 1); k < tam; k++){
            if(vet[k] < vet[menor]){
                menor = k;
            }
        }
        if(j != menor){
            aux = vet[j];
            vet[j] = vet[menor];
            vet[menor] = aux;
        }
    }
}

//Função que implementa o sheel sort:

void shell_sort(int *vet, int tam){
    int aux = 1, aux_2, aux_3;
    while(aux < tam){
        aux = (3 * aux) + 1;
    }
    while(aux > 1){
        aux = aux / 3;
        for(int i = aux; i < tam; i++){
            aux_2 = vet[i];
            aux_3 = i - aux;
            while(aux_3 >= 0 && aux_2 < vet[aux_3]){
                vet[aux_3 + aux] = vet[aux_3];
                aux_3 = aux_3 - aux;
            }
            vet[aux_3 + aux] = aux_2;
        }
    }
}
