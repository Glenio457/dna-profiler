#include <iostream>
#include <fstream>
#include <string>
#include <sstream> 

#include "../include/leitortxt.h"

bool LeitorTXT::lerTXT(const std::string& nomeArquivo) {
    std::ifstream arquivo(nomeArquivo);

    if (!arquivo.is_open()) {
        std::cerr << "Erro ao abrir o arquivo: " << nomeArquivo << std::endl;
        return false;
    }

    std::stringstream buffer;
    buffer << arquivo.rdbuf();
    texto = buffer.str();

    arquivo.close(); 
    return true;
}

const std::string& LeitorTXT::getString() const {
    return texto;
}

void LeitorTXT::imprimirString(std::ostream& os) const {
    os << texto << std::endl;
}