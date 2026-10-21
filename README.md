# 🍷 Vinheria Agnello — Monitoramento de Luminosidade

<p align="center">
  <strong>Projeto de Sistemas Embarcados com Arduino</strong><br>
  Sensor LDR • LEDs indicadores • Buzzer • Display LCD
</p>

---

## 📌 Sobre o projeto

Este projeto foi desenvolvido para a **Vinheria Agnello** com o objetivo de monitorar a luminosidade do ambiente utilizando um Arduino e um sensor LDR.

O sistema interpreta as leituras do sensor e indica diferentes estados por meio de LEDs. Um display LCD apresenta a porcentagem estimada de luminosidade e o estado atual do sistema. Quando é identificado o estado de problema, um buzzer é acionado.

## Objetivos

- Monitorar a luminosidade do ambiente com um sensor LDR.
- Utilizar a função `map()` para converter as leituras em uma porcentagem estimada.
- Indicar os estados do sistema por meio de LEDs.
- Exibir informações em um display LCD.
- Utilizar um buzzer para sinalizar uma condição de problema.
- Praticar programação e simulação de circuitos eletrônicos com Arduino.

## 🔗 Acesse o projeto

### 🖥️ Simulação no Tinkercad

[**Abrir o circuito e a simulação no Tinkercad**](https://www.tinkercad.com/things/kwbaPh3RnQr-cp-01-edge-monkey-nerds?sharecode=ArAOhECvBc8ngeoBvXghLmmu6CLJP60yd9npdsQpZlk)

### 🎬 Vídeo de apresentação

[**Assistir ao vídeo de apresentação no Google Drive**](https://drive.google.com/file/d/1q1ih_3yb7XIiu3AIEP4YuMeLF1lnxHzT/view?usp=sharing)

## Componentes utilizados

| Componente           | Função                                  |
| -------------------- | --------------------------------------- |
| Arduino              | Controla o funcionamento do sistema     |
| Sensor LDR           | Detecta a luminosidade do ambiente      |
| Resistor de 10 kΩ    | Compõe o circuito de leitura do LDR     |
| LED verde            | Indica o estado normal                  |
| LED amarelo          | Indica o estado de alerta               |
| LED vermelho         | Indica o estado de problema             |
| Resistores de 220 Ω  | Limitam a corrente dos LEDs             |
| Buzzer               | Emite o sinal sonoro de alerta          |
| Display LCD 16×2     | Exibe a porcentagem de luz e o estado   |
| Protoboard e jumpers | Permitem montar as conexões do circuito |

## Como funciona

1. O sensor LDR realiza a leitura da luminosidade.
2. O Arduino utiliza a leitura analógica para calcular uma porcentagem estimada de luz com a função `map()`.
3. O sistema compara a leitura com os limites definidos no código.
4. O LED correspondente ao estado identificado é aceso.
5. O display LCD apresenta a porcentagem estimada e o estado atual.
6. No estado de problema, o buzzer é acionado por um período de 3 segundos. Se a condição persistir, um novo ciclo do alarme poderá começar.

## Estados do sistema

| Leitura analógica | Estado   | Indicador                |
| ----------------- | -------- | ------------------------ |
| Menor que 900     | Normal   | 🟢 LED verde             |
| De 900 até 959    | Alerta   | 🟡 LED amarelo           |
| 960 ou superior   | Problema | 🔴 LED vermelho + buzzer |

_Os limites acima correspondem às condições definidas no código-fonte. A porcentagem exibida é uma estimativa baseada na calibração do sensor._

## 🔌 Mapeamento dos pinos

| Componente   | Pino do Arduino                                     |
| ------------ | --------------------------------------------------- |
| Sensor LDR   | `A0`                                                |
| LED vermelho | `12`                                                |
| LED amarelo  | `11`                                                |
| LED verde    | `10`                                                |
| Buzzer       | `9`                                                 |
| Display LCD  | Conforme a configuração da biblioteca e do circuito |

## ▶️ Como executar

1. Abra o circuito pelo link do Tinkercad.
2. Inicie a simulação, se estiver disponível.
3. Observe as leituras do sensor e as mudanças dos LEDs.
4. Verifique as informações exibidas no display LCD.
5. Observe o acionamento do buzzer quando o sistema entra no estado de problema.

Para executar o código em um ambiente Arduino compatível, instale a biblioteca `Adafruit_LiquidCrystal`, confira as conexões e carregue o arquivo `.ino`.

## 🛠️ Dificuldades encontradas

**Configuração do display LCD:** foi necessário pesquisar a documentação e utilizar uma biblioteca específica para controlar o display.

**Calibração do sensor LDR:** as leituras variavam conforme a iluminação. Para ajustar o funcionamento, foram realizados testes utilizando o Monitor Serial.

**Controle do buzzer:** foi necessário ajustar a lógica de temporização para que o som pudesse completar os 3 segundos mesmo quando o estado do sistema mudasse.

Essas etapas ajudaram a compreender a importância dos testes, da pesquisa e da correção de erros durante o desenvolvimento.

## 📚 Aprendizados

O desenvolvimento do projeto permitiu praticar a leitura de sensores, o controle de saídas digitais, a utilização de bibliotecas, a temporização e a simulação de circuitos eletrônicos.

## 👥 Integrantes

- Grupo: Monkey Nerds -> Diego Ramos Pereira Gonzalez RM:574620, Victor Santos Ferreira de Morais RM:575508, Daniel Souza Gomes RM:575813, André Ghustavo Matta de Oliveira RM:576354 e Diego Alejandro Ribeiro Olalla RM:575447

## 🏁 Conclusão

O projeto da Vinheria Agnello demonstra como o Arduino pode ser utilizado para monitorar a luminosidade e fornecer indicações visuais e sonoras.

---

<p align="center">
  <strong>Projeto FIAP — Arduino e Sistemas</strong>
</p>
