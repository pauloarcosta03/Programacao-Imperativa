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
#include <string.h>
#include "Header.h"

#pragma region IMPORTAÇÕES
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
/// Importa dieta dos pacientes de um ficheiro CSV
/// </summary>
/// <param name="dieta"></param>
/// <param name="filename"></param>
/// <returns></returns>
int DietaPaciente(Dieta dietas[], char filename[]) {
	FILE* fp;
	fp = fopen(filename, "r");
	if (fp == NULL) return 0;

	int i = 0;
	while (1)
	{
		fscanf(fp, "%d;%[^;];%[^;];%[^;];%d",
			&dietas[i].numPaciente, dietas[i].data, dietas[i].ref, dietas[i].ali, &dietas[i].cal);
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
		//AssociaPlano(planos[i], pacientes);
		if (feof(fp)) break;
		i++;
	}
	fclose(fp);
	return 1;
}
#pragma endregion

/// <summary>
/// Conta o nº de pacientes que ultrapassaram o limite de calorias
/// </summary>
/// <param name="planos"></param>
/// <param name="tamPlanos"></param>
/// <param name="dietas"></param>
/// <param name="tamDietas"></param>
/// <returns></returns>
int NumPacientesCalMais(Plano planos[], int tamPlanos, Dieta dietas[], int tamDietas) {
	int pacientesCalMais = 0;

	int calPaciente = 0;
	//Corre todos os planos de um array e depois por cada plano corre as dietas associadas a esse paciente e refeição
	for (int i = 0; i < tamPlanos; i++)
	{
		calPaciente = 0;
		
		//Corre as dietas
		for (int j = 0; j < tamDietas; j++)
		{
			if (planos[i].numPaciente == dietas[j].numPaciente && strcmp(planos[i].refeicao, dietas[j].ref) == 0)
			{
				calPaciente = calPaciente + dietas[j].cal;
			}
		}
		if (calPaciente > planos[i].maxCal) pacientesCalMais++;

	}
	return pacientesCalMais;
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

/// <summary>
/// Lista plano por refeicao
/// </summary>
/// <param name="planos"></param>
/// <param name="detalhes"></param>
/// <param name="tamPlanos"></param>
/// <param name="numPaciente"></param>
/// <param name="refeicao"></param>
/// <returns></returns>
int ListarPlanoPorRefeicao(Plano planos[], Plano detalhes[], int tamPlanos, int numPaciente, char refeicao[]) {
	int contaDetalhes = 0;
	for (int i = 0; i < tamPlanos; i++) {
		if (planos[i].numPaciente == numPaciente && strcmp(planos[i].refeicao, refeicao) == 0) {
			strcpy(detalhes[contaDetalhes].data, planos[i].data);
			detalhes[contaDetalhes].numPaciente = planos[i].numPaciente;
			detalhes[contaDetalhes].minCal = planos[i].minCal;
			detalhes[contaDetalhes].maxCal = planos[i].maxCal;
			strcpy(detalhes[contaDetalhes].refeicao, planos[i].refeicao);
			contaDetalhes++;
		}
	}return 1;

}


int calcularMediaCalorias(Dieta dietas[], int numDietas, Paciente pacientes[], int numPacientes, char refeicao[], MediaCalorias mc[]) {
	double somaCalorias = 0;
	int numRefeicoes = 0;

	int posMedia = 0;

	for (int j = 0; j < numPacientes; j++)
	{

		// Calcule a soma das calorias para a refeição e paciente específicos
		for (int i = 0; i < numDietas; i++) {
			if (dietas[i].numPaciente == pacientes[j].numPaciente && strcmp(dietas[i].ref, refeicao) == 0) {
				somaCalorias += dietas[i].cal;
				numRefeicoes++;
			}
		}

		// Calcule a média de calorias se houver pelo menos uma refeição
		if (numRefeicoes > 0) {
			mc[posMedia].numPaciente = pacientes[j].numPaciente;
			mc[posMedia].mediaCal = somaCalorias/numRefeicoes;
			strcpy(mc[posMedia].ref, refeicao);

			numRefeicoes = 0;
			posMedia++;
		}
	}

}