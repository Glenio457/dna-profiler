#include <iostream>
#include <vector>
#include <sstream>

#include "../include/comparador.h"

void Comparador::compararEImprimir(const LeitorCSV& leitorCSV, const std::vector<std::pair<std::string, std::vector<std::string>>>& maiorNumeroSequenciasString, std::ostream& os) {
    const auto& matriz = leitorCSV.getMatriz();

    if (matriz.size() <= 1 || maiorNumeroSequenciasString.empty()) {
        os << "Matriz CSV com poucas linhas ou vetor de sequencias vazio." << std::endl;
        return;
    }

    bool encontrouCorrespondencia = false;

    if (maiorNumeroSequenciasString.empty() && !leitorCSV.getMatriz().empty() && !leitorCSV.getMatriz()[0].empty()) {
        std::cout << "Nenhum termo da primeira linha do CSV (a partir da segunda coluna) foi encontrado no TXT." << std::endl;
    } else {

        for (size_t i = 1; i < leitorCSV.getMatriz().size(); ++i) {
            bool linhaCorresponde = true;
            for (size_t j = 0; j < maiorNumeroSequenciasString.size(); ++j) {
                std::string maiorSequenciaStr = maiorNumeroSequenciasString[j].second[0];
                int maiorSequencia;
                std::stringstream ss(maiorSequenciaStr);
                ss >> maiorSequencia;

                if (ss.fail()) {
                    std::cout << "Erro na conversão da string para inteiro para o termo: " << maiorNumeroSequenciasString[j].first << std::endl;
                    linhaCorresponde = false;
                    break;
                }

                std::string valorCSVStr = leitorCSV.getMatriz().at(i).at(j + 1);
                int valorCSV;
                std::stringstream ssCSV(valorCSVStr);
                ssCSV >> valorCSV;

                if (ssCSV.fail()){
                    std::cout << "Erro na conversão da string do csv para inteiro para o termo: " << maiorNumeroSequenciasString.at(j).first << " na linha: " << leitorCSV.getMatriz().at(i).at(0) << std::endl;
                    linhaCorresponde = false;
                    break;
                }

                if (maiorSequencia != valorCSV) {
                    linhaCorresponde = false;
                    break;
                }
            }
            if (linhaCorresponde) {
                std::cout << "Match ID((99.9%): " << leitorCSV.getMatriz()[i][0] << std::endl;
                encontrouCorrespondencia = true;
            }
        }
        if (!encontrouCorrespondencia) {
            std::cout << ">>>Sorry, no match in our database" << std::endl;
        }
    }
}