Gabriel: Analise do código e identificar os trechos executados por pai e filho.
Marcello: Executar o código desenvolvido na maquina da AWS e atualizar o git.
Obs: Código desenvolvido onde os processos pai e filho trocam uma interação foi desenvolvido por ambos.
Desenvolvemos a tarefa ao longo da semana, porém só nos atentamos aos requisitos de organização do git hoje (segunda), por isso as atividades estão com a data um dia antes da entrega.

No primeiro trecho de código:
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
    pid_t pid;

    /* fork a child process */
    pid = fork();
    if (pid < 0) { /* error occurred */
        fprintf(stderr, "Fork Failed\n");
        return 1;
    } else if (pid == 0) { /* child process */
        printf("I am the child %d\n", getpid());
        execlp("/bin/ls", "ls", NULL);
    } else { /* parent process */
        /* parent will wait for the child to complete */
        printf("I am the parent %d\n", getpid());
        wait(NULL);
        printf("Child Complete\n");
    }
    return 0;
}
No código acima, o trecho de código dentro do if (pid == 0) é executado pelo processo filho, enquanto o trecho dentro do else é executado pelo processo pai.

No segundo trecho de código:

#include <stdio.h>

int main() {
    printf("%d\n", getpid());
    fork();
    printf("%d\n", getpid());
    fork();
    printf("%d\n", getpid());
    fork();
    printf("%d\n", getpid());
    return 0;
}
Neste caso, a chamada fork() cria um processo filho, então cada printf("%d\n", getpid()); será executado duas vezes - uma vez no processo pai e outra no processo filho. Assim, o número total de processos criados será 2^3, ou seja, 8 processos.
