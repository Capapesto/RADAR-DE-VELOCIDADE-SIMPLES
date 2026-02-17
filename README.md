# RADAR-DE-VELOCIDADE-SIMPLES



Este projeto implementa um radar de velocidade básico utilizando um ESP32 e dois sensores de movimento PIR. Seu funcionamentoconsiste em medir o intervalo de tempo que um objeto leva para atravessar a distância entre o primeiro e o segundo sensor.

O código monitora o pino de entrada (PIR1). Assim que ele detecta nível alto, um cronômetro é zerado e o programa entra em um laço de espera até que o segundo sensor (PIR2) seja acionado. Com o tempo acumulado, o sistema calcula a velocidade média e exibe o valor em km/h no terminal.

### Configurações e Variáveis

Se você precisar ajustar o radar para o seu espaço físico ou mudar os pinos, basta alterar os valores nesta tabela dentro do código:

| Variável | Valor Padrão | Descrição |
| --- | --- | --- |
| PIR1 | 13 | Pino de entrada (início da contagem) |
| PIR2 | 35 | Pino de saída (fim da contagem) |
| distancia | 10 | Distância entre os sensores em metros |
| vTaskDelay | 100ms | Precisão do cronômetro |

### Explicação de trechos

Algumas partes do código podem parecer confusas à primeira vista, então detalhei o que elas fazem:


* `tempo * 0.1`: Como o nosso delay dentro do laço é de 100 milissegundos, cada unidade da variável `tempo` equivale a 0,1 segundo. Multiplicamos por isso para ter o valor real em segundos antes de calcular a velocidade.
  
* `* 3.6`: Fator de conversão matemática para transformar metros por segundo () em quilômetros por hora ().

* `vTaskDelay(3000 / portTICK_PERIOD_MS)`: Eu coloquei essa pausa de 3 segundos no final para evitar que o mesmo movimento dispare o radar várias vezes, já que o sensor PIR demora um pouco para voltar ao estado baixo.


### Como rodar o projeto

1. Conecte os sensores PIR nos pinos PIR1 e PIR2.
2. Mantenha uma distância de `distancia` entre eles.
3. Compile e grave no ESP32 usando o ESP-IDF ou utilize o simulador.
4. Acompanhe as leituras pelo Monitor Serial.
