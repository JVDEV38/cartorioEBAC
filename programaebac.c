#include <stdio.h>	//biblioteca de texto, comunica��o com o usu�rio.
#include <stdlib.h>	//biblioteca de aloca��o de mem�ria.
#include <locale.h>	//biblioteca de aloca��es de texto por regi�o.
#include <string.h>	//biblioteca de gerenciamento de strings.

int cadastro()	//fun��o para cadastrar clientes no sistema
{

	//in�cio da cria��o de vari�veis/string
	char arquivo[40];
	char cpf[40];
	char nome[50];
	char telefone[40];
	char email[40];
	//final da cria��o de vari�veis/string
		
		system("cls");
		
		printf("Cadastro de clientes:\n\n");	//coletando informa��o do usu�rio
		printf("CPF: ");	//coletando informa��o do usu�rio
		scanf("%s", cpf);	//armazenando o valor digitado na variavel/string "cpf"
		
		strcpy(arquivo, cpf);	//copia os valores das strings.
		FILE *file;	//"FILE" significa o navegador de arquivos do windows, "file" significa o arquivo .txt a ser criado dentro da pasta do programa.
		file = fopen(arquivo, "w");	//	abre o arquivo "file" e escreve; "w".(arquivo novo).
		fprintf(file,"CPF: ");
		fprintf(file, cpf);	//"fprintf" escreve no arquivo .txt o valor da vari�vel "cpf".
		fclose(file);	//fecha o arquivo "file".
		
		file = fopen(arquivo, "a");	//abrindo o arquivo e atualizando
		fprintf(file, ",");	//escreve uma v�rgula entre os valores
		fclose(file);	//fecha o arquivo
		
		printf("Nome: ");	//exibe na tela "Nome: " para o usu�rio entender que � o momento para digitar o Nome a ser cadastrado
		scanf("%s", nome);	//armazenando o valor que o usu�rio digitou dentro da vari�vel/string "nome"
		file = fopen(arquivo, "a");	//abrindo o arquivo e atualizando
		fprintf(file,"Nome: ");	//escrevendo no arquivo "Nome: "
		fprintf(file,nome);	//escrevendo no arquivo o conte�do da vari�vel/string "nome"
		fclose(file);	//fecha o arquivo
		
		file = fopen(arquivo, "a");	//abrindo o arquivo e atualizando
		fprintf(file, ",");	//escrevendo no arquivo uma virgula entre os valores
		fclose(file);	//fechando o arquivo
		
		printf("Telefone: ");	//exibibe na tela "Telefone: " para o usu�rio saber que � momento de digitar o telefone a ser cadastrado
		scanf("%s", telefone);	//armazena o valor digitado pelo usu�rio dentro da vari�vel/string "telefone"
		file = fopen(arquivo, "a");	//abre o arquivo e atualiza
		fprintf(file,"Telefone: ");	//escreve "Telefone: " no arquivo
		fprintf(file,telefone);	//escreve no arquivo o conte�do da vari�vel/string "telefone"
		fclose(file);	//fecha o arquivo
		
		file = fopen(arquivo, "a");	//abre o arquivo e atualiza
		fprintf(file, ",");	//abre o arquivo e digita uma virgula
		fclose(file);	//fecha o arquivo
		
		printf("Email: ");	//exibe na tela "Email: " para que o usu�rio saiba o momento para digitar o email a ser cadastrado
		scanf("%s", email);	//armazena o valor digitado pelo usu�rio dentro da vari�vel/string "email"
		file = fopen(arquivo, "a");	//abre o arquivo e atualiza
		fprintf(file,"Email: ");	//escreve no arquivo "Email: "
		fprintf(file,email);	//escreve no arquivo o valor da vari�vel/string "email"
		fclose(file);	//fecha o arquivo
		
		system("pause");	//pede para o sistema operacional dar um "pause"
		system("cls");	//pede para o sistema operacional exeutar uma limpeza na tela		
		
		int opcao=0;	//vari�vel para armazenar a escolha do usu�rio dentro do menu
		printf("Cliente cadastrado com sucesso!\n\n");	//escreve na tela uma confirma��o para o usu�rio de que o cliente doi cadastrado com sucesso no sistema
		system("pause");	//pede para o suistema operacional dar um "pause
		
		system("cls");	//pede para o sistema operacinal executar uma limpeza de tela
	
			printf("Oque deseja fazer? \n\n");	//exibe na tela "Oque deseja fazer?" para que o usu�rio entre com uma das op��es apresentadas
			printf("\t1 - Cadastrar novo cliente\n");	//exibe na tela a op��o 1
			printf("\t2 - Retornar ao MENU\n");	//exibe na tela a op��o 2
			scanf("%d", &opcao);	//armazena o valor da op��o do usu�rio
			
				switch(opcao)	//conjunto de op��es a serem escolhidas e tarefas a serem executadas segundo op��o do usu�rio
					{
						case 1:	//caso o usu�rio escolha a op��o 1, executa a proxima linha
						
							cadastro();	//caso a op��o seja 1, o sistema retorna a fun��o cadastro novamente
							break;	//pause dentro da fun��o switch, serve para separar as op��es
						
						case 2:	//caso a op��o seja 2, executa a segunda linha
							main();	//caso a op��o seja 2, o sistema retorna a fun��o main novamente
							break;	//separa��o das op�oes dentro do switch case
					
						default:	//caso o usu�rio digite uma op��o diferente das op��es fornecidas, executa a proxima linha
							printf("Por favor, selecione uma op��o v�lida!\n\n");	//escreve na tela "Por favor, selecione uma op��o v�lida!" com duas quebras de linhas logo ap�s.
							system("pause");	//pause do sistema operacinal
							break;	//separa��o de op�oes dentro do switch case
					}
}

