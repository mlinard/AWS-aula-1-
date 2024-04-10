INTERPRETAÇÃO DO PROBLEMA 
Exemplo de entrada 2<br>
3<br>
5 0<br>
7 1<br>
9 0<br>
Exemplo de saÍda 2<br>
29

A primeira linha com número 3, indica que 3 pessoas utilizaram a escada rolante. 
O número t_1 indica o momento(em segundos) em que uma pessoa entrou na escada rolante e o d_1 a direção em que está indo. 
A primeira pessoa entrou no momento 5, a segunda pessoa no momento 7 e a terceira no momento 9. 
LEMBRANDO que leva 10 segundos para cruzar a escada rolante de uma ponta a outra.
Detalhe de interpretação: a escada rolante so para quando está vazia. Isso signfica que uma pessoa ao chegar em sequencia no lado oposto, so poderá entrar na escada após esperar esse tempo. Agora ressalto o detalhe que se uma pessoa chegar na escada idependente do momento, e a escada ja estiver se movimentando para o lado desejado, ela poderá entrar imediatamente, mesmo que já houvesse uma pessoa aguardando do outro lado. Logo a pessoa que estava aguardando do lado oposto deverá aguardar 10 segundos a partir do momento que essa ultima pessoa entrou.  

Agora resolvendo o exemplo 2:

Primeira pessoa chega no lado 0 no momento 5: logo chegará na outra ponta no momento 15
Segunda pessoa chega no lado 1 no momento 7: Pórem precisa aguardar a escada parar para que possa entrar e até o momento essa pausa está prevista para o momento 15.
Porém a terceira pessoa chega no lado 0 no momento 9: como a escada rolante ja está em funcionamento ela pode subir imediatamente. Então a partir do momento que ela entra na escada, a previsão da escada para parar vai para 19, e so então a segunda pessoa que chegou no lado oposto no momento 7 poderá subir. Assim no momento 19 a segunda pessoa entrará na escada e descerá após 10 segundos. Gerando a saída 29.
