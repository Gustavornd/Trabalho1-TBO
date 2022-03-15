#pragma once
#ifndef NODO_H
#define NODO_H

#include <iostream>


using namespace std;

/*
* Essa classe tem como fun��o guardar um objeto da classe int,
* para que seja inserido como membro de uma lista encadeada.
*/
class Nodo {
public:

	/*
	* Construtor gen�rico da classe Nodo. Ao ser convocado, inicializa
	* os atributos da classe.
	*/
	Nodo();

	/*
	* Construtor da classe Nodo. Ao ser convocado, faz a inser��o dos
	* seus atributos nas vari�veis da classe.
	* 
	* @param newData		Inteiro que deve ser guardado por esse nodo.
	*/
	Nodo(const int& newData);

	/*
	* Destrutor da classe Nodo (n�o implementado).
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

