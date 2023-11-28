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

//struct da informação do Paciente
typedef struct Paciente {
	int numPaciente;
	char nome[N];
	long tel;
} Paciente;

//Struct do plano nutricional
typedef struct Plano {
	int numPaciente;
	char nome[N];
	long tel;
} Plano;

int ImportarPacientes(Paciente pacientes[], char filename[]);
