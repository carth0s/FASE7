# Sistema de Irrigação Automatizado com Monitoramento de Nutrientes

## Descrição do Projeto
Este projeto simula um sistema inteligente de irrigação utilizando sensores físicos e digitais para monitorar a umidade do solo e a presença de nutrientes (fósforo e potássio), acionando automaticamente uma bomba de irrigação quando necessário.
Foi desenvolvido com base em uma placa ESP32, utilizando o simulador Wokwi.

## Componentes Utilizados
- ESP32 - Microcontrolador principal
- DHT22	- Sensor digital de temperatura e umidade (usado aqui apenas para umidade)
- LDR - Sensor analógico utilizado como simulação de leitura de pH
- Botões - Simulam presença de fósforo e potássio no solo
- LED	- Simula o relé de acionamento de uma bomba de irrigação

## Funcionalidades
- Leitura da umidade com o sensor DHT22.
- Leitura analógica simulada do pH via um LDR.
- Detecção de nutrientes: dois botões simulam presença de fósforo e potássio.
- Acionamento automático da bomba:
  - A bomba liga (LED acende) apenas se a umidade for inferior a 40%.
  - A ausência de nutrientes não aciona a bomba, mas emite alertas no monitor serial.
- Monitor serial exibe todas as leituras e alertas.

## Lógica de Funcionamento
```cpp
  if (umidade < 40.0) {
    // Liga bomba se solo estiver seco
  }

  if (!fosforo) {
    // Alerta de falta de fósforo
  }

  if (!potassio) {
    // Alerta de falta de potássio
  }
```
A lógica foi pensada para irrigar o solo quando a umidade estiver a baixo de 40%, e monitorar a presença/ausência de fósforo e potácio no solo.

## Leitura no Monitor Serial
Exemplo de saída no monitor serial:
```yaml
  Alerta: Falta de fósforo no solo.
  ----- LEITURAS -----
  Umidade: 35.40
  pH (simulado com LDR): 846
  Fósforo (botão): 0
  Potássio (botão): 1
```
## Plataforma Utilizada
Wokwi Simulator: Link para o projeto https://wokwi.com/projects/431422752922568705

## Código Fonte
O código fonte (C++) foi disponibilizado no arquivo main.cpp

## Imagem do Circuito
<img src="assets/sensores.png" alt="Sensores simulados através do Wokwi Simulator" border="0" width=80% height=80%>

## Exemplos do Circuito em Funcionamento

Neste primeiro exemplo, a umidade do solo está abaixo de 40%, ativando a irrigação (LED vermelho), e o solo conta com a presença de potássio (botão).
<img src="assets/funcionamento1.png" alt="Sensores simulados através do Wokwi Simulator" border="0" width=95% height=95%>

No segundo exemplo, a umidade do solo está acima de 40%, desligando a irrigação (LED vermelho), e o solo conta com a presença de fósforo (botão).
<img src="assets/funcionamento2.png" alt="Sensores simulados através do Wokwi Simulator" border="0" width=95% height=95%>

## Observações Finais
O código foi comentado de forma didática para facilitar a leitura e a avaliação.

