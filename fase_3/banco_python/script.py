import sqlite3
from datetime import datetime

# Conexão com o banco de dados (será criado se não existir)
conn = sqlite3.connect("sensores.db")
cursor = conn.cursor()

# Criação da tabela T_SENSOR (caso não exista)
cursor.execute('''
CREATE TABLE IF NOT EXISTS T_SENSOR (
    ID_SENSOR INTEGER PRIMARY KEY AUTOINCREMENT,
    TIPO TEXT NOT NULL,
    STATUS TEXT,
    DATA_INSTALACAO TIMESTAMP,
    ID_PLANTACAO INTEGER
)
''')

# Criação da tabela T_LEITURA_SENSOR (caso não exista)
cursor.execute('''
CREATE TABLE IF NOT EXISTS T_LEITURA_SENSOR (
    ID_LEITURA INTEGER PRIMARY KEY AUTOINCREMENT,
    DATA_HORA TIMESTAMP,
    VALOR DOUBLE,
    TIPO_MEDICAO TEXT,
    ID_SENSOR INTEGER,
    FOREIGN KEY(ID_SENSOR) REFERENCES T_SENSOR(ID_SENSOR)
)
''')

conn.commit()

# FUNÇÕES CRUD
# Função para inserir um sensor (usada como base para leituras)
def inserir_sensor(tipo, status, data_instalacao, id_plantacao):
    cursor.execute('''
        INSERT INTO T_SENSOR (TIPO, STATUS, DATA_INSTALACAO, ID_PLANTACAO)
        VALUES (?, ?, ?, ?)
    ''', (tipo, status, data_instalacao, id_plantacao))
    conn.commit()
    print("Sensor inserido com sucesso!")

# CREATE:
def inserir_leitura(valor, tipo_medicao, id_sensor):
    agora = datetime.now()
    cursor.execute('''
        INSERT INTO T_LEITURA_SENSOR (DATA_HORA, VALOR, TIPO_MEDICAO, ID_SENSOR)
        VALUES (?, ?, ?, ?)
    ''', (agora, valor, tipo_medicao, id_sensor))
    conn.commit()
    print("Leitura inserida com sucesso!")

# READ:
def listar_leituras():
    cursor.execute("SELECT ID_LEITURA, DATA_HORA, VALOR, TIPO_MEDICAO, ID_SENSOR FROM T_LEITURA_SENSOR")
    leituras = cursor.fetchall()
    if not leituras:
        print("Nenhuma leitura encontrada.")
        return
    print(f"{'ID':<5} {'Data/Hora':<22} {'Valor':<10} {'Tipo':<12} {'Sensor ID'}")
    print("-" * 60)
    for leitura in leituras:
        print(f"{leitura[0]:<5} {leitura[1]:<22} {leitura[2]:<10} {leitura[3]:<12} {leitura[4]}")

# UPDATE:
def atualizar_leitura(id_leitura, novo_valor):
    cursor.execute('''
        UPDATE T_LEITURA_SENSOR
        SET VALOR = ?
        WHERE ID_LEITURA = ?
    ''', (novo_valor, id_leitura))
    conn.commit()
    print("Leitura atualizada com sucesso!")

# DELETE:
def deletar_leitura(id_leitura):
    cursor.execute('''
        DELETE FROM T_LEITURA_SENSOR
        WHERE ID_LEITURA = ?
    ''', (id_leitura,))
    conn.commit()
    print("Leitura deletada com sucesso!")

# EXEMPLO DE USO
def exemplo_de_uso():
    print("=== INSERINDO SENSOR BASE ===")
    inserir_sensor("solo", "ativo", datetime.now(), 101)

    print("\n=== INSERINDO LEITURAS ===")
    inserir_leitura(45.2, "umidade", 1)
    inserir_leitura(18.7, "fosforo", 1)
    inserir_leitura(27.5, "potassio", 1)

    print("\n=== LISTANDO LEITURAS INSERIDAS ===")
    listar_leituras()

    print("\n=== ATUALIZANDO LEITURA ID 1 PARA VALOR 50.0 ===")
    atualizar_leitura(1, 50.0)

    print("\n=== LISTANDO LEITURAS APÓS ATUALIZAÇÃO ===")
    listar_leituras()

    print("\n=== DELETANDO LEITURA ID 2 ===")
    deletar_leitura(2)

    print("\n=== LISTANDO LEITURAS FINAIS ===")
    listar_leituras()

# EXECUÇÃO DO EXEMPLO
exemplo_de_uso()

# Fechando conexão no final
conn.close()
