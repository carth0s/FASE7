# Armazenamento de Dados em Banco SQL com Python

## Objetivo

Esta entrega tem como foco simular o armazenamento dos dados capturados por sensores (como umidade, fósforo e potássio) em um banco de dados relacional, utilizando Python com SQLite. As operações CRUD foram implementadas, e o modelo relacional segue a estrutura definida no MER da Fase 2.


## Contexto e Simulação

Os dados utilizados representam leituras que, em um cenário real, seriam coletadas via monitor serial do ESP32. No entanto, como o circuito está hospedado no [Wokwi](https://wokwi.com/projects/431422752922568705), sem um microcontrolador físico conectado, optou-se por **simular a coleta desses dados diretamente no script Python**, conforme permitido na proposta da entrega.


## Estrutura das Tabelas e Relação com o MER

As tabelas abaixo foram criadas no script `main.py` com base nas entidades definidas no MER (com as correções aplicadas conforme a atividade da fase 2):

### T_SENSOR
| Campo              | Tipo         | Descrição                                      |
|-------------------|--------------|-----------------------------------------------|
| ID_SENSOR         | INTEGER PK   | Identificador único do sensor                 |
| TIPO              | TEXT         | Tipo do sensor (ex: umidade, fósforo, etc.)   |
| STATUS            | TEXT         | Estado atual do sensor (ativo/inativo)        |
| DATA_INSTALACAO   | TIMESTAMP    | Data de instalação do sensor                  |
| ID_PLANTACAO      | INTEGER FK   | Chave estrangeira para a plantação associada  |

### T_LEITURA_SENSOR
| Campo              | Tipo         | Descrição                                      |
|-------------------|--------------|-----------------------------------------------|
| ID_LEITURA        | INTEGER PK   | Identificador da leitura                      |
| DATA_HORA         | TIMESTAMP    | Data e hora da leitura                        |
| VALOR             | DOUBLE       | Valor quantitativo lido pelo sensor           |
| TIPO_MEDICAO      | TEXT         | Tipo da medição (umidade, fósforo, potássio)  |
| ID_SENSOR         | INTEGER FK   | Sensor associado                              |


## Funcionalidades do Script

O arquivo `main.py` contém as seguintes funcionalidades:

- **Inserção de dados simulados**, como se tivessem sido capturados pelo ESP32.
- **Consulta das leituras** por tipo ou por sensor.
- **Atualização de valores** ou tipo de medição.
- **Remoção de registros** de leitura específicos.
- **Criação e reset do banco** SQLite para testes.


## Exemplos de Dados Inseridos

```plaintext
Leitura 1: Umidade - 45.2%
Leitura 2: Fósforo - 18.7 ppm
Leitura 3: Potássio - 27.5 ppm
```

## Exemplo de Uso 

Além das funções CRUD, o código inclui um exemplo prático que demonstra como realizar operações de inserção, leitura, atualização e deleção dos dados.

```plaintext
=== INSERINDO SENSOR BASE ===
Sensor inserido com sucesso!

=== INSERINDO LEITURAS ===
Leitura inserida com sucesso!
Leitura inserida com sucesso!
Leitura inserida com sucesso!

=== LISTANDO LEITURAS INSERIDAS ===
ID    Data/Hora              Valor      Tipo         Sensor ID
------------------------------------------------------------
1     2025-05-20 13:22:32.388501 45.2       umidade      1
2     2025-05-20 13:22:32.392318 18.7       fosforo      1
3     2025-05-20 13:22:32.396405 27.5       potassio     1

=== ATUALIZANDO LEITURA ID 1 PARA VALOR 50.0 ===
Leitura atualizada com sucesso!

=== LISTANDO LEITURAS APÓS ATUALIZAÇÃO ===
ID    Data/Hora              Valor      Tipo         Sensor ID
------------------------------------------------------------
1     2025-05-20 13:22:32.388501 50.0       umidade      1
2     2025-05-20 13:22:32.392318 18.7       fosforo      1
3     2025-05-20 13:22:32.396405 27.5       potassio     1

=== DELETANDO LEITURA ID 2 ===
Leitura deletada com sucesso!

=== LISTANDO LEITURAS FINAIS ===
ID    Data/Hora              Valor      Tipo         Sensor ID
------------------------------------------------------------
1     2025-05-20 13:22:32.388501 50.0       umidade      1
3     2025-05-20 13:22:32.396405 27.5       potassio     1

```

