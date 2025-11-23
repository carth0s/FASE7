# Atividade FASE4_CAP1 - FARMTECH

## 📜 Descrição

Este projeto da Fase 4 da FarmTech Solutions tem como objetivo desenvolver um sistema inteligente de monitoramento agrícola, integrando hardware simulado (ESP32), banco de dados, modelo de Machine Learning e visualização interativa dos dados.

A solução é composta por três pilares principais:

### ESP32 (via Wokwi): 
Simula sensores ambientais como umidade, fósforo, potássio e pH do solo. Os dados são exibidos em tempo real no display LCD (I2C) e também enviados ao Serial Plotter para análise gráfica. A irrigação é acionada automaticamente quando a umidade está abaixo de 40%.

### Banco de Dados em Python (SQLite): 
Gerencia sensores e leituras com um modelo relacional robusto. Armazena e organiza as informações coletadas, permitindo operações de cadastro, atualização e histórico dos sensores e suas leituras.

### Machine Learning com Scikit-learn + Streamlit: 
Um modelo preditivo foi treinado com base em um dataset simulado de umidade. Ele prevê se o solo precisa de irrigação e está integrado a um dashboard interativo com Streamlit, permitindo que o usuário informe o valor de umidade e visualize a decisão sugerida pelo modelo.

#### Essa fase visa demonstrar como a inteligência artificial pode auxiliar na tomada de decisões agrícolas, otimizando o uso da água e promovendo um monitoramento eficiente do solo.

## 🎥 Vídeo de Demonstração

Vídeo com o código em funcionamento: [https://youtu.be/OuwjBovG9uU](https://youtu.be/OuwjBovG9uU)


## 📁 Estrutura de pastas

Dentre os arquivos e pastas presentes na raiz do projeto, definem-se:

- <b>document</b>: Aqui está presente a documentação do projeto, com explicação do sistema e prints.

- <b>src</b>: Aqui estão os códigos fontes utilizados no projeto:
   - main.cpp = Código C++ responsável por rodar no ESP32 simulado no Wokwi.
   - script.py = Script Python com um banco de dados SQLite que simula o armazenamento local de dados de sensores.
   - app.py = Aplicação interativa feita com Streamlit, que carrega um modelo de Machine Learning treinado e permite prever se o solo precisa ou não de irrigação com base no valor de umidade fornecido pelo usuário.
   - dataset_umidade.csv = Base de dados com 100 leituras simuladas de umidade e a indicação binária (precisa_irrigar) usada para treinar o modelo de ML. 
   - modelo_irrigação.pkl = Modelo preditivo treinado com Scikit-learn que recebe o valor da umidade como entrada e retorna se a irrigação deve ser ativada ou não.

- <b>README.md</b>: Arquivo que serve como guia e explicação geral sobre o projeto (o mesmo que você está lendo agora).

## 🔧 Como executar o código

### 1️⃣ Simulação ESP32 no Wokwi
✅ Como Acessar:
- Abra o projeto clicando [Aqui](https://wokwi.com/projects/434219114256049153)

✅ Componentes Usados:
- ESP32
- Sensor DHT22 (umidade)
- Fotoresistor (simula pH)
- Botões (fósforo e potássio)
- Display LCD I2C
- Serial Plotter (gráfico de variáveis)

💡 O que faz?
- Lê sensores e exibe em tempo real no LCD
- Liga a bomba se a umidade < 40%
- Mostra dados em gráfico pelo Serial Plotter
- Código comentado e otimizado para memória

### 2️⃣ Banco de Dados
✅ Requisitos:
- Python 3.x

▶️ Para Rodar:
````
python script.py
````
💡 O que faz?
- Cria tabelas para plantações, sensores e leituras
- Insere leituras simuladas
- Lista, edita e deleta dados com prints no terminal
- Simula como seria a coleta em um campo real

### 3️⃣ Machine Learning com Streamlit
✅ Requisitos:
- Python 3.8+

▶️ Para Rodar:
- Instale as dependências:
````
pip install streamlit pandas scikit-learn joblib
````
````
streamlit run app.py
````
💡 O que faz?
- Recebe valor de umidade (%)
- Mostra se o solo precisa de irrigação
- Exibe o dataset usado e previsões do modelo
- Usa modelo treinado salvo em modelo_irrigacao.pkl (deve estar na mesma pasta do app.py, junto com o dataset_umidade.csv)

## 🗃 Histórico de lançamentos

* 0.4.0 - 20/06/2025 
    * Mesmo Circuito da versão anterior, com as melhorias de um painel LCD para melhor vizualização das informações, e a presença de um gráfico plotter em tempo real.
    * Script aprimorado com novas tabelas.
    * Nova funcionalidade com Machine Learning onde é possível treinar um modelo para prever a necessidade de irrigar ou não o solo.
* 0.3.0 - 20/05/2025
    * Circuito ESP32 que coleta presença de fósforo, potásio, ph e umidade do solo, além de acionar uma bomba de irrigação quando identificar umidade a baixo de 40%.
    * Script que realiza um crud, exemplificando os dados de forma prática.
* 0.2.0 - 22/04/2025
    * Banco de dados que cria as relações entre as tabelas que serão utilizadas para armazenar as informações necessárias para a automatização das platações.
* 0.1.0 - 25/03/2025
    * Código python que calcula área de plantio de 2 culturas.
