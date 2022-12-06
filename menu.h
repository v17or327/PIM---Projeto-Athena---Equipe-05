#include <iostream>
#include <fstream>
#include <stdlib.h> //Bibliotecas utilizadas
#include <string.h>

void TelaMenu(char usuarioArg[50]);

void CadastroCliente();

/*Menu.h (header = cabeçalho, funciona como uma biblioteca criada) 
Declara métodos que estou utilizando nos arquivos .cpp
exemplo: TelaMenu recebe um char de 50 caracteres e é apenas exeutavel, não retorna nada, 
mas suas informações estão alocadas na .cpp 
Foi utilizado mais de um arquivo por conta da organização e separação de funcionaldiades*/