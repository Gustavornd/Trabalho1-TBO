#pragma warning(disable:4996)
#pragma warning(disable:4244)
#pragma warning(disable:6011)
#include "ListaDupla.h"

using namespace std;

/*
	* Construtor da classe ListaEncadeada. Ao ser convocado,
	* inicializa os atributos da classe.
	*/
ListaDupla::ListaDupla() {
    inicio = new Nodo;
    fim = new Nodo;

    inicio->prox = NULL;
    inicio->ant = NULL;

    fim->prox = NULL;
    fim->ant = inicio;
}

/*
	* Função que inicializa uma lista com dados lidos em aquivo
	*
	* @param file_name		String que reprenta o nome do arquivo que deve ser aberto.
	*/
ListaDupla::ListaDupla(string file_name) {
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
	newDataNodo = new Nodo(newData);
	//Insere(0, newDataNodo);
	for (int i = 0; i < tam; i++) {
		if (i == 0) {
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
	* Função que inicializa uma lista com dados aleatórios, com o
	* tamanho definido;
	*
	* @param tam		Número de elementos da lista (tamanho) que deve ser gerada
	*/
ListaDupla::ListaDupla(unsigned tam) {
	int seed = 107140;
	Nodo* newDataNodo;
	cout << "Semente de geração da lista: " << seed << endl;
	srand(seed);

	for (unsigned i = 0; i < tam; i++) {
		int newData = 1 + rand() % 1000;
		newDataNodo = new Nodo(newData);
		Insere(i, newDataNodo);
	}
}

/*
	* Destrutor da classe ListaDupla. Ao ser convocado,
	* desfaz a alocação de memória e apaga cada membro da lista.
	*/
ListaDupla::~ListaDupla() {
    Nodo* aux;
    cout << "\n\n" << endl;
    while (inicio)
    {
        aux = inicio->prox;
        delete inicio;
        inicio = aux;
    }
}

/*
	* Declaração da função Insere que faz a inserção de novos membros
	* na lista.
	*
	* @param posicao			Posição onde o novo membro deve ser inserido.
	* @param novoNodoPtr		Ponteiro para o nodo que deve ser inserido.
	*/
void ListaDupla::Insere(unsigned posicao, Nodo* novoNodoPtr) {
	Nodo* atualPtr = inicio;
	Nodo* aux;


	if (!inicio) {
		inicio = novoNodoPtr;
		fim = novoNodoPtr;
		tamanho++;
		return;
	}

	if (posicao == 0) {
		inicio->ant = novoNodoPtr;
		novoNodoPtr->prox = inicio;
		inicio = novoNodoPtr;
		tamanho++;
		return;
	}

	for (unsigned i = 0; i < posicao - 1; i++) {
		if (!atualPtr->prox)
			break;
		atualPtr = atualPtr->prox;
	}

	if (atualPtr->prox == NULL) {
		novoNodoPtr->prox = atualPtr->prox;
		novoNodoPtr->ant = atualPtr;
		atualPtr->prox = novoNodoPtr;
		fim = novoNodoPtr;
		tamanho++;
		return;
	}

	novoNodoPtr->prox = atualPtr->prox;
	novoNodoPtr->ant = atualPtr;   
	atualPtr->prox = novoNodoPtr;
	novoNodoPtr->prox->ant = novoNodoPtr;
	tamanho++;
	return;
}

/*
	* Declaração da função Busca, que faz uma busca por um nodo na
	* lista à partir de sua chave.
	*
	* @param data		Chave do nodo que deve ser procurado na lista.
	*/
Nodo* ListaDupla::Busca(int data) const {
	int acesso = 0;
	Nodo* atualPtr = inicio;

	acesso++;
	while (atualPtr) {
		if (atualPtr->data == data) {
			atualPtr->Print();
			cout << endl;
			cout << "Acessos: " << acesso << endl << endl;
			atualPtr->Print();
			return atualPtr;
		}
		acesso++;
		atualPtr = atualPtr->prox;
	}
	cout << "Não encontrado!!!" << endl;
	cout << "Acessos: " << acesso << endl << endl;
	return NULL;
}

/*
	* Declaração da função Busca o menor valor da lista e retorna
	* sua posição.
	*/
Nodo* ListaDupla::BuscaMenor() {
	unsigned acesso = 0;
	unsigned posicao = 0;
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
		posicao++;
		atualPtr = atualPtr->prox;
	}

	cout << "Acessos: " << acesso << endl;
	cout << "Predecessor: " << menor->ant->data << endl;
	cout << "Menor valor: " << menor->data << endl;
	return menor;
}

/*
	* Função que retorna um indice para a posição de um nodo na lista
	*
	* @param nodo		Nodo que será retornada a posição como um indice int
	*/
unsigned ListaDupla::IndiceNodo(Nodo* nodo) {
	Nodo* atualPtr = inicio;
	int posicao = 0;

	if (nodo == inicio)
		return posicao;

	if (nodo) {
		while (atualPtr != nodo && atualPtr) {
			atualPtr = atualPtr->prox;
			posicao++;
		}
		if(atualPtr!=NULL)
			return posicao;
	}


	cout << "Nodo não existente;" << endl;
	return -1;
}

/*
	* Função que retorna um nodo com base no indice informado
	* pela função anterior ou pelo usuário.
	*
	* @param posicao		Posição do nodo que deve ser retornado;
	*/
Nodo* ListaDupla::AtNodo(int posicao) {
	if (posicao == 0) {
		return inicio;
	}

	if (posicao == tamanho - 1) {
		return fim;
	}

	if (posicao > 0 && posicao < tamanho) {
		Nodo* atualPtr = inicio;

		for (int i = 0; i < posicao; i++) {
			atualPtr = atualPtr->prox;
		}
		return atualPtr;
	}
	return NULL;
}

/*
	* Função que realiza a troca de posição de dois nodos na lista encadeada;
	*
	* @param nodoA		Posição do primeiro nodo;
	* @param nodoB		Posição do segundo nodo;
	*/
void ListaDupla::Swap(Nodo* nodeA, Nodo* nodeB) {
	Nodo* atualPtr = inicio;
	Nodo* nodeAPtr = NULL;
	Nodo* nodeBPtr = NULL;
	Nodo* aux1;
	Nodo* aux2;
	if (nodeA == nodeB)
		return;

	if (inicio == nodeA && fim == nodeB) {
		nodeAPtr = inicio;
		nodeBPtr = fim;

		aux1 = nodeBPtr->prox;
		aux2 = nodeBPtr->ant;

		nodeBPtr->prox = nodeAPtr->prox;
		nodeAPtr->prox = aux1;

		nodeBPtr->ant = nodeAPtr->ant;
		nodeAPtr->ant = aux2;

		nodeBPtr->prox->ant = nodeBPtr;
		nodeAPtr->ant->prox = nodeAPtr;

		inicio = nodeBPtr;
		fim = nodeAPtr;
		return;
	}

	if (inicio == nodeA)
	{
		nodeAPtr = inicio;
		for (unsigned i = 0; i <= IndiceNodo(nodeB); i++) {
			nodeBPtr = atualPtr;
			atualPtr = atualPtr->prox;
		}
		aux1 = nodeBPtr->prox;
		aux2 = nodeBPtr->ant;

		nodeBPtr->ant->prox = nodeAPtr;
		nodeBPtr->ant = nodeAPtr->ant;
		nodeBPtr->prox = nodeAPtr->prox;

		nodeAPtr->prox = aux1;
		nodeAPtr->ant = aux2;

		nodeAPtr->prox->ant = nodeAPtr;
		nodeBPtr->prox->ant = nodeBPtr;
		
		inicio = nodeBPtr;
		return;
	}

	if (fim == nodeB) {
		nodeBPtr = fim;
		for (unsigned i = 0; i <= IndiceNodo(nodeA); i++) {
			nodeAPtr = atualPtr;
			atualPtr = atualPtr->prox;
		}
		aux1 = nodeAPtr->prox;
		aux2 = nodeAPtr->ant;

		nodeAPtr->prox = nodeBPtr->prox;
		nodeAPtr->ant = nodeBPtr->ant;

		nodeBPtr->prox = aux1;
		nodeBPtr->ant = aux2;
		nodeBPtr->prox->ant = nodeBPtr;
		nodeBPtr->ant->prox = nodeBPtr;
		nodeAPtr->ant->prox = nodeAPtr;
		
		fim = nodeAPtr;
		return;
	}

	for (unsigned i = 0; i <= IndiceNodo(nodeA); i++) {
		nodeAPtr = atualPtr;
		atualPtr = atualPtr->prox;
	}

	atualPtr = inicio;

	for (unsigned i = 0; i <= IndiceNodo(nodeB); i++) {
		nodeBPtr = atualPtr;
		atualPtr = atualPtr->prox;
	}

	if (nodeAPtr->prox == nodeBPtr) {
		nodeAPtr->ant->prox = nodeBPtr;
		nodeBPtr->prox->ant = nodeAPtr;
		nodeAPtr->prox = nodeBPtr->prox;
		nodeBPtr->ant = nodeAPtr->ant;
		nodeBPtr->prox = nodeAPtr;
		nodeAPtr->ant = nodeBPtr;
		return;
	}


	aux1 = nodeBPtr->prox;
	aux2 = nodeBPtr->ant;

	nodeAPtr->ant->prox = nodeBPtr;
	nodeBPtr->prox = nodeAPtr->prox;

	nodeBPtr->ant->prox = nodeAPtr;
	nodeAPtr->prox = aux1;

	nodeBPtr->ant = nodeAPtr->ant;
	nodeAPtr->ant = aux2;

	nodeBPtr->prox->ant = nodeBPtr;
	nodeAPtr->prox->ant = nodeAPtr;


	
	return;
}

/*
	* Faz a impressão dos dados da lista na tela.
	*/
void ListaDupla::Print() const {
	Nodo* NodoPtr = inicio;

	while (NodoPtr) {
		NodoPtr->Print();
		NodoPtr = NodoPtr->prox;
	}
	cout << endl;
}

/*
	* Função que realiza a impressão dos elementos da lista
	* em ordem inversa.
	*/
void ListaDupla::PrintInvertido() const {
	Nodo* NodoPtr = fim;

	while (NodoPtr) {
		NodoPtr->Print();
		NodoPtr = NodoPtr->ant;
	}
	cout << endl;
}