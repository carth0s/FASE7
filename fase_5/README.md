# Fase 5 
## 1. Objetivo da Fase 5 

Esta fase tem como objetivo demonstrar a implantação de recursos de Cloud Computing na AWS, aplicando boas práticas de segurança e garantindo que o sistema agrícola tenha disponibilidade, escalabilidade e proteção de dados.
Além disso, foi implementado um sistema de alertas automáticos via e-mail usando AWS SNS integrado ao código Python.

## 2. Arquitetura Implementada
### 2.1 AWS SNS (Simple Notification Service)

Foi criado um tópico SNS chamado AlertasFarmtech, responsável por enviar notificações quando as condições ambientais monitoradas atingem níveis críticos.

O código Python usa boto3 para publicar mensagens nesse tópico automaticamente.

### 2.2 Estrutura do Projeto (Fase 5)
```
fase_5/
│── sns_alerta.py        # Função que envia alertas SNS
│── envio_alerta.py      # Simulação de leitura de sensores
│── teste_manual.py      # Teste manual da funcionalidade
```
## 3. Código implementado
### 3.1 sns_alerta.py
```
import boto3
import json

def enviar_alerta(mensagem):
    with open("aws_credentials.json") as f:
        cred = json.load(f)

    sns = boto3.client(
        "sns",
        aws_access_key_id=cred["AWS_ACCESS_KEY"],
        aws_secret_access_key=cred["AWS_SECRET_KEY"],
        region_name="us-east-1"
    )

    sns.publish(
        TopicArn=cred["SNS_ARN"],
        Message=mensagem,
        Subject="Alerta Automático – FarmTech"
    )

    print("[AWS SNS] Alerta enviado:", mensagem)
```
### 3.2 envio_alerta.py
```
from sns_alerta import enviar_alerta

def monitorar_umidade(valor):
    print(f"Umidade atual: {valor}%")

    if valor < 40:
        enviar_alerta(f"Umidade muito baixa: {valor}%. Acionar irrigação!")
```
### 3.3 teste_manual.py
```
from envio_alerta import monitorar_umidade

monitorar_umidade(35)
```

> As credenciais foram removidas do código-fonte e armazenadas em um arquivo aws_credentials.json, que não é enviado ao GitHub, seguindo as boas práticas de segurança da ISO 27001.

## 4. Segurança – Aplicação das Normas ISO 27001 / ISO 27002

A Fase 5 exige explicar como padrões de segurança são aplicados. Aqui está um texto perfeito para o relatório:

### 4.1 Conformidade ISO 27001

A ISO 27001 define padrões para implementação de um Sistema de Gestão de Segurança da Informação (SGSI).
Nesta fase, os seguintes princípios foram adotados:

✔ Controle de Acesso (A.9)

As credenciais da AWS são utilizadas apenas no ambiente de desenvolvimento e não são expostas no código final ou no repositório.
Em um sistema real, seria utilizado AWS IAM Roles, evitando exposição de chaves.

### 4.2 Conformidade ISO 27002

A ISO 27002 detalha controles específicos. Os principais aplicados foram:

✔ A.10 – Criptografia

A comunicação com a AWS é realizada via HTTPS/TLS, garantindo que dados enviados aos serviços (SNS) são transmitidos com segurança.

✔ A.12 – Operações Seguras

O monitoramento automático minimiza falhas humanas e melhora a segurança operacional, enviando alertas imediatamente quando sensores detectam valores críticos.

✔ A.17 – Continuidade de Negócio

O uso da nuvem aumenta a resiliência do sistema:
mesmo que um servidor local falhe, os serviços AWS continuam funcionando.

## 5. Escalabilidade, Disponibilidade e Benefícios da AWS

Seu relatório precisa ter isso. Aqui está um texto pronto:

### 5.1 Alta Disponibilidade

O serviço SNS é totalmente gerenciado pela AWS, garantindo:

funcionamento 24/7

redundância automática

replicação em múltiplas zonas de disponibilidade (AZs)

Isso significa que o alerta será enviado mesmo se algum servidor da AWS cair.

### 5.2 Escalabilidade Automática

SNS suporta milhares de mensagens por segundo sem necessidade de configuração adicional.
Ou seja:

se a fazenda tiver 10 sensores → funciona

se tiver 10.000 sensores → também funciona

sem alterar o código.

### 5.3 Segurança

A AWS fornece:

IAM para controle de permissões

Logs em CloudWatch (se ativado)

Criptografia em trânsito (TLS)

### 5.4 Simplicidade na integração

A integração Python + SNS permite que qualquer outra fase (sensores, visão computacional, banco de dados) dispare alertas facilmente.

## 6. Conclusão

A fase 5 possui:

- Integração em nuvem usando AWS SNS
- Código Python funcional enviando alertas
- Documentação de segurança com ISO 27001/27002
- Explicação de escalabilidade e disponibilidade
- Construção da parte Cloud Computing do sistema
