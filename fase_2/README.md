# Regras de Negócio:

Em cada plantação é possível cultivar diferentes culturas ao longo do tempo, porém apenas uma cultura por vez em determinado período.

Uma cultura pode ser plantada em várias plantações diferentes, em ciclos distintos.

Os sensores realizam medições periódicas e registram leituras com data e hora.

As aplicações de água e nutrientes são registradas com data, tipo e quantidade, associadas a uma plantação específica.

O histórico de plantio (DATA_INICIO e DATA_FIM) é essencial para rastrear os períodos de cultivo de cada cultura em cada plantação.

# MER (Modelo Entidade-Relacionamento):


**T_CULTURA**

ID_CULTURA (INTEGER): Identificador único da cultura (PK)

NOME_CULTURA (VARCHAR(50)): Nome da cultura plantada

TIPO_CULTURA (VARCHAR(20)): Tipo da cultura (ex: grãos, frutas)

ESTACAO_PLANTIO (VARCHAR(30)): Estação do ano em que se planta


**T_PLANTACAO**

ID_PLANTACAO (INTEGER): Identificador único da plantação (PK)

NOME_PLANTACAO (VARCHAR(50)): Nome atribuído à plantação

LOCALIZACAO (VARCHAR(30)): Localização física ou geográfica

TAMANHO_HECTARES (NUMBER): Tamanho da plantação em hectares


**T_PLANTACAO_CULTURA**

ID_PLANTACAO_CULTURA (INTEGER): Identificador da cultura plantada (PK)

DATA_INICIO (TIMESTAMP): Data de início do ciclo da cultura

DATA_FIM (TIMESTAMP): Data de término do ciclo da cultura


**T_SENSOR**

ID_SENSOR (INTEGER): Identificador do sensor (PK)

TIPO (VARCHAR(50)): Tipo do sensor (ex: umidade, pH, temperatura)

STATUS (VARCHAR(50)): Estado do sensor (ativo, inativo)

DATA_INSTALACAO (TIMESTAMP): Data de instalação do sensor

T_PLANTACAO_ID_PLANTACAO (INTEGER): Referência à plantação onde está instalado (FK)


**T_LEITURA_SENSOR**

ID_LEITURA (INTEGER): Identificador da leitura (PK)

DATA_HORA (TIMESTAMP): Data e hora da leitura

VALOR (VARCHAR(20)): Valor capturado pelo sensor

TIPO_NUTRIENTE (VARCHAR(30)): Tipo de nutriente (se aplicável)

T_SENSOR_ID_SENSOR (INTEGER): Sensor associado (FK)


**T_APLICACAO_AGUA**

ID_APLICACAO_AGUA (INTEGER): Identificador da aplicação (PK)

DATA_HORA (TIMESTAMP): Data e hora da irrigação

QUANTIDADE_LITROS (NUMBER): Volume aplicado

T_PLANTACAO_ID_PLANTACAO (INTEGER): Plantação associada (FK)


**T_APLICACAO_NUTRIENTE**

ID_APLICACAO_NUTRIENTE (INTEGER): Identificador da aplicação (PK)

DATA_HORA (TIMESTAMP): Data e hora da aplicação

TIPO_NUTRIENTE (VARCHAR(20)): Tipo do nutriente

QUANTIDADE (NUMBER): Quantidade aplicada

T_PLANTACAO_ID_PLANTACAO (INTEGER): Plantação associada (FK)


# Relacionamentos e Cardinalidades:

Uma plantação possui vários sensores (1:N – T_PLANTACAO → T_SENSOR)

Um sensor gera várias leituras (1:N – T_SENSOR → T_LEITURA_SENSOR)

Uma plantação pode receber várias aplicações de água (1:N – T_PLANTACAO → T_APLICACAO_AGUA)

Uma plantação pode receber várias aplicações de nutrientes (1:N – T_PLANTACAO → T_APLICACAO_NUTRIENTE)

Uma plantação pode registrar diferentes ciclos de culturas (1:N – T_PLANTACAO → T_PLANTACAO_CULTURA)

Uma cultura pode ser plantada em várias plantações ao longo do tempo (1:N – T_CULTURA → T_PLANTACAO_CULTURA)
