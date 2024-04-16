
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <pthread.h>

int processFile(const char *filePath) {
    FILE *arquivo = fopen(filePath, "r");
    if (arquivo == NULL) {
        printf("Não foi possível abrir o arquivo %s.\n", filePath);
        return -1;
    }

    int N;
    fscanf(arquivo, "%d", &N);

    int ti, di;
    int momentoAtual = 0;
    int momentoFinal_direcaoAtual = 0;
    int momentoInicio_Esperar = 0;
    int direcaoesperar = -1;
    int direcaoAtual = -1;
    int esperar = 0;

    for (int i = 0; i < N; i++) {
        fscanf(arquivo, "%d %d", &ti, &di);

        if (esperar && ti >= momentoInicio_Esperar) {
            momentoAtual = momentoFinal_direcaoAtual;
            momentoFinal_direcaoAtual = momentoAtual + 10;
            direcaoAtual = direcaoesperar;
            esperar = 0;
        }

        if (direcaoAtual == -1 || di == direcaoAtual || ti > momentoFinal_direcaoAtual) {
            momentoAtual = ti;
            momentoFinal_direcaoAtual = ti + 10;
            direcaoAtual = di;
        } else {
            if (!esperar) {
                momentoInicio_Esperar = momentoFinal_direcaoAtual;
                direcaoesperar = di;
                esperar = 1;
            }
        }
    }

    if (esperar) {
        momentoFinal_direcaoAtual += 10;
    }

    fclose(arquivo);
    printf("%s: %d\n", filePath, momentoFinal_direcaoAtual);
    return momentoFinal_direcaoAtual;
}

void *threadFunction(void *arg) {
    char *filePath = (char *)arg;
    processFile(filePath);
    free(filePath); // Assuming filePath was dynamically allocated
    return NULL;
}

int main() {
    DIR *d;
    struct dirent *dir;
    d = opendir("./input");
    if (d) {
        pthread_t threads[1024]; // Assume no more than 1024 files for simplicity
        int tCount = 0;
        while ((dir = readdir(d)) != NULL) {
            if (dir->d_type == DT_REG) { 
                char *filePath = malloc(256); // Allocate memory for the file path
                snprintf(filePath, 256, "./input/%s", dir->d_name);
                pthread_create(&threads[tCount++], NULL, threadFunction, filePath);
            }
        }
        for (int i = 0; i < tCount; i++) {
            pthread_join(threads[i], NULL);
        }
        closedir(d);
    } else {
        printf("Não foi possível abrir o diretório 'input'.\n");
        return 1;
    }
    return 0;
}
