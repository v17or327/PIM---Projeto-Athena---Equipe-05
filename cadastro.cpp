/* '****************************************************************************
'Script Name: Athena
'Autor : Vitor/matheus/Gabi/Shai/Vinicius
'Data: 28/10/2022 / 24/11/2022
'Objetivo : Criar um portal de cadastro e Login para Clientes
'****************************************************************************
'**************************************************************************** */

#include <iostream>
#include <fstream>
#include <stdlib.h> //Bibliotecas utilizadas
#include <string.h>
#include <stdio.h>
#include <conio.h>
#include <locale.h>
#include "menu.h"


#define SIZE 200		//SIZE rece o valor de 200 inteiros
#define TAM 100         //TAM recebe o valor de 100 inteiros

using namespace std;

typedef struct Usuario   //é uma estrutura que pode armazenar multiplas variaveis em um tipo de dado
{ 
    char nome[50];
    char username[SIZE]; 
    char sobrenome[SIZE];
    char CNPJ[SIZE];
    char razaosocial[SIZE]; // Variáveis utilizadas
    char telefone[17];
    char email[80];
    char senha[SIZE];
}usuario; //tipo de dado criado

usuario usuarios[TAM]; //define-se uma lista de usuário (é criado um vetor que define a quantidade de usuários possíveis cadastrados) 

FILE *arquivoUsuario; /* o ponteira aponta para algo que já existe na memória, ou seja, ele retorna uma informação 
						que já foi armazenada e aponta para o lugar na memória*/

char usuarioAtual[50] = "NotFound";


// --------------- CADASTRO DE USUÁRIO ------------- //

int cadastroUsuario() // Cadastro de usuario
{ 
    system("cls"); // limpar tela

    int i = 0; 
    int sucesso;    //variável que vai confirmar

    arquivoUsuario = fopen("usuario.txt", "a"); // cria arquivo, "a" é o modo de ler e escrever, é um append (acrescentar).
	
	cout<< " Ainda não possui um cadastro na Consultoria Athena!? \n";
	cout<< " Faça parte da nossa empresa!\n";
    cout << "  Digite seu nome: " << endl;
    cin >> usuarios[i].nome;
    cout << "  Digite seu Sobrenome: " << endl;
    cin >> usuarios[i].sobrenome;
    cout << "  Digite seu Usuário: " << endl;
    cin >> usuarios[i].username;
    cout << "  Digite seu CNPJ/CPF: " << endl;
    cin >> usuarios[i].CNPJ;
    cout << "  Digite sua razão social: " << endl;
    cin >> usuarios[i].razaosocial;
    cout << "  Digite seu telefone: " << endl;
    cin >> usuarios[i].telefone;
    cout << "  Digite seu Email: " << endl;
    cin >> usuarios[i].email;
    cout << "  Digite sua senha" << endl;
    cin >> usuarios[i].senha;

    
   
    sucesso = fwrite (&usuarios[i], sizeof(usuario), 1, arquivoUsuario); //fwrite recebe quatro arguementos: onde armazenar o objeto, o
																		// o tamanhao do objeto, quantos objetos terá que ler 
																		// e o que será lido
																		// Retorna 1 se for sucesso, 0 se for falha			
    if (sucesso == 1)
	{
    	system("cls");
        cout<<("\nUsuário salvo com sucesso\n");
        system("pause");
        system("cls");
    }
    fclose(arquivoUsuario);

    return 0;
}

// ----------------- LOGIN DO USUÁRIO ------------------ 

