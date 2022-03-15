#include "menu.h"

/*
* Função que implementa o menu de testes.
*/
void Menu() {
	while (true) {
		unsigned opcao;
		system("cls");
		cout << "1. Lista Estática (arquivo)." << endl;
		cout << "2. Lista Estática (aleatória)." << endl;
		cout << "3. Lista Encadeada (arquivo)." << endl;
		cout << "4. Lista Encadeada (aleatória)" << endl;
		cout << "5. Lista Duplamente Encadeada (arquivo)." << endl;
		cout << "6. Lista Duplamente Encadeada (aleatória)." << endl;
		cout << "0. Sair." << endl;

		cout << "Escolha uma opção: ";
		cin >> opcao;

		if (opcao == 0)
			break;

		if (opcao == 1)
		{
			system("cls");
			cout << endl << "------------------LISTA ESTATICA--------------------" << endl;
			ListaEstatica a("dados.txt");
			a.print();

			cout << endl << "---------------------Inserir----------------------" << endl;
			a.Inserir(10, 11);
			a.Inserir(4, 2);
			a.Inserir(0, 7);
			a.print();

			cout << endl << "---------------------Busca----------------------" << endl;
			a.Buscar(10);
			a.Buscar(8);
			a.Buscar(12);

			cout << endl << "---------------------Swap----------------------" << endl;
			a.Swap(3, 4);
			a.Swap(0, 6);
			a.Swap(6, 12);
			a.print();

			cout << endl << "---------------------Menor Valor----------------------" << endl;
			a.BuscarMenor();

			cout << endl << "---------------------Print Invertido----------------------" << endl;
			a.printInvertido();
			cout << endl << endl;
			system("pause");
		}

		if (opcao == 2) {
			system("cls");
			cout << endl << "------------------LISTA ESTATICA ALEATÓRIA--------------------" << endl;
			ListaEstatica a(100);
			a.print();

			cout << endl << "---------------------Menor Valor----------------------" << endl;
			a.BuscarMenor();

			cout << endl << "---------------------Print Invertido----------------------" << endl;
			a.printInvertido();
			cout << endl << endl;
			system("pause");
		}

		if (opcao == 3) {
			system("cls");
			cout << endl << "------------------LISTA ENCADEADA--------------------" << endl;
			ListaEncadeada a("dados.txt");
			a.Print();

			cout << endl << "---------------------Inserir----------------------" << endl;
			Nodo* novoNodo;

			novoNodo = new Nodo(11);
			a.Insere(10, novoNodo);

			novoNodo = new Nodo(2);
			a.Insere(4, novoNodo);

			novoNodo = new Nodo(7);
			a.Insere(0, novoNodo);
			a.Print();

			cout << endl << "---------------------Busca----------------------" << endl;
			a.Busca(10);
			a.Busca(8);
			a.Busca(12);

			cout << endl << "---------------------Swap----------------------" << endl;
			a.Swap(a.AtNodo(3),a.AtNodo(4));
			a.Swap(a.AtNodo(0), a.AtNodo(6));
			a.Swap(a.AtNodo(6), a.AtNodo(12));
			a.Print();

			cout << endl << "---------------------Menor Valor----------------------" << endl;
			a.BuscarMenor();

			cout << endl << "---------------------Print Invertido----------------------" << endl;
			PrintInverso(a.inicio);
			cout << endl << endl;
			system("pause");
		}

		if (opcao == 4) {
			system("cls");
			cout << endl << "------------------LISTA ENCADEADA ALEATÓRIA--------------------" << endl;
			ListaEncadeada a(100);
			a.Print();

			cout << endl << "---------------------Menor Valor----------------------" << endl;
			a.BuscarMenor();

			cout << endl << "---------------------Print Invertido----------------------" << endl;
			PrintInverso(a.inicio);
			cout << endl << endl;
			system("pause");
		}

		if (opcao == 5) {
			system("cls");
			cout << endl << "------------------LISTA DUPLAMENTE ENCADEADA--------------------" << endl;
			ListaDupla a("dados.txt");
			a.Print();

			cout << endl << "---------------------Inserir----------------------" << endl;
			Nodo* novoNodo = NULL;

			novoNodo = new Nodo(11);
			a.Insere(10, novoNodo);

			novoNodo = new Nodo(2);
			a.Insere(4, novoNodo);

			novoNodo = new Nodo(7);
			a.Insere(0, novoNodo);
			cout << a.tamanho << endl;
			a.Print();

			cout << endl << "---------------------Busca----------------------" << endl;
			a.Busca(10);
			a.Busca(8);
			a.Busca(12);

			cout << endl << "---------------------Swap----------------------" << endl;
			a.Swap(a.AtNodo(3), a.AtNodo(4));
			a.Swap(a.AtNodo(0), a.AtNodo(6));
			a.Swap(a.AtNodo(6), a.AtNodo(12));
			a.Print();

			cout << endl << "---------------------Menor Valor----------------------" << endl;
			a.BuscaMenor();

			cout << endl << "---------------------Print Invertido----------------------" << endl;
			a.PrintInvertido();
			cout << endl << endl;
			system("pause");
		}

		if (opcao == 6) {
			system("cls");
			cout << endl << "------------------LISTA DUPLAMENTE ENCADEADA ALEATÓRIA--------------------" << endl;
			ListaDupla a(100);
			a.Print();

			cout << endl << "---------------------Menor Valor----------------------" << endl;
			a.BuscaMenor();

			cout << endl << "---------------------Print Invertido----------------------" << endl;
			a.PrintInvertido();
			cout << endl << endl;
			system("pause");
		}
	}
}
