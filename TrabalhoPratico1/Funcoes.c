/*
* Paulo Alexandre Rodrigues da Costa
* a29851@alunos.ipca.pt
* 22/11/2023
*
* Implementação de todas as funções do Trabalho Prático 1
*
* UC: PI
*/

#pragma warning (disable: 4996)

#include <stdio.h>
#include "Header.h"

/// <summary>
/// Importa pacientes de um ficheiro CSV
/// </summary>
/// <param name="pacientes"></param>
/// <param name="filename"></param>
/// <returns></returns>
int ImportarPacientes(Paciente pacientes[], char filename[]) {
	FILE* fp;
	fp = fopen(filename, "r");
	if (fp == NULL) return 0;

	int i = 0;
	while (1)
	{
		fscanf(fp, "%[^;];%[^;];%ld", pacientes[i].numPaciente, pacientes[i].nome, &pacientes[i].tel);
		if (feof(fp)) break;
		i++;
	}
	fclose(fp);
	return 1;
}
/// <summary>
/// Importa dieta dos pacientes de um ficheiro CSV
/// </summary>
/// <param name="dieta"></param>
/// <param name="filename"></param>
/// <returns></returns>
int DietaPaciente(Dieta Dietas[], char filename[]) {
	FILE* fp;
	fp = fopen(filename, "r");
	if (fp == NULL) return 0;

	int i = 0;
	while (1)
	{
		fscanf(fp, " %[^;];%[^;];%[^;];%[^;];%[^;\n]\n",
			Dietas[i].numPaciente, Dietas[i].data, Dietas[i].ref, Dietas[i].ali, Dietas[i].cal);
		if (feof(fp)) break;
		i++;
	}
	fclose(fp);
	return 1;
}
