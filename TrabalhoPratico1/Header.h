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

#include "Funcoes.c"
#define N 25

typedef struct Paciente {
	char numPaciente[N];
	char nome[N];
	long tel;
} Paciente;

int ImportarPacientes(Paciente pacientes[], char filename[]);
