#pragma warning(disable:4996)
#pragma warning(disable:4244)
#pragma warning(disable:6011)
#include "ListaEncadeada.h"


/*
* Construtor da classe ListaEncadeada. Ao ser convocado,
* inicializa os atributos da classe.
*/
ListaEncadeada::ListaEncadeada() { 
	inicio = new Nodo;
	inicio = NULL;
	tamanho = 0;
}

/*
* Fun��o que inicializa uma lista com dados lidos em aquivo
*
* @param file_name		String que reprenta o nome do arquivo que deve ser aberto.
*/
ListaEncadeada::ListaEncadeada(string file_name) {
	int tam, newData;
	Nodo* newDataNodo;

	fstream input;
	input.open(file_name, ios::in);

	if (!input)
		abort();

	char linha[TAM_LINHA + 1];
	input.getline(linha, TAM_LINHA);
	tam = atoi(strtok(linha, "endl"));

	input.getline(linha, TAM_LINHA);
	newData = atoi(strtok(linha, " "));
	for (int i = 0; i < tam; i++) {
		if (i == 0) {
			newDataNodo = new Nodo(newData);
			Insere(i, newDataNodo);
			continue;
		}

		newData = atoi(strtok(NULL, " "));
		newDataNodo = new Nodo(newData);
		Insere(i, newDataNodo);

	}

	input.close();

}

/*
* Fun��o que inicializa uma lista com dados aleat�rios, com o
* tamanho definido;
*
* @param tam		N�mero de elementos da lista (tamanho) que deve ser gerada
*/
ListaEncadeada::ListaEncadeada(unsigned tam){
	int seed = 107140;
	Nodo* newDataNodo;
	cout << "Semente de gera��o da lista: " << seed << endl;
	srand(seed);

	for (unsigned i = 0; i < tam; i++) {
		int newData = 1 + rand() % 1000;
		newDataNodo = new Nodo(newData);
		Insere(i, newDataNodo);
	}
}

/*
* Destrutor da classe ListaEncadeada. Ao ser convocado,
* desfaz a aloca��o de mem�ria e apaga cada membro da lista.
*/
ListaEncadeada::~ListaEncadeada() {
	Nodo* prox;
	while (inicio) {
		prox = inicio->prox;
		delete inicio;
		inicio = prox;
	}
}


/*
* Faz a impress�o dos dados da lista na tela.
*/
void ListaEncadeada::Print() const {
	Nodo* NodoPtr = inicio;

	while(NodoPtr){
		NodoPtr->Print();
		NodoPtr = NodoPtr->prox;
	}
	cout << endl;
}


/*
* Declara��o da fun��o Insere que faz a inser��o de novos membros
* na lista.
*
* @param posicao			Posi��o onde o novo membro deve ser inserido.
* @param novoNodoPtr		Ponteiro para o nodo que deve ser inserido.
*/
void ListaEncadeada::Insere(unsigned posicao, Nodo*  novoNodoPtr) {
	Nodo* anteriorPtr = inicio;

	if (posicao == 0) {
		novoNodoPtr->prox = inicio;
		inicio = novoNodoPtr;
		tamanho++;
		return;
	}

	for (unsigned i = 0; i < posicao-1; i++) {
		if (anteriorPtr->prox==NULL) {
			anteriorPtr->prox = novoNodoPtr;
			cout << "Posi��o inv�lida!! Inserindo no fim da lista!" << endl;
			tamanho++;
			return;
		}
		anteriorPtr = anteriorPtr->prox;
	}

	novoNodoPtr->prox = anteriorPtr->prox;
	anteriorPtr->prox = novoNodoPtr;
	tamanho++;
}


