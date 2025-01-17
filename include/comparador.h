#ifndef COMPARADOR_H
#define COMPARADOR_H

#include <string>
#include <vector> 
#include <utility> 
#include <iostream> 
#include "leitorcsv.h" 

class Comparador {
public:
    Comparador() {}

    void compararEImprimir(const LeitorCSV& leitorCSV, const std::vector<std::pair<std::string, std::vector<std::string>>>& maiorNumeroSequenciasString, std::ostream& os = std::cout);
};

#endif