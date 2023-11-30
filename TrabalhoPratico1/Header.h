/*
* Paulo Alexandre Rodrigues da Costa
* a29851@alunos.ipca.pt
* 22/11/2023
*
* Trabalho Prático 1
*
* UC: PI
*/
#pragma once

#define N 25
#define M 50

//Struct do plano nutricional
typedef struct Plano {
	int numPaciente;
	char data[N];
	char refeicao[N];
	int minCal;
	int maxCal;
} Plano;

typedef struct Dieta {
	char numPaciente[N];
	char data[M];
	char ref[M];
	char ali[M];
	char cal[N];
} Dieta;

//struct da informação do Paciente
typedef struct Paciente {
	int numPaciente;
	char nome[N];
	long tel;
	Plano planos[N];
} Paciente;

int ImportarPacientes(Paciente pacientes[], char filename[]);

//Importa planos nutricionais de um ficheiro CSV
int ImportarPlanos(Plano planos[], char filename[], Paciente pacientes[]);

//Importa dietas de um ficheiro CSV
int DietaPaciente(Dieta dietas[], char filename[]);