int consulta()	//fun��o para consultar clientes cadastrados
{
	system("cls");	//limpar a tela.
	setlocale(LC_ALL, "Portuguese");	//linguagem dos usu�rios e que o programa ir� exibir os textos
	
	//inicio das vari�veis/string
	char cpf[40];
	char conteudo[200];
	//final das vari�veis/string
	
	printf("Digite o cpf a ser consultado: ");	//exibe na tela "Digite o cpf a ser consultado: ", para que o usu�rio saiba que � o momento de digitar o cpf que deseja consultar
	scanf("%s", cpf);	//armazena o valor digitado pelo usu�rio dentro da vari�vel/string "cpf"
	
	FILE *file;	//o sistema acessa o gerenciador de arquivos do sistema operacional e procura os arquivos do programa
	file = fopen(cpf, "r");	//abre o arquivo encontrado com o valor da vari�vel/string "cpf" digitado pelo usu�rio e l�
	
	if(file == NULL)	//caso n�o exista o cpf digitado pelo usu�rio, executa a pr�xima linha de c�digo
	{
		printf("\n\nEsse cliente n�o existe!\n\n");	//exibe na tela "Esse cliente n�o existe!"
	}
		
	while(fgets(conteudo, 200, file) != NULL)	//faz uma busca dentro do arquivo, armazena o conteudo dentro da variavel "conteudo" at� 200 caracteres, at� que n�o existam mais caracteres
	{
		printf("\nInforma��es do Cliente: ");	//exibe na tela "Informa��es do Cliente: "
		printf("%s", conteudo);	//exibe na tela o conteudo armazenado dentro da vari�vel/string "conteudo"
		printf("\n\n");	//exibe duas quebras de linha
	}
		system("pause");	//pede para o sistema operacinal executar uma limpeza de tela
	
		system("cls");	//limpar a tela.
		
			int opcao=0;
			printf("Oque deseja fazer? \n\n");	//exibe na tela "Oque deseja fazer?" para que o usu�rio entre com uma das op��es apresentadas
			printf("\t1 - Consultar novo cliente\n");	//exibe na tela a op��o 1
			printf("\t2 - Retornar ao MENU\n");	//exibe na tela a op��o 2
			scanf("%d", &opcao);	//armazena o valor da op��o do usu�rio
			
				switch(opcao)	//conjunto de op��es a serem escolhidas e tarefas a serem executadas segundo op��o do usu�rio
					{
						case 1:	//caso o usu�rio escolha a op��o 1, executa a proxima linha
							consulta();	//caso a op��o seja 1, o sistema retorna a fun��o "consulta" novamente
							break;	//pause dentro da fun��o switch, serve para separar as op��es
						
						case 2:	//caso a op��o seja 2, executa a segunda linha
							main();	//caso a op��o seja 2, o sistema retorna a fun��o main novamente
							break;	//separa��o das op�oes dentro do switch case
					
						default:	//caso o usu�rio digite uma op��o diferente das op��es fornecidas, executa a proxima linha
							printf("Por favor, selecione uma op��o v�lida!\n\n");	//escreve na tela "Por favor, selecione uma op��o v�lida!" com duas quebras de linhas logo ap�s.
							system("pause");	//pause do sistema operacinal
							break;	//separa��o de op�oes dentro do switch case
					}
		
		system("pause");	//o sistema operacional da um "pause"
	
}

