#include "../include/leitorcsv.h"
#include <iostream>
#include <fstream>
#include <sstream>

LeitorCSV::LeitorCSV(const std::string& nomeArquivo) {
    lerCSV(nomeArquivo);
}

bool LeitorCSV::lerCSV(const std::string& nomeArquivo) {
    std::ifstream arquivo(nomeArquivo);

    if (!arquivo.is_open()) {
        std::cerr << "Erro ao abrir o arquivo: " << nomeArquivo << std::endl;
        return false;
    }

    matrizDados.clear();

    std::string linha;

    while (std::getline(arquivo, linha)) {
        std::vector<std::string> linhaDados;
        std::stringstream linhaStream(linha);
        std::string celula;

        while (std::getline(linhaStream, celula, ',')) {
            linhaDados.push_back(celula);
        }
        matrizDados.push_back(linhaDados);
    }

    arquivo.close();
    return true;
}

const std::vector<std::vector<std::string>>& LeitorCSV::getMatriz() const {
    return matrizDados;
}

void LeitorCSV::imprimirMatrizCSV(std::ostream& os) const {
    if (matrizDados.empty()) {
        os << "O arquivo CSV está vazio ou contém apenas cabeçalho." << std::endl;
        return;
    }

    for (size_t i = 0; i < matrizDados.size(); ++i) {
        for (size_t j = 0; j < matrizDados[i].size(); ++j) {
            os << matrizDados[i][j];
            if (j < matrizDados[i].size() - 1) {
                os << ",";
            }
        }
        os << std::endl;
    }
}