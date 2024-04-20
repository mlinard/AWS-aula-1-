# Projeto Escada rolante 
- Marcello Linard
- Gabriel Mason

## Passo 1: Preparação do Ambiente
-Instalar Git e GCC: <br/> 
-Abra o terminal no AWS.  <br/> 
-Instale o Git  <br/> 
-Instale o GCC  <br/> 

## Passo 2: Clonagem do Repositório
-Navegue até o diretório onde você deseja clonar o repositório.  <br/> 
-Acesse o diretório clonado.  <br/> 

## Passo 3: Compilação do Programa
-Compile o programa  usando o GCC.  <br/> 

## Passo 4: Execução do Programa

## Explicação Detalhada da Solução com Threads e Processos
Contexto do Problema:
O problema da escada rolante envolve gerenciar o fluxo de passageiros que desejam usar uma escada rolante em direções possivelmente opostas. A complexidade surge na necessidade de trocar a direção da escada rolante eficientemente, minimizando o tempo de espera dos passageiros.

### Solução Desenvolvida:
#### Estrutura de Dados:
Passageiro: Cada passageiro é representado por uma estrutura contendo informações como o tempo de chegada e a direção desejada (subir ou descer).
#### Implementação do Código:
### Código com Threads (TesteThreads):
#### Concorrência: 
  Utilizamos threads para simular a operação da escada rolante. Cada thread pode representar um passageiro ou um grupo de passageiros chegando em momentos diferentes.
#### Sincronização:
  Para evitar conflitos, como dois passageiros tentando usar a escada em direções opostas simultaneamente, implementamos mecanismos de sincronização (e.g., semáforos, mutexes).
#### Vantagens:
  A abordagem com threads permite uma simulação mais realista do cenário onde múltiplos eventos (passageiros chegando) ocorrem ao mesmo tempo.
### Código com Processos (TesteProcessos):
#### Isolamento:
  Cada processo é usado para simular grupos de passageiros de forma isolada, garantindo que a mudança de direção da escada ocorra somente quando necessário e de forma controlada.
#### Comunicação Entre Processos:
  Utilizamos pipes ou outros métodos de IPC (Inter-process communication) para gerenciar a fila de espera e a troca de direção da escada rolante.
#### Robustez: 
  Processos são mais robustos contra falhas, pois o erro em um processo não afeta diretamente os outros.
### Funcionamento do Programa:
Os programas processam os passageiros na ordem de chegada.
Se a escada está indo na direção correta e pode continuar, o passageiro é processado imediatamente.
Caso contrário, o passageiro é adicionado a uma fila de espera e a escada muda de direção quando não há mais passageiros para descer ou subir na direção atual.
O ciclo continua até que todos os passageiros tenham sido processados.
