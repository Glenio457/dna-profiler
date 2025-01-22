#ifndef ANALISADOR_H
#define ANALISADOR_H

#include <string>
#include <vector>
#include <utility>
#include <iostream>

#include "leitorcsv.h"
#include "leitortxt.h"

class AnalisadorDados {
private:
    std::vector<std::pair<std::string, std::vector<std::string>>> maiorNumeroSequenciasString;

public:
    AnalisadorDados() {}
    std::vector<std::pair<std::string, std::vector<std::string>>> obterMaiorNumeroSequenciasString(const LeitorCSV& leitorCSV, const LeitorTXT& leitorTXT);
    
    const std::vector<std::pair<std::string, std::vector<std::string>>>& getMaiorNumeroSequenciasString() const;
    
    void imprimirMaiorNumeroSequenciasString(std::ostream& os = std::cout) const;
};

#endif