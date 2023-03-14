#include <stdio.h>  // biblioteca de comunica��o com o usu�rio
#include <stdlib.h> // biblioteca de aloca��o de mem�ria
#include <locale.h> // biblioteca de aloca��es de texto por regi�o
#include <string.h> // respons�vel por cuidar das strings


int registro() //Fun��o para cadastro de usu�rios
{
	printf("Voc� escolheu o registro de nomes!");
	
	//in�cio da cria��o vari�veis/strings
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da cria��o vari�veis/strings
	
	printf("Digite o CPF a ser cadastrado: "); //colentando informa��o do usu�rio
	scanf("%s", cpf); //%s para salvar strings
	
	strcpy(arquivo, cpf); //responsavel por copiar os valores das strings
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo,"w"); //cria o arquivo
	fprintf(file,cpf); //salva o valor da variavel
	fclose(file); //fecha o arquivo

    file = fopen(arquivo,"a");//"a" para abrir o arquivo e adicionar informa��es
    fprintf(file, ",");//adicionando virgula entre as informa��es
    fclose(file);//fecha o arquivo depois que adicionou a virgula
    
    //repete o processo da v�rgula em toda atualiza��o dos dados do cadastro, nome, sobrenome, cargo
    
    printf("Digite o nome a ser cadastrado: "); 
    scanf("%s",nome);
    
    file = fopen(arquivo,"a");
    fprintf(file,nome);
    fclose(file);
    
    file = fopen(arquivo,"a");
    fprintf(file,",");
    fclose(file);
    
    printf("Digite o sobrenome a ser cadastrado: ");
    scanf("%s",sobrenome);
    
    file = fopen(arquivo, "a");
    fprintf(file,sobrenome);
    fclose(file);
    
    file = fopen(arquivo, "a");
    fprintf(file,",");
    fclose(file);
    
    printf("Digite o cargo a ser cadastrado: ");
    scanf("%s", cargo);
    
    file = fopen(arquivo, "a");
    fprintf(file,cargo);
    fclose(file);
    
    //fim do processo de cadastro de dados
    
    system("pause"); 

}


int consultar()//fun��o de consulta
{
	setlocale(LC_ALL, "Portuguese");//definindo linguagem
	
	char cpf[40];//definindo vari�veis da consulta
	char conteudo[100];//vari�vel criada para armazenamento dos dados para leitura do cadastro
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s",cpf);
	
	
	FILE *file;
	file = fopen(cpf,"r");//adicionando "r" na fun�o fopen() para apenas ler o arquivo com os dados do cadastro
	
	if(file == NULL) //valida��o caso arquivo n�o seja localizado
	{
	    printf("N�o foi possivel localizar o arquivo.\n");
	}
	
	while(fgets(conteudo, 100, file) != NULL)//la�o de repeti��o, busca o conte�do e grava na string conte�do at� achar para printar na tela
	{
		printf("\nEssas s�o as informa��es do usu�rio:\n ");
		printf("%s",conteudo);
		printf("\n\n");
	} 
	    
        system("pause");
        fclose(file); //fecha o arquivo q foi aberto para localizar os dados
}

int deletar()//fun��o pra deletar cadastro
{
    char cpf[40];//cria��o da vari�vel. CPF � a primary key para cria��o do cadastro
	
	printf("Digite o CPF a ser deletado: \n");
	scanf("%s", cpf);
	
    FILE *file;
	file = fopen(cpf, "r");
	
    if(file != NULL)//valida��o criada para que o arquivo seja deletado caso seja compativel com o cpf digitado na busca
    {
    fclose(file);
	remove(cpf);
	printf("CPF deletado com sucesso!\n");
	system("pause");
    }
    else //valida��o caso o cpf seja incompativel com os dados salvos no banco de dados
    {
	printf("CPF inv�lido!\n");
    system("pause");
    }

}
	



int main() //fun��o tela do menu        
{
    int opcao=0;
	int laco=1; //Definindo vari�veis
	
	for(laco=1;laco=1;)//operadores de repeti��o
    {
		system("cls");
	    setlocale (LC_ALL, "Portuguese"); //Definindo linguagem

	    printf ("### Cart�rio da EBAC ###\n\n"); //In�cio do menu
        printf ("Escolha a op��o desejada do menu\n\n"); 
	    printf ("\t1 - Registrar nomes\n");
	    printf ("\t2 - Consultar nomes\n");
	    printf ("\t3 - Deletar nomes\n\n"); 
	    printf ("op��o: ");//Fim do menu

        scanf("%d" , &opcao); //Armazenando escolha do usu�rio
    
        system("cls");
        
        switch(opcao) //inicio da sele��o do menu
        { 
            case 1: 
            registro(); //chamada para cadastro
    	    break;
    	    
    	    case 2:
    	    consultar(); //chamda para consulta
		    break;
		    
		    case 3:
		    deletar(); //chamada para remover
		    break;
		    
		    default:
		    printf("Essa op��o n�o est� dispon�vel!\n");
		    system("pause");
		    break;
		}  //Fim da sele��o
     
    } //fim do la�o de repeti��o
}




