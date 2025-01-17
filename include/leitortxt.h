#ifndef LEITORTXT_H
#define LEITORTXT_H

#include <string>
#include <fstream>
#include <iostream>

class LeitorTXT {
    private:
        std::string texto; 

    public:
        LeitorTXT() {}
    
        bool lerTXT(const std::string& nomeArquivo);
    
        const std::string& getString() const;
    
        void imprimirString(std::ostream& os = std::cout) const;
};

#endif