#ifndef LEITORCSV_H
#define LEITORCSV_H

#include <string> 
#include <vector> 
#include <iostream> 

class LeitorCSV {
private:
    std::vector<std::vector<std::string>> matrizDados;

public:
    LeitorCSV() {}

    LeitorCSV(const std::string& nomeArquivo);

    bool lerCSV(const std::string& nomeArquivo);

    const std::vector<std::vector<std::string>>& getMatriz() const;

    void imprimirMatrizCSV(std::ostream& os = std::cout) const;
};

#endif