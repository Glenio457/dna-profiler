# 🧬 DNA Profiler

O **DNA Profiler** é um programa em **C++** para análise de similaridade entre sequências de DNA.  
Ele lê duas sequências em formato de texto, compara posição por posição e retorna a porcentagem de similaridade entre elas.

---

## ⚙️ Como funciona

1. O programa recebe **dois arquivos de texto** como entrada.  
   - Cada arquivo deve conter uma sequência de DNA (usando apenas as bases `A`, `T`, `C`, `G`).  
   - Exemplo (`dna1.txt`):  
     ```
     ATGCGTAC
     ```  
     Exemplo (`dna2.txt`):  
     ```
     ATGCCGAC
     ```

2. O algoritmo percorre as duas sequências **caractere por caractere**, contando:  
   - Quantas bases são **iguais na mesma posição**.  
   - O tamanho total da comparação (considera o comprimento da menor sequência).

3. A similaridade é calculada pela fórmula:

