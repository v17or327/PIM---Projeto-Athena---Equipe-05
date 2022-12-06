#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string.h>

#define TAM 50         //TAM recebe o valor de 50 inteiros

using namespace std;

typedef struct Cliente{
    char nome[50];
    char CNPJ[16];
    char razaosocial[100]; // Variáveis utilizadas
    char telefone[17];
    char email[80];
    char nomeUsuario[50];
}cliente;

cliente clientes[TAM];  

FILE *arquivoCliente;

char usuarioAtu[50];

// ------------------ CADASTRO CLIENTES --------------------

void CadastroCliente()
{
 system("cls");// limpar tela

    int i = 0; 
    int sucesso; 
	
	cout<< "\n\t\t >> BEM VINDO AO CADASTRO DE CLIENTES << \n";
    arquivoCliente = fopen("cliente.txt", "a");

    cout << "  Nome da empresa: " << endl;
    cin >> clientes[i].nome;
    cout << "  CNPJ/CPF: " << endl;
    cin >> clientes[i].CNPJ;
    cout << "  Razão Social: " << endl;
    cin >> clientes[i].razaosocial;
    cout << "  Telefone " << endl;
    cin >> clientes[i].telefone;
    cout << "  E-mail: " << endl;
    cin >> clientes[i].email;
    strcpy(clientes[i].nomeUsuario, usuarioAtu);

    sucesso = fwrite (&clientes[i], sizeof(cliente), 1, arquivoCliente);

    if (sucesso == 1){
        cout<<"\nUsuário salvo com sucesso!";
    }
    fclose(arquivoCliente);
}

// ---------------- LISTAGEM DE CLIENTES ------------------

void ListarClientes(){
    system("cls");
    int i=0, clienteExiste=0;
    arquivoCliente = fopen("cliente.txt", "r"); //R = READ
    if (arquivoCliente == NULL)
	{
       cout<< "Erro!\nO arquivo não pôde ser aberto!\n";
       system("pause");
       exit(1);
    }

    cout<< "--- Lista de Clientes de " << usuarioAtu <<"\n";
    clienteExiste = fread(&clientes[i], sizeof(cliente), 1, arquivoCliente);
    while (clienteExiste == 1)
	{
        if(strcmp(usuarioAtu, clientes[i].nomeUsuario) == 0)
		{
            cout<<"\n Nome ------------" << clientes[i].nome;
            cout<<"\n CNPJ ------------" << clientes[i].CNPJ;
            cout<<"\n Razão Social --- " << clientes[i].razaosocial;
            cout<<"\n Telefone --------" << clientes[i].telefone;
            cout<<"\n Email -----------" << clientes[i].email<< "\n";
        }
        i++;
        clienteExiste = fread(&clientes[i], sizeof(cliente), 1, arquivoCliente);
    }
    fclose(arquivoCliente);
    system("pause");
}

// ------------------------- TELA DE MENU ----------------------

void TelaMenu(char usuarioArg[50]) /* função que foi chamada no arquivo de cadastro, no case 2. usuarioArg vai receber
									uma informação, no caso, o usuário logado. Dessa forma, ocorre o seguimento do codigo*/
{
       
	cout << "Bem vindo ao Athena ADM Tool v1.0" << endl;
    
	int Novamente=4, selecao;
    do
    {
    strcpy(usuarioAtu, usuarioArg); //string copy -> copia as informações armazaenadas em usuarioArg (que veio do arquivo de cadastro) e vai guardar no usuarioAtu
    								// é necessário que essa variavel seja global, para que ela possa ser utilizada em qq. metodo desse arquivo
									// usuarioArg recebe as informações de usuarioAtual
									//não tem como utilizar o usuarioAtu, pois ela já está declarada e não há informações armazenadas nela.
        system("cls"); 
        cout << "Selecione 1 para Cadastrar um cliente." << endl
             << endl
             << "selecione 2 para Listar seus Clientes." << endl
             << endl
             << "Selecione 3 para sair." << endl;
        cin >> selecao;

        if (selecao > 3)
        {
            cout << "   Por favor selecione uma opção entre 1 e 3. " << Novamente << endl;
            cout << "===========================" << endl;
        } else {
            switch (selecao) // switch para fazer a seleção do cadastro ou Login
            {
            case 1: // Cadastro
                CadastroCliente();
                break;
            case 2: // login
                ListarClientes();
                break;
            case 3: // Saida
                Novamente = 0;
                break;
            }
        }
    }
    while (Novamente == 4);
}

//endif
