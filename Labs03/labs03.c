#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include <sched.h>
#include <unistd.h>

// Tamanho da pilha: 64kB
#define FIBER_STACK (1024*64)

// Definindo constantes caso não estejam definidas
#ifndef CLONE_FS
#define CLONE_FS 0x00000200
#endif

#ifndef CLONE_FILES
#define CLONE_FILES 0x00000400
#endif

#ifndef CLONE_SIGHAND
#define CLONE_SIGHAND 0x00000800
#endif

#ifndef CLONE_VM
#define CLONE_VM 0x00000100
#endif

// Estrutura para os argumentos da thread
struct ThreadArgs {
    int valor;
};

// Função que será executada pela thread
int funcaoThread(void* argumento) {
    // Convertendo o argumento para a estrutura correta
    struct ThreadArgs *args = (struct ThreadArgs*)argumento;
    printf("Thread filho encerrando com valor: %d\n", args->valor);
    return args->valor;
}

int main() {
    void* pilha;
    pid_t pid;
    // Alocando a pilha
    pilha = malloc(FIBER_STACK);
    if (pilha == 0) {
        perror("malloc: não foi possível alocar a pilha");
        exit(1);
    }

    printf("Criando thread filho\n");
    struct ThreadArgs args = {42}; // Exemplo de valor a ser passado para a thread
    // Chamando a chamada de sistema clone para criar a thread filho
    pid = clone(&funcaoThread, (char*)pilha + FIBER_STACK,
                SIGCHLD | CLONE_FS | CLONE_FILES | CLONE_SIGHAND | CLONE_VM, (void*)&args);
    if (pid == -1) {
        perror("clone");
        exit(2);
    }

    int status;
    // Aguardando a thread filho encerrar e capturando o seu valor de retorno
    pid = waitpid(pid, &status, 0);
    if (pid == -1) {
        perror("waitpid");
        exit(3);
    }

    // Verificando se a thread filho encerrou corretamente
    if (WIFEXITED(status)) {
        int retornoThread = WEXITSTATUS(status);
        // Liberando a pilha
        free(pilha);
        printf("Thread filho retornou com valor: %d e a pilha foi liberada.\n", retornoThread);
    } else {
        perror("waitpid: erro na thread filho");
        exit(4);
    }

    return 0;
}

