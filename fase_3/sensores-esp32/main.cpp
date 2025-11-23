#include "DHT.h"  // Biblioteca para o sensor DHT

// Definição dos pinos conectados aos sensores e atuadores
#define SENSOR_PH 34          // pino analógico para simular sensor de pH (com LDR)
#define SENSOR_UMIDADE 4      // pino digital ligado ao DHT22 (umidade)
#define SENSOR_FOSFORO 18     // pino digital ligado a botão/fonte para fósforo
#define SENSOR_POTASSIO 19    // pino digital ligado a botão/fonte para potássio
#define LED_BOMBA 5           // pino digital para LED que simula o acionamento da bomba

// Inicializa o sensor de umidade do solo (DHT22) no pino definido
DHT dht(SENSOR_UMIDADE, DHT22);

void setup() {
  Serial.begin(115200);  // Inicializa comunicação serial para exibição de dados

  // Configura os sensores de nutrientes como entrada com resistor de pull-up
  // (espera-se LOW quando o botão estiver pressionado, ou seja, presença do nutriente)
  pinMode(SENSOR_FOSFORO, INPUT_PULLUP);
  pinMode(SENSOR_POTASSIO, INPUT_PULLUP);

  // Configura o LED que representa a bomba de irrigação como saída
  pinMode(LED_BOMBA, OUTPUT);
  
  // Inicia o sensor DHT
  dht.begin();
}

void loop() {
  // Leitura do "sensor de pH", simulado com um LDR ligado ao pino analógico
  int ph = analogRead(SENSOR_PH);

  // Leitura da umidade do solo através do DHT22
  float umidade = dht.readHumidity();

  // Verificação da presença de fósforo e potássio
  // (LOW = botão pressionado = nutriente presente)
  bool fosforo = digitalRead(SENSOR_FOSFORO) == LOW;
  bool potassio = digitalRead(SENSOR_POTASSIO) == LOW;

  // Lógica de irrigação:
  // A bomba é acionada apenas se a umidade estiver abaixo de 40%
  if (umidade < 40.0) {
    digitalWrite(LED_BOMBA, HIGH);  // Liga a bomba
  } else {
    digitalWrite(LED_BOMBA, LOW);   // Desliga a bomba
  }

  // Alerta de ausência de nutrientes (não interfere diretamente na irrigação)
  if (!fosforo) {
    Serial.println("Alerta: Falta de fósforo no solo.");
  }
  if (!potassio) {
    Serial.println("Alerta: Falta de potássio no solo.");
  }

  // Exibe todas as leituras e estados no monitor serial
  Serial.println("----- LEITURAS -----");
  Serial.print("Umidade: ");
  Serial.println(umidade);
  Serial.print("pH (simulado com LDR): ");
  Serial.println(ph);
  Serial.print("Fósforo (botão): ");
  Serial.println(fosforo ? "Presente" : "Ausente");
  Serial.print("Potássio (botão): ");
  Serial.println(potassio ? "Presente" : "Ausente");

  delay(2000);  // Aguarda 2 segundos antes da próxima leitura
}
