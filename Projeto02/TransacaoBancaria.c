#define _GNU_SOURCE
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include <sched.h>
#include <stdio.h>
#include <pthread.h>

// 64kB stack
#define FIBER_STACK 1024*64
struct c {
    int saldo;
    pthread_mutex_t mutex;
};
typedef struct c conta;

conta from, to;
int valor;

// The child thread will execute this function
void* transferencia(void *arg) {
    pthread_mutex_lock(&from.mutex);   // Lock the from account
    pthread_mutex_lock(&to.mutex);     // Lock the to account

    if (from.saldo >= valor) {
        from.saldo -= valor;
        to.saldo += valor;
    }

    pthread_mutex_unlock(&to.mutex);   // Unlock the to account
    pthread_mutex_unlock(&from.mutex); // Unlock the from account

    printf("Transferência concluída com sucesso!\n");
    printf("Saldo de c1: %d\n", from.saldo);
    printf("Saldo de c2: %d\n", to.saldo);
    return NULL;
}

int main() {
    pthread_t threads[10];
    int i;

    // Initialize the mutexes
    pthread_mutex_init(&from.mutex, NULL);
    pthread_mutex_init(&to.mutex, NULL);

    // Todas as contas começam com saldo 100
    from.saldo = 100;
    to.saldo = 100;
    printf("Transferindo 10 para a conta c2\n");
    valor = 10;

    for (i = 0; i < 10; i++) {
        // Create the child thread
        if (pthread_create(&threads[i], NULL, transferencia, NULL) != 0) {
            perror("pthread_create");
            exit(2);
        }
    }

    // Wait for all child threads to finish
    for (i = 0; i < 10; i++) {
        pthread_join(threads[i], NULL);
    }

    // Destroy the mutexes
    pthread_mutex_destroy(&from.mutex);
    pthread_mutex_destroy(&to.mutex);

    printf("Transferências concluídas e memória liberada.\n");
    return 0;
}
