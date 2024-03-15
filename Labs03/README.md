# O que foi feito

### Inclusão do cabeçalho sched.h:

O sched.h é necessário para utilizar a função clone(), que é uma chamada de sistema específica do Linux para criar threads.
Definição manual das constantes CLONE_FS, CLONE_FILES, CLONE_SIGHAND e CLONE_VM:

Algumas constantes utilizadas como flags na chamada clone() podem não estar definidas em todas as versões ou distribuições do Linux. Portanto, definimos manualmente essas constantes caso elas não estejam definidas no sistema.

### Correção na definição do tamanho da pilha:

A macro FIBER_STACK foi corrigida para utilizar parênteses ao redor da multiplicação para garantir a precedência correta.
Essas alterações garantem que o código compile corretamente em sistemas Linux, incluindo a definição das constantes necessárias para a chamada clone().
