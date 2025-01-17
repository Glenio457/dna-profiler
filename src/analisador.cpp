#include "../include/analisador.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>

std::vector<std::pair<std::string, std::vector<std::string>>> AnalisadorDados::obterMaiorNumeroSequenciasString(const LeitorCSV& leitorCSV, const LeitorTXT& leitorTXT) {
    maiorNumeroSequenciasString.clear();
    const auto& matriz = leitorCSV.getMatriz();
    const std::string& texto = leitorTXT.getString();

    if (matriz.empty() || matriz[0].size() <= 1) {
        std::cerr << "Matriz CSV vazia ou com apenas um elemento na primeira linha." << std::endl;
        return maiorNumeroSequenciasString;
    }

    for (size_t i = 1; i < matriz[0].size(); ++i) {
        std::string termoBusca = matriz[0][i];
        std::vector<std::string> numerosSequencias;
        int maiorSequencia = 0;
        int sequenciaAtual = 0;
        size_t posicao = 0;

        while ((posicao = texto.find(termoBusca, posicao)) != std::string::npos) {
            sequenciaAtual++;
            posicao += termoBusca.length();

            size_t proximaPosicao = texto.find(termoBusca, posicao);
            if (proximaPosicao != std::string::npos && proximaPosicao == posicao) {
                // Continua a sequência
            } else {
                maiorSequencia = std::max(maiorSequencia, sequenciaAtual);
                sequenciaAtual = 0;
            }
        }
        maiorSequencia = std::max(maiorSequencia, sequenciaAtual);
        std::stringstream ss;
        ss << maiorSequencia;
        numerosSequencias.push_back(ss.str());
        maiorNumeroSequenciasString.push_back({termoBusca, numerosSequencias});
    }

    return maiorNumeroSequenciasString;
}

const std::vector<std::pair<std::string, std::vector<std::string>>>& AnalisadorDados::getMaiorNumeroSequenciasString() const{
    return maiorNumeroSequenciasString;
}

void AnalisadorDados::imprimirMaiorNumeroSequenciasString(std::ostream& os) const{
    if (maiorNumeroSequenciasString.empty()) {
        os << "Nenhum termo da primeira linha do CSV (a partir da segunda coluna) foi encontrado no TXT." << std::endl;
    } else {
        os << "\nMaior sequencia consecutiva encontrada:\n";
        for (const auto& par : maiorNumeroSequenciasString) {
            os << "Maior sequencia do termo \"" << par.first << "\": ";
            for(const auto& seq : par.second){
                os << seq << "\n";
            }
        }
    }
}