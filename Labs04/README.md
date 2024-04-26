# Projeto Multiplicação de Matriz por Vetor com Threads

## Desenvolvedores
- [Marcello Linard Teixeira Ra: 10419338]
- [ Gabriel Mason Gueriano Ra: 10409928]

## Passo 1: Preparação do Ambiente
- Instalar Git e GCC:
  - Abra o terminal no AWS.
  - Instale o Git com `sudo yum install git -y`.
  - Instale o GCC com `sudo yum install gcc -y`.

## Passo 2: Clonagem do Repositório
- Navegue até o diretório onde você deseja clonar o repositório.
- Clone o repositório com git clone.
- Acesse o diretório clonado com cd.

## Passo 3: Compilação do Programa
- Compile o programa usando o GCC com `gcc Labs04.c -o Labs04 -lpthread`.

## Passo 4: Execução do Programa
- Execute o programa compilado com `./Labs04`.

## Explicação Detalhada da Solução com Threads

### Contexto do Problema
O problema abordado envolve a multiplicação de uma matriz por um vetor utilizando threads para simular operações paralelas e melhorar a eficiência do cálculo.

### Solução Desenvolvida
- **Estrutura de Dados**: 
  - Matriz: Uma matriz de tamanho `MxN` contendo valores double.
  - Vetor: Um vetor de tamanho `N` contendo valores double.
  - Resultado: Um vetor de tamanho `M` para armazenar o resultado da multiplicação.

- **Implementação do Código**:
  - **Código com Threads (`Labs04.c`)**:
    - **Concorrência**: Utilizamos threads para realizar a multiplicação de cada linha da matriz pelo vetor de forma concorrente.
    - **Sincronização**: Cada thread calcula uma linha do resultado de forma independente, evitando conflitos de acesso à memória.
    - **Vantagens**: A abordagem com threads permite uma execução mais rápida e eficiente, especialmente em sistemas com múltiplos núcleos de processamento.

### Funcionamento do Programa
O programa cria uma thread para cada linha da matriz. Cada thread realiza a multiplicação da sua linha correspondente pelo vetor e armazena o resultado no vetor de saída. Após todas as threads terminarem sua execução, o programa imprime o vetor resultado.