int loginUsuario()
{
    char username[50], senha[20];
    int existeUsuario=1, usuarioEncontrado=0, i=0;

    system("cls");// limpar tela
    cout<<("Login\n");

    
    arquivoUsuario = fopen("usuario.txt", "r");// Abrir arquivo para leitura r=read (a variável arquivoUsuario abre o arqueivo .txt) 

    if (!arquivoUsuario) //se não encontrar (se for nulo)
	{
        cout<< (" Erro!\nO arquivo da lista não pode ser aberto! \n");//sera mostrada esta mensagens
        exit(1);
    }

    cout<<(" Username: ");
    cin >> username;
    cout<<(" Senha: ");
    cin >> senha;
    // Retorna o primeiro registro. Retorna 1 caso encontre.
    existeUsuario = fread(&usuarios[i], sizeof(usuario),1,arquivoUsuario);
    //fread recebe quatro arguementos: onde armazenar o objeto, o tamanhao do objeto, quantos objetos terá que ler e o que será lido 
	//depois que ele armazenar o objeto, ele vai retornar quantos objetos foram lidos
    while (existeUsuario == 1) //enquanto essa variavel retornar 1, ele vai continuar procurando no arquivo o objeto solicitado
	{
        if(strcmp(username, usuarios[i].username) == 0)
		{      											/*aqui ocorre uma comparação entre as variaveis "username"
														e "usuarios[i].username", no caso usuários é tida como uma array e o [i] são as 
														posições que seráo buscadas dentro do arquivo .txt, .username é um atributo do objeto usuario (scruct) */
            											/*nesta linha, a strcomp está questionando se o resulto da comparação é igual a 0, 
														se for igual a 0, a comparação é verdadeira e o Login executará normalmente. */
			if(strcmp(senha, usuarios[i].senha) != 0)   /* esta linha está verificando se a senha digitada no login é diferente da senha lida do arquivo, 			
														se for diferente de 0, o login não vai entrar, caso contrário, o login ocorrerá normalmente. */
            {
			    										//caso seja diferente, a lógica para aqui e retorna para a tela principal
				return 0;								
            }
            
            usuarioEncontrado++; //após o looping, é necessário checar quantos usurários foram encontrados e esta variável é tida como contadora
        }
        i++; //incrementa as posições
        existeUsuario = fread(&usuarios[i], sizeof(usuario),1,arquivoUsuario); // verificar se não foram encontrados usuários
    }
    
    if(usuarioEncontrado == 0) //se essa variável não encontrar nenhum usuário anteriormente, não haverá usuário para logar, ou seja, o código irá parar em return 0
	{
        return 0;
    }

    fclose(arquivoUsuario); //fechamento do arquivo txt.
    strcpy(usuarioAtual, username); //saber qual usuário está logado. após os testes, é certeza que existe um usuário e ele etsá logado.
									// Esta linha é para guardar em memória quem está logado.
    return 1; //usuario logado com sucesso e o case 2 puxará a função TelaMenu
}

// -------------- MANUAL DO USUÁRIO ----------- 

int ManualUsuario() // função manual do usuario
{
	
			system("cls");
	cout<< "\n\n\t\t\t BEM-VINDO AO MANUAL DO USUÁRIO\n\n";
	cout<< "\t\t     Aqui você consegue tirar suas dúvidas\n\n";
	cout<< " Primeiramente, é necessário que seja feito\n um cadastro para que você possa\n";
	cout<< " acessar o portal.";
	cout<< "\n\n Depois de criar um usuário e senha,\n você irá realizar o Login.\n\n";
	cout<< " Em nosso portal você conseguirá cadastrar clientes\n e verificar quais são os clientes cadastrados em seu usuário.\n\n";
	cout<< " Viu? Não é nada complexo!\n\n";
		system("pause");
		system("cls");
	return 0;
}
// ------------ TELA INICIAL --------------

int TelaInicial() //função da tela inicial

{
    int selecao, sucesso; 
    char Novamente = 5;
    
    cout<< "\n\t\t >> BEM VINDO AO PORTAL ATHENA << \n";
	cout<< " \n\t\t      < CONSULTORIA ATHENA > \n";
	cout<< " \n\n  Por favor, selecione a opção desejada. \n\n";
	
    do
    {
        cout << ">> 1 << Ainda não possui cadastro? Cadastre-se." << endl
             << endl
             << ">> 2 << Já faz parte da nossa equipe? Faça Login." << endl
             << endl
             << ">> 3 << Manual do Usuário." << endl
             << endl
             << ">> 4 << Sair do Portal." << endl;
        cin >> selecao;

        if (selecao > 4) 
        {																// a variável "novamente" atua de modo que o menu inicial retorne
            cout << " Ops, acho que clicou em algo errado. Tente novamente, ok? " << Novamente << endl; 
            cout << "===============================" << endl;
        }

        else
        {
            switch (selecao) // switch para fazer a seleção do cadastro ou Login
            {
            case 1: // chama a função de cadastro
                cadastroUsuario();
                break;
            case 2: // chama a função de login
                sucesso = loginUsuario(); //variável "sucesso" chama a função de login atribuindo-a a ela
                if (sucesso == 1) //se a variável sucesso é verdadeira, o login é realizado
				{
					
                    cout<<("\nUsuário logado com sucesso!\n");
                    TelaMenu(usuarioAtual); //chama o void TelaMenu no arquivo menu.cpp, usuarioAtual corresponde a usuarioArg. 
					//Estava dando conflito com o mesmo nome. 
                }else{
                    cout<<("Erro ao logar: Usuário ou Senha incorretos.\n"); // senão, não haverá login
                    system("pause");
                    system("cls");
                }
                break;

            case 3: 
            	ManualUsuario();
                break;
            case 4:
            	cout << "  Obrigado por utilizar nosso portal" << endl;
                Novamente = 0;
                break;
            }
        }
    } while (Novamente == 5);
    return 0;
}

int main() //Função Main
{
	system("color 4F");
    setlocale(LC_ALL, "portuguese"); 
    
    TelaInicial();
}
