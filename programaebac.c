#include <stdio.h>	//biblioteca de texto, comunicação com o usuário.
#include <stdlib.h>	//biblioteca de alocação de memória.
#include <locale.h>	//biblioteca de alocações de texto por região.
#include <string.h>	//biblioteca de gerenciamento de strings.

int cadastro()	//função para cadastrar clientes no sistema
{

	//início da criação de variáveis/string
	char arquivo[40];
	char cpf[40];
	char nome[50];
	char telefone[40];
	char email[40];
	//final da criação de variáveis/string
		
		system("cls");
		
		printf("Cadastro de clientes:\n\n");	//coletando informação do usuário
		printf("CPF: ");	//coletando informação do usuário
		scanf("%s", cpf);	//armazenando o valor digitado na variavel/string "cpf"
		
		strcpy(arquivo, cpf);	//copia os valores das strings.
		FILE *file;	//"FILE" significa o navegador de arquivos do windows, "file" significa o arquivo .txt a ser criado dentro da pasta do programa.
		file = fopen(arquivo, "w");	//	abre o arquivo "file" e escreve; "w".(arquivo novo).
		fprintf(file,"CPF: ");
		fprintf(file, cpf);	//"fprintf" escreve no arquivo .txt o valor da variável "cpf".
		fclose(file);	//fecha o arquivo "file".
		
		file = fopen(arquivo, "a");	//abrindo o arquivo e atualizando
		fprintf(file, ",");	//escreve uma vírgula entre os valores
		fclose(file);	//fecha o arquivo
		
		printf("Nome: ");	//exibe na tela "Nome: " para o usuário entender que é o momento para digitar o Nome a ser cadastrado
		scanf("%s", nome);	//armazenando o valor que o usuário digitou dentro da variável/string "nome"
		file = fopen(arquivo, "a");	//abrindo o arquivo e atualizando
		fprintf(file,"Nome: ");	//escrevendo no arquivo "Nome: "
		fprintf(file,nome);	//escrevendo no arquivo o conteúdo da variável/string "nome"
		fclose(file);	//fecha o arquivo
		
		file = fopen(arquivo, "a");	//abrindo o arquivo e atualizando
		fprintf(file, ",");	//escrevendo no arquivo uma virgula entre os valores
		fclose(file);	//fechando o arquivo
		
		printf("Telefone: ");	//exibibe na tela "Telefone: " para o usuário saber que é momento de digitar o telefone a ser cadastrado
		scanf("%s", telefone);	//armazena o valor digitado pelo usuário dentro da variável/string "telefone"
		file = fopen(arquivo, "a");	//abre o arquivo e atualiza
		fprintf(file,"Telefone: ");	//escreve "Telefone: " no arquivo
		fprintf(file,telefone);	//escreve no arquivo o conteúdo da variável/string "telefone"
		fclose(file);	//fecha o arquivo
		
		file = fopen(arquivo, "a");	//abre o arquivo e atualiza
		fprintf(file, ",");	//abre o arquivo e digita uma virgula
		fclose(file);	//fecha o arquivo
		
		printf("Email: ");	//exibe na tela "Email: " para que o usuário saiba o momento para digitar o email a ser cadastrado
		scanf("%s", email);	//armazena o valor digitado pelo usuário dentro da variável/string "email"
		file = fopen(arquivo, "a");	//abre o arquivo e atualiza
		fprintf(file,"Email: ");	//escreve no arquivo "Email: "
		fprintf(file,email);	//escreve no arquivo o valor da variável/string "email"
		fclose(file);	//fecha o arquivo
		
		system("pause");	//pede para o sistema operacional dar um "pause"
		system("cls");	//pede para o sistema operacional exeutar uma limpeza na tela		
		
		int opcao=0;	//variável para armazenar a escolha do usuário dentro do menu
		printf("Cliente cadastrado com sucesso!\n\n");	//escreve na tela uma confirmação para o usuário de que o cliente doi cadastrado com sucesso no sistema
		system("pause");	//pede para o suistema operacional dar um "pause
		
		system("cls");	//pede para o sistema operacinal executar uma limpeza de tela
	
			printf("Oque deseja fazer? \n\n");	//exibe na tela "Oque deseja fazer?" para que o usuário entre com uma das opções apresentadas
			printf("\t1 - Cadastrar novo cliente\n");	//exibe na tela a opção 1
			printf("\t2 - Retornar ao MENU\n");	//exibe na tela a opção 2
			scanf("%d", &opcao);	//armazena o valor da opção do usuário
			
				switch(opcao)	//conjunto de opções a serem escolhidas e tarefas a serem executadas segundo opção do usuário
					{
						case 1:	//caso o usuário escolha a opção 1, executa a proxima linha
						
							cadastro();	//caso a opção seja 1, o sistema retorna a função cadastro novamente
							break;	//pause dentro da função switch, serve para separar as opções
						
						case 2:	//caso a opção seja 2, executa a segunda linha
							main();	//caso a opção seja 2, o sistema retorna a função main novamente
							break;	//separação das opçoes dentro do switch case
					
						default:	//caso o usuário digite uma opção diferente das opções fornecidas, executa a proxima linha
							printf("Por favor, selecione uma opção válida!\n\n");	//escreve na tela "Por favor, selecione uma opção válida!" com duas quebras de linhas logo após.
							system("pause");	//pause do sistema operacinal
							break;	//separação de opçoes dentro do switch case
					}
}

