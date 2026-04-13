# Sistema em C para Estúdio de Tatuagem

## Descrição do Projeto

Este projeto consiste no desenvolvimento de um sistema em linguagem C para registro e análise de dados de atendimentos em um estúdio de tatuagem.

Os dados são fornecidos por meio de um arquivo CSV e processados pelo sistema, que realiza a leitura, organização e geração de relatórios simples com base nas informações dos atendimentos.

O objetivo é integrar conceitos de programação estruturada em C com uma análise básica de dados aplicada a um cenário real.

---

## Objetivo

Desenvolver um sistema simples capaz de:

- Ler dados de atendimentos a partir de um arquivo CSV
- Armazenar os dados utilizando estruturas (`struct`)
- Processar e analisar informações básicas
- Gerar relatórios no terminal

---

## Funcionalidades

- Leitura de arquivo CSV
- Armazenamento de dados em estruturas
- Listagem de atendimentos
- Cálculo de:
  - Total de atendimentos
  - Faturamento total
  - Média de valores por atendimento

---

## Estrutura dos Dados (CSV)

O arquivo de entrada segue o formato:

```csv
cliente,data,servico,valor
Diego,03/01/2026,Tatuagem,800
Ana,04/01/2026,Fineline,500
João,05/01/2026,Old School,300