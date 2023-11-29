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
		fscanf(fp, "%d;%[^;];%ld\n", &pacientes[i].numPaciente, pacientes[i].nome, &pacientes[i].tel);
		if (feof(fp)) break;
		i++;
	}
	fclose(fp);
	return 1;
}

/// <summary>
/// Importa planos nutricionais de um ficheiro CSV
/// </summary>
/// <param name="planos"></param>
/// <param name="filename"></param>
/// <param name="pacientes"></param>
/// <returns></returns>
int ImportarPlanos(Plano planos[], char filename[], Paciente pacientes[]) {
	FILE* fp;
	fp = fopen(filename, "r");
	if (fp == NULL) return 0;

	int i = 0;
	while (1)
	{
		fscanf(fp, "%d;%[^;];%[^;];%d;%d\n", &planos[i].numPaciente, planos[i].data, planos[i].refeicao, &planos[i].minCal, &planos[i].maxCal);
		AssociaPlano(planos[i], pacientes);
		if (feof(fp)) break;
		i++;
	}
	fclose(fp);
	return 1;
}

/// <summary>
/// Adiciona o plano a um paciente
/// </summary>
/// <param name="plano"></param>
/// <param name="pacientes"></param>
int AssociaPlano(Plano plano, Paciente pacientes[]) {
	for (int i = 0; i < N; i++)
	{
		if(plano.numPaciente == pacientes[i].numPaciente) {
			//Procura um sitio vazio no array de planos para preencher com um plano novo
			for (int j = 0; j < N; j++)
			{
				if (pacientes[i].planos[j].numPaciente <= 0)
				{
					pacientes[i].planos[j] = plano;
					return 1;
				}
			}
			return 0;
		}
	}
	return 0;
}