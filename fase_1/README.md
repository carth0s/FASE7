# 🌾 Sistema de Gestão Agrícola --- FarmTech 2025

Este projeto reúne dois programas desenvolvidos para apoiar o
gerenciamento agrícola, permitindo calcular consumo de insumos e
organizar informações de culturas, áreas plantadas e aplicações de
fertilizantes ou pesticidas.

O repositório contém: - Um script em **R** focado em cálculos anuais de
consumo e custos. - Um sistema em **Python** com menu interativo para
cadastro e gerenciamento de culturas.

------------------------------------------------------------------------

## 📌 1. Script em R --- Cálculo de Gastos Anuais (`calcular_gastos.R`)

Este programa permite calcular automaticamente:

-   Consumo anual de insumos (fertilizante ou pesticida)\
-   Média anual de litros utilizados\
-   Excedente em relação à média\
-   Custo total\
-   Informações específicas para as culturas **Arroz** ou **Feijão**

### ✔ Como funciona

O usuário informa:

1.  Cultura
    -   A = Arroz\
    -   F = Feijão
2.  Insumo
    -   F = Fertilizante\
    -   P = Pesticida
3.  Valores de consumo (em litros)

O programa ajusta os valores conforme: - Fatores de produção anuais\
- Tempo de ciclo da cultura\
- Preço por litro do insumo

E devolve um relatório com: - Total anual\
- Média\
- Excedentes\
- Custo total estimado

### ▶ Como executar

No R:

``` r
source("calcular_gastos.R")
calcular_gastos()
```

------------------------------------------------------------------------

## 📌 2. Sistema em Python --- Gerenciamento de Culturas (`gestao_agricola.py`)

Sistema interativo em menu de texto, permitindo cadastrar culturas,
calcular áreas e estimar aplicação de insumos.

### ✔ Funcionalidades

#### **1) Selecionar cultura**

Permite escolher entre: - Arroz\
- Feijão

E calcular a área em: - Retângulo\
- Círculo\
- Trapézio

Após isso, o usuário seleciona o insumo: - Fertilizante (500 mL por m²)\
- Pesticida (250 mL por m²)

O sistema calcula automaticamente: - Aplicação total\
- Volume em litros

------------------------------------------------------------------------

#### **2) Exibir culturas adicionadas**

Mostra uma lista com: - Cultura cadastrada\
- Área (m²)\
- Insumo aplicado\
- Quantidade estimada (litros)

------------------------------------------------------------------------

#### **3) Atualizar informações**

Permite alterar: - Área total (com novo formato)\
- Insumo utilizado

E recalcula automaticamente a aplicação necessária.

------------------------------------------------------------------------

#### **4) Excluir dados**

Remove uma cultura cadastrada.

------------------------------------------------------------------------

#### **5) Sair do programa**

Finaliza a execução.

------------------------------------------------------------------------

### ▶ Como executar

No terminal:

``` bash
python gestao_agricola.py
```

------------------------------------------------------------------------

## 🧩 Tecnologias utilizadas

-   **R (base)**\
-   **Python 3 (math library)**

------------------------------------------------------------------------

## 📘 Objetivo do projeto

Este mini-sistema foi desenvolvido como parte de um estudo sobre: -
Gerenciamento agrícola - Processamento de dados - Estruturação de
sistemas simples - Comparação entre lógica aplicada em R e Python
