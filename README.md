# 🧬 DNA Profiler

O **DNA Profiler** é um programa em **C++** para análise de similaridade entre sequências de DNA.  
Ele lê duas sequências em formato de texto, compara posição por posição e retorna a porcentagem de similaridade entre elas.

---

## ⚙️ Como funciona

 O código recebe duas entradas, uma sendo um banco de dados CSV e outra sendo um arquivo txt, e a partir disso, ele verifica se a "amostra de dna" apresenta correspondência com uma pessoa no banco de dados ou não.

## Execução:

para executar o código você deve fazer o comando: ./dna_profiler -d [x] -s [y]

x = arquivo csv do banco de dados a ser utilizado.
y = amostra de dna a ser utilizada.

Exemplo: ./dna_profiler -d data/data.csv -s data/sequence_alice.txt
