# FASE7

## FarmTech Solutions - Sistema Integrado de Gestão Agrícola (Fase 7)
Este projeto representa a consolidação final (Fase 7) de um ecossistema completo de agricultura inteligente (Agro 4.0). O sistema integra desde o planejamento inicial de plantio, passando por monitoramento IoT e armazenamento de dados, até a tomada de decisão avançada com Inteligência Artificial e Visão Computacional, tudo conectado à nuvem AWS.

## Objetivo da Fase 7: A Consolidação
A Fase 7 não é apenas uma nova funcionalidade, mas sim o Painel de Controle Unificado.

Anteriormente, cada fase do projeto rodava de forma isolada (scripts soltos, terminais separados). Nesta etapa, utilizamos o framework Streamlit para criar uma interface web única e interativa. O usuário navega entre os módulos através de um menu lateral, onde todas as tecnologias conversam entre si:

Front-end: Streamlit (Python).

Back-end: Integração direta com APIs, Banco de Dados e Serviços Cloud.

Segurança: Gestão de credenciais via secrets.toml (não expostas no código).

## Detalhamento dos Módulos Integrados
O dashboard está dividido nas seguintes seções, correspondentes às entregas anteriores:

### Fase 1: Planejamento & Análise Estatística
O que faz: Realiza o cálculo da área de plantio (suportando geometrias complexas como Trapézios e Círculos) e projeta o custo de insumos (Fertilizantes/Pesticidas).

Tecnologia: Scripts Python para cálculo geométrico e tradução da lógica estatística (originalmente em R) para calcular Média, Desvio Padrão e Excedentes de consumo baseados em amostras de campo.

### Fase 2: Banco de Dados (CRUD)
O que faz: Garante a persistência dos dados. Permite cadastrar Sensores e registrar Leituras históricas.

Tecnologia: SQLite. O sistema cria automaticamente o arquivo sensores.db e gerencia duas tabelas relacionais (T_SENSOR e T_LEITURA_SENSOR). Inclui interface visual para inserir, visualizar, atualizar e deletar registros.

### Fase 3: IoT & Gêmeo Digital (Digital Twin)
O que faz: Simula o hardware físico (ESP32) dentro do navegador.

Funcionalidade:

Sliders simulam sensores de Umidade (DHT22) e pH (LDR).

Automação: Se a umidade cair abaixo de 40%, o sistema liga visualmente a "Bomba de Irrigação" no dashboard.

Gráfico em tempo real simulando o "Serial Plotter".

### Fase 4: Machine Learning (Preditivo)
O que faz: Utiliza Inteligência Artificial para decidir se o solo precisa de irrigação, indo além da simples regra "se/então".

Tecnologia: Modelo Scikit-Learn (RandomForest ou similar) treinado com dados históricos.

Integração: O dashboard carrega o arquivo modelo_irrigacao.pkl. O usuário insere a umidade e o modelo classifica a situação como "Irrigar" ou "Aguardar". Possui sistema de fallback (simulação) caso o modelo não seja encontrado.

### Fase 5: Cloud Computing (AWS)
O que faz: Sistema de mensageria para alertas críticos. Conecta a borda (Edge) à Nuvem.

Tecnologia: AWS SNS (Simple Notification Service) via biblioteca boto3.

Fluxo: Quando uma condição crítica é detectada (ex: Umidade < 40% ou Doença na planta), o sistema dispara um e-mail/SMS real para o agrônomo responsável. As credenciais são gerenciadas de forma segura.

### Fase 6: Visão Computacional
O que faz: Monitoramento fitossanitário visual.

Tecnologia: Simulação de uma rede neural YOLO (You Only Look Once).

Funcionalidade: O usuário faz upload de uma foto da folha (ex: Batata). O sistema "analisa" e diagnostica se a planta está Saudável, com Pinta Preta ou Requeima. Se uma doença grave for detectada, o sistema libera o acionamento do alerta via AWS.

## Como Executar o Projeto
### Pré-requisitos
Certifique-se de ter o Python 3.8+ instalado.

### 1. Instalação das Dependências
No terminal, na raiz do projeto, execute:
```
pip install -r requirements.txt
```
O arquivo requirements.txt inclui: streamlit, pandas, numpy, scikit-learn, joblib, boto3.

### 2. Configuração de Credenciais AWS (Segurança)
Para que a Fase 5 funcione, não coloque suas chaves no código! Crie uma pasta .streamlit na raiz e um arquivo secrets.toml dentro dela:

```
AWS_ACCESS_KEY = "SUA_CHAVE_AQUI"
AWS_SECRET_KEY = "SUA_SECRET_AQUI"
SNS_ARN = "arn:aws:sns:us-east-1:SEU_ID:NOME_TOPICO"
```
> Nota: Este arquivo é ignorado pelo Git para sua segurança.

### 3. Executando o Dashboard
Rode o comando:

```
streamlit run app.py
```
O sistema abrirá automaticamente no seu navegador (geralmente em http://localhost:8501).
