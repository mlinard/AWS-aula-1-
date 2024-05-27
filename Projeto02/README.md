# Projeto Transferência Bancária Concorrente
- Marcello Linard
- Gabriel Mason

## Passo 1: Preparação do Ambiente
- Instalar Git e GCC: <br/>
- Abra o terminal no AWS. <br/>
- Instale o Git <br/>
- Instale o GCC <br/>

## Passo 2: Clonagem do Repositório
- Navegue até o diretório onde você deseja clonar o repositório. <br/>
- Acesse o diretório clonado. <br/>

## Passo 3: Compilação do Programa
- Compile o programa usando o GCC. <br/>

## Passo 4: Execução do Programa
- Execute o programa compilado para testar as transferências de fundos entre contas de forma segura e verifique o saldo final após as operações.

## Explicação Detalhada da Solução
### Contexto do Problema:
A implementação precisa gerenciar transferências de fundos entre duas contas bancárias, garantindo que os saldos sejam atualizados de forma correta e segura, mesmo com múltiplas operações ocorrendo de forma concorrente.

### Solução Desenvolvida:
#### Estrutura de Dados:
- **Conta:** Cada conta é representada por uma estrutura que contém informações como saldo e um mutex para controle de acesso concorrente.

### Implementação do Código:
#### Concorrência:
- A concorrência é gerenciada usando a chamada de sistema `pthread_create` para criar threads que executam a função de transferência.

#### Sincronização:
- Mutexes são usados para sincronizar o acesso às contas, garantindo que as transferências sejam feitas de forma atômica e segura.

#### Detalhes Técnicos:
- Cada thread verifica se há saldo suficiente antes de proceder com a transferência. Se o saldo é suficiente, a transferência é realizada; caso contrário, a operação é ignorada.

### Funcionamento do Programa:
- O programa realiza dez tentativas de transferir um valor fixo de uma conta para outra. Cada tentativa é feita em uma nova thread.
- Após todas as transferências, o programa exibe os saldos finais das contas para verificar a precisão e consistência das operações realizadas.
