#pragma once
#ifndef NODO_H
#define NODO_H

#include <iostream>


using namespace std;

/*
* Essa classe tem como função guardar um objeto da classe int,
* para que seja inserido como membro de uma lista encadeada.
*/
class Nodo {
public:

	/*
	* Construtor genérico da classe Nodo. Ao ser convocado, inicializa
	* os atributos da classe.
	*/
	Nodo();

	/*
	* Construtor da classe Nodo. Ao ser convocado, faz a inserção dos
	* seus atributos nas variáveis da classe.
	* 
	* @param newData		Inteiro que deve ser guardado por esse nodo.
	*/
	Nodo(const int& newData);

	/*
	* Destrutor da classe Nodo (não implementado).
	*/
	~Nodo();

	void Print();

	/*
	* Atributos da classe Nodo.
	*/
	Nodo* prox;
	Nodo* ant;
	int data;
};



#endif // !NODO_H

