calcular_gastos <- function(){
  
  cultura <- readline("Escolha a cultura (A - Arroz, F - Feijão): ")
  cultura <- toupper(cultura)
  
  if (cultura != "A" && cultura != "F") {
    stop("Opção inválida! Escolha A para Arroz ou F para Feijão.")
  }
  
  insumo <- readline("Escolha o insumo (F - Fertilizante, P - Pesticida): ")
  insumo <- toupper(insumo)
  
  if (insumo != "F" && insumo != "P") {
    stop("Opção inválida! Escolha F para Fertilizante ou P para Pesticida.")
  }
  
  if (cultura == "A") {
    fator <- 2.607142857142857
    ciclo <- 140
    nome_cultura <- "Arroz"
  } else {
    fator <- 4.5625
    ciclo <- 80
    nome_cultura <- "Feijão"
  }
  
  if (insumo == "F") {
    custo_litro <- 47
    nome_insumo <- "Fertilizante"
  } else {
    custo_litro <- 389
    nome_insumo <- "Pesticida"
  }
  
  litros <- as.numeric(unlist(strsplit(readline("Digite os valores de consumo de litros: "), " ")))
  
  if (any(is.na(litros))) {
    stop("Entrada inválida! Certifique-se de inserir apenas números.")
  }
  
  litros_anuais <- litros * fator
  media <- floor(mean(litros_anuais))
  excedente <- sum(litros_anuais - media)
  gasto_total <- sum(litros_anuais) * custo_litro
  
  cat("\nResultados:\n")
  cat("Cultura:", nome_cultura, "\n")
  cat("Ciclo de plantio:", ciclo, "dias\n")
  cat("Insumo utilizado:", nome_insumo, "\n")
  cat("Total de litros por ano:", litros_anuais, "\n")
  cat("Média anual de litros:", media, "(Custo por litro: R$", custo_litro, ")\n")
  cat("Desvio (excedente em litros além da média):", excedente, "litros\n")
  cat("Gasto total em reais (R$):", gasto_total, "\n")
}

calcular_gastos()
