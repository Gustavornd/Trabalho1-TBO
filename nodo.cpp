#pragma warning(disable:26495)
#include "nodo.h"



/*
* Construtor genérico da classe Nodo. Ao ser convocado, inicializa
* os atributos da classe.
*/
Nodo::Nodo() {

	prox = NULL;
	ant = NULL;
	data = 0;
}


/*
* Construtor da classe Nodo. Ao ser convocado, faz a inserção dos
* seus atributos nas variáveis da classe.
*
* @param newData		Inteiro que deve ser guardado por esse nodo.
*/
Nodo::Nodo(const int& newData) {
	prox = NULL;
	ant = NULL;
	data = newData;
}


/*
* Destrutor da classe Nodo (não implementado).
*/
Nodo::~Nodo() {}

void Nodo::Print() {
	cout << data << " ";
}