/*
* Declara��o da fun��o Busca, que faz uma busca por um nodo na
* lista � partir de sua chave.
*
* @param data		Chave do nodo que deve ser procurado na lista.
*/
Nodo* ListaEncadeada::Busca(int data) const {
	int acesso = 0;
	Nodo* atualPtr = inicio;

	acesso++;
	while (atualPtr) {
		if (atualPtr->data == data) {
			atualPtr->Print();
			cout << endl;
			cout << "Acessos: " << acesso << endl << endl;;
			return atualPtr;
		}
		acesso++;
		atualPtr = atualPtr->prox;
	}
	cout << "N�o encontrado!!!" << endl;
	cout << "Acessos: " << acesso << endl << endl;
	return NULL;
}

/*
* Declara��o da fun��o Busca o menor valor da lista e retorna
* sua posi��o.
*/
Nodo* ListaEncadeada::BuscarMenor() {
	unsigned acesso = 0;
	Nodo* menor = NULL;
	Nodo* atualPtr = inicio;

	if (!atualPtr) {
		cout << "Lista vazia!!" << endl;
		return NULL;
	}

	acesso++;
	menor = atualPtr;

	while (atualPtr) {
		acesso++;
		if (menor->data > atualPtr->data) {
			menor = atualPtr;
		}
		atualPtr = atualPtr->prox;
	}

	cout << "Acessos: " << acesso << endl;
	cout << "Menor valor: " << menor->data << endl;
	return menor;
}

/*
* Fun��o que retorna um indice para a posi��o de um nodo na lista
*
* @param nodo		Nodo que ser� retornada a posi��o como um indice int
*/
unsigned ListaEncadeada::IndiceNodo(Nodo* nodo) {
	Nodo* atualPtr = inicio;
	int posicao = 0;

	if (nodo) {
		while (atualPtr != nodo && atualPtr) {
			atualPtr = atualPtr->prox;
			posicao++;
		}
		return posicao;
	}


	cout << "Nodo n�o existente;" << endl;
	return -1;
}

/*
* Fun��o que retorna um nodo com base no indice informado
* pela fun��o anterior ou pelo usu�rio.
*
* @param posicao		Posi��o do nodo que deve ser retornado;
*/
Nodo* ListaEncadeada::AtNodo(int posicao) {
	if (posicao >= 0 && posicao < tamanho) {
		Nodo* atualPtr = inicio;

		for (int i = 0; i < posicao; i++) {
			if (atualPtr->prox == NULL)
				break;
			atualPtr = atualPtr->prox;
		}
		return atualPtr;
	}
	return NULL;
}

/*
* Fun��o que realiza a troca de posi��o de dois nodos na lista encadeada;
*
* @param nodoA		Posi��o do primeiro nodo;
* @param nodoB		Posi��o do segundo nodo;
*/
void ListaEncadeada::Swap(Nodo* nodeA, Nodo* nodeB ) {
	Nodo* atualPtr = inicio;
	Nodo* prevNodeA = new Nodo;
	Nodo* prevNodeB = new Nodo;
	Nodo* aux = NULL;

	if (nodeA == nodeB)
		return;

	for (unsigned i=0; i < IndiceNodo(nodeA); i++) {
		prevNodeA = atualPtr;
		atualPtr = atualPtr->prox;
	}

	atualPtr = inicio;

	for (unsigned i=0; i < IndiceNodo(nodeB); i++) {
		prevNodeB = atualPtr;
		atualPtr = atualPtr->prox;
	}

	if (nodeA == inicio) {
		aux = nodeB->prox;
		nodeB->prox = nodeA->prox;
		nodeA->prox = aux;
		prevNodeB->prox = nodeA;
		inicio = nodeB;
	}

	else {
		prevNodeA->prox = nodeB;
		prevNodeB->prox = nodeA;
		aux = nodeA->prox;
		nodeA->prox = nodeB->prox;
		nodeB->prox = aux;
	}

	return;
}

/*
* Fun��o que realiza a impress�o dos elementos da lista
* em ordem inversa, por meio de recurs�o;
*/
void PrintInverso(Nodo*& start) {
	if (start->prox == NULL)
	{
		start->Print();
		return;
	}

	PrintInverso(start->prox);
	start->Print();
	return;
}