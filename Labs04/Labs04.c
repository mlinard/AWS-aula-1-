#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

// A matriz e o vetor que serão multiplicados
// Suponha que temos uma matriz 4x3
double matriz[M][N] = {
    {1.0, 2.0, 3.0},  // Primeira linha da matriz
    {4.0, 5.0, 6.0},  // Segunda linha da matriz
    {7.0, 8.0, 9.0},  // Terceira linha da matriz
    {10.0, 11.0, 12.0} // Quarta linha da matriz
};

// Suponha que temos um vetor de tamanho 3
double vetor[N] = {2.0, 1.0, 3.0}; // Vetor para multiplicar pela matriz

#define NUM_THREADS M // Número de threads

// A matriz e o vetor que serão multiplicados
double matriz[M][N] = { /* inicialize a matriz aqui */ };
double vetor[N] = { /* inicialize o vetor aqui */ };
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
    pthread_t threads[NUM_THREADS];
    thread_data data[NUM_THREADS];
    int rc;
    
    // Criar threads para realizar a multiplicação
    for(int i = 0; i < NUM_THREADS; i++) {
        data[i].row = i;
        rc = pthread_create(&threads[i], NULL, multiplicar, (void *)&data[i]);
        
        if (rc) {
            printf("Erro ao criar thread: %d\n", rc);
            exit(-1);
        }
    }
    
    // Esperar todas as threads terminarem
    for(int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }
    
    // Imprimir o vetor resultado
    for(int i = 0; i < M; i++) {
        printf("%f\n", resultado[i]);
    }
    
    pthread_exit(NULL);
}