int consulta()	//função para consultar clientes cadastrados
{
	system("cls");	//limpar a tela.
	setlocale(LC_ALL, "Portuguese");	//linguagem dos usuários e que o programa irá exibir os textos
	
	//inicio das variáveis/string
	char cpf[40];
	char conteudo[200];
	//final das variáveis/string
	
	printf("Digite o cpf a ser consultado: ");	//exibe na tela "Digite o cpf a ser consultado: ", para que o usuário saiba que é o momento de digitar o cpf que deseja consultar
	scanf("%s", cpf);	//armazena o valor digitado pelo usuário dentro da variável/string "cpf"
	
	FILE *file;	//o sistema acessa o gerenciador de arquivos do sistema operacional e procura os arquivos do programa
	file = fopen(cpf, "r");	//abre o arquivo encontrado com o valor da variável/string "cpf" digitado pelo usuário e lê
	
	if(file == NULL)	//caso não exista o cpf digitado pelo usuário, executa a próxima linha de código
	{
		printf("\n\nEsse cliente não existe!\n\n");	//exibe na tela "Esse cliente não existe!"
	}
		
	while(fgets(conteudo, 200, file) != NULL)	//faz uma busca dentro do arquivo, armazena o conteudo dentro da variavel "conteudo" até 200 caracteres, até que não existam mais caracteres
	{
		printf("\nInformações do Cliente: ");	//exibe na tela "Informações do Cliente: "
		printf("%s", conteudo);	//exibe na tela o conteudo armazenado dentro da variável/string "conteudo"
		printf("\n\n");	//exibe duas quebras de linha
	}
		system("pause");	//pede para o sistema operacinal executar uma limpeza de tela
	
		system("cls");	//limpar a tela.
		
			int opcao=0;
			printf("Oque deseja fazer? \n\n");	//exibe na tela "Oque deseja fazer?" para que o usuário entre com uma das opções apresentadas
			printf("\t1 - Consultar novo cliente\n");	//exibe na tela a opção 1
			printf("\t2 - Retornar ao MENU\n");	//exibe na tela a opção 2
			scanf("%d", &opcao);	//armazena o valor da opção do usuário
			
				switch(opcao)	//conjunto de opções a serem escolhidas e tarefas a serem executadas segundo opção do usuário
					{
						case 1:	//caso o usuário escolha a opção 1, executa a proxima linha
							consulta();	//caso a opção seja 1, o sistema retorna a função "consulta" novamente
							break;	//pause dentro da função switch, serve para separar as opções
						
						case 2:	//caso a opção seja 2, executa a segunda linha
							main();	//caso a opção seja 2, o sistema retorna a função main novamente
							break;	//separação das opçoes dentro do switch case
					
						default:	//caso o usuário digite uma opção diferente das opções fornecidas, executa a proxima linha
							printf("Por favor, selecione uma opção válida!\n\n");	//escreve na tela "Por favor, selecione uma opção válida!" com duas quebras de linhas logo após.
							system("pause");	//pause do sistema operacinal
							break;	//separação de opçoes dentro do switch case
					}
		
		system("pause");	//o sistema operacional da um "pause"
	
}

