
<img src="../assets/logo-fiap.png" alt="FIAP - Faculdade de Informática e Admnistração Paulista" border="0" width=30% height=30%>

# FARMTECH SOLUTIONS - FASE 4 - FIAP

## Sumário

[1. Introdução](#c1)

[2. Visão Geral do Projeto](#c2)

[3. Desenvolvimento do Projeto](#c3)

[4. Resultados e Avaliações](#c4)

[5. Conclusões e Trabalhos Futuros](#c5)

[6. Referências](#c6)

<br>

# <a name="c1"></a>1. Introdução

## 1.1. Escopo do Projeto

### 1.1.1. Contexto da Inteligência Artificial

A Inteligência Artificial tem desempenhado um papel cada vez mais relevante no agronegócio, otimizando a coleta de dados e a tomada de decisões automatizadas. Suas aplicações se estendem a nível nacional e internacional, influenciando diretamente a produtividade, a eficiência no uso de recursos e a sustentabilidade.

### 1.1.2. Descrição da Solução Desenvolvida

Este projeto propõe um sistema completo de monitoramento agrícola composto por três módulos: um sistema embarcado com ESP32, um modelo de Machine Learning para prever a necessidade de irrigação e um script Python com banco de dados SQLite. Juntos, esses elementos criam uma solução robusta e acessível para pequenas e médias propriedades rurais.

# <a name="c2"></a>2. Visão Geral do Projeto

## 2.1. Objetivos do Projeto

- Monitorar as condições do solo (umidade, pH, fósforo e potássio) em tempo real
- Prever automaticamente a necessidade de irrigação
- Armazenar histórico de leituras para análise e relatórios

## 2.2. Público-Alvo

Produtores rurais, estudantes de IoT/IA, pesquisadores e desenvolvedores interessados em soluções agrícolas acessíveis e inteligentes.

## 2.3. Metodologia

O projeto foi dividido em três módulos principais:

- Desenvolvimento de sistema embarcado com ESP32 no simulador Wokwi
- Treinamento de modelo preditivo com Scikit-learn e visualização com Streamlit
- Desenvolvimento de banco de dados com SQLite e operações CRUD

# <a name="c3"></a>3. Desenvolvimento do Projeto

## 3.1. Tecnologias Utilizadas

- C++ (ESP32)
- Python (Scikit-learn, Streamlit, SQLite)
- Wokwi (simulador ESP32)
- Visual Studio Code / Jupyter Notebook

## 3.2. Modelagem e Algoritmos

Utilizou-se um classificador binário simples (DecisionTreeClassifier) treinado com dados simulados de umidade. O objetivo é classificar se o solo precisa de irrigação (Sim/Não).

## 3.3. Treinamento e Teste

O modelo foi treinado com 100 amostras artificiais. A divisão treino/teste foi feita com 80/20. A acurácia superou 90% nas previsões. A interface Streamlit permite testar manualmente a previsão com valores inseridos pelo usuário.

# <a name="c4"></a>4. Resultados e Avaliações

## 4.1. Análise dos Resultados

- A previsão de irrigação foi consistente com a lógica do ESP32 (umidade < 40%).
- O Serial Plotter apresentou corretamente a evolução das leituras.
- O banco de dados armazenou e permitiu editar registros com sucesso.

## 4.2. Feedback dos Usuários

Como se trata de um projeto acadêmico, o feedback foi interno entre os membros do grupo e tutor. A abordagem modular foi elogiada pela clareza e divisão funcional.

# <a name="c5"></a>5. Conclusões e Trabalhos Futuros

O projeto FarmTech Solutions - Fase 4 atingiu os objetivos propostos ao integrar sensores simulados, um modelo preditivo funcional e uma estrutura de armazenamento de dados. O uso de tecnologias acessíveis como Streamlit, SQLite e Wokwi permite replicabilidade e expansão futura.

Possíveis trabalhos futuros:

- Utilização de dados reais capturados por sensores físicos
- Treinamento com dados multivariados (pH, fósforo, potássio)
- Integração com dashboard online e notificações automatizadas

# <a name="c6"></a>6. Referências

- Documentação oficial do Streamlit: https://docs.streamlit.io/
- Scikit-learn Documentation: https://scikit-learn.org/stable/
- SQLite Python Docs: https://docs.python.org/3/library/sqlite3.html
- Simulador Wokwi: https://wokwi.com/
