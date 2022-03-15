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
* Esta classe tem como função implementar uma lista encadeada
* assim como as funções para manipulação dessa lista.
*/
class ListaEncadeada {
public:

	/*
	* Construtor da classe ListaEncadeada. Ao ser convocado,
	* inicializa os atributos da classe.
	*/
	ListaEncadeada();

	/*
	* Função que inicializa uma lista com dados lidos em aquivo
	*
	* @param file_name		String que reprenta o nome do arquivo que deve ser aberto.
	*/
	ListaEncadeada(string file_name);

	/*
	* Função que inicializa uma lista com dados aleatórios, com o
	* tamanho definido;
	*
	* @param tam		Número de elementos da lista (tamanho) que deve ser gerada
	*/
	ListaEncadeada(unsigned tamanho);

	/*
	* Destrutor da classe ListaEncadeada. Ao ser convocado,
	* desfaz a alocação de memória e apaga cada membro da lista.
	*/
	~ListaEncadeada();

	/*
	* Faz a impressão dos dados da lista na tela.
	*/
	void Print() const;

	/*
	* Declaração da função Insere que faz a inserção de novos membros 
	* na lista.
	* 
	* @param posicao			Posição onde o novo membro deve ser inserido.
	* @param novoNodoPtr		Ponteiro para o nodo que deve ser inserido.
	*/
	void Insere(unsigned posicao, Nodo* novoNodoPtr);
	
	/*
	* Declaração da função Busca, que faz uma busca por um nodo na 
	* lista à partir de sua chave.
	* 
	* @param data		Chave do nodo que deve ser procurado na lista.
	*/
	Nodo* Busca(int data) const;

	/*
	* Declaração da função Busca o menor valor da lista e retorna
	* sua posição.
	*/
	Nodo* BuscarMenor();

	/*
	* Função que retorna um indice para a posição de um nodo na lista
	* 
	* @param nodo		Nodo que será retornada a posição como um indice int
	*/
	unsigned IndiceNodo(Nodo* nodo);

	/*
	* Função que retorna um nodo com base no indice informado
	* pela função anterior ou pelo usuário.
	* 
	* @param posicao		Posição do nodo que deve ser retornado;
	*/
	Nodo* AtNodo(int posicao);

	/*
	* Função que realiza a troca de posição de dois nodos na lista encadeada;
	* 
	* @param nodoA		Posição do primeiro nodo;
	* @param nodoB		Posição do segundo nodo;
	*/
	void Swap(Nodo* nodoA, Nodo* nodoB);


	/*
	* Atributos da classe ListaEncadeada.
	*/
	Nodo* inicio;
	int tamanho;
};

/*
* Função que realiza a impressão dos elementos da lista
* em ordem inversa, por meio de recursão;
*/
void PrintInverso(Nodo*& start);


#endif // !LISTA_ENCADEADA_H
