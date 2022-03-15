#pragma once
#ifndef LISTA_ENCADEADA_H
#define LISTA_ENCADEADA_H

#include "nodo.h"
#include <fstream>
#include <string>
#include <cstdlib>
#define TAM_LINHA 5000

using namespace std;

/*
* Esta classe tem como fun��o implementar uma lista encadeada
* assim como as fun��es para manipula��o dessa lista.
*/
class ListaEncadeada {
public:

	/*
	* Construtor da classe ListaEncadeada. Ao ser convocado,
	* inicializa os atributos da classe.
	*/
	ListaEncadeada();

	/*
	* Fun��o que inicializa uma lista com dados lidos em aquivo
	*
	* @param file_name		String que reprenta o nome do arquivo que deve ser aberto.
	*/
	ListaEncadeada(string file_name);

	/*
	* Fun��o que inicializa uma lista com dados aleat�rios, com o
	* tamanho definido;
	*
	* @param tam		N�mero de elementos da lista (tamanho) que deve ser gerada
	*/
	ListaEncadeada(unsigned tamanho);

	/*
	* Destrutor da classe ListaEncadeada. Ao ser convocado,
	* desfaz a aloca��o de mem�ria e apaga cada membro da lista.
	*/
	~ListaEncadeada();

	/*
	* Faz a impress�o dos dados da lista na tela.
	*/
	void Print() const;

	/*
	* Declara��o da fun��o Insere que faz a inser��o de novos membros 
	* na lista.
	* 
	* @param posicao			Posi��o onde o novo membro deve ser inserido.
	* @param novoNodoPtr		Ponteiro para o nodo que deve ser inserido.
	*/
	void Insere(unsigned posicao, Nodo* novoNodoPtr);
	
	/*
	* Declara��o da fun��o Busca, que faz uma busca por um nodo na 
	* lista � partir de sua chave.
	* 
	* @param data		Chave do nodo que deve ser procurado na lista.
	*/
	Nodo* Busca(int data) const;

	/*
	* Declara��o da fun��o Busca o menor valor da lista e retorna
	* sua posi��o.
	*/
	Nodo* BuscarMenor();

	/*
	* Fun��o que retorna um indice para a posi��o de um nodo na lista
	* 
	* @param nodo		Nodo que ser� retornada a posi��o como um indice int
	*/
	unsigned IndiceNodo(Nodo* nodo);

	/*
	* Fun��o que retorna um nodo com base no indice informado
	* pela fun��o anterior ou pelo usu�rio.
	* 
	* @param posicao		Posi��o do nodo que deve ser retornado;
	*/
	Nodo* AtNodo(int posicao);

	/*
	* Fun��o que realiza a troca de posi��o de dois nodos na lista encadeada;
	* 
	* @param nodoA		Posi��o do primeiro nodo;
	* @param nodoB		Posi��o do segundo nodo;
	*/
	void Swap(Nodo* nodoA, Nodo* nodoB);


	/*
	* Atributos da classe ListaEncadeada.
	*/
	Nodo* inicio;
	int tamanho;
};

/*
* Fun��o que realiza a impress�o dos elementos da lista
* em ordem inversa, por meio de recurs�o;
*/
void PrintInverso(Nodo*& start);


#endif // !LISTA_ENCADEADA_H
