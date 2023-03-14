#include <stdio.h>  // biblioteca de comunicação com o usuário
#include <stdlib.h> // biblioteca de alocação de memória
#include <locale.h> // biblioteca de alocações de texto por região
#include <string.h> // responsável por cuidar das strings


int registro() //Função para cadastro de usuários
{
	printf("Você escolheu o registro de nomes!");
	
	//início da criação variáveis/strings
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da criação variáveis/strings
	
	printf("Digite o CPF a ser cadastrado: "); //colentando informação do usuário
	scanf("%s", cpf); //%s para salvar strings
	
	strcpy(arquivo, cpf); //responsavel por copiar os valores das strings
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo,"w"); //cria o arquivo
	fprintf(file,cpf); //salva o valor da variavel
	fclose(file); //fecha o arquivo

    file = fopen(arquivo,"a");//"a" para abrir o arquivo e adicionar informações
    fprintf(file, ",");//adicionando virgula entre as informações
    fclose(file);//fecha o arquivo depois que adicionou a virgula
    
    //repete o processo da vírgula em toda atualização dos dados do cadastro, nome, sobrenome, cargo
    
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


int consultar()//função de consulta
{
	setlocale(LC_ALL, "Portuguese");//definindo linguagem
	
	char cpf[40];//definindo variáveis da consulta
	char conteudo[100];//variável criada para armazenamento dos dados para leitura do cadastro
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s",cpf);
	
	
	FILE *file;
	file = fopen(cpf,"r");//adicionando "r" na funão fopen() para apenas ler o arquivo com os dados do cadastro
	
	if(file == NULL) //validação caso arquivo não seja localizado
	{
	    printf("Não foi possivel localizar o arquivo.\n");
	}
	
	while(fgets(conteudo, 100, file) != NULL)//laço de repetição, busca o conteúdo e grava na string conteúdo até achar para printar na tela
	{
		printf("\nEssas são as informações do usuário:\n ");
		printf("%s",conteudo);
		printf("\n\n");
	} 
	    
        system("pause");
        fclose(file); //fecha o arquivo q foi aberto para localizar os dados
}

int deletar()//função pra deletar cadastro
{
    char cpf[40];//criação da variável. CPF é a primary key para criação do cadastro
	
	printf("Digite o CPF a ser deletado: \n");
	scanf("%s", cpf);
	
    FILE *file;
	file = fopen(cpf, "r");
	
    if(file != NULL)//validação criada para que o arquivo seja deletado caso seja compativel com o cpf digitado na busca
    {
    fclose(file);
	remove(cpf);
	printf("CPF deletado com sucesso!\n");
	system("pause");
    }
    else //validação caso o cpf seja incompativel com os dados salvos no banco de dados
    {
	printf("CPF inválido!\n");
    system("pause");
    }

}
	



int main() //função tela do menu        
{
    int opcao=0;
	int laco=1; //Definindo variáveis
	
	for(laco=1;laco=1;)//operadores de repetição
    {
		system("cls");
	    setlocale (LC_ALL, "Portuguese"); //Definindo linguagem

	    printf ("### Cartório da EBAC ###\n\n"); //Início do menu
        printf ("Escolha a opção desejada do menu\n\n"); 
	    printf ("\t1 - Registrar nomes\n");
	    printf ("\t2 - Consultar nomes\n");
	    printf ("\t3 - Deletar nomes\n\n"); 
	    printf ("opção: ");//Fim do menu

        scanf("%d" , &opcao); //Armazenando escolha do usuário
    
        system("cls");
        
        switch(opcao) //inicio da seleção do menu
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
		    printf("Essa opção não está disponível!\n");
		    system("pause");
		    break;
		}  //Fim da seleção
     
    } //fim do laço de repetição
}