int deletar()	//função para deletar clientes cadastrados
{
	system("cls");	//limpar a tela.
	
	setlocale(LC_ALL, "Portuguese");	//define o idioma do programa
	
	char cpf[40];	//variável/string
	
	printf("Digite o CPF do cliente a ser deletado: ");	//exibe na tela "Digite o CPF do cliente a ser deletado" para que o usuário saiba o que é o momento de digitar o CPF a ser excluído
	scanf("%s", cpf);	//armazena o valor digitado pelo usuário dentro da variável/string "cpf"
	
	remove(cpf);	//deleta/apaga o arquivo com o nome do cpf armazenado dentro da variável/string "cpf" fornecido pelo usuário
	
	FILE *file;	//abre o arquivo
	file = fopen(cpf, "r");	//abre o arquivo encontrado com o valor da variável/string "cpf" e lê (r)= ready
	
	if(file == NULL)	//caso não for encontrado um cliente com o cpf digitado pelo usuário, executa a próxima linha
	{
		printf("Não foram encontrados clientes com esse CPF!\n");	//exibe na tela "Não foram encontrados clientes com esse CPF!" com uma quebra de linha após
	}
	system("pause");	//o sistema operacional executa um "pause"
	system("cls");	//pede para o sistema operacinal executar uma limpeza de tela
	
			int opcao=0;
			printf("Oque deseja fazer? \n\n");	//exibe na tela "Oque deseja fazer?" para que o usuário entre com uma das opções apresentadas
			printf("\t1 - Deletar cliente\n");	//exibe na tela a opção 1
			printf("\t2 - Retornar ao MENU\n");	//exibe na tela a opção 2
			scanf("%d", &opcao);	//armazena o valor da opção do usuário
			
				switch(opcao)	//conjunto de opções a serem escolhidas e tarefas a serem executadas segundo opção do usuário
					{
						case 1:	//caso o usuário escolha a opção 1, executa a proxima linha
						
							deletar();	//caso a opção seja 1, o sistema retorna a função "deletar" novamente
							break;	//pause dentro da função switch, serve para separar as opções
						
						case 2:	//caso a opção seja 2, executa a segunda linha
							main();	//caso a opção seja 2, o sistema retorna a função main novamente
							break;	//separação das opçoes dentro do switch case
					
						default:	//caso o usuário digite uma opção diferente das opções fornecidas, executa a proxima linha
							printf("Por favor, selecione uma opção válida!\n\n");	//escreve na tela "Por favor, selecione uma opção válida!" com duas quebras de linhas logo após.
							system("pause");	//pause do sistema operacinal
							break;	//separação de opçoes dentro do switch case
					}
}

int main()	//função principal do sistema
{
	int opcao=0;	//variável interna da função "main", armazena o valor de escolha do cliente no "MENU", (1,2 ou 3).
	int laco=1;	//loop definido para reiniciar o menu caso a opção seja inválida
	char senhaDigitada[10]="a";
	int comparacao;
	printf("***** CLIENTES EBAC *****\n\n");	//anuncia o nome do programa.
	printf("AdminUser!\n\nDigite a sua senha:");
	scanf("%s",senhaDigitada);
	
	comparacao = strcmp(senhaDigitada, "admin");
	
	if(comparacao == 0)
	{
		
		for(laco=1;laco=1;)	//complemento do loop/laço, executa sempre pois o valor de entrada e de saída são iguais
		{
			system("cls");	//o sistema operacional limpa a tela
		
			setlocale(LC_ALL, "Portuguese");	//define a linguagem local dos usuários do programa.
			
			printf("***** CLIENTES EBAC *****\n\n");	//anuncia o nome do programa.
			printf("\tMENU:\n\n");	//anuncia que o cliente está no menu de opções.
			printf("\t1 - Registrar novo cliente\n");	//anuncia a escolha "1".
			printf("\t2 - Consultar cliente\n ");	//anuncia a escolha "2".
			printf("\t3 - Excluir cliente\n\n");	//anuncia a escolha "3".
			printf("\t4 - Sair\n\n");
			
			scanf("%d", &opcao);	//armazena a opção do cliente na variável "opcao".
			
			system("cls");	//limpar a tela.
			
			switch(opcao)	//switch case das opções
			{
				case 1:	//caso a escolha do usuário for "1", executa a próxima linha de comando
					cadastro();	//caso a escolha do usuário seja "1", a função "cadastro" é executada
					break;	//usado para separar as opções dentro do switch case
			
				case 2:	//caso a escolha do usuário for "2", executa a próxima linha de comando
					consulta();	//caso a escolha do usuário seja "2", a função "consulta" é executada
					break;	//usado para separar as opções dentro do switch case
			
				case 3:	//caso a escolha do usuário for "3", executa a próxima linha de comando
					deletar();	//caso a escolha do usuário seja "3", a função "deletar" é executada
					break;	//usado para separar as opções dentro do switch case
					
				case 4:
					printf("Obrigado por utilizar o sistema!\n");
					return 0;
					break;
			
				default:	//caso a escolha do usuário não existir nas opções", executa a próxima linha de comando
					printf("Por favor, selecione uma opção válida!\n\n");	//escreve na tela "Por favor, selecione uma opção válida!" com duas quebras de linhas logo após.
					system("pause");	//o sistema operacional da um "pause"
					break;	//usado para separar as opções dentro do switch case
			}
		}
	}
	
	else
	{
		printf("Senha incorreta!");
	}
}
