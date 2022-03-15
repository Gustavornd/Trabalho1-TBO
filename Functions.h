#pragma once
#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include "nodo.h"
#include "ListaEstatica.h"
#include "ListaEncadeada.h"


using namespace std;

/*
* Função usada para criar o arquivo de entrada de dados;
*/
void CreateInputFile();

/*
* Função usada para criar um aquivo de entrada com dados
* aleatórios, mas não foi utilizado;
*/
void CreateRandomInputFile();

#endif // !FUNCTIONS_H

