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

typedef struct Paciente {
	char numPaciente[N];
	char nome[N];
	long tel;
} Paciente;

typedef struct Dieta {
	char numPaciente[N];
	char data[M];
	char ref[M];
	char ali[M];
	char cal[N];
} Dieta;

int ImportarPacientes(Paciente pacientes[], char filename[]);

int DietaPaciente(Dieta dietas[], char filename[]);