int deletar()	//fun��o para deletar clientes cadastrados
{
	system("cls");	//limpar a tela.
	
	setlocale(LC_ALL, "Portuguese");	//define o idioma do programa
	
	char cpf[40];	//vari�vel/string
	
	printf("Digite o CPF do cliente a ser deletado: ");	//exibe na tela "Digite o CPF do cliente a ser deletado" para que o usu�rio saiba o que � o momento de digitar o CPF a ser exclu�do
	scanf("%s", cpf);	//armazena o valor digitado pelo usu�rio dentro da vari�vel/string "cpf"
	
	remove(cpf);	//deleta/apaga o arquivo com o nome do cpf armazenado dentro da vari�vel/string "cpf" fornecido pelo usu�rio
	
	FILE *file;	//abre o arquivo
	file = fopen(cpf, "r");	//abre o arquivo encontrado com o valor da vari�vel/string "cpf" e l� (r)= ready
	
	if(file == NULL)	//caso n�o for encontrado um cliente com o cpf digitado pelo usu�rio, executa a pr�xima linha
	{
		printf("N�o foram encontrados clientes com esse CPF!\n");	//exibe na tela "N�o foram encontrados clientes com esse CPF!" com uma quebra de linha ap�s
	}
	system("pause");	//o sistema operacional executa um "pause"
	system("cls");	//pede para o sistema operacinal executar uma limpeza de tela
	
			int opcao=0;
			printf("Oque deseja fazer? \n\n");	//exibe na tela "Oque deseja fazer?" para que o usu�rio entre com uma das op��es apresentadas
			printf("\t1 - Deletar cliente\n");	//exibe na tela a op��o 1
			printf("\t2 - Retornar ao MENU\n");	//exibe na tela a op��o 2
			scanf("%d", &opcao);	//armazena o valor da op��o do usu�rio
			
				switch(opcao)	//conjunto de op��es a serem escolhidas e tarefas a serem executadas segundo op��o do usu�rio
					{
						case 1:	//caso o usu�rio escolha a op��o 1, executa a proxima linha
						
							deletar();	//caso a op��o seja 1, o sistema retorna a fun��o "deletar" novamente
							break;	//pause dentro da fun��o switch, serve para separar as op��es
						
						case 2:	//caso a op��o seja 2, executa a segunda linha
							main();	//caso a op��o seja 2, o sistema retorna a fun��o main novamente
							break;	//separa��o das op�oes dentro do switch case
					
						default:	//caso o usu�rio digite uma op��o diferente das op��es fornecidas, executa a proxima linha
							printf("Por favor, selecione uma op��o v�lida!\n\n");	//escreve na tela "Por favor, selecione uma op��o v�lida!" com duas quebras de linhas logo ap�s.
							system("pause");	//pause do sistema operacinal
							break;	//separa��o de op�oes dentro do switch case
					}
}

int main()	//fun��o principal do sistema
{
	int opcao=0;	//vari�vel interna da fun��o "main", armazena o valor de escolha do cliente no "MENU", (1,2 ou 3).
	int laco=1;	//loop definido para reiniciar o menu caso a op��o seja inv�lida
	char senhaDigitada[10]="a";
	int comparacao;
	printf("***** CLIENTES EBAC *****\n\n");	//anuncia o nome do programa.
	printf("AdminUser!\n\nDigite a sua senha:");
	scanf("%s",senhaDigitada);
	
	comparacao = strcmp(senhaDigitada, "admin");
	
	if(comparacao == 0)
	{
		
		for(laco=1;laco=1;)	//complemento do loop/la�o, executa sempre pois o valor de entrada e de sa�da s�o iguais
		{
			system("cls");	//o sistema operacional limpa a tela
		
			setlocale(LC_ALL, "Portuguese");	//define a linguagem local dos usu�rios do programa.
			
			printf("***** CLIENTES EBAC *****\n\n");	//anuncia o nome do programa.
			printf("\tMENU:\n\n");	//anuncia que o cliente est� no menu de op��es.
			printf("\t1 - Registrar novo cliente\n");	//anuncia a escolha "1".
			printf("\t2 - Consultar cliente\n ");	//anuncia a escolha "2".
			printf("\t3 - Excluir cliente\n\n");	//anuncia a escolha "3".
			printf("\t4 - Sair\n\n");
			
			scanf("%d", &opcao);	//armazena a op��o do cliente na vari�vel "opcao".
			
			system("cls");	//limpar a tela.
			
			switch(opcao)	//switch case das op��es
			{
				case 1:	//caso a escolha do usu�rio for "1", executa a pr�xima linha de comando
					cadastro();	//caso a escolha do usu�rio seja "1", a fun��o "cadastro" � executada
					break;	//usado para separar as op��es dentro do switch case
			
				case 2:	//caso a escolha do usu�rio for "2", executa a pr�xima linha de comando
					consulta();	//caso a escolha do usu�rio seja "2", a fun��o "consulta" � executada
					break;	//usado para separar as op��es dentro do switch case
			
				case 3:	//caso a escolha do usu�rio for "3", executa a pr�xima linha de comando
					deletar();	//caso a escolha do usu�rio seja "3", a fun��o "deletar" � executada
					break;	//usado para separar as op��es dentro do switch case
					
				case 4:
					printf("Obrigado por utilizar o sistema!\n");
					return 0;
					break;
			
				default:	//caso a escolha do usu�rio n�o existir nas op��es", executa a pr�xima linha de comando
					printf("Por favor, selecione uma op��o v�lida!\n\n");	//escreve na tela "Por favor, selecione uma op��o v�lida!" com duas quebras de linhas logo ap�s.
					system("pause");	//o sistema operacional da um "pause"
					break;	//usado para separar as op��es dentro do switch case
			}
		}
	}
	
	else
	{
		printf("Senha incorreta!");
	}
}
