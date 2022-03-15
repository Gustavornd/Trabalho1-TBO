#include "Functions.h"




/*
* Função usada para criar o arquivo de entrada de dados;
*/
void CreateInputFile() {
	fstream output;
	output.open("dados.txt", ios::out);

	if (!output)
		abort();

	output << "10" << endl;
	output << "8 1 3 4 3 6 10 8 9 1";

	output.close();
}


/*
* Função usada para criar um aquivo de entrada com dados
* aleatórios, mas não foi utilizado;
*/
void CreateRandomInputFile() {
	fstream output;
	output.open("dadosRadom.txt", ios::out);

	if (!output)
		abort();

	output << 100 << endl;

	for (unsigned i = 1; i <= 100; i++)
	{
		output << 1 + rand() % 1000 << " ";
	}

	output.close();
}