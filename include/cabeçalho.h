#ifndef CABECALHO_H
#define CABECALHO_H

#include <iostream>

const std::string BLUE = "\033[0;34m";
const std::string RED = "\033[0;31m";
const std::string RESET = "\033[0m";

void printcabeçalho(std::string csv, std::string txt){
    std::cout << "===================================================" << std::endl;
    std::cout << "      Welcome to the Basic DNA profiler, v1.0" << std::endl << "Copiright (C) 2025, Glênio Queiroz & Matheus Guedes" << std::endl;
    std::cout << "===================================================" << std::endl;
    std::cout << std::endl << std::endl;


    std::cout << BLUE << "This program loads a DNA database and an unknown" << std::endl << "DNA sequence and tries to find a  match between" << std::endl << "the input DNA sequence and the DNA database." << RESET << std::endl;

    std::cout << std::endl << "[+] Preparing to read the DNA database file: [" << RED << csv << RESET << "]" << std::endl;
    std::cout << std::endl << "[+] Preparing to read the unknown DNA sequence file: [" << RED << txt << RESET << "]" << std::endl;
    std::cout << "[+] Processing data, please wait." << std::endl << std::endl;
    std::cout << "[+] Input file sucessfully read." << std::endl;
    std::cout << "[+] Searching the database for a match... please wait." << std::endl << std::endl << std::endl; 
}

#endif