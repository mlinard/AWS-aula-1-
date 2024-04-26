#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#define M 4 // Número de linhas da matriz
#define N 3 // Número de colunas da matriz e tamanho do vetor

// A matriz e o vetor que serão multiplicados
double matriz[M][N] = {
    {1.0, 2.0, 3.0},  // Primeira linha da matriz
    {4.0, 5.0, 6.0},  // Segunda linha da matriz
    {7.0, 8.0, 9.0},  // Terceira linha da matriz
    {10.0, 11.0, 12.0} // Quarta linha da matriz
};

// Vetor para multiplicar pela matriz
double vetor[N] = {2.0, 1.0, 3.0};

// Resultado da multiplicação da matriz pelo vetor
double resultado[M] = {0};

// Estrutura para passar dados para as threads
typedef struct {
    int row;
} thread_data;

// A função que cada thread irá executar
void *multiplicar(void *arg) {
    thread_data *data = (thread_data *)arg;
    int row = data->row;
    
    for(int j = 0; j < N; j++) {
        resultado[row] += matriz[row][j] * vetor[j];
    }
    
    pthread_exit(NULL);
}

int main() {
    pthread_t threads[M];
    thread_data data[M];
    int rc;
    
    // Criar threads para realizar a multiplicação
    for(int i = 0; i < M; i++) {
        data[i].row = i;
        rc = pthread_create(&threads[i], NULL, multiplicar, (void *)&data[i]);
        
        if (rc) {
            printf("Erro ao criar thread: %d\n", rc);
            exit(-1);
        }
    }
    
    // Esperar todas as threads terminarem
    for(int i = 0; i < M; i++) {
        pthread_join(threads[i], NULL);
    }
    
    // Imprimir o vetor resultado
    for(int i = 0; i < M; i++) {
        printf("%.f\n", resultado[i]); // Alterado para imprimir sem casas decimais
    }
    
    pthread_exit(NULL);
}
