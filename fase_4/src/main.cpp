#include "DHT.h"                // Biblioteca para o sensor DHT22 (umidade e temperatura, usamos só a umidade)
#include <Wire.h>              // Biblioteca base para comunicação I2C
#include <LiquidCrystal_I2C.h> // Biblioteca para controlar o display LCD 16x2 via I2C

// === Definição dos pinos usados no projeto ===
#define SENSOR_PH 34           // Entrada analógica conectada a um LDR (simulando sensor de pH)
#define SENSOR_UMIDADE 4       // Pino digital conectado ao DHT22
#define SENSOR_FOSFORO 18      // Pino com botão simulando presença de fósforo
#define SENSOR_POTASSIO 19     // Pino com botão simulando presença de potássio
#define LED_BOMBA 5            // Pino conectado ao LED que simula a bomba d'água

// === Instanciação de objetos de sensores ===
DHT dht(SENSOR_UMIDADE, DHT22);         // Inicializa o objeto DHT, especificando pino e tipo de sensor
LiquidCrystal_I2C lcd(0x27, 16, 2);     // Inicializa o LCD 16x2 no endereço I2C 0x27

void setup() {
  Serial.begin(115200); // Inicia a comunicação serial com o baud rate de 115200

  // Envia o cabeçalho das colunas para o Serial Plotter
  Serial.println("Umidade\tpH\tFosforo\tPotassio\tBomba");

  // Configura os pinos de entrada/saída
  pinMode(SENSOR_FOSFORO, INPUT_PULLUP);   // Botão com pull-up interno ativado
  pinMode(SENSOR_POTASSIO, INPUT_PULLUP);  // Idem
  pinMode(LED_BOMBA, OUTPUT);              // LED como saída

  // Inicializa os dispositivos
  dht.begin();       // Inicia o sensor DHT22
  lcd.init();        // Inicializa o LCD
  lcd.backlight();   // Liga a luz de fundo do LCD
}

void loop() {
  // === Leitura dos sensores ===
  uint16_t phRaw = analogRead(SENSOR_PH);              // Leitura analógica bruta (0 a 4095)
  float umidade = dht.readHumidity();                  // Lê umidade do ar (0–100%)
  bool fosforo = digitalRead(SENSOR_FOSFORO) == LOW;   // Botão pressionado = presença de fósforo
  bool potassio = digitalRead(SENSOR_POTASSIO) == LOW; // Botão pressionado = presença de potássio

  // === Conversão do valor analógico em pH real (0.0 a 14.0) ===
  float phReal = map(phRaw, 0, 4095, 0, 1400) / 100.0; // Equivalência linear simulada

  // === Normalização dos dados para exibição equilibrada no Serial Plotter ===
  float phPlot = (phReal / 14.0) * 100.0;        // pH real convertido para 0–100
  float umidadePlot = umidade;                   // Umidade já está em 0–100
  int fosforoPlot = fosforo ? 100 : 0;           // Presença vira 100; ausência, 0
  int potassioPlot = potassio ? 100 : 0;         // Idem
  int bombaPlot = (umidade < 40.0 && !isnan(umidade)) ? 100 : 0; // Liga a bomba se a umidade for válida e menor que 40%

  // === Controle da bomba d'água (LED) ===
  digitalWrite(LED_BOMBA, bombaPlot > 0 ? HIGH : LOW); // Liga ou desliga o LED com base na condição da bomba

  // === Atualização do display LCD ===
  lcd.clear();                       // Limpa o display
  lcd.setCursor(0, 0);              // Linha 1
  lcd.print("Umi:");
  lcd.print(umidade, 0);            // Mostra umidade sem casas decimais
  lcd.print("% ");
  lcd.print(bombaPlot ? "ON" : "OFF"); // Mostra status da bomba

  lcd.setCursor(0, 1);              // Linha 2
  lcd.print(fosforo ? "Fos+ " : "Fos- ");   // Presença ou ausência de fósforo
  lcd.print(potassio ? "Pot+ " : "Pot- "); // Presença ou ausência de potássio

  // === Envio dos dados para o Serial Plotter ===
  Serial.print(umidadePlot);   Serial.print("\t");  // Umidade
  Serial.print(phPlot);        Serial.print("\t");  // pH
  Serial.print(fosforoPlot);   Serial.print("\t");  // Fósforo
  Serial.print(potassioPlot);  Serial.print("\t");  // Potássio
  Serial.println(bombaPlot);                       // Bomba

  delay(2000); // Aguarda 2 segundos para a próxima leitura
}
