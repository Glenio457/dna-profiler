#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <unistd.h> 

#include "../include/leitorcsv.h"
#include "../include/leitortxt.h"
#include "../include/analisador.h"
#include "../include/comparador.h"
#include "../include/cabeçalho.h"

using namespace std;

int main(int argc, char *argv[]) {
    string nomeArquivoCSV;
    string nomeArquivoTXT;

    int opt;
    while ((opt = getopt(argc, argv, "d:s:")) != -1) {
        switch (opt) {
            case 'd':
                nomeArquivoCSV = optarg;
                break;
            case 's':
                nomeArquivoTXT = optarg;
                break;
            default:
                cerr << "Uso: " << argv[0] << " -d <arquivo csv> -s <arquivo txt>" << endl;
                return 1;
        }
    }

    if (nomeArquivoCSV.empty() || nomeArquivoTXT.empty()) {
        cerr << "Uso: " << argv[0] << " -d <arquivo csv> -s <arquivo txt>" << endl;
        return 1;
    }

    printcabeçalho(nomeArquivoCSV, nomeArquivoTXT);

    LeitorCSV leitorCSV;
    if (!leitorCSV.lerCSV(nomeArquivoCSV)) {
        cerr << "Falha ao ler o arquivo CSV." << endl;
        return 1;
    }

    LeitorTXT leitorTXT;
    if (!leitorTXT.lerTXT(nomeArquivoTXT)) {
        cerr << "Falha ao ler o arquivo TXT." << endl;
        return 1;
    }

    AnalisadorDados analisador;
    analisador.obterMaiorNumeroSequenciasString(leitorCSV, leitorTXT);
    const auto& maiorNumeroSequenciasString = analisador.getMaiorNumeroSequenciasString();

    Comparador comparador;

    comparador.compararEImprimir(leitorCSV, maiorNumeroSequenciasString);

    return 0;
}