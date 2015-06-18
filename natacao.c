#include <stdio.h>
#include <stdlib.h>
#define TAM 50 		//constante
#include <locale.h>
//definição de estrutura -> criação de um novo tipo de dado
struct tipo_aluno{
	char nome[80];
	int anoNasc;
	float peso, altura;
};
//variáveis globais->criar os 50 alunos
struct tipo_aluno vet[TAM];
int contAlunos;

//procedimento para inserir um aluno, caso haja espaço
void inserirAluno(){
	//verificar se tem espaço
	if(contAlunos<TAM){
		printf("Informe o nome do aluno: \n");
		fflush(stdin);
		gets(vet[contAlunos].nome);
		printf("Informe o ano de nascimento do aluno: \n");
		scanf("%d", &vet[contAlunos].anoNasc);
		printf("Informe a altura do aluno: \n");
		scanf("%f", &vet[contAlunos].altura);
		printf("Informe o peso do aluno: \n");
		scanf("%f", &vet[contAlunos].peso);
		contAlunos++;
	}
}

//procedimento para listar todos os alunos cadastrados, se houver
void mostrarTodos(){
	int i;
	for(i=0;i<contAlunos;i++){
		printf("Nome: %s\n", vet[i].nome);
		printf("Ano: %d\n", vet[i].anoNasc);
		printf("Peso: %.2f\n", vet[i].altura);
		printf("Altura: %.2f\n", vet[i].peso);
	}
}
//função que recebe um nome e retorna a posição do vetor que contém este nome
//caso o nome não esteja no vetor, retornar a posição -1
int consultaAluno(char *nome){
	int i;
	
	for(i=0;i<contAlunos;i++){
		if(strcmp(vet[i].nome,nome)==0){
			return i;
		}
	}
	
	return -1;
}

int mediaIdades(){
	int idade, soma=0, i;
	for(i=0;i<contAlunos;i++){
		idade=2015 -vet[i].anoNasc;
		soma=soma+idade;
	}
	if(contAlunos>0){
		return soma/contAlunos;
	}else{
		return 0;
	}
}

main(){
	setlocale(LC_ALL, "");
	
	int op, pos, media;
	char nome[80];
	
	//inicializar contAlunos
	contAlunos=0;
	
	//menu
	do{
		system("cls");
		printf("# ESCOLA DE NATAÇÃO #\n\n");
		printf("1-inserir aluno\n");
		printf("2-Consultar aluno por nome\n");
		printf("3-Calcular idade média\n");
		printf("4-Mostrar maior altura\n");
		printf("5-Mostrar maior altura\n");
		printf("6-Mostrar todos\n");
		printf("7-Sair\n");
		printf("Opção: ");
		scanf("%d", &op);
		
		switch(op){
			case 1:		//inserir um aluno
				inserirAluno();
				break;
			case 2:
				printf("Informe o nome do aluno a ser buscado: ");
				fflush(stdin);
				gets(nome);
				pos=consultaAluno(nome);
				if(pos ==-1){
					printf("Nome nao encontrado.\n\n");
				}else{
					printf("Nome: %s\n", vet[pos].nome);
					printf("Ano: %d\n", vet[pos].anoNasc);
					printf("Peso: %.2f\n", vet[pos].altura);
					printf("Altura: %.2f\n", vet[pos].peso);
				}
				
				break;
			case 3:
				media=mediaIdades();
				printf("Média das idades: %d\n", media);
				break;
			case 4:
				printf("Opção 4\n");
				break;
			case 5:
				printf("Opção 5\n");
				break;
			case 6:
				mostrarTodos();
				break;
			case 7:
				break;
			default:
				printf("Opção invalida. Tente novamente.\n\n");							
		}
		
		getch();
		
	}while(op!=7);
}
